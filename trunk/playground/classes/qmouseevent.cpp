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
 * QMouseEvent.cpp - QMouseEvent PHP implementation.
 * begin           : Sun Jan  8 12:02:25 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QMouseEvent>
#include "../php_qt.h"


#include <QMouseEvent>


/*********************************
 *    class     QMouseEvent */
/*
 *    function  x
 *    flags:    c
 */
ZEND_METHOD(QMouseEvent, x){
			QMouseEvent *obj = (QMouseEvent*) PHP_QT_FETCH();
			RETURN_LONG(obj->x());
}

/*********************************
 *    class     QMouseEvent */
/*
 *    function  globalX
 *    flags:    c
 */
ZEND_METHOD(QMouseEvent, globalX){
			QMouseEvent *obj = (QMouseEvent*) PHP_QT_FETCH();
			RETURN_LONG(obj->globalX());
}

/*********************************
 *    class     QMouseEvent */
/*
 *    function  globalPos
 *    flags:    c
 */
ZEND_METHOD(QMouseEvent, globalPos){
			QMouseEvent *obj = (QMouseEvent*) PHP_QT_FETCH();
			const QPoint & return_object = (const QPoint &) obj->globalPos();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QMouseEvent_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QMouseEvent */
/*
 *    function  y
 *    flags:    c
 */
ZEND_METHOD(QMouseEvent, y){
			QMouseEvent *obj = (QMouseEvent*) PHP_QT_FETCH();
			RETURN_LONG(obj->y());
}

/*********************************
 *    class     QMouseEvent */
/*
 *    function  globalY
 *    flags:    c
 */
ZEND_METHOD(QMouseEvent, globalY){
			QMouseEvent *obj = (QMouseEvent*) PHP_QT_FETCH();
			RETURN_LONG(obj->globalY());
}

/*********************************
 *    class     QMouseEvent */
/*
 *    function  pos
 *    flags:    c
 */
ZEND_METHOD(QMouseEvent, pos){
			QMouseEvent *obj = (QMouseEvent*) PHP_QT_FETCH();
			const QPoint & return_object = (const QPoint &) obj->pos();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QMouseEvent_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QMouseEvent */
/*
 *    function  button
 *    flags:    c
 */
ZEND_METHOD(QMouseEvent, button){
			QMouseEvent *obj = (QMouseEvent*) PHP_QT_FETCH();
			Qt::MouseButton return_object = (Qt::MouseButton) obj->button();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QMouseEvent_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QMouseEvent */
/*
 *    function  buttons
 *    flags:    c
 */
ZEND_METHOD(QMouseEvent, buttons){
			QMouseEvent *obj = (QMouseEvent*) PHP_QT_FETCH();
			Qt::MouseButtons return_object = (Qt::MouseButtons) obj->buttons();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QMouseEvent_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}



ZEND_METHOD(QMouseEvent,__construct){

	QMouseEvent *QMouseEvent_ptr = new QMouseEvent();

	if(ZEND_NUM_ARGS() == 5){
		zval* param_0;
		zval* param_1;
		zval* param_2;
		zval* param_3;
		zval* param_4;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zzzzz", &param_1, &param_2, &param_3, &param_4, &param_5) == FAILURE) {
			return;
		}
		 /*long type Type*/
		if(Z_TYPE_P(param_0) == IS_LONG) {
			Type tmp(Z_STRVAL_P(param_0));
			QMouseEvent_ptr = new QMouseEvent(tmp);
		}
		 /*long pos QPoint&*/
		if(Z_TYPE_P(param_1) == IS_LONG) {
			QPoint& tmp(Z_STRVAL_P(param_1));
			QMouseEvent_ptr = new QMouseEvent(tmp);
		}
		 /*zval* button Qt::MouseButton*/
		if(Z_TYPE_P(param_2) == IS_OBJECT) {
			Qt::MouseButton tmp(Z_STRVAL_P(param_2));
			QMouseEvent_ptr = new QMouseEvent(tmp);
		}
		 /*zval* buttons Qt::MouseButtons*/
		if(Z_TYPE_P(param_3) == IS_OBJECT) {
			Qt::MouseButtons tmp(Z_STRVAL_P(param_3));
			QMouseEvent_ptr = new QMouseEvent(tmp);
		}
		 /*zval* modifiers Qt::KeyboardModifiers*/
		if(Z_TYPE_P(param_4) == IS_OBJECT) {
			Qt::KeyboardModifiers tmp(Z_STRVAL_P(param_4));
			QMouseEvent_ptr = new QMouseEvent(tmp);
		}
	}

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
			QMouseEvent_ptr = new QMouseEvent(tmp);
		}
		 /*long pos QPoint&*/
		if(Z_TYPE_P(param_1) == IS_LONG) {
			QPoint& tmp(Z_STRVAL_P(param_1));
			QMouseEvent_ptr = new QMouseEvent(tmp);
		}
		 /*long globalPos QPoint&*/
		if(Z_TYPE_P(param_2) == IS_LONG) {
			QPoint& tmp(Z_STRVAL_P(param_2));
			QMouseEvent_ptr = new QMouseEvent(tmp);
		}
		 /*zval* button Qt::MouseButton*/
		if(Z_TYPE_P(param_3) == IS_OBJECT) {
			Qt::MouseButton tmp(Z_STRVAL_P(param_3));
			QMouseEvent_ptr = new QMouseEvent(tmp);
		}
		 /*zval* buttons Qt::MouseButtons*/
		if(Z_TYPE_P(param_4) == IS_OBJECT) {
			Qt::MouseButtons tmp(Z_STRVAL_P(param_4));
			QMouseEvent_ptr = new QMouseEvent(tmp);
		}
		 /*zval* modifiers Qt::KeyboardModifiers*/
		if(Z_TYPE_P(param_5) == IS_OBJECT) {
			Qt::KeyboardModifiers tmp(Z_STRVAL_P(param_5));
			QMouseEvent_ptr = new QMouseEvent(tmp);
		}
	}

	PHP_QT_REGISTER(QMouseEvent_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QMouseEvent);
