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
 * QTime.cpp - QTime PHP implementation.
 * begin           : Sun Jan 15 17:39:22 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QTime>
#include "../php_qt.h"


/*********************************
 *    class     QTime */
/*
 *    function  hour
 *    flags:    c
 */
ZEND_METHOD(QTime, hour){
	if (ZEND_NUM_ARGS() == 0){
			QTime *obj = (QTime*) PHP_QT_FETCH();
			RETURN_LONG(obj->hour());
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  isValid
 *    flags:    c
 */
ZEND_METHOD(QTime, isValid){
	if (ZEND_NUM_ARGS() == 0){
			QTime *obj = (QTime*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isValid());
	}

	if (ZEND_NUM_ARGS() == 4){
		/* llll public*/
		long var_llll_0;    // default: 
		long var_llll_1;    // default: 
		long var_llll_2;    // default: 
		long var_llll_3;    // default: 0

		/* int h, int m, int s, int ms,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"llll|", &var_llll_0, &var_llll_1, &var_llll_2, &var_llll_3) == SUCCESS) {
			QTime *obj = (QTime*) PHP_QT_FETCH();

			
			RETURN_BOOL(obj->isValid((int) var_llll_0 ,(int) var_llll_1 ,(int) var_llll_2 ,(int) var_llll_3));
		}
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  elapsed
 *    flags:    c
 */
ZEND_METHOD(QTime, elapsed){
	if (ZEND_NUM_ARGS() == 0){
			QTime *obj = (QTime*) PHP_QT_FETCH();
			RETURN_LONG(obj->elapsed());
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  toString
 *    flags:    c
 */
ZEND_METHOD(QTime, toString){

	if (ZEND_NUM_ARGS() == 1){
		/* l public*/
		long var_l_0;    // default: Qt::TextDate

		/* int f,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l|", &var_l_0) == SUCCESS) {
			QTime *obj = (QTime*) PHP_QT_FETCH();

			
			QString return_object = (QString) obj->toString((Qt::DateFormat) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QTime_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
		/* o public*/
		zval* z_var_o_0;   // default: 

		/* const QString& format,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QTime *obj = (QTime*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QString") {
				QString return_object = (QString) obj->toString((const QString&) var_o_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QTime_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			}
		}
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  msec
 *    flags:    c
 */
ZEND_METHOD(QTime, msec){
	if (ZEND_NUM_ARGS() == 0){
			QTime *obj = (QTime*) PHP_QT_FETCH();
			RETURN_LONG(obj->msec());
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  secsTo
 *    flags:    c
 */
ZEND_METHOD(QTime, secsTo){

	if (ZEND_NUM_ARGS() == 1){
		/* o public*/
		zval* z_var_o_0;   // default: 

		/* const QTime& ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QTime *obj = (QTime*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QTime") {
				RETURN_LONG(obj->secsTo((const QTime&) var_o_0));
			}
		}
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  restart
 *    flags:    
 */
ZEND_METHOD(QTime, restart){
	if (ZEND_NUM_ARGS() == 0){
			QTime *obj = (QTime*) PHP_QT_FETCH();
			RETURN_LONG(obj->restart());
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  fromString
 *    flags:    s
 */
ZEND_METHOD(QTime, fromString){

	if (ZEND_NUM_ARGS() == 2){
		/* ol public*/
		zval* z_var_ol_0;   // default: 
		long var_ol_1;    // default: Qt::TextDate

		/* const QString& s, int f,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ol|", &z_var_ol_0, &var_ol_1) == SUCCESS) {
			QTime *obj = (QTime*) PHP_QT_FETCH();
			QObject* var_ol_0 = (QObject*) php_qt_fetch(z_var_ol_0);

			QString tmp_ol_0(var_ol_0->metaObject()->className());
			
			if(tmp_ol_0 == "const QString") {
				QTime return_object = (QTime) obj->fromString((const QString&) var_ol_0, (Qt::DateFormat) var_ol_1);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QTime_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			}
		}
		/* oo public*/
		zval* z_var_oo_0;   // default: 
		zval* z_var_oo_1;   // default: 

		/* const QString& s, const QString& format,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oo", &z_var_oo_0, &z_var_oo_1) == SUCCESS) {
			QTime *obj = (QTime*) PHP_QT_FETCH();
			QObject* var_oo_0 = (QObject*) php_qt_fetch(z_var_oo_0);
			QObject* var_oo_1 = (QObject*) php_qt_fetch(z_var_oo_1);

			QString tmp_oo_0(var_oo_0->metaObject()->className());
			QString tmp_oo_1(var_oo_1->metaObject()->className());
			
			if(tmp_oo_0 == "const QString" && tmp_oo_1 == "const QString") {
				QTime return_object = (QTime) obj->fromString((const QString&) var_oo_0, (const QString&) var_oo_1);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QTime_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			}
		}
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  second
 *    flags:    c
 */
ZEND_METHOD(QTime, second){
	if (ZEND_NUM_ARGS() == 0){
			QTime *obj = (QTime*) PHP_QT_FETCH();
			RETURN_LONG(obj->second());
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  QTime
 *    flags:    
 */
ZEND_METHOD(QTime, __construct){
	if (ZEND_NUM_ARGS() == 0){
			QTime *QTime_ptr = new QTime();
			PHP_QT_REGISTER(QTime_ptr);
			RETURN_NULL();
	}

	if (ZEND_NUM_ARGS() == 4){
		/* llll public*/
		long var_llll_0;    // default: 
		long var_llll_1;    // default: 
		long var_llll_2;    // default: 0
		long var_llll_3;    // default: 0

		/* int h, int m, int s, int ms,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lll|l|", &var_llll_0, &var_llll_1, &var_llll_2, &var_llll_3) == SUCCESS) {

			
			QTime *QTime_ptr = new QTime((int) var_llll_0 ,(int) var_llll_1 ,(int) var_llll_2 ,(int) var_llll_3);
			PHP_QT_REGISTER(QTime_ptr);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  addSecs
 *    flags:    c
 */
ZEND_METHOD(QTime, addSecs){

	if (ZEND_NUM_ARGS() == 1){
		/* l public*/
		long var_l_0;    // default: 

		/* int secs,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QTime *obj = (QTime*) PHP_QT_FETCH();

			
			QTime return_object = (QTime) obj->addSecs((int) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QTime_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  addMSecs
 *    flags:    c
 */
ZEND_METHOD(QTime, addMSecs){

	if (ZEND_NUM_ARGS() == 1){
		/* l public*/
		long var_l_0;    // default: 

		/* int ms,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QTime *obj = (QTime*) PHP_QT_FETCH();

			
			QTime return_object = (QTime) obj->addMSecs((int) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QTime_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  currentTime
 *    flags:    s
 */
ZEND_METHOD(QTime, currentTime){
	if (ZEND_NUM_ARGS() == 0){
			QTime *obj = (QTime*) PHP_QT_FETCH();
			QTime return_object = (QTime) obj->currentTime();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QTime_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  minute
 *    flags:    c
 */
ZEND_METHOD(QTime, minute){
	if (ZEND_NUM_ARGS() == 0){
			QTime *obj = (QTime*) PHP_QT_FETCH();
			RETURN_LONG(obj->minute());
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  setHMS
 *    flags:    
 */
ZEND_METHOD(QTime, setHMS){

	if (ZEND_NUM_ARGS() == 4){
		/* llll public*/
		long var_llll_0;    // default: 
		long var_llll_1;    // default: 
		long var_llll_2;    // default: 
		long var_llll_3;    // default: 0

		/* int h, int m, int s, int ms,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"llll|", &var_llll_0, &var_llll_1, &var_llll_2, &var_llll_3) == SUCCESS) {
			QTime *obj = (QTime*) PHP_QT_FETCH();

			
			RETURN_BOOL(obj->setHMS((int) var_llll_0 ,(int) var_llll_1 ,(int) var_llll_2 ,(int) var_llll_3));
		}
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  isNull
 *    flags:    c
 */
ZEND_METHOD(QTime, isNull){
	if (ZEND_NUM_ARGS() == 0){
			QTime *obj = (QTime*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isNull());
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  msecsTo
 *    flags:    c
 */
ZEND_METHOD(QTime, msecsTo){

	if (ZEND_NUM_ARGS() == 1){
		/* o public*/
		zval* z_var_o_0;   // default: 

		/* const QTime& ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QTime *obj = (QTime*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QTime") {
				RETURN_LONG(obj->msecsTo((const QTime&) var_o_0));
			}
		}
	}
}

/*********************************
 *    class     QTime */
/*
 *    function  start
 *    flags:    
 */
ZEND_METHOD(QTime, start){
	if (ZEND_NUM_ARGS() == 0){
			QTime *obj = (QTime*) PHP_QT_FETCH();
			obj->start();
			RETURN_NULL();
	}
}


PHP_QT_DESTRUCT(QTime);

