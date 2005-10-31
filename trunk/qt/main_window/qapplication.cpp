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
#include "../php_qt.h"

int argc__;
char *argv__[1];

/**
 *  Constructor
 */ 

ZEND_METHOD(QApplication,__construct){
    QApplication *app;
    app = new QApplication(argc__, argv__);
    PHP_QT_REGISTER(app);

}


/**
 *  Public slots functions
 *  add by Jean-Luc Gyger
 */ 

PHP_QT_METHOD(QApplication, closeAllWindows)
PHP_QT_METHOD(QApplication, aboutQt)

/**
 *  Static functions
 *  add by Jean-Luc Gyger
 */ 

PHP_QT_STATIC_METHOD(QApplication, exec) 
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
