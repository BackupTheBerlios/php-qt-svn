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
 * QDragMoveEvent.cpp - QDragMoveEvent PHP implementation.
 * begin           : Sun Jan  8 23:20:48 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QDragMoveEvent>
#include "../php_qt.h"


/*********************************
 *    class     QDragMoveEvent */
/*
 *    function  accept
 *    flags:    
 */
ZEND_METHOD(QDragMoveEvent, accept){
	if (ZEND_NUM_ARGS() == 0){
			QDragMoveEvent *obj = (QDragMoveEvent*) PHP_QT_FETCH();
			obj->accept();
			RETURN_NULL();
	}

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QDragMoveEvent *obj = (QDragMoveEvent*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QRect&") {
				obj->accept((const QRect&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QDragMoveEvent */
/*
 *    function  answerRect
 *    flags:    c
 */
ZEND_METHOD(QDragMoveEvent, answerRect){
	if (ZEND_NUM_ARGS() == 0){
			QDragMoveEvent *obj = (QDragMoveEvent*) PHP_QT_FETCH();
			QRect return_object = (QRect) obj->answerRect();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDragMoveEvent_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QDragMoveEvent */
/*
 *    function  ignore
 *    flags:    
 */
ZEND_METHOD(QDragMoveEvent, ignore){
	if (ZEND_NUM_ARGS() == 0){
			QDragMoveEvent *obj = (QDragMoveEvent*) PHP_QT_FETCH();
			obj->ignore();
			RETURN_NULL();
	}

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QDragMoveEvent *obj = (QDragMoveEvent*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QRect&") {
				obj->ignore((const QRect&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}


PHP_QT_DESTRUCT(QDragMoveEvent);

