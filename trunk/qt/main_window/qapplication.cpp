/*
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2005 
 * Thomas Moenicke <tm@ippfp.org>, 
 * Jean-Luc Gyger <jean_luc.gyger@freesurf.ch>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <iostream>
using namespace std;

#include <QApplication>
#include <QWidget>
#include "../php_qt.h"

int argc__;
char *argv__[1];

extern zval* qcoreApplication;


/**
 *  Constructor
 */ 

ZEND_METHOD(QApplication,__construct){
    QApplication *app;
    app = new QApplication(argc__, argv__);
    PHP_QT_REGISTER(app);
	qcoreApplication = getThis();
}

/// @todo must be implemented
ZEND_METHOD(QApplication,commitData){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,inputContext){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,isSessionRestored){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,macEventFilter){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,qwsEventFilter){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,qwsSetCustomColors){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,saveState){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,sessionId){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,sessionKey){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,setInputContext){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,winFocus){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,x11EventFilter){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,x11ProcessEvent){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}


/**
 *  Public slots functions
 */ 

PHP_QT_METHOD(QApplication, closeAllWindows)
PHP_QT_METHOD(QApplication, aboutQt)

/**
 *  Static functions
 */ 

//PHP_QT_STATIC_METHOD(QApplication, exec) 
PHP_QT_STATIC_METHOD(QApplication, beep) 
PHP_QT_STATIC_RETURN_METHOD(QApplication, colorSpec, RETURN_LONG)
PHP_QT_STATIC_RETURN_METHOD(QApplication, cursorFlashTime, RETURN_LONG)
PHP_QT_STATIC_RETURN_METHOD(QApplication, desktopSettingsAware, RETURN_BOOL)
PHP_QT_STATIC_RETURN_METHOD(QApplication, doubleClickInterval, RETURN_LONG)
PHP_QT_STATIC_RETURN_METHOD(QApplication, isLeftToRight, RETURN_BOOL)
PHP_QT_STATIC_RETURN_METHOD(QApplication, isRightToLeft, RETURN_BOOL)
PHP_QT_STATIC_RETURN_METHOD(QApplication, keyboardInputInterval, RETURN_LONG)
PHP_QT_STATIC_RETURN_METHOD(QApplication, quitOnLastWindowClosed, RETURN_BOOL)
PHP_QT_STATIC_METHOD(QApplication, restoreOverrideCursor)
PHP_QT_SETLONG_STATIC_METHOD(QApplication, setColorSpec)
PHP_QT_SETLONG_STATIC_METHOD(QApplication, setCursorFlashTime) 
PHP_QT_SETBOOL_STATIC_METHOD(QApplication, setDesktopSettingsAware)
PHP_QT_SETLONG_STATIC_METHOD(QApplication, setDoubleClickInterval) 
PHP_QT_SETLONG_STATIC_METHOD(QApplication, setKeyboardInputInterval) 
PHP_QT_SETBOOL_STATIC_METHOD(QApplication, setQuitOnLastWindowClosed)
PHP_QT_SETLONG_STATIC_METHOD(QApplication, setStartDragDistance) 
PHP_QT_SETLONG_STATIC_METHOD(QApplication, setStartDragTime) 
PHP_QT_SETLONG_STATIC_METHOD(QApplication, setWheelScrollLines) 
PHP_QT_STATIC_RETURN_METHOD(QApplication, startDragDistance, RETURN_LONG)
PHP_QT_STATIC_RETURN_METHOD(QApplication, startDragTime, RETURN_LONG)
PHP_QT_STATIC_METHOD(QApplication, syncX) 
PHP_QT_STATIC_RETURN_METHOD(QApplication, wheelScrollLines, RETURN_LONG)
PHP_QT_STATIC_RETURN_OBJ_METHOD(QApplication, activeModalWidget, QWidget)
PHP_QT_STATIC_RETURN_OBJ_METHOD(QApplication, activePopupWidget, QWidget)
PHP_QT_STATIC_RETURN_OBJ_METHOD(QApplication, activeWindow, QWidget)
PHP_QT_STATIC_RETURN_OBJ_METHOD(QApplication, focusWidget, QWidget)
PHP_QT_STATIC_RETURN_METHOD(QApplication, type, RETURN_LONG)

ZEND_METHOD(QApplication,setActiveWindow){
	QWidget *act = NULL;
	zval *object;	
	
    if(ZEND_NUM_ARGS() != 1)
		return;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE)
		return;
	
	act = (QWidget*) php_qt_fetch(object);

	if(getThis() != NULL)
	{
        QApplication *o = (QApplication*) PHP_QT_FETCH();
        o->setActiveWindow(act);
    } 
	else 
		QApplication::setActiveWindow(act);
		
    RETURN_NULL();
} 

ZEND_METHOD(QApplication,widgetAt){

	long x,y;	
	zval *object;
	
    if(ZEND_NUM_ARGS() == 2 || ZEND_NUM_ARGS() == 1)
	{
		if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ll|o", &x,&y) == FAILURE)
			return;
	}
	else
	{
		if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE)
			return;
	}
	
    if(getThis() != NULL)
	{
        QApplication *o = (QApplication*) PHP_QT_FETCH();
        if(ZEND_NUM_ARGS() == 2)
			PHP_QT_RET_OBJ(QWidget,o->widgetAt(x,y));
		/// @todo implemented for QPoint parameters 
		
    } 
	else  
	{
        if(ZEND_NUM_ARGS() == 2)
			PHP_QT_RET_OBJ(QWidget,QApplication::widgetAt(x,y))
		/// @todo implemented for QPoint parameters 
	}
    RETURN_NULL();
} 

ZEND_METHOD(QApplication,topLevelAt){

	long x,y;	
	zval *object;
	
    if(ZEND_NUM_ARGS() == 2 )
	{
		if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ll", &x,&y) == FAILURE)
			return;
	}
	else
	{
		if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE)
			return;
	}
	
    if(getThis() != NULL)
	{
        QApplication *o = (QApplication*) PHP_QT_FETCH();
        if(ZEND_NUM_ARGS() == 2)
			PHP_QT_RET_OBJ(QWidget,o->topLevelAt(x,y));
		/// @todo implemented for QPoint parameters 
		
    } 
	else  
	{
        if(ZEND_NUM_ARGS() == 2)
			PHP_QT_RET_OBJ(QWidget,QApplication::topLevelAt(x,y))
		/// @todo implemented for QPoint parameters 
	}
    RETURN_NULL();
} 

/// @todo must be implemented
ZEND_METHOD(QApplication,allWidgets){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,changeOverrideCursor){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,clipboard){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,desktop){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,fontMetrics){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,globalStrut){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,isEffectEnabled){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,keyboardModifiers){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,layoutDirection){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,mouseButton){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,overrideCursor){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,palette){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,qwsDecoration){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,qwsSetDecoration){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,setEffectEnabled){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,setFont){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,setGlobalStrut){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,setLayoutDirection){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,setOverrideCursor){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,setPalette){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,setStyle){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,setWindowIcon){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,style){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,topLevelWidgets){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QApplication,windowIcon){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

