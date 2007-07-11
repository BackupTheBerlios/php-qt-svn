/*!
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2006 - 2007
 * Thomas Moenicke <tm at php-qt.org>
 * Katrina Niolet <katrina at niolet.name>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#include <QtCore/qglobal.h>
#include <QtCore/QHash>

#include "php_qt.h"
#include "ext/standard/info.h"
#include "ext/standard/php_string.h"

#include "zend_handlers.h"
#include "smoke.h"
#include "marshall_types.h"
#include "phpqt_internals.h"

// #define IQUIP

#define DEBUG 1
#define MOC_DEBUG 0

extern void init_qt_Smoke();
extern TypeHandler Qt_handlers[];
void install_handlers(TypeHandler *);

static int le_php_qt;

// object list
int le_php_qt_hashtype;
HashTable php_qt_objptr_hash;

// object handler
extern zend_object_handlers php_qt_handler;

PHP_INI_BEGIN()
    PHP_INI_ENTRY("qt.codec", "UTF8", PHP_INI_ALL, NULL)
PHP_INI_END()

/*! php_qt_functions[]
 *
 * Every user visible function must have an entry in php_qt_functions[].
 */
#undef emit
function_entry php_qt_functions[] = {
	PHP_FE(confirm_php_qt_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(SIGNAL,	NULL)
	PHP_FE(SLOT,	NULL)
	PHP_FE(emit,	NULL)
	PHP_FE(qDebug,	NULL)
	PHP_FE(qWarning,	NULL)
	PHP_FE(qCritical,	NULL)
	PHP_FE(qAbs, 		NULL)
	PHP_FE(qRound,		NULL)
	PHP_FE(qRound64,	NULL)
	PHP_FE(qMin,		NULL)
	PHP_FE(qMax,		NULL)
	PHP_FE(qBound,		NULL)
	PHP_FE(qPrintable,	NULL)
	PHP_FE(qFuzzyCompare,	NULL)
	PHP_FE(qIsNull,		NULL)
	PHP_FE(qIntCast,	NULL)
	PHP_FE(qVersion,	NULL)
	PHP_FE(PHPQtVersion,	NULL)
	PHP_FE(QiDiVersion,	NULL)
	PHP_FE(qSharedBuild,		NULL)
	PHP_FE(qMalloc,		NULL)
	PHP_FE(qFree,		NULL)
	PHP_FE(qRealloc,	NULL)
	PHP_FE(qMemCopy,	NULL)
	PHP_FE(qt_noop,		NULL)
	PHP_FE(qt_assert,	NULL)
	PHP_FE(qt_assert_x,	NULL)
	PHP_FE(Q_ASSERT,	NULL)
	PHP_FE(Q_ASSERT_X,	NULL)
	PHP_FE(qt_check_pointer,	NULL)
	PHP_FE(qobject_cast,	phpqt_cast_arginfo)
	PHP_FE(tr,	NULL)
	PHP_FE(check_qobject,	NULL)
	{NULL, NULL, NULL}	/* Must be the last line in php_qt_functions[] */
};

/*! php_qt_module_entry
 */
zend_module_entry php_qt_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"php_qt",
	php_qt_functions,
	PHP_MINIT(php_qt),
	PHP_MSHUTDOWN(php_qt),
	PHP_RINIT(php_qt),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(php_qt),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(php_qt),
#if ZEND_MODULE_API_NO >= 20010901
	PHPQT_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_PHP_QT
ZEND_GET_MODULE(php_qt)
#endif

QStack<QByteArray*> methodNameStack;

zend_class_entry* activeCe;
zval* activeScope;
bool parentCall;

// cached
Smoke::Index qbool;
Smoke::Index qstring;
Smoke::Index qobject;
extern zend_class_entry* qobject_ce;
extern zend_class_entry* qstring_ce;
extern void 	_register_QString();

/**
 *	generic object
 */

static zend_function_entry php_qt_generic_methods[] = {
    ZEND_ME(php_qt_generic_class,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(php_qt_generic_class,__destruct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(php_qt_generic_class,__toString,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(php_qt_generic_class,emit,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(php_qt_generic_class,proxyMethod,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(php_qt_generic_class,staticProxyMethod,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    {NULL,NULL,NULL}
};

ZEND_METHOD(php_qt_generic_class, emit){
  smokephp_object* o = PHPQt::getSmokePHPObjectFromZval(const_cast<const zval*>(getThis()));
  qDebug() << o->meta();

}

ZEND_METHOD(php_qt_generic_class, __toString)
{
	RETURN_STRING("", 1);
}

ZEND_METHOD(php_qt_generic_class, __destruct)
{
	if(PHPQt::SmokePHPObjectExists(getThis())) {
 		smokephp_object *o = PHPQt::getSmokePHPObjectFromZval(getThis());
		//! its not a reference
		if(!PZVAL_IS_REF(getThis()))
		{
			o->setAllocated(false);
		}
		if(!PHPQt::unmapSmokePHPObject(getThis()))
		{
			qFatal("try to unmap unregistered zval");
		}
	}
}

ZEND_METHOD(php_qt_generic_class, __construct)
{
	activeScope = getThis();

    // find parents
    zend_class_entry *ce = Z_OBJCE_P(getThis());
    zend_class_entry *ce_parent = Z_OBJCE_P(getThis());

    while (PQ::smoke()->idClass(ce->name) <= 0) {
// 	    ce_parent = ce->parent;
	    ce = ce->parent; // orig
    }

    activeCe = ce;

    // get arguments
    int i, argc = ZEND_NUM_ARGS();
    zval ***args = (zval ***) safe_emalloc(argc, sizeof(zval **), 0);
    if(zend_get_parameters_array_ex(argc, args) == FAILURE)
    {
	    efree(args);   WRONG_PARAM_COUNT;
    }

    methodNameStack.push(new QByteArray(ce->name));

#ifdef IQUIP
	// remove the leading '_'
	methodNameStack.top()->remove(0,1);
#endif

    smokephp_prepareMethodName(args, argc, methodNameStack);	// #, $, ?
    Smoke::Index method = smokephp_getMethod(ce->name, methodNameStack.top()->constData(), ZEND_NUM_ARGS(), args);

    MethodCall c(PQ::smoke(), method, getThis(), args, argc-1, getThis(), return_value_ptr);
    c.next();

	// smokephp_object is created above in c.next()
    smokephp_object* o = PHPQt::getSmokePHPObjectFromZval(getThis());
    o->setParentCePtr(ce_parent); // = ce if no parent

	// if QObject
	if(smokephp_isQObject(PQ::smoke()->idClass(ce->name))){

		// fetch superdata
		Smoke::Index nameId = o->smoke()->idMethodName("metaObject");
		Smoke::Index meth = o->smoke()->findMethod(o->classId(), nameId);
		Smoke::Method &methodId = o->smoke()->methods[o->smoke()->methodMaps[meth].method];
		Smoke::ClassFn fn = o->smoke()->classes[methodId.classId].classFn;
		Smoke::StackItem i[1];
		(*fn)(methodId.method, const_cast<void*>(o->ptr()), i);
		QMetaObject *superdata = (QMetaObject *) i[0].s_voidp;

 		QString* phpqt_meta_stringdata = new QString("");
    		uint* phpqt_meta_data = (uint*) emalloc(sizeof(uint)*20*5+10);

		//	create the metaObject
		if(PHPQt::getMocData(
				getThis(),
				o->parent_ce_ptr()->name,
				superdata,
				o->meta(),
				phpqt_meta_stringdata,
				phpqt_meta_data
		)){
		  	const char* phpqt_meta_stringdata_ = estrndup(phpqt_meta_stringdata->toAscii(), phpqt_meta_stringdata->size());
  			QMetaObject ob = {
				{superdata, phpqt_meta_stringdata_,
					phpqt_meta_data, 0}
 			};
 			QMetaObject* m = (QMetaObject*) emalloc(sizeof(ob));
 			memcpy(m, &ob, sizeof(ob));
			o->setMetaObject(m);
		} else {
			o->setMetaObject(superdata);
		}

	}

    // cleanup
    efree(args);
    methodNameStack.pop();

    return;

}

ZEND_METHOD(php_qt_generic_class, proxyMethod)
{

    zend_class_entry *ce;
    // nonstaticphp_qt_generic_class_proxyMethod
    if(getThis()){
		// if a parent:: call occurs this_ptr has the wrong ce, so we need to
		// correct it here
		if(parentCall)
		{
			ce = activeCe;
			parentCall = false;
        } else {
        	activeScope = getThis();
        	ce = Z_OBJCE_P(getThis());
        	activeCe = ce;
        }
    // static
    } else {
		ce = activeCe;
    }

    // find parents
    while (PQ::smoke()->idClass(ce->name) <= 0) {
	    ce = ce->parent;
	}
    // arguments
    int j, argc = ZEND_NUM_ARGS();
    zval ***args;
    args = (zval ***) safe_emalloc(argc, sizeof(zval **), 0);
    if(zend_get_parameters_array_ex(argc, args) == FAILURE){
	    efree(args);
	    WRONG_PARAM_COUNT;
    }

    smokephp_prepareMethodName(args, argc, methodNameStack);
    Smoke::Index method = smokephp_getMethod(ce->name, methodNameStack.top()->constData(), argc, args);

    if(method <= 0) {
	if(methodNameStack.top()->constData()) {

	    // is it a signal?
	    if(getThis()){
		smokephp_object* o = PHPQt::getSmokePHPObjectFromZval(getThis());
		if(o->meta() != NULL){
		    QMetaObject* mo = static_cast<QMetaObject*>(o->meta());
		    QByteArray signalname(methodNameStack.top()->constData());
		    signalname.replace("$","");
		    signalname.replace("#","");
		    signalname.replace("?","");
		    MocArgument *mocStack = new MocArgument[argc+1]; // first entry is return value
		    signalname.append(smokephp_getSignature(argc, args, mocStack)->constData());
		    // seems to be a signal
		    int index = mo->indexOfSignal(signalname);
		    if(index >= 0) {
			QObject *qobj = (QObject*)o->smoke()->cast(
			    const_cast<void*>(o->ptr()),
			    o->classId(),
			    o->smoke()->idClass("QObject")
			);
			zval* result;
			EmitSignal signal(qobj, index, argc, mocStack, args, result);
			signal.next();
			// TODO return value
			RETURN_NULL();
		    }
		}
	    }

	    php_error(E_ERROR,"Call to undefined method %s::%s() or wrong arguments", ce->name, methodNameStack.top()->constData());

	}
	else
	    php_error(E_ERROR,"Call to undefined method!");
    }

    MethodCall c(PQ::smoke(), method, getThis(), args, argc-1, return_value, return_value_ptr);
    c.next();

    // cleanup
    efree(args);
    methodNameStack.pop();

    return;
} // proxyMethod

ZEND_METHOD(php_qt_generic_class, staticProxyMethod)
{
	this_ptr = NULL;

	// do we have a parent::foo() call?
	if(EG(active_op_array)->scope){
		if(EG(scope) == EG(active_op_array)->scope->parent)
		{
			if(activeScope)
			{
				parentCall = true;
				this_ptr = activeScope;
			}
		}
	}

	// forward to proxyMethod
	zim_php_qt_generic_class_proxyMethod(ht, return_value, return_value_ptr, this_ptr, return_value_used);
}

/*!
 *	PHP_MINIT_FUNCTION
 */

PHP_MINIT_FUNCTION(php_qt)
{
	REGISTER_INI_ENTRIES();
	init_codec();

	install_handlers(Qt_handlers);

	// object list
	le_php_qt_hashtype = zend_register_list_destructors_ex(PHPQt::destroyHashtable, NULL, "PHP-Qt object list", module_number);
	zend_hash_init_ex(&php_qt_objptr_hash, PHPQT_CLASS_COUNT, NULL, NULL, 1, 0);

	ZendHandlers::installZendHandlers();
	smokephp_init();

	// cache class entries
	Smoke::Index i = 1;
	QHash<const char*, zend_class_entry*> tmpCeTable;

	// loop for all classes, register class entries
	for(i = 1; i <= PQ::smoke()->numClasses; i++){

        zend_function_entry* t = (zend_function_entry*) safe_emalloc(7, sizeof(zend_function_entry), 0);
        zend_function_entry* p = t;

        PHP_QT_ME(php_qt_generic_class,__construct,phpqt_cast_arginfo,ZEND_ACC_PUBLIC);
        PHP_QT_ME(php_qt_generic_class,__destruct,NULL,ZEND_ACC_PUBLIC);
        PHP_QT_ME(php_qt_generic_class,__toString,NULL,ZEND_ACC_PUBLIC);
		PHP_QT_ME(php_qt_generic_class,emit,NULL,ZEND_ACC_PUBLIC);
        PHP_QT_ME(php_qt_generic_class,proxyMethod,phpqt_cast_arginfo,ZEND_ACC_PUBLIC);
        PHP_QT_ME(php_qt_generic_class,staticProxyMethod,phpqt_cast_arginfo,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

		// register zend class
		zend_class_entry ce;

		INIT_CLASS_ENTRY(ce, PQ::smoke()->classes[i].className, p);
		ce.name_length = strlen(PQ::smoke()->classes[i].className);
		zend_class_entry* ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);
		tmpCeTable[PQ::smoke()->classes[i].className] = ce_ptr;
		// cache QObject
		if(qobject == i){
			qobject_ce = ce_ptr;
		}

	} // end loop classes

	// do inheritance, all classes must be defined before
	for(Smoke::Index i = 1; i <= PQ::smoke()->numClasses; i++){
	    zend_class_entry* ce = tmpCeTable[PQ::smoke()->classes[i].className];
	    for(Smoke::Index *p = PQ::smoke()->inheritanceList + PQ::smoke()->classes[i].parents; *p; p++) {
		zend_class_entry *parent_ce = tmpCeTable[PQ::smoke()->classes[*p].className];
    		zend_do_inheritance(ce, parent_ce TSRMLS_CC);
	    }
	}

	// cache some stuff
	Smoke::Index qobject = PQ::smoke()->idClass("QObject");
	_register_QString();

    return SUCCESS;
} // PHP_MINIT


/* PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(php_qt)
{
//	methodNameStack.~QStack();
//	SmokeQtObjects.~QHash();
	return SUCCESS;
}

/*! PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(php_qt)
{
	return SUCCESS;
}

/*! PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(php_qt)
{
	zend_hash_destroy(&php_qt_objptr_hash);
	return SUCCESS;
}

/*! PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(php_qt)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "PHP-Qt support", "enabled");
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}
