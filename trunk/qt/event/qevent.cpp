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

#include <QEvent>
#include "../php_qt.h" 

ZEND_METHOD(QEvent,__construct){
    long type;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l",&type) == FAILURE) {
            return;
    }    
	
	QEvent *event;
    event = new QEvent((QEvent::Type)type);
    PHP_QT_REGISTER(event);

}

PHP_QT_METHOD(QEvent,accept )
PHP_QT_METHOD(QEvent,ignore )
PHP_QT_RETURN_METHOD(QEvent, isAccepted, RETURN_BOOL)
PHP_QT_RETURN_METHOD(QEvent, spontaneous, RETURN_BOOL)
PHP_QT_RETURN_METHOD(QEvent, type, RETURN_LONG)

ZEND_METHOD(QEvent,setAccepted) {
    zend_bool b;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b",&b) == FAILURE) {
            return;
    }
	QEvent *o = (QEvent*) PHP_QT_FETCH(); 
    o->setAccepted(b); 
    RETURN_NULL() 
}

