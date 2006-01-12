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
 * QLayoutItem.cpp - QLayoutItem PHP implementation.
 * begin           : Wed Jan 11 20:29:53 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QLayoutItem>
#include "../php_qt.h"


/*********************************
 *    class     QLayoutItem */
/*
 *    function  isEmpty
 *    flags:    cpv
 */
ZEND_METHOD(QLayoutItem, isEmpty){
	if (ZEND_NUM_ARGS() == 0){
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isEmpty());
	}
}

/*********************************
 *    class     QLayoutItem */
/*
 *    function  layout
 *    flags:    v
 */
ZEND_METHOD(QLayoutItem, layout){
	if (ZEND_NUM_ARGS() == 0){
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();
			QLayout * return_object = (QLayout *) obj->layout();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayoutItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayoutItem */
/*
 *    function  spacerItem
 *    flags:    v
 */
ZEND_METHOD(QLayoutItem, spacerItem){
	if (ZEND_NUM_ARGS() == 0){
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();
			QSpacerItem * return_object = (QSpacerItem *) obj->spacerItem();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayoutItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayoutItem */
/*
 *    function  minimumSize
 *    flags:    cpv
 */
ZEND_METHOD(QLayoutItem, minimumSize){
	if (ZEND_NUM_ARGS() == 0){
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();
			QSize return_object = (QSize) obj->minimumSize();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayoutItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayoutItem */
/*
 *    function  alignment
 *    flags:    c
 */
ZEND_METHOD(QLayoutItem, alignment){
	if (ZEND_NUM_ARGS() == 0){
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();
			Qt::Alignment return_object = (Qt::Alignment) obj->alignment();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayoutItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayoutItem */
/*
 *    function  sizeHint
 *    flags:    cpv
 */
ZEND_METHOD(QLayoutItem, sizeHint){
	if (ZEND_NUM_ARGS() == 0){
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();
			QSize return_object = (QSize) obj->sizeHint();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayoutItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayoutItem */
/*
 *    function  heightForWidth
 *    flags:    cv
 */
ZEND_METHOD(QLayoutItem, heightForWidth){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();

			
			RETURN_LONG(obj->heightForWidth((int) var_l_0));
		}
	}
}

/*********************************
 *    class     QLayoutItem */
/*
 *    function  geometry
 *    flags:    cpv
 */
ZEND_METHOD(QLayoutItem, geometry){
	if (ZEND_NUM_ARGS() == 0){
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();
			QRect return_object = (QRect) obj->geometry();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayoutItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayoutItem */
/*
 *    function  hasHeightForWidth
 *    flags:    cv
 */
ZEND_METHOD(QLayoutItem, hasHeightForWidth){
	if (ZEND_NUM_ARGS() == 0){
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();
			RETURN_BOOL(obj->hasHeightForWidth());
	}
}

/*********************************
 *    class     QLayoutItem */
}

/*********************************
 *    class     QLayoutItem */
/*
 *    function  invalidate
 *    flags:    v
 */
ZEND_METHOD(QLayoutItem, invalidate){
	if (ZEND_NUM_ARGS() == 0){
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();
			obj->invalidate();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QLayoutItem */
/*
 *    function  setGeometry
 *    flags:    pv
 */
ZEND_METHOD(QLayoutItem, setGeometry){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		/* const QRect& ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();
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
 *    class     QLayoutItem */
/*
 *    function  setAlignment
 *    flags:    
 */
ZEND_METHOD(QLayoutItem, setAlignment){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int a,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();

			
			obj->setAlignment((Qt::Alignment) var_l_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QLayoutItem */
/*
 *    function  maximumSize
 *    flags:    cpv
 */
ZEND_METHOD(QLayoutItem, maximumSize){
	if (ZEND_NUM_ARGS() == 0){
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();
			QSize return_object = (QSize) obj->maximumSize();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayoutItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayoutItem */
/*
 *    function  minimumHeightForWidth
 *    flags:    cv
 */
ZEND_METHOD(QLayoutItem, minimumHeightForWidth){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();

			
			RETURN_LONG(obj->minimumHeightForWidth((int) var_l_0));
		}
	}
}

/*********************************
 *    class     QLayoutItem */
/*
 *    function  expandingDirections
 *    flags:    cpv
 */
ZEND_METHOD(QLayoutItem, expandingDirections){
	if (ZEND_NUM_ARGS() == 0){
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();
			Qt::Orientations return_object = (Qt::Orientations) obj->expandingDirections();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayoutItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayoutItem */
/*
 *    function  widget
 *    flags:    v
 */
ZEND_METHOD(QLayoutItem, widget){
	if (ZEND_NUM_ARGS() == 0){
			QLayoutItem *obj = (QLayoutItem*) PHP_QT_FETCH();
			QWidget * return_object = (QWidget *) obj->widget();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayoutItem_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}


PHP_QT_DESTRUCT(QLayoutItem);

