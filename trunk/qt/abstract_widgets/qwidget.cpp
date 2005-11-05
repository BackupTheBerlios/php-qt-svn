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


// PHP_QT_RETURN_OBJ_METHOD(QWidget, function, object_type) \

 //PHP_QT_RETURN_OBJ_METHOD(QWidget, accessibleDescription, QString);
 //PHP_QT_RETURN_OBJ_METHOD(QWidget, accessibleName, QString);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, backgroundRole, QPalette::ColorRole); // ??
//PHP_QT_RETURN_OBJ_METHOD(QWidget, baseSize, QSize);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, childrenRecr, QRect);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, childrenRegion, QRegion);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, contentsRect, QRect);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, contextMenuPolicy, Qt::ContextMenyPolicy); // ??
//PHP_QT_RETURN_OBJ_METHOD(QWidget, cursor, QCursor);
PHP_QT_METHOD(QWidget, ensurePolished);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, focusPolicy, Qt::FocusPolicy); // ??
PHP_QT_RETURN_OBJ_METHOD(QWidget, focusProxy, QWidget);
PHP_QT_RETURN_OBJ_METHOD(QWidget, focusWidget, QWidget);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, font, QFont); // const QFont &
//PHP_QT_RETURN_OBJ_METHOD(QWidget, fontInfo, QFontInfo);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, fontMetrics, QFontMetrics);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, foregroundRole, QPalette::ColorRole); // ??
//PHP_QT_RETURN_OBJ_METHOD(QWidget, frameGeometry, QRect);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, frameSize, QSize);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, geometry, QRect); // const QRect &
//PHP_QT_RETURN_OBJ_METHOD(QWidget, getDC, HDC); // virtual HDC
//PHP_QT_RETURN_OBJ_METHOD(QWidget, inputContext, QInputContext);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, inputMethodQuery, QVariant); // virtual QVariant
//PHP_QT_RETURN_OBJ_METHOD(QWidget, layout, QLayout); // QLayout *
//PHP_QT_RETURN_OBJ_METHOD(QWidget, layoutDirection, Qt::LayoutDirection); // ??
//PHP_QT_RETURN_OBJ_METHOD(QWidget, mask, QRegion);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, maximumSize, QSize);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, minimumSize, QSize);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, minimumSizeHint, QSize); // virtual QSize
//PHP_QT_RETURN_OBJ_METHOD(QWidget, nextInFocusChain, QWidget); // QWidget *
//PHP_QT_RETURN_OBJ_METHOD(QWidget, normalGeometry, QRect);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, paintEngine, QPaintEngine); // QPaintEngine *
//PHP_QT_RETURN_OBJ_METHOD(QWidget, palette, QPalette); // const
PHP_QT_RETURN_OBJ_METHOD(QWidget, parentWidget, QWidget); // QWidget *
//PHP_QT_RETURN_OBJ_METHOD(QWidget, pos, QPoint);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, rect, QRect);
//PHP_QT_METHOD(QWidget, releaseDC);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, size, QSize);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, sizeHint, QSize); // virtual QSize
//PHP_QT_RETURN_OBJ_METHOD(QWidget, sizeIncrement, QSize);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, sizePolicy, QSizePolicy);
 //PHP_QT_RETURN_OBJ_METHOD(QWidget, statusTip, QString);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, style, QStyle); // QStyle *
 //PHP_QT_RETURN_OBJ_METHOD(QWidget, toolTip, QString);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, visibleRegion, QRegion);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, whatsThis, QString);
PHP_QT_RETURN_OBJ_METHOD(QWidget, window, QWidget); // QWidget *
//PHP_QT_RETURN_OBJ_METHOD(QWidget, windowFlags, Qt::WindowFlags); // ??
//PHP_QT_RETURN_OBJ_METHOD(QWidget, windowIcon, QIcon);
 //PHP_QT_RETURN_OBJ_METHOD(QWidget, windowIconText, QString);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, windowOpacity, qreal);
 //PHP_QT_RETURN_OBJ_METHOD(QWidget, windowRole, QString);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, windowState, Qt::WindowStates); // ??
 //PHP_QT_RETURN_OBJ_METHOD(QWidget, windowTitle, QString);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, windowType, Qt::WindowType);
//PHP_QT_RETURN_OBJ_METHOD(QWidget, x11Info, QX11Info); // const QX11Info &
//PHP_QT_RETURN_OBJ_METHOD(QWidget, x11PictureHandle, Qt::HANDLE); // ??


















