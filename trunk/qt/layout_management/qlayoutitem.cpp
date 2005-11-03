/*
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2005 Jean-Luc Gyger <jean_luc.gyger@freesurf.ch>
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

#include <QLayoutItem>
#include "../php_qt.h"

ZEND_METHOD(QLayoutItem,__construct){}
PHP_QT_RETURN_METHOD(QLayoutItem,hasHeightForWidth, RETURN_BOOL);
PHP_QT_METHOD(QLayoutItem,invalidate)
PHP_QT_RETURN_OBJ_METHOD(QLayoutItem,layout,QLayout)
PHP_QT_RETURN_OBJ_METHOD(QLayoutItem,spacerItem,QSpacerItem)
PHP_QT_RETURN_OBJ_METHOD(QLayoutItem,widget,QWidget)

ZEND_METHOD(QLayoutItem, alignment)
{
    QLayoutItem* obj = (QLayoutItem*) PHP_QT_FETCH();
    RETURN_LONG((long)obj->alignment());

}


ZEND_METHOD(QLayoutItem,heightForWidth)
{
    long l;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l",&l) == FAILURE) {
            return;
    }
    QLayoutItem* obj = (QLayoutItem*) PHP_QT_FETCH();
    RETURN_LONG(obj->heightForWidth(l));

}


ZEND_METHOD(QLayoutItem,minimumHeightForWidth)
{
    long l;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l",&l) == FAILURE) {
            return;
    }
    QLayoutItem* obj = (QLayoutItem*) PHP_QT_FETCH();
	qDebug("%u",obj->minimumHeightForWidth(l));
    RETURN_LONG(obj->minimumHeightForWidth(l));
}

ZEND_METHOD(QLayoutItem,setAlignment)
{
    long l;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l",&l) == FAILURE) {
            return;
    }
    QLayoutItem* obj = (QLayoutItem*) PHP_QT_FETCH();
    obj->setAlignment(( Qt::Alignment)l);
    RETURN_NULL();
}


ZEND_METHOD(QLayoutItem,expandingDirections){}//abstract
ZEND_METHOD(QLayoutItem,geometry){}//abstract
ZEND_METHOD(QLayoutItem,isEmpty){}//abstract
ZEND_METHOD(QLayoutItem,maximumSize){}//abstract
ZEND_METHOD(QLayoutItem,minimumSize){}//abstract
ZEND_METHOD(QLayoutItem,setGeometry){}//abstract
ZEND_METHOD(QLayoutItem,sizeHint){}//abstract
