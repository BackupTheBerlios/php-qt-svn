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
 *
 * QKeyEvent.cpp - QKeyEvent PHP implementation.
 * begin           : Sun Jan  8 12:02:25 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QKeyEvent>
#include "../php_qt.h"


#include <QKeyEvent>


/*********************************
 *    class     QKeyEvent */
/*
 *    function  count
 *    flags:    c
 */
ZEND_METHOD(QKeyEvent, count){
			QKeyEvent *obj = (QKeyEvent*) PHP_QT_FETCH();
			RETURN_LONG(obj->count());
}

/*********************************
 *    class     QKeyEvent */
/*
 *    function  text
 *    flags:    c
 */
ZEND_METHOD(QKeyEvent, text){
			QKeyEvent *obj = (QKeyEvent*) PHP_QT_FETCH();
			QString return_object = (QString) obj->text();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QKeyEvent_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QKeyEvent */
/*
 *    function  isAutoRepeat
 *    flags:    c
 */
ZEND_METHOD(QKeyEvent, isAutoRepeat){
			QKeyEvent *obj = (QKeyEvent*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isAutoRepeat());
}

/*********************************
 *    class     QKeyEvent */
/*
 *    function  modifiers
 *    flags:    c
 */
ZEND_METHOD(QKeyEvent, modifiers){
			QKeyEvent *obj = (QKeyEvent*) PHP_QT_FETCH();
			Qt::KeyboardModifiers return_object = (Qt::KeyboardModifiers) obj->modifiers();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QKeyEvent_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QKeyEvent */
/*
 *    function  key
 *    flags:    c
 */
ZEND_METHOD(QKeyEvent, key){
			QKeyEvent *obj = (QKeyEvent*) PHP_QT_FETCH();
			RETURN_LONG(obj->key());
}



ZEND_METHOD(QKeyEvent,__construct){

	QKeyEvent *QKeyEvent_ptr = new QKeyEvent();

	if(ZEND_NUM_ARGS() == 6){
		zval* param_0;
		zval* param_1;
		zval* param_2;
		zval* param_3;
		zval* param_4;
		zval* param_5;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zzzzzz", &param_1, &param_2, &param_3, &param_4, &param_5, &param_6) == FAILURE) {
			return;
		}
		 /*long type Type*/
		if(Z_TYPE_P(param_0) == IS_LONG) {
			Type tmp(Z_STRVAL_P(param_0));
			QKeyEvent_ptr = new QKeyEvent(tmp);
		}
		 /*long key int*/
		if(Z_TYPE_P(param_1) == IS_LONG) {
			int tmp(Z_STRVAL_P(param_1));
			QKeyEvent_ptr = new QKeyEvent(tmp);
		}
		 /*zval* modifiers Qt::KeyboardModifiers*/
		if(Z_TYPE_P(param_2) == IS_OBJECT) {
			Qt::KeyboardModifiers tmp(Z_STRVAL_P(param_2));
			QKeyEvent_ptr = new QKeyEvent(tmp);
		}
		 /*zval* text QString&*/
		if(Z_TYPE_P(param_3) == IS_OBJECT) {
			QString& tmp(Z_STRVAL_P(param_3));
			QKeyEvent_ptr = new QKeyEvent(tmp);
		}
		 /*bool autorep bool*/
		if(Z_TYPE_P(param_4) == IS_BOOL) {
			bool tmp(Z_STRVAL_P(param_4));
			QKeyEvent_ptr = new QKeyEvent(tmp);
		}
		 /*ushort count ushort*/
		if(Z_TYPE_P(param_5) == IS_LONG) {
			ushort tmp(Z_STRVAL_P(param_5));
			QKeyEvent_ptr = new QKeyEvent(tmp);
		}
	}

	PHP_QT_REGISTER(QKeyEvent_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QKeyEvent);
