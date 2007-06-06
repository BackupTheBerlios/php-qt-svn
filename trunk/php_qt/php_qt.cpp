/*!
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2006
 * Thomas Moenicke <thomas.moenicke at kdemail.net>
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

#include <zend_interfaces.h>
#include "php_qt.h"
#include "ext/standard/php_string.h"

#include <QtCore/qglobal.h>

#include "marshall.h"
#include "php_qt.h"
#include "smokephp.h"
#include "smoke.h"
#include "marshall_types.h"

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
static zend_object_handlers php_qt_handler;
static zend_object_handlers zend_orig_handler;

PHP_INI_BEGIN()
    PHP_INI_ENTRY("qt.codec", "UTF8", PHP_INI_ALL, NULL)
PHP_INI_END()

// opcode handler
#define PHPQT_OPHANDLER_COUNT				((25 * 151) + 1)
#define EX__(element) execute_data->element
#define EX_T(offset) (*(temp_variable *)((char *) EX__(Ts) + offset))
static opcode_handler_t *phpqt_original_opcode_handlers;
static opcode_handler_t phpqt_opcode_handlers[PHPQT_OPHANDLER_COUNT];


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

QHash<void*, smokephp_object*> SmokeQtObjects;
QHash<zend_object_handle, smokephp_object*> obj_x_smokephp;
QStack<QByteArray*> methodNameStack;

zend_class_entry* activeCe;
zval* activeScope;
bool parentCall;

// cached
Smoke::Index qbool;
Smoke::Index qstring;
Smoke::Index qobject;
zend_class_entry* qobject_ce;
extern zend_class_entry* qstring_ce;
extern void 	_register_QString();

/*!
 *	constant method handler
 *
 *	here we'll try to find a defined static method in Qt and assign the
 *  staticProxyMethod handler
 *  see ZEND_INIT_STATIC_METHOD_CALL_SPEC_CONST_HANDLER in zend_vm_execute.h
 */
#undef EX
#define EX(element) execute_data->element

static int (*originalConstantMethodHandler)(ZEND_OPCODE_HANDLER_ARGS);

static int constantMethodHandler(ZEND_OPCODE_HANDLER_ARGS)
{
	zend_op *opline = EX(opline);
	zend_class_entry *ce = EX_T(opline->op1.u.var).class_entry;
	union _zend_function *fbc;
	zval* function_name;
	char* function_name_strval;
	int function_name_strlen;

	function_name = &opline->op2.u.constant;
	// store the active ce
	activeCe = EX_T(opline->op1.u.var).class_entry;

	if (Z_TYPE_P(function_name) != IS_STRING) {
		zend_error_noreturn(E_ERROR, "Function name must be a string");
	}

	// get method name
  	function_name_strval = zend_str_tolower_dup(function_name->value.str.val, function_name->value.str.len);
 	function_name_strlen = function_name->value.str.len;

	// call proxyMethod if method is not defined in userspace
	if(zend_hash_find(&ce->function_table, function_name_strval, function_name_strlen+1, (void**) &fbc) == FAILURE)
	{
		zend_ptr_stack_3_push(&EG(arg_types_stack), EX(fbc), EX(object), NULL);
		zend_bool is_const = (IS_CONST == IS_CONST);

		if(zend_hash_find(&ce->function_table, "staticproxymethod", 18, (void**) &fbc) != FAILURE)
		{

			//! TODO	darn! we have a lowersized string here!
			const char* methodName = PQ::findRealMethodName( function_name->value.str.val );
			methodNameStack.push( new QByteArray( methodName ) );

			EX(fbc) = fbc;

			if(!is_const){ efree(function_name_strval); }
			EX(opline)++;
			ZEND_VM_CONTINUE();

		}

		if(!is_const){ efree(function_name_strval); }

	}  // end try call proxyMethod

  	return originalConstantMethodHandler(execute_data);

}


