/*!
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2006 
 * Thomas Moenicke <thomas.moenicke at kdemail.net>
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

// TODO		references, arrays
// TODO		emit()

//#define DEBUG=0

#include <zend_interfaces.h>
#include "php_qt.h"

#include "ext/standard/php_string.h"

extern Smoke *qt_Smoke;
extern void init_qt_Smoke();

/* If you declare any globals in php_php_qt.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(php_qt)
*/

/* True global resources - no need for thread safety here */
static int le_php_qt;

// object list
int le_php_qt_hashtype;
HashTable php_qt_objptr_hash;

static zend_object_handlers php_qt_handler;
static zend_object_handlers zend_orig_handler;

/*! php_qt_functions[]
 *
 * Every user visible function must have an entry in php_qt_functions[].
 */
function_entry php_qt_functions[] = {
	PHP_FE(confirm_php_qt_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(SIGNAL,	NULL)
	PHP_FE(SLOT,	NULL)	
	PHP_FE(qobject_cast,	NULL)
	PHP_FE(tr,	NULL)
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
	"0.0.4", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_PHP_QT
ZEND_GET_MODULE(php_qt)
#endif

static QHash<void*, zval*> zval_x_qt;
QHash<void*, long int>SmokeToPtr;
QStack<QString*> methodNameStack;

// cached
Smoke::Index qbool;
Smoke::Index qstring;
Smoke::Index qobject;
zend_class_entry* qobject_ce;
zend_class_entry* qstring_ce;

/**
 *	proxy handler
 */

union _zend_function *proxyHandler(zval **obj_ptr, char* methodname, int methodname_len TSRMLS_DC){

    union _zend_function *fbc;
    // a try for non-Qt objects
    fbc = zend_orig_handler.get_method(obj_ptr, methodname, methodname_len);

    if(!fbc) {    // maybe a Qt object
        methodNameStack.push(new QString(methodname));
	    // call proxy
	    fbc = zend_orig_handler.get_method(obj_ptr, "proxyMethod", 11);
    }

    return fbc;
}

/**
 *	generic object
 */

ZEND_METHOD(php_qt_generic_class, __construct);
ZEND_METHOD(php_qt_generic_class, __destruct);
ZEND_METHOD(php_qt_generic_class, __toString);
ZEND_METHOD(php_qt_generic_class, proxyMethod);
ZEND_METHOD(php_qt_generic_class, staticProxyMethod);

static zend_function_entry php_qt_generic_methods[] = {
    ZEND_ME(php_qt_generic_class,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(php_qt_generic_class,__destruct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(php_qt_generic_class,__toString,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(php_qt_generic_class,proxyMethod,NULL,ZEND_ACC_PUBLIC)
    {NULL,NULL,NULL}
};

static zend_function_entry*** php_qt_static_methods;

ZEND_METHOD(php_qt_generic_class, __toString)
{
	if(!strcmp(Z_OBJCE_P(getThis())->name,"QString")){
		smokephp_object* o = phpqt_fetch(getThis());
		RETVAL_STRING((char*)((QString*) o->ptr)->toAscii().constData(), 1);
//		RETVAL_STRING((char*)((QString*) o->ptr)->toLocal8Bit().constData(), 1);
	} else {
		RETVAL_STRING("", 1);
	}
	return;
}

ZEND_METHOD(php_qt_generic_class, __destruct)
{
    smokephp_object *o = phpqt_fetch(getThis());
    zval_x_qt.remove(o->ptr);
    SmokeToPtr.remove(o->ptr);
	RETVAL_NULL();
}

ZEND_METHOD(php_qt_generic_class, __construct)
{

    // find parents
    zend_class_entry *ce = Z_OBJCE_P(getThis());
    while (qt_Smoke->idClass(ce->name) <= 0) {
	    ce = ce->parent;
	}

    int i, argc = ZEND_NUM_ARGS();
    zval ***args = (zval ***) safe_emalloc(argc, sizeof(zval **), 0);    
    if(zend_get_parameters_array_ex(argc, args) == FAILURE){
	    efree(args);
	    WRONG_PARAM_COUNT;
    }

    methodNameStack.push(new QString(ce->name));
    Smoke::StackItem* qargs = (Smoke::StackItem*) safe_emalloc(argc+10, sizeof(Smoke::StackItem), 0);
    smokephp_convertArgsZendToCxx(args, ZEND_NUM_ARGS(), qargs, methodNameStack);
    Smoke::Index method = smokephp_getMethod(qt_Smoke,ce->name, (methodNameStack.top())->toAscii(), &qargs, ZEND_NUM_ARGS(), args);
	
	// connect uses char*
	if(smokephp_isConnect(method)){
    	smokephp_prepareConnect(args, ZEND_NUM_ARGS(), qargs, method);
	}

	smokephp_object *o = (smokephp_object*) emalloc(sizeof(smokephp_object));

	// FIXME
	if(!strcmp(ce->name, "QApplication")){
		char** c = new char*[1];
		c[0] = "";
		int argc_dummy = 1;
		qargs[0].s_class = new QApplication(argc_dummy, c);
	// handle QString
	} else if (!strcmp(ce->name, "QString")){
		if(argc > 0){
        	qargs[0].s_class = new QString(Z_STRVAL_PP(args[0]));
    	} else {
    		qargs[0].s_class = new QString("");
    	}
	} else {
	    // call Qt method via Smoke
    	smokephp_callMethod(qt_Smoke, 0, method, qargs);
 	}

	o->ptr = qargs[0].s_class;
	o->zval_ptr = getThis();
	o->ce_ptr = ce;
	o->classId = qt_Smoke->idClass(ce->name);
	o->smoke = qt_Smoke;

	// if QObject
	if(smokephp_isQObject(qt_Smoke, qt_Smoke->idClass(ce->name))){

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
				Z_OBJCE_P(getThis())->name,
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

	// store relations
	SmokeToPtr.insert(o->ptr, (long int) o);
    PHP_QT_REGISTER(o);
	zval_x_qt.insert(qargs[0].s_class, getThis());

    // return value
    smokephp_convertReturn(&qargs[0], qt_Smoke->types[qt_Smoke->methods[method].ret], qt_Smoke->methods[method].ret, return_value);

    // cleanup
    efree(args);
    efree(qargs);
    methodNameStack.pop();

    return;

}

ZEND_METHOD(php_qt_generic_class, proxyMethod)
{

    zend_class_entry *ce;
    // nonstaticphp_qt_generic_class_proxyMethod
    if(getThis()){
        ce = Z_OBJCE_P(getThis());
    // static
    } else {
        char* space = "::";
        char* class_name = get_active_class_name(&space);
        char* method_name = get_active_function_name();
        ce = zend_fetch_class(class_name,strlen(class_name), ZEND_FETCH_CLASS_AUTO TSRMLS_DC);
        methodNameStack.push(new QString(method_name));
    }

    // find parents
    while (qt_Smoke->idClass(ce->name) <= 0) {
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

    Smoke::StackItem* qargs = (Smoke::StackItem*) safe_emalloc(argc+10, sizeof(Smoke::StackItem), 0);
    smokephp_convertArgsZendToCxx(args, argc, qargs, methodNameStack);
    Smoke::Index method = smokephp_getMethod(qt_Smoke,ce->name, (methodNameStack.top())->toAscii(), &qargs, argc, args);
    smokephp_prepareConnect(args, argc, qargs, method);

    // self
    if(getThis()){
    	smokephp_object *o = phpqt_fetch(getThis());
        qargs[0].s_class = o->ptr;
    }

    // call
    smokephp_callMethod(qt_Smoke, qargs[0].s_class, method, qargs);

    // return now
    smokephp_convertReturn(&qargs[0], qt_Smoke->types[qt_Smoke->methods[method].ret], qt_Smoke->methods[method].ret, return_value);

    // cleanup
    efree(args);
    efree(qargs);
    methodNameStack.pop();

    return;

}

/*! 
 *	PHP_MINIT_FUNCTION
 */

PHP_MINIT_FUNCTION(php_qt)
{

	// object list
	le_php_qt_hashtype = zend_register_list_destructors_ex(phpqt_destroy_hashtable, NULL, "PHP-Qt object list", module_number);
	// FIXME: 50 is fix
	zend_hash_init_ex(&php_qt_objptr_hash, 50, NULL, NULL, 1, 0);

	// overwrite method handler
	php_qt_handler = *zend_get_std_object_handlers();
	zend_orig_handler = php_qt_handler;
	php_qt_handler.get_method = proxyHandler;

	smokephp_init();

// TODO		QObject Nummer suchen, nachher vergleichen
	smokephp_findConnect();

	Smoke::Index qobject = smokephp_getClassId("QObject");
	Smoke::Index qstring = smokephp_getClassId("QString");

    php_qt_static_methods = (zend_function_entry***) safe_emalloc((qt_Smoke->numClasses), sizeof(zend_function_entry **), 0);

    int method_count;
	// loop for all classes, register them
	for(Smoke::Index i = 1; i <= qt_Smoke->numClasses; i++){

        // statical methods, there is no method handler which can be overwritten
        // hope this will be better in future / see zend_std_get_static_method()
        method_count = 0;
        for(int j=0;j<qt_Smoke->numMethods;j++){
            if(qt_Smoke->methods[j].classId == i){
                if(!(qt_Smoke->methods[j].flags & Smoke::mf_enum)){
                    if((qt_Smoke->methods[j].flags & Smoke::mf_static) && (qt_Smoke->methods[j].classId == i)){
                        // avoids overloaded methods
                        if(strcmp(qt_Smoke->methodNames[qt_Smoke->methods[j-1].name],qt_Smoke->methodNames[qt_Smoke->methods[j].name])){
                            method_count++;
                        }
                    }
                }
            }
        } // for

        zend_function_entry* t = (zend_function_entry*) safe_emalloc((method_count+7), sizeof(zend_function_entry), 0);
        zend_function_entry* p = t;

        PHP_QT_ME(php_qt_generic_class,__construct,NULL,ZEND_ACC_PUBLIC);
        PHP_QT_ME(php_qt_generic_class,__destruct,NULL,ZEND_ACC_PUBLIC);
        PHP_QT_ME(php_qt_generic_class,__toString,NULL,ZEND_ACC_PUBLIC);
        PHP_QT_ME(php_qt_generic_class,proxyMethod,NULL,ZEND_ACC_PUBLIC);

		QHash<const char*, bool> tmpMethodList;	// avoids doubled method names

        for(int j=0;j<qt_Smoke->numMethods;j++){
            if(qt_Smoke->methods[j].classId == i){
                if(!(qt_Smoke->methods[j].flags & Smoke::mf_enum)){
                    if(qt_Smoke->methods[j].flags & Smoke::mf_static){
                        // avoids overloaded methods, fast
                        if(strcmp(qt_Smoke->methodNames[qt_Smoke->methods[j-1].name],qt_Smoke->methodNames[qt_Smoke->methods[j].name])){
                        	if(!tmpMethodList.contains(qt_Smoke->methodNames[qt_Smoke->methods[j].name])){ // method already defined in this class?
								tmpMethodList[qt_Smoke->methodNames[qt_Smoke->methods[j].name]] = true;
								t->fname = (char*) emalloc(strlen(qt_Smoke->methodNames[qt_Smoke->methods[j].name])+1);
								t->fname = (char*) qt_Smoke->methodNames[qt_Smoke->methods[j].name];
								t->handler = ZEND_FN(php_qt_generic_class_proxyMethod);
								t->arg_info = NULL;
								t->flags = ZEND_ACC_PUBLIC|ZEND_ACC_STATIC;
								t++;
                        	}
                        }
                    }
                }
			}
        }

        // stops the zend-loop 'while(ptr->fname) {...}' in zend_register_functions
        t->fname = NULL;
        t->handler = NULL;
        t->arg_info = NULL;
        t->flags = NULL;
        t++;

		// register class
	    zend_class_entry ce;
	    INIT_CLASS_ENTRY(ce, qt_Smoke->classes[i].className, p);
	    ce.name_length = strlen(qt_Smoke->classes[i].className);
	    zend_class_entry* ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);
		if(qobject == i){
			qobject_ce = ce_ptr;
		}
		else if(qstring == i){
			qstring_ce = ce_ptr;
		}


        // register enums
		if(!strcmp(qt_Smoke->classes[i].className, "Qt")){
			zend_declare_class_constant_long(ce_ptr, "Horizontal", strlen("Horizontal"), Qt::Horizontal);
			zend_declare_class_constant_long(ce_ptr, "Vertical", strlen("Vertical"), Qt::Vertical);
			zend_declare_class_constant_long(ce_ptr, "AlignRight", strlen("AlignRight"), Qt::AlignRight);
		}
	}

    for(Smoke::Index i = 1; i <= qt_Smoke->numClasses; i++){
		zend_class_entry *ce = zend_fetch_class((char*) qt_Smoke->classes[i].className, strlen(qt_Smoke->classes[i].className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

        // inheritance
	    for(Smoke::Index *p = qt_Smoke->inheritanceList + qt_Smoke->classes[i].parents; *p; p++) {
		    zend_class_entry *parent_ce = zend_fetch_class((char*) qt_Smoke->classes[*p].className, strlen(qt_Smoke->classes[*p].className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
            zend_do_inheritance(ce, parent_ce TSRMLS_CC);
        }
    }

	return SUCCESS;
}


/* PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(php_qt)
{
    methodNameStack.~QStack();
	SmokeToPtr.~QHash();
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

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}

/*!
 *	PHP-Qt internal functions
 */

int	
phpqt_metacall(smokephp_object* so, Smoke::StackItem* args, QMetaObject::Call _c, int _id, void **_a){

	QMetaObject* d = so->meta;
//	int offset = d->methodOffset();
	int offset = d->methodCount();

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
        if(method_name[i] == 40){
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
                    zend_class_entry *ce;
                    object_init_ex(arg, qobject_ce);
                    zend_rsrc_list_entry le;
                    le.ptr = *reinterpret_cast< QObject**>(_a[1]);
                    phpqt_register(arg, le);

            }

            args[j++] = &arg;

        }

        phpqt_callmethod(so->zval_ptr, method_name, j, args);

    // is a signal
    } else {
        void *_b[] = { 0, _a[1] };
        QMetaObject::activate((QObject*) so->ptr, d, 0, _b);
    }

	efree(method_name);
    return _id;
	
}

void 
phpqt_register(zval* this_ptr, zend_rsrc_list_entry le){

    assert(&php_qt_objptr_hash);
    assert(le_php_qt_hashtype);

	Z_OBJ_HT_P(this_ptr) = &php_qt_handler;
	zval *listhandle;
	MAKE_STD_ZVAL(listhandle);
	Z_TYPE_P(listhandle) = IS_LONG;
	Z_LVAL_P(listhandle) = zend_list_insert(le.ptr, le_php_qt_hashtype);

	if(zend_hash_index_update(Z_OBJPROP_P(this_ptr), 0, &listhandle, sizeof(zval*), NULL) == FAILURE){
		php_error(E_ERROR,"could not bind resource to object.");
	}
	zval_add_ref(&this_ptr);

	if(zend_hash_index_update(&php_qt_objptr_hash, (long) le.ptr, (void*) &this_ptr, sizeof(zval *), NULL) == FAILURE){
		php_error(E_ERROR,"could not register Qt object in resource table.");
	}

}

smokephp_object* 
phpqt_fetch(zval* this_ptr){

	if(this_ptr == NULL){
	  php_error(E_ERROR,"fatal: object does not exists and could not be fetched, %s",Z_OBJCE_P(this_ptr)->name);
	}

	smokephp_object *ptr;
	zval **listhandle;
	int type;
	TSRMLS_FETCH();

	if(zend_hash_index_find(Z_OBJPROP_P(this_ptr), 0, (void**) &listhandle) == FAILURE){
	  php_error(E_ERROR,"underlying Qt-Object missing. Make sure that the constructor of the parent is called, instance of type '%s' fails",Z_OBJCE_P(this_ptr)->name,Z_OBJCE_P(this_ptr)->name);
	}
	ptr = (smokephp_object*) zend_list_find(Z_LVAL_PP(listhandle), &type);

	if(!ptr){
		php_error(E_ERROR,"reference to Qt object missing, %s",Z_OBJCE_P(this_ptr)->name);
	} 
	if(type != le_php_qt_hashtype){
		php_error(E_ERROR,"phpqt_fetch(): wrong type, %s",Z_OBJCE_P(this_ptr)->name);
	}

	return ptr;

}

static void 
phpqt_destroy_hashtable(zend_rsrc_list_entry *rsrc TSRMLS_DC)
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

	return false;

}

zval* 
phpqt_callmethod(zval* this_ptr, char* methodname, zend_uint param_count, zval** args[])
{

	if(this_ptr == NULL){
	  php_error(E_ERROR,"callmethod fatal error: object does not exists");
	}

    zval *function_name;
    MAKE_STD_ZVAL(function_name);
    ZVAL_STRING(function_name,methodname,1);

    zval* retval;
    MAKE_STD_ZVAL(retval);

    if(call_user_function_ex(CG(function_table),&this_ptr,function_name,&retval,param_count,args,0,NULL) == FAILURE){
    	php_error(E_ERROR, "PHP-Qt could not call method %s", methodname);
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
		return true;
	} else {
		return false;
  	}
}

/*!
 *	fetchs the zval-ptr from hashtable
 *	@param	QObject*
 *	@return	zval*
 */

zval* 
phpqt_fetch_zend_ptr(const QObject *o){
	return zval_x_qt[(void*) o];
}

bool
phpqt_zval2qtIsEnd(void *o){
	return (zval_x_qt.find(o) != zval_x_qt.end());
}

/**
 *	maps method names to the related names of operator-extension
 *	@param	const char*		fname		function name
 *  TODO: implement! ask in proxyHandler for it
 */

char*
phpqt_checkForOperator(const char* fname){
	return (char*) fname;
}

smokephp_object*
phpqt_getSmokePHPObject(void* ptr){
	return (smokephp_object*) SmokeToPtr[ptr];
}


