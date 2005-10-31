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
/*
 * Copyright (C) 2005 
 * Thomas Moenicke <tm@ippfp.org>, 
 * Jean-Luc Gyger <jean_luc.gyger@freesurf.ch>
 *
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

//public members
ZEND_METHOD(QApplication,__construct);
//public slots
ZEND_METHOD(QApplication,aboutQt); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,closeAllWindows); // add by Gyger Jean-Luc
//static public members
ZEND_METHOD(QApplication,exec);
ZEND_METHOD(QApplication,beep); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,colorSpec); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,cursorFlashTime); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,desktopSettingsAware); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,doubleClickInterval); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,isLeftToRight); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,isRightToLeft); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,keyboardInputInterval); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,quitOnLastWindowClosed); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,restoreOverrideCursor); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,setDesktopSettingsAware); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,setColorSpec); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,setCursorFlashTime); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,setDoubleClickInterval); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,setKeyboardInputInterval); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,setQuitOnLastWindowClosed); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,setStartDragDistance); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,setStartDragTime); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,setWheelScrollLines); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,startDragDistance); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,startDragTime); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,syncX); // add by Gyger Jean-Luc
ZEND_METHOD(QApplication,wheelScrollLines); // add by Gyger Jean-Luc
/*//ZEND_METHOD(QApplication,activeModalWidget); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,activePopupWidget); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,activeWindow); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,allWidgets); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,changeOverrideCursor); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,clipboard); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,desktop); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,focusWidget); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,font); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,fontMetrics); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,globalStrut); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,isEffectEnabled); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,keyboardModifiers); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,layoutDirection); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,mouseButton); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,overrideCursor); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,palette); // WARNING 3 implementations, add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,qwsDecoration); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,qwsSetDecoration); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,setActiveWindow); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,setEffectEnabled); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,setFont); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,setGlobalStrut); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,setLayoutDirection); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,setOverrideCursor); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,setPalette); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,setStyle); //WARNING 2 imlementation, add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,setWindowIcon); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,style); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,topLevelAt); //WARNING 2 imlementation, add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,topLevelWidgets); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,type); // add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,widgetAt); //WARNING 2 imlementation, add by Gyger Jean-Luc
//ZEND_METHOD(QApplication,windowIcon); //add by Gyger Jean-Luc
*/

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
ZEND_METHOD(QWidget,show);
ZEND_METHOD(QWidget,hide);

ZEND_METHOD(QWidget,acceptDrops);
ZEND_METHOD(QWidget,activateWindow);
ZEND_METHOD(QWidget,adjustSize);
ZEND_METHOD(QWidget,clearFocus);
ZEND_METHOD(QWidget,clearMask);
ZEND_METHOD(QWidget,grabKeyboard);
ZEND_METHOD(QWidget,grabMouse);
ZEND_METHOD(QWidget,hasFocus);
ZEND_METHOD(QWidget,hasMouseTracking);
ZEND_METHOD(QWidget,height);
ZEND_METHOD(QWidget,isActiveWindow);
ZEND_METHOD(QWidget,isEnabled);
ZEND_METHOD(QWidget,isFullScreen);
ZEND_METHOD(QWidget,isHidden);
ZEND_METHOD(QWidget,isMaximized);
ZEND_METHOD(QWidget,isMinimized);
ZEND_METHOD(QWidget,isModal);
ZEND_METHOD(QWidget,isVisible);
ZEND_METHOD(QWidget,isWindow);
ZEND_METHOD(QWidget,isWindowModified);
ZEND_METHOD(QWidget,maximumHeight);
ZEND_METHOD(QWidget,maximumWidth);
ZEND_METHOD(QWidget,minimumHeight);
ZEND_METHOD(QWidget,minimumWidth);
ZEND_METHOD(QWidget,releaseKeyboard);
ZEND_METHOD(QWidget,releaseMouse);
ZEND_METHOD(QWidget,underMouse);
ZEND_METHOD(QWidget,unsetCursor);
ZEND_METHOD(QWidget,unsetLayoutDirection);
ZEND_METHOD(QWidget,updateGeometry);
ZEND_METHOD(QWidget,updatesEnabled);
ZEND_METHOD(QWidget,width);
ZEND_METHOD(QWidget,x);
ZEND_METHOD(QWidget,y);



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
