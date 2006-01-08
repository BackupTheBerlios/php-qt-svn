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
 * QDateTime.cpp - QDateTime PHP implementation.
 * begin           : Sun Jan  8 02:08:27 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QDateTime>
#include "../php_qt.h"


/*********************************
 *    class     QDateTime */
/*
 *    function  time
 *    flags:    c
 */
ZEND_METHOD(QDateTime, time){
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			QTime return_object = (QTime) obj->time();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QDateTime_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QDateTime */
/*
 *    function  date
 *    flags:    c
 */
ZEND_METHOD(QDateTime, date){
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			QDate return_object = (QDate) obj->date();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QDateTime_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QDateTime */
/*
 *    function  isValid
 *    flags:    c
 */
ZEND_METHOD(QDateTime, isValid){
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isValid());
}

/*********************************
 *    class     QDateTime */
/*
 *    function  toString
 *    flags:    c
 */
ZEND_METHOD(QDateTime, toString){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: Qt::TextDate
		int* len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s|", &var_s_0, &len_s_0) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();

			
		}
		/* o */
		zval* z_var_o_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_1) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			QObject* var_o_1 = (QObject*) php_qt_fetch(z_var_o_1);

			QString tmp_o_0(var_o_1->metaObject()->className());
			
			if(tmp_o_0 == "const QString&") {
				QString return_object = (QString) obj->toString((const QString&) var_o_1);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QDateTime_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
			}
		}
	}
}

/*********************************
 *    class     QDateTime */
/*
 *    function  toTime_t
 *    flags:    c
 */
ZEND_METHOD(QDateTime, toTime_t){
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			RETURN_LONG(obj->toTime_t());
}

/*********************************
 *    class     QDateTime */
/*
 *    function  setTime_t
 *    flags:    
 */
ZEND_METHOD(QDateTime, setTime_t){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QDateTime */
/*
 *    function  addDays
 *    flags:    c
 */
ZEND_METHOD(QDateTime, addDays){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QDateTime */
/*
 *    function  secsTo
 *    flags:    c
 */
ZEND_METHOD(QDateTime, secsTo){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QDateTime&") {
				RETURN_LONG(obj->secsTo((const QDateTime&) var_o_0));
			}
		}
	}
}

/*********************************
 *    class     QDateTime */
/*
 *    function  toTimeSpec
 *    flags:    c
 */
ZEND_METHOD(QDateTime, toTimeSpec){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QDateTime */
/*
 *    function  fromString
 *    flags:    s
 */
ZEND_METHOD(QDateTime, fromString){

	if (ZEND_NUM_ARGS() == 2){
		/* oo */
		zval* z_var_oo_0;   // default: 
		zval* z_var_oo_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oo", &z_var_oo_0, &z_var_oo_1) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			QObject* var_oo_0 = (QObject*) php_qt_fetch(z_var_oo_0);
			QObject* var_oo_1 = (QObject*) php_qt_fetch(z_var_oo_1);

			QString tmp_oo_0(var_oo_0->metaObject()->className());
			QString tmp_oo_1(var_oo_1->metaObject()->className());
			
			if(tmp_oo_0 == "const QString&" && tmp_oo_1 == "const QString&") {
				QDateTime return_object = (QDateTime) obj->fromString((const QString&) var_oo_0, (const QString&) var_oo_1);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QDateTime_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
			}
		}
		/* os */
		zval* z_var_os_2;   // default: 
		char* var_os_3;   // default: Qt::TextDate
		int* len_os_3;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"os|", &z_var_os_2, &var_os_3, &len_os_3) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			QObject* var_os_2 = (QObject*) php_qt_fetch(z_var_os_2);

			QString tmp_os_0(var_os_2->metaObject()->className());
			
			if(tmp_os_0 == "const QString&") {
				QDateTime return_object = (QDateTime) obj->fromString((const QString&) var_os_2, (const char*) var_os_3);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QDateTime_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
			}
		}
	}
}

/*********************************
 *    class     QDateTime */
/*
 *    function  timeSpec
 *    flags:    c
 */
