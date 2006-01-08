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
 * QPaintEvent.cpp - QPaintEvent PHP implementation.
 * begin           : Sun Jan  8 12:02:25 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QPaintEvent>
#include "../php_qt.h"


#include <QPaintEvent>


/*********************************
 *    class     QPaintEvent */
/*
 *    function  rect
 *    flags:    c
 */
ZEND_METHOD(QPaintEvent, rect){
			QPaintEvent *obj = (QPaintEvent*) PHP_QT_FETCH();
			const QRect & return_object = (const QRect &) obj->rect();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QPaintEvent_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QPaintEvent */
/*
 *    function  region
 *    flags:    c
 */
ZEND_METHOD(QPaintEvent, region){
			QPaintEvent *obj = (QPaintEvent*) PHP_QT_FETCH();
			const QRegion & return_object = (const QRegion &) obj->region();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QPaintEvent_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}



ZEND_METHOD(QPaintEvent,__construct){

	QPaintEvent *QPaintEvent_ptr = new QPaintEvent();

	if(ZEND_NUM_ARGS() == 1){
		zval* param_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param_1) == FAILURE) {
			return;
		}
		 /*zval* paintRegion QRegion&*/
		if(Z_TYPE_P(param_0) == IS_OBJECT) {
			QRegion& tmp(Z_STRVAL_P(param_0));
			QPaintEvent_ptr = new QPaintEvent(tmp);
		}
	}

	if(ZEND_NUM_ARGS() == 1){
		zval* param_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param_1) == FAILURE) {
			return;
		}
		 /*zval* paintRect QRect&*/
		if(Z_TYPE_P(param_0) == IS_OBJECT) {
			QRect& tmp(Z_STRVAL_P(param_0));
			QPaintEvent_ptr = new QPaintEvent(tmp);
		}
	}

	PHP_QT_REGISTER(QPaintEvent_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QPaintEvent);
