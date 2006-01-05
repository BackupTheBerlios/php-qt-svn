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
 * QVBoxLayout.cpp - QVBoxLayout PHP implementation.
 * begin           : Fri Jan  6 00:06:34 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include "../php_qt.h"

#include <QVBoxLayout>


/*********************************
 *    class     QVBoxLayout */
/*
 *    function  metaObject
 *    flags:    cv
 */
ZEND_METHOD(QVBoxLayout, metaObject){
			QVBoxLayout *obj = (QVBoxLayout) PHP_QT_FETCH();
			QMetaObject * return_object = (QMetaObject *) obj->metaObject();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QVBoxLayout_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QVBoxLayout */
/*
 *    function  tr
 *    flags:    s
 */
ZEND_METHOD(QVBoxLayout, tr){

	if (ZEND_NUM_ARGS() == 2){
		/* ss */
		char* var_ss_0;   // default: 
		int* len_ss_0;

		char* var_ss_1;   // default: 0
		int* len_ss_1;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ss|", &var_0, &len_0, &var_1, &len_1) == SUCCESS) {
			QVBoxLayout *obj = (QVBoxLayout*) PHP_QT_FETCH();

			
			QVBoxLayout *obj = (QVBoxLayout) PHP_QT_FETCH();
			QString return_object = (QString) obj->tr( var_0 , var_1);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QVBoxLayout_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
		}
	}
}

/*********************************
 *    class     QVBoxLayout */
/*
 *    function  qt_invoke
 *    flags:    v
 */
ZEND_METHOD(QVBoxLayout, qt_invoke){

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* var_lo_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo", &var_lo_0, &var_lo_1) == SUCCESS) {
			QVBoxLayout *obj = (QVBoxLayout*) PHP_QT_FETCH();
			QObject* var_o_1 = (QObject*) php_qt_fetch(var_o_1);

			QString tmp_0(var_o_1->metaObject()->className());
			
			if(tmp_0 == "QUObject*") {
				QVBoxLayout *obj = (QVBoxLayout) PHP_QT_FETCH();
			RETURN_BOOL(obj->qt_invoke((int) var_lo_0, (QUObject*) var_o_1));
			}
		}
	}
}

/*********************************
 *    class     QVBoxLayout */
/*
 *    function  staticMetaObject
 *    flags:    s
 */
ZEND_METHOD(QVBoxLayout, staticMetaObject){
			QVBoxLayout *obj = (QVBoxLayout) PHP_QT_FETCH();
			QMetaObject* return_object = (QMetaObject*) obj->staticMetaObject();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QVBoxLayout_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QVBoxLayout */
/*
 *    function  qt_emit
 *    flags:    v
 */
ZEND_METHOD(QVBoxLayout, qt_emit){

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* var_lo_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo", &var_lo_0, &var_lo_1) == SUCCESS) {
			QVBoxLayout *obj = (QVBoxLayout*) PHP_QT_FETCH();
			QObject* var_o_1 = (QObject*) php_qt_fetch(var_o_1);

			QString tmp_0(var_o_1->metaObject()->className());
			
			if(tmp_0 == "QUObject*") {
				QVBoxLayout *obj = (QVBoxLayout) PHP_QT_FETCH();
			RETURN_BOOL(obj->qt_emit((int) var_lo_0, (QUObject*) var_o_1));
			}
		}
	}
}

/*********************************
 *    class     QVBoxLayout */
/*
 *    function  className
 *    flags:    cv
 */
ZEND_METHOD(QVBoxLayout, className){
			QVBoxLayout *obj = (QVBoxLayout) PHP_QT_FETCH();
			const char * return_object = (const char *) obj->className();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QVBoxLayout_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QVBoxLayout */
/*
 *    function  qObject
 *    flags:    
 */
ZEND_METHOD(QVBoxLayout, qObject){
			QVBoxLayout *obj = (QVBoxLayout) PHP_QT_FETCH();
			QObject* return_object = (QObject*) obj->qObject();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QVBoxLayout_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QVBoxLayout */
/*
 *    function  trUtf8
 *    flags:    s
 */
ZEND_METHOD(QVBoxLayout, trUtf8){

	if (ZEND_NUM_ARGS() == 2){
		/* ss */
		char* var_ss_0;   // default: 
		int* len_ss_0;

		char* var_ss_1;   // default: 0
		int* len_ss_1;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ss|", &var_0, &len_0, &var_1, &len_1) == SUCCESS) {
			QVBoxLayout *obj = (QVBoxLayout*) PHP_QT_FETCH();

			
			QVBoxLayout *obj = (QVBoxLayout) PHP_QT_FETCH();
			QString return_object = (QString) obj->trUtf8( var_0 , var_1);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QVBoxLayout_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
		}
	}
}

/*********************************
 *    class     QVBoxLayout */
/*
 *    function  qt_property
 *    flags:    v
 */
ZEND_METHOD(QVBoxLayout, qt_property){

	if (ZEND_NUM_ARGS() == 3){
		/* llo */
		long var_llo_0;    // default: 
		long var_llo_1;    // default: 
		zval* var_llo_2;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"llo", &var_llo_0, &var_llo_1, &var_llo_2) == SUCCESS) {
			QVBoxLayout *obj = (QVBoxLayout*) PHP_QT_FETCH();
			QObject* var_o_2 = (QObject*) php_qt_fetch(var_o_2);

			QString tmp_0(var_o_2->metaObject()->className());
			
			if(tmp_0 == "QVariant*") {
				QVBoxLayout *obj = (QVBoxLayout) PHP_QT_FETCH();
			RETURN_BOOL(obj->qt_property((int) var_llo_0, (int) var_llo_0, (QVariant*) var_o_2));
			}
		}
	}
}

/*********************************
 *    class     QVBoxLayout */
/*
 *    function  QVBoxLayout
 *    flags:    
 */
ZEND_METHOD(QVBoxLayout, QVBoxLayout){
			QVBoxLayout *obj = (QVBoxLayout) PHP_QT_FETCH();
			RETURN_~(obj->QVBoxLayout());
}

/*********************************
 *    class     QVBoxLayout */
/*
 *    function  qt_cast
 *    flags:    v
 */
ZEND_METHOD(QVBoxLayout, qt_cast){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int* len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_0, &len_0) == SUCCESS) {
			QVBoxLayout *obj = (QVBoxLayout*) PHP_QT_FETCH();

			
			QVBoxLayout *obj = (QVBoxLayout) PHP_QT_FETCH();
			obj->qt_cast( var_0);
			RETURN_NULL();
		}
	}
}



ZEND_METHOD(QVBoxLayout,__construct){

	QVBoxLayout *QVBoxLayout_ptr = new QVBoxLayout();

	if(ZEND_NUM_ARGS() == 0){
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"") == FAILURE) {
			return;
		}
	}

	if(ZEND_NUM_ARGS() == 1){
		zval* param_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param_1) == FAILURE) {
			return;
		}
		 /*zval* parent QWidget**/
		if(Z_TYPE_P(param_0) == IS_OBJECT) {
			QWidget* tmp(Z_STRVAL_P(param_0));
			QVBoxLayout_ptr = new QVBoxLayout(tmp);
		}
	}

	PHP_QT_REGISTER(QVBoxLayout_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QVBoxLayout);