/*!
 *	constants handler
 */

static int constantHandler(ZEND_OPCODE_HANDLER_ARGS) {

	zend_op *opline = EX__(opline);
	zend_class_entry *ce = NULL;
	zval **value;

	if (IS_CONST == IS_UNUSED) {
		if (!zend_get_constant(opline->op2.u.constant.value.str.val, opline->op2.u.constant.value.str.len, &EX_T(opline->result.u.var).tmp_var TSRMLS_CC)) {
			zend_error(E_NOTICE, "Use of undefined constant %s - assumed '%s'",
						opline->op2.u.constant.value.str.val,
						opline->op2.u.constant.value.str.val);
			EX_T(opline->result.u.var).tmp_var = opline->op2.u.constant;
			zval_copy_ctor(&EX_T(opline->result.u.var).tmp_var);
		}
		execute_data->opline++;
	}

	ce = EX_T(opline->op1.u.var).class_entry;

	if (zend_hash_find(&ce->constants_table, opline->op2.u.constant.value.str.val, opline->op2.u.constant.value.str.len+1, (void **) &value) == SUCCESS) {
		zval_update_constant(value, (void *) 1 TSRMLS_CC);
		EX_T(opline->result.u.var).tmp_var = **value;
		zval_copy_ctor(&EX_T(opline->result.u.var).tmp_var);
	} else {
		// enums are methods here
		Smoke::Index method = PQ::smoke()->findMethod(ce->name, opline->op2.u.constant.value.str.val);
		if(method <= 0) // smoke could not find one
		    php_error(E_ERROR, "undefined class constant '%s'", opline->op2.u.constant.value.str.val);

		method = PQ::smoke()->methodMaps[method].method;

		// get the Qt value
		Smoke::Stack args = (Smoke::Stack) safe_emalloc(1, sizeof(Smoke::Stack), 0);
		void* dummy; // dummy here
		smokephp_callMethod(dummy, method, args);

		// write the zend return value
		zval* return_value;
		MAKE_STD_ZVAL(return_value);
		ZVAL_LONG(return_value, args[0].s_enum);
		EX_T(opline->result.u.var).tmp_var = *return_value;
		zval_copy_ctor(&EX_T(opline->result.u.var).tmp_var);

		efree(args);

	}

	execute_data->opline++;
	return 0;

}

/**
 *	proxy handler
 */

union _zend_function* proxyHandler(zval **obj_ptr, char* methodName, int methodName_len TSRMLS_DC)
{
    union _zend_function *fbc;

    // overwritten protected Qt methods wont work until we cheat here
    int method_len = strlen(methodName);
    char* lc_method_name = (char*) do_alloca(method_len+1);
    zend_str_tolower_copy(lc_method_name, methodName, method_len);
    // get the zend object and the function pointer
    zend_object *zobj = zend_objects_get_address(*obj_ptr TSRMLS_CC);
    if (zend_hash_find(&zobj->ce->function_table, lc_method_name, method_len+1, (void **)&fbc) != FAILURE)
    {
		if(fbc->common.fn_flags & ZEND_ACC_PROTECTED)
		{
			if(PQ::smoke()->idMethodName(methodName) > 0)
			{
				fbc->common.fn_flags = ZEND_ACC_PUBLIC;
			}
		}
    }

    // a try for non-Qt objects
    fbc = zend_orig_handler.get_method(obj_ptr, methodName, methodName_len);
    if(!fbc) // maybe a Qt object
    {
        methodNameStack.push(new QByteArray(methodName));
	    // call proxy
	    fbc = zend_orig_handler.get_method(obj_ptr, "proxyMethod", 11);
    }

    return fbc;
}

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
}

ZEND_METHOD(php_qt_generic_class, __toString)
{
	RETURN_STRING("", 1);
}

