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
 * QHelpEvent.cpp - QHelpEvent PHP implementation.
 * begin           : Fri Jan  6 00:06:34 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include "../php_qt.h"

#include <QHelpEvent>


/*********************************
 *    class     QHelpEvent */
/*
 *    function  y
 *    flags:    c
 */
ZEND_METHOD(QHelpEvent, y){
			QHelpEvent *obj = (QHelpEvent) PHP_QT_FETCH();
			RETURN_LONG(obj->y());
}

/*********************************
 *    class     QHelpEvent */
/*
 *    function  globalY
 *    flags:    c
 */
ZEND_METHOD(QHelpEvent, globalY){
			QHelpEvent *obj = (QHelpEvent) PHP_QT_FETCH();
			RETURN_LONG(obj->globalY());
}

/*********************************
 *    class     QHelpEvent */
/*
 *    function  pos
 *    flags:    c
 */
ZEND_METHOD(QHelpEvent, pos){
			QHelpEvent *obj = (QHelpEvent) PHP_QT_FETCH();
			const QPoint& return_object = (const QPoint&) obj->pos();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QHelpEvent_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QHelpEvent */
/*
 *    function  x
 *    flags:    c
 */
ZEND_METHOD(QHelpEvent, x){
			QHelpEvent *obj = (QHelpEvent) PHP_QT_FETCH();
			RETURN_LONG(obj->x());
}

/*********************************
 *    class     QHelpEvent */
/*
 *    function  globalPos
 *    flags:    c
 */
ZEND_METHOD(QHelpEvent, globalPos){
			QHelpEvent *obj = (QHelpEvent) PHP_QT_FETCH();
			const QPoint& return_object = (const QPoint&) obj->globalPos();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QHelpEvent_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QHelpEvent */
/*
 *    function  globalX
 *    flags:    c
 */
ZEND_METHOD(QHelpEvent, globalX){
			QHelpEvent *obj = (QHelpEvent) PHP_QT_FETCH();
			RETURN_LONG(obj->globalX());
}



ZEND_METHOD(QHelpEvent,__construct){

	QHelpEvent *QHelpEvent_ptr = new QHelpEvent();

	if(ZEND_NUM_ARGS() == 3){
		zval* param_0;
		zval* param_1;
		zval* param_2;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zzz", &param_1, &param_2, &param_3) == FAILURE) {
			return;
		}
		 /*long type Type*/
		if(Z_TYPE_P(param_0) == IS_LONG) {
			Type tmp(Z_STRVAL_P(param_0));
			QHelpEvent_ptr = new QHelpEvent(tmp);
		}
		 /*long pos QPoint&*/
		if(Z_TYPE_P(param_1) == IS_LONG) {
			QPoint& tmp(Z_STRVAL_P(param_1));
			QHelpEvent_ptr = new QHelpEvent(tmp);
		}
		 /*long globalPos QPoint&*/
		if(Z_TYPE_P(param_2) == IS_LONG) {
			QPoint& tmp(Z_STRVAL_P(param_2));
			QHelpEvent_ptr = new QHelpEvent(tmp);
		}
	}

	PHP_QT_REGISTER(QHelpEvent_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QHelpEvent);

