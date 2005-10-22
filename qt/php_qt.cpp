/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2004 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id: header,v 1.15 2004/01/08 16:46:52 sniper Exp $ */

#include "php_qt.h"
#include <QObject>
#include <QApplication>

//static int objects_handle;

/* If you declare any globals in php_php_qt.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(php_qt)
*/

/* True global resources - no need for thread safety here */
static int le_php_qt;

static zend_class_entry *QWidget_ce_ptr;
static zend_class_entry *QString_ce_ptr;
static zend_class_entry *QObject_ce_ptr;
static zend_class_entry *QLatin1String_ce_ptr;
static zend_class_entry *QPushButton_ce_ptr;
static zend_class_entry *QAbstractButton_ce_ptr;
static zend_class_entry *QApplication_ce_ptr;

/* {{{ php_qt_functions[]
 *
 * Every user visible function must have an entry in php_qt_functions[].
 */
function_entry php_qt_functions[] = {
	PHP_FE(confirm_php_qt_compiled,	NULL)		/* For testing, remove later. */
	{NULL, NULL, NULL}	/* Must be the last line in php_qt_functions[] */
};
/* }}} */

/* {{{ php_qt_module_entry
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
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PHP_QT
ZEND_GET_MODULE(php_qt)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("php_qt.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_php_qt_globals, php_qt_globals)
    STD_PHP_INI_ENTRY("php_qt.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_php_qt_globals, php_qt_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_php_qt_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_php_qt_init_globals(zend_php_qt_globals *php_qt_globals)
{
	php_qt_globals->global_value = 0;
	php_qt_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */

PHP_MINIT_FUNCTION(php_qt)
{
	/* If you have INI entries, uncomment these lines 
	ZEND_INIT_MODULE_GLOBALS(php_qt, php_php_qt_init_globals, NULL);
	REGISTER_INI_ENTRIES();
	*/

    _register_QApplication(TSRMLS_C);
    _register_QString(TSRMLS_C);
    _register_QLatin1String(TSRMLS_C);
    _register_QObject(TSRMLS_C);
    _register_QWidget(TSRMLS_C);
    _register_QAbstractButton(TSRMLS_C);
    _register_QPushButton(TSRMLS_C);

//    objects_handle = zend_register_list_destructors_ex(NULL,NULL,"Qt Wrapper",module_number);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(php_qt)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(php_qt)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(php_qt)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(php_qt)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "php_qt support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_php_qt_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_php_qt_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char string[256];

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

  	len = sprintf(string, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "php_qt", arg);
	RETURN_STRINGL(string, len, 1);

}

/* }}} */
/* {{{ */

void php_qt_register(zval* this_ptr, zend_rsrc_list_entry le){

    if(PHP_QT_REGISTER_OBJECT(le) == FAILURE){
        php_error(E_ERROR,"PHP_QT: %s(): could not register qobject in hashtable.",get_active_function_name(TSRMLS_C));
        return;
    }

}

void* php_qt_fetch(zval* this_ptr){

    zend_rsrc_list_entry* le;  

    if(!zend_hash_exists(HASH_OF(this_ptr),PHP_QT_HASH_QOBJECT,strlen(PHP_QT_HASH_QOBJECT))){
        php_error(E_ERROR,"PHP_QT: %s(): hash not found.",get_active_function_name(TSRMLS_C));
    }

    if(PHP_QT_FETCH_OBJECT(le) == FAILURE){
        php_error(E_ERROR,"PHP_QT: %s(): could not fetch qobject from hashtable.",get_active_function_name(TSRMLS_C));
        return NULL;
    }

    return le->ptr;

}

///



static zend_function_entry QString_methods[] = { 
    ZEND_ME(QString,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QString,append,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QString,arg,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QString,at,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}

};

void _register_QString(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QString",QString_methods);
    QString_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

    zend_declare_property_string(QString_ce_ptr,"QString",strlen("QString"),"",ZEND_ACC_PROTECTED TSRMLS_CC);

}

static zend_function_entry QLatin1String_methods[] = { 
    ZEND_ME(QLatin1String,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QLatin1String,latin1,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}

};

void _register_QLatin1String(TSRMLS_D){

    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLatin1String",QLatin1String_methods);
    QLatin1String_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

    zend_declare_property_string(QLatin1String_ce_ptr,"QLatin1String",strlen("QLatin1String"),"",ZEND_ACC_PROTECTED TSRMLS_CC);

}

