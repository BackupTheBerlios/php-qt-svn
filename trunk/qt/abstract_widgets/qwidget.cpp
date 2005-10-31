/*
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2005 Thomas Moenicke <tm@ippfp.org>
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

#include <QWidget>
#include "../php_qt.h"


ZEND_METHOD(QWidget,__construct){

    if(ZEND_NUM_ARGS() == 1){
        zval *object;

	    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
            return;
        }
        QWidget *parent = (QWidget*) php_qt_fetch(object);
        QWidget* QWidget_ptr = new QWidget(parent);
        PHP_QT_REGISTER(QWidget_ptr);

        RETURN_NULL();

    } else if(ZEND_NUM_ARGS() == 0){

        QWidget* QWidget_ptr = new QWidget();
        PHP_QT_REGISTER(QWidget_ptr);

        RETURN_NULL();

    }
}

PHP_QT_METHOD(QWidget,show);
PHP_QT_METHOD(QWidget,hide);
PHP_QT_RETURN_METHOD(QWidget,acceptDrops,RETURN_BOOL);
PHP_QT_METHOD(QWidget,activateWindow);
PHP_QT_METHOD(QWidget,adjustSize);
PHP_QT_METHOD(QWidget,clearFocus);
PHP_QT_METHOD(QWidget,clearMask);
PHP_QT_METHOD(QWidget,grabKeyboard);
PHP_QT_METHOD(QWidget,grabMouse);
PHP_QT_RETURN_METHOD(QWidget,hasFocus,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QWidget,hasMouseTracking,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QWidget,height,RETURN_LONG);
PHP_QT_RETURN_METHOD(QWidget,isActiveWindow,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QWidget,isEnabled,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QWidget,isFullScreen,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QWidget,isHidden,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QWidget,isMaximized,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QWidget,isMinimized,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QWidget,isModal,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QWidget,isVisible,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QWidget,isWindow,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QWidget,isWindowModified,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QWidget,maximumHeight,RETURN_LONG);
PHP_QT_RETURN_METHOD(QWidget,maximumWidth,RETURN_LONG);
PHP_QT_RETURN_METHOD(QWidget,minimumHeight,RETURN_LONG);
PHP_QT_RETURN_METHOD(QWidget,minimumWidth,RETURN_LONG);
PHP_QT_METHOD(QWidget,releaseKeyboard);
PHP_QT_METHOD(QWidget,releaseMouse);
PHP_QT_RETURN_METHOD(QWidget,underMouse,RETURN_BOOL);
PHP_QT_METHOD(QWidget,unsetCursor);
PHP_QT_METHOD(QWidget,unsetLayoutDirection);
PHP_QT_METHOD(QWidget,updateGeometry);
PHP_QT_RETURN_METHOD(QWidget,updatesEnabled,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QWidget,width,RETURN_LONG);
PHP_QT_RETURN_METHOD(QWidget,x,RETURN_LONG);
PHP_QT_RETURN_METHOD(QWidget,y,RETURN_LONG);



