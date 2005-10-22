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

#ifndef PHP_PHP_QT_H
#define PHP_PHP_QT_H

extern zend_module_entry php_qt_module_entry;
#define phpext_php_qt_ptr &php_qt_module_entry

#ifdef ZTS
#include "TSRM.h"
#endif

//#include <QApplication>

PHP_MINIT_FUNCTION(php_qt);
PHP_MSHUTDOWN_FUNCTION(php_qt);
PHP_RINIT_FUNCTION(php_qt);
PHP_RSHUTDOWN_FUNCTION(php_qt);
PHP_MINFO_FUNCTION(php_qt);

PHP_FUNCTION(confirm_php_qt_compiled);	/* For testing, remove later. */

/* QObject */
ZEND_METHOD(QObject,__construct);
ZEND_METHOD(QObject,__destruct);
ZEND_METHOD(QObject,test);
ZEND_METHOD(QObject,blockSignals);
ZEND_METHOD(QObject,children);
ZEND_METHOD(QObject,connect);
ZEND_METHOD(QObject,disconnect);
ZEND_METHOD(QObject,dumpObjectInfo);
ZEND_METHOD(QObject,dumpObjectTree);
ZEND_METHOD(QObject,event);
ZEND_METHOD(QObject,eventFilter);
ZEND_METHOD(QObject,findChild);
ZEND_METHOD(QObject,findChildren);
ZEND_METHOD(QObject,inherits);
ZEND_METHOD(QObject,installEventFilter);
ZEND_METHOD(QObject,isWidgetType);
ZEND_METHOD(QObject,killTimer);
ZEND_METHOD(QObject,metaObject);
ZEND_METHOD(QObject,moveToThread);
ZEND_METHOD(QObject,objectName);
ZEND_METHOD(QObject,parent);
ZEND_METHOD(QObject,property);
ZEND_METHOD(QObject,removeEventFilter);
ZEND_METHOD(QObject,setObjectName);
ZEND_METHOD(QObject,setParent);
ZEND_METHOD(QObject,setProperty);
ZEND_METHOD(QObject,signalsBlocked);
ZEND_METHOD(QObject,startTimer);
ZEND_METHOD(QObject,thread);

ZEND_METHOD(QString,__construct);
ZEND_METHOD(QString,append);
ZEND_METHOD(QString,arg);
ZEND_METHOD(QString,at);
ZEND_METHOD(QString,capacity);
ZEND_METHOD(QString,chop);
ZEND_METHOD(QString,clear);
ZEND_METHOD(QString,compare);

ZEND_METHOD(QLatin1String,__construct);
ZEND_METHOD(QLatin1String,latin1);

ZEND_METHOD(QApplication,__construct);
ZEND_METHOD(QApplication,exec);

ZEND_METHOD(QAbstractButton,__construct);
ZEND_METHOD(QAbstractButton,autoExclusive);
ZEND_METHOD(QAbstractButton,autoRepeat);
ZEND_METHOD(QAbstractButton,isCheckable);
ZEND_METHOD(QAbstractButton,isChecked);
ZEND_METHOD(QAbstractButton,isDown);
ZEND_METHOD(QAbstractButton,setAutoExclusive);
ZEND_METHOD(QAbstractButton,setAutoRepeat);
ZEND_METHOD(QAbstractButton,setCheckable);

ZEND_METHOD(QPushButton,__construct);
ZEND_METHOD(QPushButton,autoDefault);
ZEND_METHOD(QPushButton,isDefault);
ZEND_METHOD(QPushButton,isFlat);
ZEND_METHOD(QPushButton,menu);
ZEND_METHOD(QPushButton,setAutoDefault);
ZEND_METHOD(QPushButton,setDefault);
ZEND_METHOD(QPushButton,setFlat);
ZEND_METHOD(QPushButton,setMenu);

ZEND_METHOD(QWidget,__construct);
ZEND_METHOD(QWidget,isVisible);
ZEND_METHOD(QWidget,isHidden);
ZEND_METHOD(QWidget,show);
ZEND_METHOD(QWidget,hide);

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(php_qt)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(php_qt)
*/

/* In every utility function you add that needs to use variables 
   in php_php_qt_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as PHP_QT_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define PHP_QT_G(v) TSRMG(php_qt_globals_id, zend_php_qt_globals *, v)
#else
#define PHP_QT_G(v) (php_qt_globals.v)
#endif

#endif	/* PHP_PHP_QT_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
