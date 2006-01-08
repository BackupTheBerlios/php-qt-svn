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
 * QBoxLayout.cpp - QBoxLayout PHP implementation.
 * begin           : Mon Jan  9 00:39:35 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QBoxLayout>
#include "../php_qt.h"



/*		public enumDirection:long {
			Direction = 0,
			Direction = 1,
			Direction = 2,
			Direction = 3,
			Down = TopToBottom,
			Up = BottomToTop
		}
*/
/*********************************
 *    class     QBoxLayout */
/*
 *    function  tr
 *    flags:    s
 */
ZEND_METHOD(QBoxLayout, tr){

	if (ZEND_NUM_ARGS() == 2){
		/* ss */
		char* var_ss_0;   // default: 
		int len_ss_0;

		char* var_ss_1;   // default: 0
		int len_ss_1;


		/* const char* , const char* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ss|", &var_ss_0, len_ss_0, &var_ss_1, len_ss_1) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();

			
			QString return_object = (QString) obj->tr( (const char*) var_ss_0 , (const char*) var_ss_1);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QBoxLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  addLayout
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, addLayout){

	if (ZEND_NUM_ARGS() == 2){
		/* ol */
		zval* z_var_ol_0;   // default: 
		long var_ol_1;    // default: 0

		/* QLayout* layout, int stretch,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ol|", &z_var_ol_0, &var_ol_1) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QObject* var_ol_0 = (QObject*) php_qt_fetch(z_var_ol_0);

			QString tmp_ol_0(var_ol_0->metaObject()->className());
			
			if(tmp_ol_0 == "QLayout*") {
				obj->addLayout((QLayout*) var_ol_0, (int) var_ol_1);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  qt_invoke
 *    flags:    v
 */
ZEND_METHOD(QBoxLayout, qt_invoke){

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* z_var_lo_1;   // default: 

		/* int , QUObject* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo", &var_lo_0, &z_var_lo_1) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QObject* var_lo_1 = (QObject*) php_qt_fetch(z_var_lo_1);

			QString tmp_lo_0(var_lo_1->metaObject()->className());
			
			if(tmp_lo_0 == "QUObject*") {
				RETURN_BOOL(obj->qt_invoke((int) var_lo_0, (QUObject*) var_lo_1));
			}
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  setStretchFactor
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, setStretchFactor){

	if (ZEND_NUM_ARGS() == 2){
		/* ol */
		zval* z_var_ol_0;   // default: 
		long var_ol_1;    // default: 

		/* QWidget* w, int stretch,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ol", &z_var_ol_0, &var_ol_1) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QObject* var_ol_0 = (QObject*) php_qt_fetch(z_var_ol_0);

			QString tmp_ol_0(var_ol_0->metaObject()->className());
			
			if(tmp_ol_0 == "QWidget*") {
				RETURN_BOOL(obj->setStretchFactor((QWidget*) var_ol_0, (int) var_ol_1));
			}			
			if(tmp_ol_0 == "QLayout*") {
				RETURN_BOOL(obj->setStretchFactor((QLayout*) var_ol_0, (int) var_ol_3));
			}
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  setDirection
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, setDirection){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		/* Direction ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "Direction") {
				obj->setDirection((Direction) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  addItem
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, addItem){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		/* QLayoutItem* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "QLayoutItem*") {
				obj->addItem((QLayoutItem*) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  insertSpacing
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, insertSpacing){

	if (ZEND_NUM_ARGS() == 2){
		/* ll */
		long var_ll_0;    // default: 
		long var_ll_1;    // default: 

		/* int index, int size,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ll", &var_ll_0, &var_ll_1) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();

			
			obj->insertSpacing((int) var_ll_0 ,(int) var_ll_1);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  qt_cast
 *    flags:    v
 */
ZEND_METHOD(QBoxLayout, qt_cast){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int len_s_0;


		/* const char* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_s_0, len_s_0) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();

			
			obj->qt_cast( (const char*) var_s_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  metaObject
 *    flags:    cv
 */
ZEND_METHOD(QBoxLayout, metaObject){
	if (ZEND_NUM_ARGS() == 0){
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QMetaObject * return_object = (QMetaObject *) obj->metaObject();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QBoxLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  count
 *    flags:    c
 */
ZEND_METHOD(QBoxLayout, count){
	if (ZEND_NUM_ARGS() == 0){
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			RETURN_LONG(obj->count());
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  invalidate
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, invalidate){
	if (ZEND_NUM_ARGS() == 0){
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			obj->invalidate();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  setGeometry
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, setGeometry){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		/* const QRect& ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
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
 *    class     QBoxLayout */
/*
 *    function  qt_emit
 *    flags:    v
 */
ZEND_METHOD(QBoxLayout, qt_emit){

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* z_var_lo_1;   // default: 

		/* int , QUObject* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo", &var_lo_0, &z_var_lo_1) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QObject* var_lo_1 = (QObject*) php_qt_fetch(z_var_lo_1);

			QString tmp_lo_0(var_lo_1->metaObject()->className());
			
			if(tmp_lo_0 == "QUObject*") {
				RETURN_BOOL(obj->qt_emit((int) var_lo_0, (QUObject*) var_lo_1));
			}
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  className
 *    flags:    cv
 */
ZEND_METHOD(QBoxLayout, className){
	if (ZEND_NUM_ARGS() == 0){
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			const char * return_object = (const char *) obj->className();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QBoxLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  addWidget
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, addWidget){

	if (ZEND_NUM_ARGS() == 3){
		/* oll */
		zval* z_var_oll_0;   // default: 
		long var_oll_1;    // default: 0
		long var_oll_2;    // default: 0

		/* QWidget* , int stretch, int alignment,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ol|l|", &z_var_oll_0, &var_oll_1, &var_oll_2) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QObject* var_oll_0 = (QObject*) php_qt_fetch(z_var_oll_0);

			QString tmp_oll_0(var_oll_0->metaObject()->className());
			
			if(tmp_oll_0 == "QWidget*") {
				obj->addWidget((QWidget*) var_oll_0, (int) var_oll_1, (Qt::Alignment) var_oll_2);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  addStrut
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, addStrut){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();

			
			obj->addStrut((int) var_l_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  takeAt
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, takeAt){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();

			
			QLayoutItem * return_object = (QLayoutItem *) obj->takeAt((int) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QBoxLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  staticMetaObject
 *    flags:    s
 */
ZEND_METHOD(QBoxLayout, staticMetaObject){
	if (ZEND_NUM_ARGS() == 0){
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QMetaObject* return_object = (QMetaObject*) obj->staticMetaObject();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QBoxLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  itemAt
 *    flags:    c
 */
ZEND_METHOD(QBoxLayout, itemAt){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();

			
			QLayoutItem * return_object = (QLayoutItem *) obj->itemAt((int) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QBoxLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  direction
 *    flags:    c
 */
ZEND_METHOD(QBoxLayout, direction){
	if (ZEND_NUM_ARGS() == 0){
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			RETURN_LONG(obj->direction());
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  qObject
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, qObject){
	if (ZEND_NUM_ARGS() == 0){
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QObject* return_object = (QObject*) obj->qObject();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QBoxLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  minimumSize
 *    flags:    c
 */
ZEND_METHOD(QBoxLayout, minimumSize){
	if (ZEND_NUM_ARGS() == 0){
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QSize return_object = (QSize) obj->minimumSize();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QBoxLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  sizeHint
 *    flags:    c
 */
ZEND_METHOD(QBoxLayout, sizeHint){
	if (ZEND_NUM_ARGS() == 0){
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QSize return_object = (QSize) obj->sizeHint();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QBoxLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  heightForWidth
 *    flags:    c
 */
ZEND_METHOD(QBoxLayout, heightForWidth){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();

			
			RETURN_LONG(obj->heightForWidth((int) var_l_0));
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  addSpacing
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, addSpacing){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int size,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();

			
			obj->addSpacing((int) var_l_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  addStretch
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, addStretch){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 0

		/* int stretch,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l|", &var_l_0) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();

			
			obj->addStretch((int) var_l_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  hasHeightForWidth
 *    flags:    c
 */
ZEND_METHOD(QBoxLayout, hasHeightForWidth){
	if (ZEND_NUM_ARGS() == 0){
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			RETURN_BOOL(obj->hasHeightForWidth());
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  QBoxLayout
 *    flags:    t
 */
ZEND_METHOD(QBoxLayout, __construct){

	if (ZEND_NUM_ARGS() == 2){
		/* oo */
		zval* z_var_oo_0;   // default: 
		zval* z_var_oo_1;   // default: 0

		/* Direction , QWidget* parent,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oo|", &z_var_oo_0, &z_var_oo_1) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QObject* var_oo_0 = (QObject*) php_qt_fetch(z_var_oo_0);
			QObject* var_oo_1 = (QObject*) php_qt_fetch(z_var_oo_1);

			QString tmp_oo_0(var_oo_0->metaObject()->className());
			QString tmp_oo_1(var_oo_1->metaObject()->className());
			
			if(tmp_oo_0 == "Direction" && tmp_oo_1 == "QWidget*") {
				QBoxLayout *QBoxLayout_ptr = new QBoxLayout((Direction) var_oo_0, (QWidget*) var_oo_1);
			PHP_QT_REGISTER(QBoxLayout_ptr);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  insertStretch
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, insertStretch){

	if (ZEND_NUM_ARGS() == 2){
		/* ll */
		long var_ll_0;    // default: 
		long var_ll_1;    // default: 0

		/* int index, int stretch,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ll|", &var_ll_0, &var_ll_1) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();

			
			obj->insertStretch((int) var_ll_0 ,(int) var_ll_1);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  insertWidget
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, insertWidget){

	if (ZEND_NUM_ARGS() == 4){
		/* loll */
		long var_loll_0;    // default: 
		zval* z_var_loll_1;   // default: 
		long var_loll_2;    // default: 0
		long var_loll_3;    // default: 0

		/* int index, QWidget* widget, int stretch, int alignment,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lol|l|", &var_loll_0, &z_var_loll_1, &var_loll_2, &var_loll_3) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QObject* var_loll_1 = (QObject*) php_qt_fetch(z_var_loll_1);

			QString tmp_loll_0(var_loll_1->metaObject()->className());
			
			if(tmp_loll_0 == "QWidget*") {
				obj->insertWidget((int) var_loll_0, (QWidget*) var_loll_1, (int) var_loll_2, (Qt::Alignment) var_loll_3);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  insertLayout
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, insertLayout){

	if (ZEND_NUM_ARGS() == 3){
		/* lol */
		long var_lol_0;    // default: 
		zval* z_var_lol_1;   // default: 
		long var_lol_2;    // default: 0

		/* int index, QLayout* layout, int stretch,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lol|", &var_lol_0, &z_var_lol_1, &var_lol_2) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QObject* var_lol_1 = (QObject*) php_qt_fetch(z_var_lol_1);

			QString tmp_lol_0(var_lol_1->metaObject()->className());
			
			if(tmp_lol_0 == "QLayout*") {
				obj->insertLayout((int) var_lol_0, (QLayout*) var_lol_1, (int) var_lol_2);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  trUtf8
 *    flags:    s
 */
ZEND_METHOD(QBoxLayout, trUtf8){

	if (ZEND_NUM_ARGS() == 2){
		/* ss */
		char* var_ss_0;   // default: 
		int len_ss_0;

		char* var_ss_1;   // default: 0
		int len_ss_1;


		/* const char* , const char* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ss|", &var_ss_0, len_ss_0, &var_ss_1, len_ss_1) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();

			
			QString return_object = (QString) obj->trUtf8( (const char*) var_ss_0 , (const char*) var_ss_1);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QBoxLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  qt_property
 *    flags:    v
 */
ZEND_METHOD(QBoxLayout, qt_property){

	if (ZEND_NUM_ARGS() == 3){
		/* llo */
		long var_llo_0;    // default: 
		long var_llo_1;    // default: 
		zval* z_var_llo_2;   // default: 

		/* int , int , QVariant* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"llo", &var_llo_0, &var_llo_1, &z_var_llo_2) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QObject* var_llo_2 = (QObject*) php_qt_fetch(z_var_llo_2);

			QString tmp_llo_0(var_llo_2->metaObject()->className());
			
			if(tmp_llo_0 == "QVariant*") {
				RETURN_BOOL(obj->qt_property((int) var_llo_0, (int) var_llo_1, (QVariant*) var_llo_2));
			}
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  maximumSize
 *    flags:    c
 */
ZEND_METHOD(QBoxLayout, maximumSize){
	if (ZEND_NUM_ARGS() == 0){
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QSize return_object = (QSize) obj->maximumSize();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QBoxLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  minimumHeightForWidth
 *    flags:    c
 */
ZEND_METHOD(QBoxLayout, minimumHeightForWidth){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();

			
			RETURN_LONG(obj->minimumHeightForWidth((int) var_l_0));
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  insertItem
 *    flags:    
 */
ZEND_METHOD(QBoxLayout, insertItem){

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* z_var_lo_1;   // default: 

		/* int index, QLayoutItem* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo", &var_lo_0, &z_var_lo_1) == SUCCESS) {
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			QObject* var_lo_1 = (QObject*) php_qt_fetch(z_var_lo_1);

			QString tmp_lo_0(var_lo_1->metaObject()->className());
			
			if(tmp_lo_0 == "QLayoutItem*") {
				obj->insertItem((int) var_lo_0, (QLayoutItem*) var_lo_1);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QBoxLayout */
/*
 *    function  expandingDirections
 *    flags:    c
 */
ZEND_METHOD(QBoxLayout, expandingDirections){
	if (ZEND_NUM_ARGS() == 0){
			QBoxLayout *obj = (QBoxLayout*) PHP_QT_FETCH();
			Qt::Orientations return_object = (Qt::Orientations) obj->expandingDirections();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QBoxLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}


PHP_QT_DESTRUCT(QBoxLayout);

