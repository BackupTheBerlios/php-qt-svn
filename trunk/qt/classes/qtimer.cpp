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
 * QTimer.cpp - QTimer PHP implementation.
 * begin           : Wed Jan 11 20:29:53 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QTimer>
#include "../php_qt.h"


/*********************************
 *    class     QTimer */
/*
 *    function  tr
 *    flags:    s
 */
ZEND_METHOD(QTimer, tr){

	if (ZEND_NUM_ARGS() == 2){
		/* ss */
		char* var_ss_0;   // default: 
		int len_ss_0;

		char* var_ss_1;   // default: 0
		int len_ss_1;


		/* const char* , const char* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ss|", &var_ss_0, len_ss_0, &var_ss_1, len_ss_1) == SUCCESS) {
			QTimer *obj = (QTimer*) PHP_QT_FETCH();

			
			QString return_object = (QString) obj->tr( (const char*) var_ss_0 , (const char*) var_ss_1);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QTimer_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  qt_invoke
 *    flags:    v
 */
ZEND_METHOD(QTimer, qt_invoke){

/*	if (ZEND_NUM_ARGS() == 2){

		long var_lo_0;    // default: 
		zval* z_var_lo_1;   // default: 


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo", &var_lo_0, &z_var_lo_1) == SUCCESS) {
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			QObject* var_lo_1 = (QObject*) php_qt_fetch(z_var_lo_1);

			QString tmp_lo_0(var_lo_1->metaObject()->className());
			
			if(tmp_lo_0 == "QUObject*") {
				RETURN_BOOL(obj->qt_invoke((int) var_lo_0, (QUObject*) var_lo_1));
			}
		}
	}*/
}

/*********************************
 *    class     QTimer */
/*
 *    function  staticMetaObject
 *    flags:    s
 */
ZEND_METHOD(QTimer, staticMetaObject){
/*	if (ZEND_NUM_ARGS() == 0){
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			QMetaObject* return_object = (QMetaObject*) obj->staticMetaObject();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QTimer_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}*/
}

/*********************************
 *    class     QTimer */
/*
 *    function  setInterval
 *    flags:    
 */
ZEND_METHOD(QTimer, setInterval){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int msec,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QTimer *obj = (QTimer*) PHP_QT_FETCH();

			
			obj->setInterval((int) var_l_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  qObject
 *    flags:    
 */
ZEND_METHOD(QTimer, qObject){
/*	if (ZEND_NUM_ARGS() == 0){
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			QObject* return_object = (QObject*) obj->qObject();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QTimer_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}*/
}

/*********************************
 *    class     QTimer */
/*
 *    function  timerId
 *    flags:    c
 */
ZEND_METHOD(QTimer, timerId){
	if (ZEND_NUM_ARGS() == 0){
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			RETURN_LONG(obj->timerId());
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  singleShot
 *    flags:    s
 */
ZEND_METHOD(QTimer, singleShot){

	if (ZEND_NUM_ARGS() == 3){
		/* los */
		long var_los_0;    // default: 
		zval* z_var_los_1;   // default: 
		char* var_los_2;   // default: 
		int len_los_2;


		/* int msec, QObject* receiver, const char* member,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"los", &var_los_0, &z_var_los_1, &var_los_2, len_los_2) == SUCCESS) {
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			QObject* var_los_1 = (QObject*) php_qt_fetch(z_var_los_1);

			QString tmp_los_0(var_los_1->metaObject()->className());
			
			if(tmp_los_0 == "QObject*") {
				obj->singleShot((int) var_los_0, (QObject*) var_los_1, (const char*) var_los_2);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  qt_cast
 *    flags:    v
 */
ZEND_METHOD(QTimer, qt_cast){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int len_s_0;


		/* const char* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_s_0, len_s_0) == SUCCESS) {
			QTimer *obj = (QTimer*) PHP_QT_FETCH();

			
//			obj->qt_cast( (const char*) var_s_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  metaObject
 *    flags:    cv
 */
ZEND_METHOD(QTimer, metaObject){
	if (ZEND_NUM_ARGS() == 0){
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			QMetaObject * return_object = (QMetaObject *) obj->metaObject();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QTimer_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  stop
 *    flags:    l
 */
ZEND_METHOD(QTimer, stop){
	if (ZEND_NUM_ARGS() == 0){
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			obj->stop();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  isActive
 *    flags:    c
 */
ZEND_METHOD(QTimer, isActive){
	if (ZEND_NUM_ARGS() == 0){
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isActive());
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  QTimer
 *    flags:    t
 */
ZEND_METHOD(QTimer, __construct){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 0

		/* QObject* parent,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o|", &z_var_o_0) == SUCCESS) {
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "QObject*") {
				QTimer *QTimer_ptr = new QTimer((QObject*) var_o_0);
			PHP_QT_REGISTER(QTimer_ptr);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  qt_emit
 *    flags:    v
 */
ZEND_METHOD(QTimer, qt_emit){

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* z_var_lo_1;   // default: 

		/* int , QUObject* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo", &var_lo_0, &z_var_lo_1) == SUCCESS) {
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			QObject* var_lo_1 = (QObject*) php_qt_fetch(z_var_lo_1);

			QString tmp_lo_0(var_lo_1->metaObject()->className());
			
/*			if(tmp_lo_0 == "QUObject*") {
				RETURN_BOOL(obj->qt_emit((int) var_lo_0, (QUObject*) var_lo_1));
			}*/
		}
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  interval
 *    flags:    c
 */
ZEND_METHOD(QTimer, interval){
	if (ZEND_NUM_ARGS() == 0){
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			RETURN_LONG(obj->interval());
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  setSingleShot
 *    flags:    
 */
ZEND_METHOD(QTimer, setSingleShot){

	if (ZEND_NUM_ARGS() == 1){
		/* b */
		bool var_b_0;   // _default: 

		/* bool singleShot,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b", &var_b_0) == SUCCESS) {
			QTimer *obj = (QTimer*) PHP_QT_FETCH();

			
			obj->setSingleShot((bool) var_b_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  className
 *    flags:    cv
 */
ZEND_METHOD(QTimer, className){
/*	if (ZEND_NUM_ARGS() == 0){
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			const char * return_object = (const char *) obj->className();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QTimer_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}*/
}

/*********************************
 *    class     QTimer */
/*
 *    function  trUtf8
 *    flags:    s
 */
ZEND_METHOD(QTimer, trUtf8){

	if (ZEND_NUM_ARGS() == 2){
		/* ss */
		char* var_ss_0;   // default: 
		int len_ss_0;

		char* var_ss_1;   // default: 0
		int len_ss_1;


		/* const char* , const char* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ss|", &var_ss_0, len_ss_0, &var_ss_1, len_ss_1) == SUCCESS) {
			QTimer *obj = (QTimer*) PHP_QT_FETCH();

			
			QString return_object = (QString) obj->trUtf8( (const char*) var_ss_0 , (const char*) var_ss_1);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QTimer_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  qt_property
 *    flags:    v
 */
ZEND_METHOD(QTimer, qt_property){

	if (ZEND_NUM_ARGS() == 3){
		/* llo */
		long var_llo_0;    // default: 
		long var_llo_1;    // default: 
		zval* z_var_llo_2;   // default: 

		/* int , int , QVariant* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"llo", &var_llo_0, &var_llo_1, &z_var_llo_2) == SUCCESS) {
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			QObject* var_llo_2 = (QObject*) php_qt_fetch(z_var_llo_2);

			QString tmp_llo_0(var_llo_2->metaObject()->className());
			
/*			if(tmp_llo_0 == "QVariant*") {
				RETURN_BOOL(obj->qt_property((int) var_llo_0, (int) var_llo_1, (QVariant*) var_llo_2));
			}*/
		}
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  isSingleShot
 *    flags:    c
 */
ZEND_METHOD(QTimer, isSingleShot){
	if (ZEND_NUM_ARGS() == 0){
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isSingleShot());
	}
}

/*********************************
 *    class     QTimer */
/*
 *    function  start
 *    flags:    l
 */
ZEND_METHOD(QTimer, start){
	if (ZEND_NUM_ARGS() == 0){
			QTimer *obj = (QTimer*) PHP_QT_FETCH();
			obj->start();
			RETURN_NULL();
	}

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int msec,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QTimer *obj = (QTimer*) PHP_QT_FETCH();

			
			obj->start((int) var_l_0);
			RETURN_NULL();
		}
	}
}


PHP_QT_DESTRUCT(QTimer);

