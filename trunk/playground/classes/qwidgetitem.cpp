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
 * QWidgetItem.cpp - QWidgetItem PHP implementation.
 * begin           : Sun Jan  8 12:02:25 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QWidgetItem>
#include "../php_qt.h"


#include <QWidgetItem>


/*********************************
 *    class     QWidgetItem */
/*
 *    function  hasHeightForWidth
 *    flags:    c
 */
ZEND_METHOD(QWidgetItem, hasHeightForWidth){
			QWidgetItem *obj = (QWidgetItem*) PHP_QT_FETCH();
			RETURN_BOOL(obj->hasHeightForWidth());
}

/*********************************
 *    class     QWidgetItem */
/*
 *    function  isEmpty
 *    flags:    c
 */
ZEND_METHOD(QWidgetItem, isEmpty){
			QWidgetItem *obj = (QWidgetItem*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isEmpty());
}

/*********************************
 *    class     QWidgetItem */
/*
 *    function  setGeometry
 *    flags:    
 */
ZEND_METHOD(QWidgetItem, setGeometry){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QWidgetItem *obj = (QWidgetItem*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QRect&") {
				obj->setGeometry((const QRect&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QWidgetItem */
/*
 *    function  minimumSize
 *    flags:    c
 */
ZEND_METHOD(QWidgetItem, minimumSize){
			QWidgetItem *obj = (QWidgetItem*) PHP_QT_FETCH();
			QSize return_object = (QSize) obj->minimumSize();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QWidgetItem_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QWidgetItem */
/*
 *    function  sizeHint
 *    flags:    c
 */
ZEND_METHOD(QWidgetItem, sizeHint){
			QWidgetItem *obj = (QWidgetItem*) PHP_QT_FETCH();
			QSize return_object = (QSize) obj->sizeHint();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QWidgetItem_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QWidgetItem */
/*
 *    function  maximumSize
 *    flags:    c
 */
ZEND_METHOD(QWidgetItem, maximumSize){
			QWidgetItem *obj = (QWidgetItem*) PHP_QT_FETCH();
			QSize return_object = (QSize) obj->maximumSize();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QWidgetItem_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QWidgetItem */
/*
 *    function  heightForWidth
 *    flags:    c
 */
ZEND_METHOD(QWidgetItem, heightForWidth){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QWidgetItem *obj = (QWidgetItem*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QWidgetItem */
/*
 *    function  expandingDirections
 *    flags:    c
 */
ZEND_METHOD(QWidgetItem, expandingDirections){
			QWidgetItem *obj = (QWidgetItem*) PHP_QT_FETCH();
			Qt::Orientations return_object = (Qt::Orientations) obj->expandingDirections();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QWidgetItem_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QWidgetItem */
/*
 *    function  geometry
 *    flags:    c
 */
ZEND_METHOD(QWidgetItem, geometry){
			QWidgetItem *obj = (QWidgetItem*) PHP_QT_FETCH();
			QRect return_object = (QRect) obj->geometry();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QWidgetItem_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QWidgetItem */
/*
 *    function  widget
 *    flags:    v
 */
ZEND_METHOD(QWidgetItem, widget){
			QWidgetItem *obj = (QWidgetItem*) PHP_QT_FETCH();
			QWidget * return_object = (QWidget *) obj->widget();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QWidgetItem_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}



ZEND_METHOD(QWidgetItem,__construct){

	QWidgetItem *QWidgetItem_ptr = new QWidgetItem();

	if(ZEND_NUM_ARGS() == 1){
		zval* param_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param_1) == FAILURE) {
			return;
		}
		 /*zval* w QWidget**/
		if(Z_TYPE_P(param_0) == IS_OBJECT) {
			QWidget* tmp(Z_STRVAL_P(param_0));
			QWidgetItem_ptr = new QWidgetItem(tmp);
		}
	}

	PHP_QT_REGISTER(QWidgetItem_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QWidgetItem);