ZEND_METHOD(php_qt_generic_class, __destruct)
{
// qDebug() << "__destruct" << getThis() << PZVAL_IS_REF(getThis());
	if(phpqt_SmokePHPObjectExists(getThis())) {

 		smokephp_object *o = phpqt_getSmokePHPObjectFromZval(getThis());

// qDebug() << (o->zval_ptr == getThis());
// qDebug() << "__destruct" << (o->zval_ptr == getThis()) << getThis() << o->zval_ptr;
		// its not a reference
// 		if(getThis() == o->zval_ptr)
		if(!PZVAL_IS_REF(getThis()))
		{
			o->allocated = false;
		}
		if(!phpqt_unmapSmokePHPObject(getThis()))
		{
			qFatal("try to unmap unregistered zval");
		}

//check_qobject(getThis());
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

    // get arguments
    int i, argc = ZEND_NUM_ARGS();
    zval ***args = (zval ***) safe_emalloc(argc, sizeof(zval **), 0);
    if(zend_get_parameters_array_ex(argc, args) == FAILURE)
    {
	    efree(args);   WRONG_PARAM_COUNT;
    }

    methodNameStack.push(new QByteArray(ce->name));
    smokephp_prepareMethodName(args, argc, methodNameStack);	// #, $, ?
    Smoke::Index method = smokephp_getMethod(ce->name, methodNameStack.top()->constData(), ZEND_NUM_ARGS(), args);

 	MethodCall c(PQ::smoke(), method, getThis(), args, argc-1, getThis(), return_value_ptr);
    c.next();

	// smokephp_object is created above in c.next()
    smokephp_object* o = phpqt_getSmokePHPObjectFromZval(getThis());
    o->parent_ce_ptr = ce_parent; // = ce if no parent

	// if QObject
	if(smokephp_isQObject(PQ::smoke()->idClass(ce->name))){

		// fetch superdata
		Smoke::Index nameId = o->smoke->idMethodName("metaObject");
		Smoke::Index meth = o->smoke->findMethod(o->classId, nameId);
		Smoke::Method &methodId = o->smoke->methods[o->smoke->methodMaps[meth].method];
		Smoke::ClassFn fn = o->smoke->classes[methodId.classId].classFn;
		Smoke::StackItem i[1];
		(*fn)(methodId.method, o->ptr, i);
		QMetaObject *superdata = (QMetaObject *) i[0].s_voidp;

 		QString* phpqt_meta_stringdata = new QString("");
    		uint* phpqt_meta_data = (uint*) emalloc(sizeof(uint)*20*5+10);

		//	create the metaObject
		if(phpqt_getMocData(
				getThis(),
				o->parent_ce_ptr->name,
				superdata,
				o->meta,
				phpqt_meta_stringdata,
				phpqt_meta_data
		)){
		  	const char* phpqt_meta_stringdata_ = estrndup(phpqt_meta_stringdata->toAscii(), phpqt_meta_stringdata->size());
  			QMetaObject ob = {
				{superdata, phpqt_meta_stringdata_,
					phpqt_meta_data, 0}
 			};
 			o->meta = (QMetaObject*) emalloc(sizeof(ob));
 			memcpy(o->meta, &ob, sizeof(ob));

		} else {
			o->meta = superdata;
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
    	activeScope = getThis();

		// if a parent:: call occurs this_ptr has the wrong ce, so we need to
		// correct it here
		if(parentCall)
		{
			ce = activeCe;
			parentCall = false;
        } else {
        	ce = Z_OBJCE_P(getThis());
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
		smokephp_object* o = phpqt_getSmokePHPObjectFromZval(getThis());
		if(o->meta != NULL){
		    QMetaObject* mo = (QMetaObject*) o->meta;
		    QByteArray signalname(methodNameStack.top()->constData());
		    signalname.replace("$","");
		    signalname.replace("#","");
		    signalname.replace("?","");
		    MocArgument *mocStack = new MocArgument[argc+1]; // first entry is return value
		    signalname.append(smokephp_getSignature(argc, args, mocStack)->constData());
		    // seems to be a signal
		    int index = mo->indexOfSignal(signalname);
		    if(index >= 0) {
			QObject *qobj = (QObject*)o->smoke->cast(
			    o->ptr,
			    o->classId,
			    o->smoke->idClass("QObject")
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

	// do we have a parent::blablub() call?
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
	le_php_qt_hashtype = zend_register_list_destructors_ex(phpqt_destroyHashtable, NULL, "PHP-Qt object list", module_number);
	zend_hash_init_ex(&php_qt_objptr_hash, PHPQT_CLASS_COUNT, NULL, NULL, 1, 0);

	// overwrite method handler
	php_qt_handler = *zend_get_std_object_handlers();
	zend_orig_handler = php_qt_handler;
	php_qt_handler.get_method = proxyHandler;

	// overwrite :: operator, see zend_vm_execute.h
	memcpy(phpqt_opcode_handlers, zend_opcode_handlers, sizeof(phpqt_opcode_handlers));
	phpqt_original_opcode_handlers = zend_opcode_handlers;
	zend_opcode_handlers = phpqt_opcode_handlers;
	// ZEND_FETCH_CONSTANT = 99 => 2475
	phpqt_opcode_handlers[(ZEND_FETCH_CONSTANT*25) + 0] = constantHandler;
	// replace and store ZEND_INIT_STATIC_METHOD_CALL_SPEC_CONST_HANDLER
	originalConstantMethodHandler = phpqt_opcode_handlers[2825];
	phpqt_opcode_handlers[2825] = constantMethodHandler;
	phpqt_opcode_handlers[2830] = constantMethodHandler;
	phpqt_opcode_handlers[2835] = constantMethodHandler;
	phpqt_opcode_handlers[2840] = constantMethodHandler;
	phpqt_opcode_handlers[2845] = constantMethodHandler;

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

	// cache some stuff
	Smoke::Index qobject = PQ::smoke()->idClass("QObject");
	_register_QString();

	// do inheritance, all classes must be defined before
	for(Smoke::Index i = 1; i <= PQ::smoke()->numClasses; i++){
	    zend_class_entry* ce = tmpCeTable[PQ::smoke()->classes[i].className];
	    for(Smoke::Index *p = PQ::smoke()->inheritanceList + PQ::smoke()->classes[i].parents; *p; p++) {
		zend_class_entry *parent_ce = tmpCeTable[PQ::smoke()->classes[*p].className];
    		zend_do_inheritance(ce, parent_ce TSRMLS_CC);
	    }
	}

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

/*!
 *	PHP-Qt internal functions
 */

int
phpqt_metacall(smokephp_object* so, Smoke::StackItem* args, QMetaObject::Call _c, int _id, void **_a)
{
	QMetaObject* d = so->meta;
//	int offset = d->methodOffset();
	int offset = d->methodCount();

#if MOC_DEBUG
	cout << "qt_metacall " << so->ce_ptr->name << endl;
#endif

	// call the C++ one
	if(_id < offset){
		// find parent
		Smoke::Index parent = so->smoke->inheritanceList[so->smoke->classes[so->classId].parents];

		// methodId
		Smoke::Index nameId = so->smoke->idMethodName("qt_metacall$$?");
		Smoke::Index method = so->smoke->findMethod(so->classId, nameId);

		if(method > 0){
			Smoke::Method &m = so->smoke->methods[so->smoke->methodMaps[method].method];
			Smoke::ClassFn fn = so->smoke->classes[m.classId].classFn;
			Smoke::StackItem i[4];
			i[1].s_enum = _c;
			i[2].s_int = _id;
			i[3].s_voidp = (void*) args[3].s_voidp;
			(*fn)(m.method, so->ptr, i);

#if MOC_DEBUG
			cout << "\tcall Qt method " << so->ce_ptr->name << "::" << PQ::smoke()->methodNames[method] << endl;
#endif

			if((int)i[0].s_int < 0)
				return i[0].s_int;

		} else {
			// should never happen
			php_error(E_ERROR, "Cannot find %s::qt_metacall() method\n", d->className());
		}

	}

    if (_c != QMetaObject::InvokeMetaMethod) {
		return _id;
	}

	// try the PHP one
	// eg _q_buttonPressed(), breaking at the first bracket
	char* method_name = estrdup((d->method(_id)).signature());

    for(int i = 0; i < strlen(method_name); i++){
#define LEFT_PARENTHESIS 40
        if(method_name[i] == LEFT_PARENTHESIS){
            method_name[i] = 0;
            break;
        }
    }

    // is a Slot
    if(d->method(_id).methodType() == QMetaMethod::Slot){

        int j = 0;
        zval*** args = (zval***) safe_emalloc(2, sizeof(zval*), 0);
        QList<QByteArray> qargs = d->method(_id).parameterTypes();
        for(int i = 0; i < qargs.count(); i++){
            zval *arg;
            MAKE_STD_ZVAL(arg);

            // invoke to zend types
            if(!strncmp("int",(const char*) qargs[i],3)){

                ZVAL_LONG(arg, *reinterpret_cast< int*>(_a[i+1]));
            } else if(!strncmp("char*",(const char*) qargs[i],5)){
                ZVAL_STRING(arg, *reinterpret_cast< char**>(_a[i+1]), 1);
            } else if(!strncmp("bool",(const char*) qargs[i],4)){
                ZVAL_BOOL(arg, *reinterpret_cast< bool*>(_a[i+1]));
            } else if(!strncmp("double",(const char*) qargs[i],4)){
                ZVAL_DOUBLE(arg, *reinterpret_cast< double*>(_a[i+1]));
            } else {
                    // must be an object
                    void* ptr = *reinterpret_cast< QObject**>(_a[1]);

                    phpqt_createObject(arg, ptr, qobject_ce);
            }

            args[j++] = &arg;

        }

#if MOC_DEBUG
    cout << "\tcall PHP method " << so->ce_ptr->name << "::" << method_name << endl;
#endif

         phpqt_callPHPMethod(so->zval_ptr, method_name, j, *args);

    // is a signal
    } else {
        void *_b[] = { 0, _a[1] };
        QMetaObject::activate((QObject*) so->ptr, d, 0, _b);
    }

	efree(method_name);
    return _id;

}

static void
phpqt_destroyHashtable(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
#ifdef DEBUG
	php_error(E_ERROR,"Hashtable destroyed. Shutdown PHP-Qt now.");
#endif
}

bool
phpqt_methodExists(zend_class_entry* ce_ptr, char* methodname)
{

	if(ce_ptr == NULL){
	  php_error(E_ERROR,"methodExists fatal error: no class entry");
	}

	char* lcname = zend_str_tolower_dup(methodname, strlen(methodname));

	if(zend_hash_exists(&ce_ptr->function_table, lcname, strlen(methodname)+1)){
		return true;
	}

	efree(lcname);
	return false;

}


zval*
phpqt_callPHPMethod(zval* this_ptr, char* methodName, zend_uint param_count, zval** args)
{

	if(this_ptr == NULL){
	  php_error(E_ERROR,"callmethod fatal error: object does not exists");
	}

    zval *function_name;
    MAKE_STD_ZVAL(function_name);
    ZVAL_STRING(function_name,methodName,1);

    zval* retval;
    MAKE_STD_ZVAL(retval);

    if(call_user_function(EG(function_table),&this_ptr,function_name,retval,param_count,args) == FAILURE){
    	smokephp_object* o = phpqt_getSmokePHPObjectFromZval(this_ptr);
    	php_error(E_ERROR, "PHP-Qt could not call method %s::%s", o->ce_ptr->name, methodName);
    }

    return retval;
}

/*!
 *	creates metaObject data
 *  example: "QWidget\0\0value\0test(int)\0"
 *	@param	zval*				this_ptr	pointer of the zval
 *	@param	char*				classname	name of the class
 *	@param	const QMetaObject*	superdata	superdata
 *	@return	QMetaObject*
 */

bool
phpqt_getMocData(zval* this_ptr, char* classname, const QMetaObject* superdata, QMetaObject* meta, QString* meta_stringdata, uint* signature){

    /// readout the slots table
    zval **slotdata;

    zval *zslot;
    zslot = zend_read_property(Z_OBJCE_P(this_ptr),this_ptr,"slots",5,0);

    zval *zsignal;
    zsignal = zend_read_property(Z_OBJCE_P(this_ptr),this_ptr,"signals",7,0);

    if((zslot)->type==IS_ARRAY && (zsignal)->type==IS_ARRAY ) {


        HashTable* slots_hash = HASH_OF(zslot);
        HashTable* signals_hash = HASH_OF(zsignal);

        char* assocKey;
        ulong numKey;

        int signaturecount;
        signaturecount = 2 + strlen(classname);

#if MOC_DEBUG
	QString *qr = new QString();
	cout << "+== begin metaobject dump ==+\n";
	cout << "\t" << classname << "\n\t1 0 0 0 " << zend_hash_num_elements(slots_hash)+zend_hash_num_elements(signals_hash) << " 10 0 0 0 0" << endl << endl;
#endif

		/// write class signature
		signature[0] = 1;
		signature[1] = 0;
		signature[2] = 0;
		signature[3] = 0;
		signature[4] = zend_hash_num_elements(slots_hash)+zend_hash_num_elements(signals_hash);
		signature[5] = 10;
		signature[6] = 0;
		signature[7] = 0;
		signature[8] = 0;
		signature[9] = 0;

		/// write classname
		meta_stringdata->append(classname);
 		meta_stringdata->append(QChar::Null);
 		meta_stringdata->append(QChar::Null);

		int i;
		i = 10;

		zend_hash_internal_pointer_reset(signals_hash);

		while(zend_hash_has_more_elements(signals_hash) == SUCCESS){

			/// read slot from hashtable
			zend_hash_get_current_key(signals_hash,&assocKey,&numKey,0);
			zend_hash_get_current_data(signals_hash,(void**)&slotdata);

#if MOC_DEBUG
			qr->append(Z_STRVAL_PP(slotdata));
			qr->append(" ");
			cout << "\t" << signaturecount << "8 8 8 0x05 ::s" << endl;
#endif

			meta_stringdata->append(Z_STRVAL_PP(slotdata));
			meta_stringdata->append(QChar::Null);

			zend_hash_move_forward(signals_hash);

			/// write slot signature
			signature[i++] = signaturecount;
			signature[i++] = 8;
			signature[i++] = 8;
			signature[i++] = 8;
			signature[i++] = 0x05;

			signaturecount += strlen(Z_STRVAL_PP(slotdata)) + 1;

		}

    	zend_hash_internal_pointer_reset(slots_hash);

		while(zend_hash_has_more_elements(slots_hash) == SUCCESS){

			/// read slot from hashtable
			zend_hash_get_current_key(slots_hash,&assocKey,&numKey,0);
			zend_hash_get_current_data(slots_hash,(void**)&slotdata);

#if MOC_DEBUG
			qr->append(Z_STRVAL_PP(slotdata));
			qr->append(" ");
			cout << "\t" << signaturecount << "8 8 8 0x0a ::s" << endl;
#endif

			meta_stringdata->append(Z_STRVAL_PP(slotdata));
			meta_stringdata->append(QChar::Null);

			zend_hash_move_forward(slots_hash);

			/// write slot signature
			signature[i++] = signaturecount;
			signature[i++] = 8;
			signature[i++] = 8;
			signature[i++] = 8;
			signature[i++] = 0x0a;

			signaturecount += strlen(Z_STRVAL_PP(slotdata)) + 1;

		}
#if MOC_DEBUG
		cout << qr->toAscii().constData() << endl;
		cout << "+== end metaobject dump ==+" << endl;
#endif
		return true;
	} else {
		return false;
  	}
}

char*
phpqt_checkForOperator(const char* fname){
	return (char*) fname;
}

bool
phpqt_SmokePHPObjectExists(zval* this_ptr)
{
	return obj_x_smokephp.contains(this_ptr->value.obj.handle);
}

smokephp_object*
phpqt_getSmokePHPObjectFromZval(zval* this_ptr)
{

	if(this_ptr == NULL){
	  php_error(E_ERROR,"fatal: object does not exists and could not be fetched, %s",Z_OBJCE_P(this_ptr)->name);
	}

	// value.obj.handle
 	return (smokephp_object*) obj_x_smokephp.value(this_ptr->value.obj.handle);

}

void*
phpqt_getQtObjectFromZval(zval* this_ptr){
	smokephp_object* o = phpqt_getSmokePHPObjectFromZval(this_ptr);
	return o->ptr;
}

smokephp_object*
phpqt_getSmokePHPObjectFromQt(void* QtPtr){
	return (smokephp_object*) SmokeQtObjects.value(QtPtr);
}

void
phpqt_setSmokePHPObject(smokephp_object* o){
	SmokeQtObjects.insert(o->ptr, o);
}

bool
phpqt_SmokePHPObjectExists(void* ptr){
	return (SmokeQtObjects.find(ptr) != SmokeQtObjects.end());
}

bool
phpqt_unmapSmokePHPObject(zval* o)
{
	return (bool) obj_x_smokephp.remove(o->value.obj.handle);
}

/**
 *	marshall_basetypes.h marshall_to_php<SmokeClassWrapper>(Marshall *m)
 */

smokephp_object*
phpqt_createObject(zval* zval_ptr, void* ptr, zend_class_entry* ce, Smoke::Index classId){

	Q_ASSERT (zval_ptr);
	Q_ASSERT (ptr);

 	if(!ce) {
 		qFatal("no class entry!");
 	}

	if(classId == QSTRING_CLASSID)
	{
		ce = qstring_ce;
	} else if (classId == 0)
	{
		qDebug("\nno class id");
		check_qobject(zval_ptr);
		qFatal("php object creation failed");
	}

	Z_TYPE_P(zval_ptr) = IS_OBJECT;
	object_init_ex(zval_ptr, ce);

	smokephp_object* o = (smokephp_object*) emalloc(sizeof(smokephp_object));
	o->allocated = true;
	o->ptr = ptr;
	o->zval_ptr = zval_ptr;
	o->ce_ptr = ce;
	o->parent_ce_ptr = ce;
 	o->classId = classId;
	o->smoke = PQ::smoke();

	Z_OBJ_HT_P(zval_ptr) = &php_qt_handler;
	phpqt_setSmokePHPObject(o);
	zval_add_ref(&zval_ptr);

	obj_x_smokephp.insert(zval_ptr->value.obj.handle, o);

	return o;

}

smokephp_object*
phpqt_createOriginal(zval* zval_ptr, void* ptr)
{
	smokephp_object* o = phpqt_getSmokePHPObjectFromQt(ptr);
/* 		ZVAL_ZVAL(zval_ptr, o->zval_ptr, 1, 0);
// 		zval_ptr->is_ref = 1;
		Z_OBJ_HT_P(zval_ptr) = &php_qt_handler;
		zval_x_smokephp.insert(zval_ptr, o);*/
	Z_OBJ_HT_P(zval_ptr) = &php_qt_handler;
	zval_ptr = o->zval_ptr;
	zval_add_ref(&zval_ptr);
	return o;
}
