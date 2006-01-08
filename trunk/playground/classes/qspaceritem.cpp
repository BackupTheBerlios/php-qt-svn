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
 * QSpacerItem.cpp - QSpacerItem PHP implementation.
 * begin           : Sun Jan  8 23:20:48 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QSpacerItem>
#include "../php_qt.h"


/*********************************
 *    class     QSpacerItem */
/*
 *    function  changeSize
 *    flags:    
 */
ZEND_METHOD(QSpacerItem, changeSize){

	if (ZEND_NUM_ARGS() == 4){
		/* lloo */
		long var_lloo_0;    // default: 
		long var_lloo_1;    // default: 
		zval* z_var_lloo_2;   // default: QSizePolicy::Minimum
		zval* z_var_lloo_3;   // default: QSizePolicy::Minimum

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"llo|o|", &var_lloo_0, &var_lloo_1, &z_var_lloo_2, &z_var_lloo_3) == SUCCESS) {
			QSpacerItem *obj = (QSpacerItem*) PHP_QT_FETCH();
			QObject* var_lloo_2 = (QObject*) php_qt_fetch(z_var_lloo_2);
			QObject* var_lloo_3 = (QObject*) php_qt_fetch(z_var_lloo_3);

			QString tmp_lloo_0(var_lloo_2->metaObject()->className());
			QString tmp_lloo_1(var_lloo_3->metaObject()->className());
			
			if(tmp_lloo_0 == "QSizePolicy::Policy" && tmp_lloo_1 == "QSizePolicy::Policy") {
				obj->changeSize((int) var_lloo_0, (int) var_lloo_1, (QSizePolicy::Policy) var_lloo_2, (QSizePolicy::Policy) var_lloo_3);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QSpacerItem */
/*
 *    function  isEmpty
 *    flags:    c
 */
ZEND_METHOD(QSpacerItem, isEmpty){
	if (ZEND_NUM_ARGS() == 0){
			QSpacerItem *obj = (QSpacerItem*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isEmpty());
	}
}

/*********************************
 *    class     QSpacerItem */
/*
 *    function  setGeometry
 *    flags:    
 */
ZEND_METHOD(QSpacerItem, setGeometry){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QSpacerItem *obj = (QSpacerItem*) PHP_QT_FETCH();
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
 *    class     QSpacerItem */
/*
 *    function  spacerItem
 *    flags:    
 */
ZEND_METHOD(QSpacerItem, spacerItem){
	if (ZEND_NUM_ARGS() == 0){
			QSpacerItem *obj = (QSpacerItem*) PHP_QT_FETCH();
			QSpacerItem * return_object = (QSpacerItem *) obj->spacerItem();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QSpacerItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QSpacerItem */
/*
 *    function  minimumSize
 *    flags:    c
 */
ZEND_METHOD(QSpacerItem, minimumSize){
	if (ZEND_NUM_ARGS() == 0){
			QSpacerItem *obj = (QSpacerItem*) PHP_QT_FETCH();
			QSize return_object = (QSize) obj->minimumSize();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QSpacerItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QSpacerItem */
/*
 *    function  sizeHint
 *    flags:    c
 */
ZEND_METHOD(QSpacerItem, sizeHint){
	if (ZEND_NUM_ARGS() == 0){
			QSpacerItem *obj = (QSpacerItem*) PHP_QT_FETCH();
			QSize return_object = (QSize) obj->sizeHint();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QSpacerItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QSpacerItem */
/*
 *    function  maximumSize
 *    flags:    c
 */
ZEND_METHOD(QSpacerItem, maximumSize){
	if (ZEND_NUM_ARGS() == 0){
			QSpacerItem *obj = (QSpacerItem*) PHP_QT_FETCH();
			QSize return_object = (QSize) obj->maximumSize();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QSpacerItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QSpacerItem */
/*
 *    function  geometry
 *    flags:    c
 */
ZEND_METHOD(QSpacerItem, geometry){
	if (ZEND_NUM_ARGS() == 0){
			QSpacerItem *obj = (QSpacerItem*) PHP_QT_FETCH();
			QRect return_object = (QRect) obj->geometry();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QSpacerItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QSpacerItem */
/*
 *    function  expandingDirections
 *    flags:    c
 */
ZEND_METHOD(QSpacerItem, expandingDirections){
	if (ZEND_NUM_ARGS() == 0){
			QSpacerItem *obj = (QSpacerItem*) PHP_QT_FETCH();
			Qt::Orientations return_object = (Qt::Orientations) obj->expandingDirections();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QSpacerItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QSpacerItem */
/*
 *    function  QSpacerItem
 *    flags:    
 */
ZEND_METHOD(QSpacerItem, __construct){

	if (ZEND_NUM_ARGS() == 4){
		/* lloo */
		long var_lloo_0;    // default: 
		long var_lloo_1;    // default: 
		zval* z_var_lloo_2;   // default: QSizePolicy::Minimum
		zval* z_var_lloo_3;   // default: QSizePolicy::Minimum

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"llo|o|", &var_lloo_0, &var_lloo_1, &z_var_lloo_2, &z_var_lloo_3) == SUCCESS) {
			QSpacerItem *obj = (QSpacerItem*) PHP_QT_FETCH();
			QObject* var_lloo_2 = (QObject*) php_qt_fetch(z_var_lloo_2);
			QObject* var_lloo_3 = (QObject*) php_qt_fetch(z_var_lloo_3);

			QString tmp_lloo_0(var_lloo_2->metaObject()->className());
			QString tmp_lloo_1(var_lloo_3->metaObject()->className());
			
			if(tmp_lloo_0 == "QSizePolicy::Policy" && tmp_lloo_1 == "QSizePolicy::Policy") {
				obj->QSpacerItem((int) var_lloo_0, (int) var_lloo_1, (QSizePolicy::Policy) var_lloo_2, (QSizePolicy::Policy) var_lloo_3);
			RETURN_NULL();
			}
		}
	}
}


PHP_QT_DESTRUCT(QSpacerItem);

