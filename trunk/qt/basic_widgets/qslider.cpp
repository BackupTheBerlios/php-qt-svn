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

#include <QSlider>
#include "../php_qt.h"

// note: TickPosition is an enum at qslider.h, line 43

ZEND_METHOD(QSlider,__construct){

    QSlider *QSlider_ptr = new QSlider();

    if(ZEND_NUM_ARGS() > 0){
        zval *object;

        if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o|", &object) == FAILURE) {
            return; 
        }
        QSlider *tmp = (QSlider*) php_qt_fetch(object);
        QSlider_ptr->setParent(tmp);
        zend_update_property(Z_OBJCE_P(getThis()),getThis(),"parent",strlen("parent"),object TSRMLS_CC);
    }
// orientation
    PHP_QT_REGISTER(QSlider_ptr);
    RETURN_NULL();
}

PHP_QT_DESTRUCT(QSlider);

PHP_QT_SETLONG_METHOD(QSlider,setTickInterval);
PHP_QT_SETPROPERTY_LONGENUM_METHOD(QSlider,setTickPosition,QSlider::TickPosition,TickPosition);
PHP_QT_RETURN_METHOD(QSlider,tickInterval,RETURN_LONG);
PHP_QT_RETURN_METHOD(QSlider,tickPosition,RETURN_LONG);