ZEND_METHOD(QDateTime, timeSpec){
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			Qt::TimeSpec return_object = (Qt::TimeSpec) obj->timeSpec();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QDateTime_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QDateTime */
/*
 *    function  setTime
 *    flags:    
 */
ZEND_METHOD(QDateTime, setTime){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QTime&") {
				obj->setTime((const QTime&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QDateTime */
/*
 *    function  addMonths
 *    flags:    c
 */
ZEND_METHOD(QDateTime, addMonths){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QDateTime */
/*
 *    function  QDateTime
 *    flags:    
 */
/*ZEND_METHOD(QDateTime, QDateTime){
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			RETURN_~(obj->QDateTime());
}
*/
/*********************************
 *    class     QDateTime */
/*
 *    function  addSecs
 *    flags:    c
 */
ZEND_METHOD(QDateTime, addSecs){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QDateTime */
/*
 *    function  setDate
 *    flags:    
 */
ZEND_METHOD(QDateTime, setDate){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QDate&") {
				obj->setDate((const QDate&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QDateTime */
/*
 *    function  currentDateTime
 *    flags:    s
 */
ZEND_METHOD(QDateTime, currentDateTime){
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			QDateTime return_object = (QDateTime) obj->currentDateTime();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QDateTime_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QDateTime */
/*
 *    function  daysTo
 *    flags:    c
 */
ZEND_METHOD(QDateTime, daysTo){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QDateTime&") {
				RETURN_LONG(obj->daysTo((const QDateTime&) var_o_0));
			}
		}
	}
}

/*********************************
 *    class     QDateTime */
/*
 *    function  addYears
 *    flags:    c
 */
ZEND_METHOD(QDateTime, addYears){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QDateTime */
/*
 *    function  isNull
 *    flags:    c
 */
ZEND_METHOD(QDateTime, isNull){
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isNull());
}

/*********************************
 *    class     QDateTime */
/*
 *    function  toUTC
 *    flags:    c
 */
ZEND_METHOD(QDateTime, toUTC){
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			QDateTime return_object = (QDateTime) obj->toUTC();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QDateTime_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QDateTime */
/*
 *    function  toLocalTime
 *    flags:    c
 */
ZEND_METHOD(QDateTime, toLocalTime){
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();
			QDateTime return_object = (QDateTime) obj->toLocalTime();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QDateTime_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QDateTime */
/*
 *    function  setTimeSpec
 *    flags:    
 */
ZEND_METHOD(QDateTime, setTimeSpec){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDateTime *obj = (QDateTime*) PHP_QT_FETCH();

			
		}
	}
}



ZEND_METHOD(QDateTime,__construct){

	QDateTime *QDateTime_ptr = new QDateTime();

	if(ZEND_NUM_ARGS() == 0){
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"") == FAILURE) {
			return;
		}
	}

/*	if(ZEND_NUM_ARGS() == 1){
		zval* param_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param_0) == FAILURE) {
			return;
		}

		if(Z_TYPE_P(param_0) == IS_OBJECT) {
			QDate& tmp(Z_STRVAL_P(param_0));
			QDateTime_ptr = new QDateTime(tmp);
		}
	}

	if(ZEND_NUM_ARGS() == 3){
		zval* param_0;
		zval* param_1;
		zval* param_2;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zzz", &param_0, &param_1, &param_2) == FAILURE) {
			return;
		}

		if(Z_TYPE_P(param_0) == IS_OBJECT) {
			QDate& tmp(Z_STRVAL_P(param_0));
			QDateTime_ptr = new QDateTime(tmp);
		}

		if(Z_TYPE_P(param_1) == IS_OBJECT) {
			QTime& tmp(Z_STRVAL_P(param_1));
			QDateTime_ptr = new QDateTime(tmp);
		}

		if(Z_TYPE_P(param_2) == IS_OBJECT) {
			Qt::TimeSpec tmp(Z_STRVAL_P(param_2));
			QDateTime_ptr = new QDateTime(tmp);
		}
	}

	if(ZEND_NUM_ARGS() == 1){
		zval* param_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param_0) == FAILURE) {
			return;
		}

		if(Z_TYPE_P(param_0) == IS_OBJECT) {
			QDateTime& tmp(Z_STRVAL_P(param_0));
			QDateTime_ptr = new QDateTime(tmp);
		}
	}
*/
	PHP_QT_REGISTER(QDateTime_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QDateTime);