static zend_function_entry QObject_methods[] = { 
    ZEND_ME(QObject,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,test,NULL,ZEND_ACC_PUBLIC)    
    ZEND_ME(QObject,blockSignals,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,children,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,connect,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,disconnect,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,dumpObjectInfo,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,dumpObjectTree,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,event,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,eventFilter,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,findChild,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,findChildren,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,inherits,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,installEventFilter,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,isWidgetType,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,killTimer,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,metaObject,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,moveToThread,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,objectName,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,parent,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,property,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,removeEventFilter,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,setObjectName,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,setParent,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,setProperty,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,signalsBlocked,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,startTimer,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,thread,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QObject(TSRMLS_D){

    zend_class_entry ce;
    TSRMLS_FETCH();

    INIT_CLASS_ENTRY(ce,"QObject",QObject_methods);
    QObject_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

    zend_declare_property_null(QObject_ce_ptr,"parent",strlen("parent"),ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_null(QObject_ce_ptr,"objectName",strlen("objectName"),ZEND_ACC_PROTECTED TSRMLS_CC);

}

static zend_function_entry QWidget_methods[] = {
 
    ZEND_ME(QWidget,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,isVisible,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,isHidden,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,show,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,hide,NULL,ZEND_ACC_PUBLIC)
    
    {NULL,NULL,NULL}
};

void _register_QWidget(TSRMLS_D)
{
    zend_class_entry ce;
    
    INIT_CLASS_ENTRY(ce,"QWidget",QWidget_methods);
    
    QWidget_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QObject_ce_ptr,NULL TSRMLS_CC);
    // call zend_do_inheritance directly to inherit from QPaintDevice

}

static zend_function_entry QPushButton_methods[] = {
 
    ZEND_ME(QPushButton,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,autoDefault,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,isDefault,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,isFlat,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,menu,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,setAutoDefault,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,setDefault,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,setFlat,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,setMenu,NULL,ZEND_ACC_PUBLIC)
    
    {NULL,NULL,NULL}

};

void _register_QPushButton(TSRMLS_D)
{
    zend_class_entry ce;
    
    INIT_CLASS_ENTRY(ce,"QPushButton",QPushButton_methods);
    
    QPushButton_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QAbstractButton_ce_ptr,NULL TSRMLS_CC);
    zend_declare_property_null(QPushButton_ce_ptr,"menu",strlen("menu"),ZEND_ACC_PRIVATE TSRMLS_CC);

}

static zend_function_entry QAbstractButton_methods[] = {
 
    ZEND_ME(QAbstractButton,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,autoExclusive,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,autoRepeat,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,isCheckable,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,isChecked,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,isDown,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,setAutoExclusive,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,setAutoRepeat,NULL,ZEND_ACC_PUBLIC)
//    ZEND_ME(QAbstractButton,setCheckable,NULL,ZEND_ACC_PUBLIC)
//    ZEND_ME(QAbstractButton,setDown,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}

};

void _register_QAbstractButton(TSRMLS_D)
{
    zend_class_entry ce;
    
    INIT_CLASS_ENTRY(ce,"QAbstractButton",QAbstractButton_methods);
    
    QAbstractButton_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QWidget_ce_ptr,NULL TSRMLS_CC);
    zend_declare_property_null(QAbstractButton_ce_ptr,"menu",strlen("menu"),ZEND_ACC_PRIVATE TSRMLS_CC);

    zend_declare_property_bool(QAbstractButton_ce_ptr,"autoExclusive",strlen("autoExclusive"),0,ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_bool(QAbstractButton_ce_ptr,"autoRepeat",strlen("autoRepeat"),0,ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_bool(QAbstractButton_ce_ptr,"checkable",strlen("checkable"),0,ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_bool(QAbstractButton_ce_ptr,"checked",strlen("checked"),0,ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_bool(QAbstractButton_ce_ptr,"down",strlen("down"),0,ZEND_ACC_PRIVATE TSRMLS_CC);

    zend_declare_property_null(QAbstractButton_ce_ptr,"icon",strlen("icon"),ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_null(QAbstractButton_ce_ptr,"iconSize",strlen("iconSize"),ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_null(QAbstractButton_ce_ptr,"shortcut",strlen("shortcut"),ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_null(QAbstractButton_ce_ptr,"text",strlen("text"),ZEND_ACC_PRIVATE TSRMLS_CC);

}

static zend_function_entry QApplication_methods[] = {
 
    ZEND_ME(QApplication,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QApplication,exec,NULL,ZEND_ACC_PUBLIC)
    
    {NULL,NULL,NULL}

};

void _register_QApplication(TSRMLS_D)
{
    zend_class_entry ce;
    
    INIT_CLASS_ENTRY(ce,"QApplication",QApplication_methods);
    
    QApplication_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);


    // properties
    
    zend_declare_property_bool(QApplication_ce_ptr,"quitOnLastWindowClosed",strlen("quitOnLastWindowClosed"), QApplication::quitOnLastWindowClosed(),ZEND_ACC_PROTECTED TSRMLS_CC);

    zend_declare_property_long(QApplication_ce_ptr,"doubleClickInterval",strlen("doubleClickInterval"),QApplication::doubleClickInterval(),ZEND_ACC_PROTECTED TSRMLS_CC);
    zend_declare_property_long(QApplication_ce_ptr,"cursorFlashTime",strlen("cursorFlashTime"),QApplication::cursorFlashTime(),ZEND_ACC_PROTECTED TSRMLS_CC);

    zend_declare_property_long(QApplication_ce_ptr,"keyboardInputInterval",strlen("keyboardInputInterval"),QApplication::keyboardInputInterval(),ZEND_ACC_PROTECTED TSRMLS_CC);


    zend_declare_property_long(QApplication_ce_ptr,"startDragDistance",strlen("startDragDistance"),QApplication::startDragDistance(),ZEND_ACC_PROTECTED TSRMLS_CC);
    zend_declare_property_long(QApplication_ce_ptr,"startDragTime",strlen("startDragTime"),QApplication::startDragTime(),ZEND_ACC_PROTECTED TSRMLS_CC);
    zend_declare_property_long(QApplication_ce_ptr,"wheelScrollLines",strlen("wheelScrollLines"),QApplication::wheelScrollLines(),ZEND_ACC_PROTECTED TSRMLS_CC);

}


/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

