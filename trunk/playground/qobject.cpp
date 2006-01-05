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
 * QObject.cpp - QObject PHP implementation.
 * begin           : Fri Jan  6 00:06:34 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include "../php_qt.h"

/*********************************
 *    class     QObject */
/*
 *    function  removeEventFilter
 *    flags:    
 */
ZEND_METHOD(QObject, removeEventFilter){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "QObject*") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			obj->removeEventFilter((QObject*) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  connectNotify
 *    flags:    v
 */
ZEND_METHOD(QObject, connectNotify){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int* len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_0, &len_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();

			
			QObject *obj = (QObject) PHP_QT_FETCH();
			obj->connectNotify( var_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  tr
 *    flags:    s
 */
ZEND_METHOD(QObject, tr){

	if (ZEND_NUM_ARGS() == 2){
		/* ss */
		char* var_ss_0;   // default: 
		int* len_ss_0;

		char* var_ss_1;   // default: 0
		int* len_ss_1;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ss|", &var_0, &len_0, &var_1, &len_1) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();

									
			QObject *obj = (QObject) PHP_QT_FETCH();
			QString return_object = (QString) obj->tr( var_0 , var_1);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QObject_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  disconnect
 *    flags:    
 */
ZEND_METHOD(QObject, disconnect){

	if (ZEND_NUM_ARGS() == 2){
		/* os */
		zval* var_os_0;   // default: 
		char* var_os_1;   // default: 0
		int* len_os_1;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"os|", &var_os_0, &var_1, &len_1) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "const QObject*") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->disconnect((const QObject*) var_o_0, (const char*) var_os_1));
			}
		}
	}

	if (ZEND_NUM_ARGS() == 3){
		/* sos */
		char* var_sos_0;   // default: 0
		int* len_sos_0;

		zval* var_sos_1;   // default: 0
		char* var_sos_2;   // default: 0
		int* len_sos_2;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s|o|s|", &var_0, &len_0, &var_sos_1, &var_2, &len_2) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_1 = (QObject*) php_qt_fetch(var_o_1);

			QString tmp_0(var_o_1->metaObject()->className());
			
			if(tmp_0 == "const QObject*") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->disconnect((const char*) var_sos_0, (const QObject*) var_o_1, (const char*) var_sos_1));
			}
		}
	}

	if (ZEND_NUM_ARGS() == 4){
		/* osos */
		zval* var_osos_0;   // default: 
		char* var_osos_1;   // default: 
		int* len_osos_1;

		zval* var_osos_2;   // default: 
		char* var_osos_3;   // default: 
		int* len_osos_3;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"osos", &var_osos_0, &var_1, &len_1, &var_osos_2, &var_3, &len_3) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);
			QObject* var_o_2 = (QObject*) php_qt_fetch(var_o_2);

			QString tmp_0(var_o_0->metaObject()->className());
			QString tmp_1(var_o_2->metaObject()->className());
			
			if(tmp_0 == "const QObject*" && tmp_1 == "const QObject*") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->disconnect((const QObject*) var_o_0, (const char*) var_osos_1, (const QObject*) var_o_2, (const char*) var_osos_2));
			}
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  children
 *    flags:    c
 */
ZEND_METHOD(QObject, children){
			QObject *obj = (QObject) PHP_QT_FETCH();
			const QObjectList & return_object = (const QObjectList &) obj->children();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QObject_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QObject */
/*
 *    function  qt_invoke
 *    flags:    v
 */
ZEND_METHOD(QObject, qt_invoke){

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* var_lo_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo", &var_lo_0, &var_lo_1) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_1 = (QObject*) php_qt_fetch(var_o_1);

			QString tmp_0(var_o_1->metaObject()->className());
			
			if(tmp_0 == "QUObject*") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->qt_invoke((int) var_lo_0, (QUObject*) var_o_1));
			}
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  deleteLater
 *    flags:    l
 */
ZEND_METHOD(QObject, deleteLater){
			QObject *obj = (QObject) PHP_QT_FETCH();
			obj->deleteLater();
			RETURN_NULL();
}

/*********************************
 *    class     QObject */
/*
 *    function  installEventFilter
 *    flags:    
 */
ZEND_METHOD(QObject, installEventFilter){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "QObject*") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			obj->installEventFilter((QObject*) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  qt_cast
 *    flags:    v
 */
ZEND_METHOD(QObject, qt_cast){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int* len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_0, &len_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();

			
			QObject *obj = (QObject) PHP_QT_FETCH();
			obj->qt_cast( var_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  setProperty
 *    flags:    
 */
ZEND_METHOD(QObject, setProperty){

	if (ZEND_NUM_ARGS() == 2){
		/* so */
		char* var_so_0;   // default: 
		int* len_so_0;

		zval* var_so_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"so", &var_0, &len_0, &var_so_1) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_1 = (QObject*) php_qt_fetch(var_o_1);

			QString tmp_0(var_o_1->metaObject()->className());
			
			if(tmp_0 == "const QVariant&") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->setProperty((const char*) var_so_0, (const QVariant&) var_o_1));
			}
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  disconnectNotify
 *    flags:    v
 */
ZEND_METHOD(QObject, disconnectNotify){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int* len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_0, &len_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();

			
			QObject *obj = (QObject) PHP_QT_FETCH();
			obj->disconnectNotify( var_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  property
 *    flags:    c
 */
ZEND_METHOD(QObject, property){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int* len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_0, &len_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();

			
			QObject *obj = (QObject) PHP_QT_FETCH();
			QVariant return_object = (QVariant) obj->property( var_0);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QObject_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  dumpObjectInfo
 *    flags:    
 */
ZEND_METHOD(QObject, dumpObjectInfo){
			QObject *obj = (QObject) PHP_QT_FETCH();
			obj->dumpObjectInfo();
			RETURN_NULL();
}

/*********************************
 *    class     QObject */
/*
 *    function  registerUserData
 *    flags:    s
 */
ZEND_METHOD(QObject, registerUserData){
			QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_LONG(obj->registerUserData());
}

/*********************************
 *    class     QObject */
/*
 *    function  metaObject
 *    flags:    cv
 */
ZEND_METHOD(QObject, metaObject){
			QObject *obj = (QObject) PHP_QT_FETCH();
			QMetaObject * return_object = (QMetaObject *) obj->metaObject();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QObject_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
			QObject *obj = (QObject) PHP_QT_FETCH();
			const QMetaObject * return_object = (const QMetaObject *) obj->metaObject();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QObject_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QObject */
/*
 *    function  parent
 *    flags:    c
 */
ZEND_METHOD(QObject, parent){
			QObject *obj = (QObject) PHP_QT_FETCH();
			QObject * return_object = (QObject *) obj->parent();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QObject_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QObject */
/*
 *    function  receivers
 *    flags:    c
 */
ZEND_METHOD(QObject, receivers){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int* len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_0, &len_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();

			
			QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_LONG(obj->receivers( var_0));
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  qt_emit
 *    flags:    v
 */
ZEND_METHOD(QObject, qt_emit){

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* var_lo_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo", &var_lo_0, &var_lo_1) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_1 = (QObject*) php_qt_fetch(var_o_1);

			QString tmp_0(var_o_1->metaObject()->className());
			
			if(tmp_0 == "QUObject*") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->qt_emit((int) var_lo_0, (QUObject*) var_o_1));
			}
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  event
 *    flags:    v
 */
ZEND_METHOD(QObject, event){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "QEvent*") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->event((QEvent*) var_o_0));
			}
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  className
 *    flags:    cv
 */
ZEND_METHOD(QObject, className){
			QObject *obj = (QObject) PHP_QT_FETCH();
			const char * return_object = (const char *) obj->className();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QObject_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QObject */
/*
 *    function  thread
 *    flags:    c
 */
ZEND_METHOD(QObject, thread){
			QObject *obj = (QObject) PHP_QT_FETCH();
			QThread * return_object = (QThread *) obj->thread();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QObject_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QObject */
/*
 *    function  isWidgetType
 *    flags:    c
 */
ZEND_METHOD(QObject, isWidgetType){
			QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->isWidgetType());
}

/*********************************
 *    class     QObject */
/*
 *    function  sender
 *    flags:    c
 */
ZEND_METHOD(QObject, sender){
			QObject *obj = (QObject) PHP_QT_FETCH();
			QObject * return_object = (QObject *) obj->sender();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QObject_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QObject */
/*
 *    function  signalsBlocked
 *    flags:    c
 */
ZEND_METHOD(QObject, signalsBlocked){
			QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->signalsBlocked());
}

/*********************************
 *    class     QObject */
/*
 *    function  staticMetaObject
 *    flags:    s
 */
ZEND_METHOD(QObject, staticMetaObject){
			QObject *obj = (QObject) PHP_QT_FETCH();
			QMetaObject* return_object = (QMetaObject*) obj->staticMetaObject();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QObject_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QObject */
/*
 *    function  setUserData
 *    flags:    
 */
ZEND_METHOD(QObject, setUserData){

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* var_lo_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo", &var_lo_0, &var_lo_1) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_1 = (QObject*) php_qt_fetch(var_o_1);

			QString tmp_0(var_o_1->metaObject()->className());
			
			if(tmp_0 == "QObjectUserData*") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			obj->setUserData((uint) var_lo_0, (QObjectUserData*) var_o_1);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  userData
 *    flags:    c
 */
ZEND_METHOD(QObject, userData){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();

			
			QObject *obj = (QObject) PHP_QT_FETCH();
			QObjectUserData* return_object = (QObjectUserData*) obj->userData((uint) var_l_0);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QObject_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  qObject
 *    flags:    
 */
ZEND_METHOD(QObject, qObject){
			QObject *obj = (QObject) PHP_QT_FETCH();
			QObject* return_object = (QObject*) obj->qObject();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QObject_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QObject */
/*
 *    function  setObjectName
 *    flags:    
 */
ZEND_METHOD(QObject, setObjectName){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "const QString&") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			obj->setObjectName((const QString&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  killTimer
 *    flags:    
 */
ZEND_METHOD(QObject, killTimer){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();

			
			QObject *obj = (QObject) PHP_QT_FETCH();
			obj->killTimer((int) var_l_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  setParent
 *    flags:    
 */
ZEND_METHOD(QObject, setParent){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "QObject*") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			obj->setParent((QObject*) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  moveToThread
 *    flags:    
 */
ZEND_METHOD(QObject, moveToThread){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "QThread*") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			obj->moveToThread((QThread*) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  connect
 *    flags:    c
 */
ZEND_METHOD(QObject, connect){

	if (ZEND_NUM_ARGS() == 4){
		/* osso */
		zval* var_osso_0;   // default: 
		char* var_osso_1;   // default: 
		int* len_osso_1;

		char* var_osso_2;   // default: 
		int* len_osso_2;

		zval* var_osso_3;   // default: Qt::AutoConnection

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"osso|", &var_osso_0, &var_1, &len_1, &var_2, &len_2, &var_osso_3) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);
			QObject* var_o_3 = (QObject*) php_qt_fetch(var_o_3);

			QString tmp_0(var_o_0->metaObject()->className());
			QString tmp_1(var_o_3->metaObject()->className());
			
			if(tmp_0 == "const QObject*" && tmp_1 == "Qt::ConnectionType") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->connect((const QObject*) var_o_0, (const char*) var_osso_1, (const char*) var_osso_1, (Qt::ConnectionType) var_o_3));
			}
		}
	}

	if (ZEND_NUM_ARGS() == 5){
		/* ososo */
		zval* var_ososo_0;   // default: 
		char* var_ososo_1;   // default: 
		int* len_ososo_1;

		zval* var_ososo_2;   // default: 
		char* var_ososo_3;   // default: 
		int* len_ososo_3;

		zval* var_ososo_4;   // default: Qt::AutoConnection

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ososo|", &var_ososo_0, &var_1, &len_1, &var_ososo_2, &var_3, &len_3, &var_ososo_4) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);
			QObject* var_o_2 = (QObject*) php_qt_fetch(var_o_2);
			QObject* var_o_4 = (QObject*) php_qt_fetch(var_o_4);

			QString tmp_0(var_o_0->metaObject()->className());
			QString tmp_1(var_o_2->metaObject()->className());
			QString tmp_2(var_o_4->metaObject()->className());
			
			if(tmp_0 == "const QObject*" && tmp_1 == "const QObject*" && tmp_2 == "Qt::ConnectionType") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->connect((const QObject*) var_o_0, (const char*) var_ososo_1, (const QObject*) var_o_2, (const char*) var_ososo_2, (Qt::ConnectionType) var_o_4));
			}
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  blockSignals
 *    flags:    
 */
ZEND_METHOD(QObject, blockSignals){

	if (ZEND_NUM_ARGS() == 1){
		/* b */
		bool* var_b_0;   // _default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b", &var_b_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();

			
			QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->blockSignals((bool) var_b_0));
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  objectName
 *    flags:    c
 */
ZEND_METHOD(QObject, objectName){
			QObject *obj = (QObject) PHP_QT_FETCH();
			QString return_object = (QString) obj->objectName();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QObject_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QObject */
/*
 *    function  QObject
 *    flags:    v
 */
ZEND_METHOD(QObject, QObject){
			QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_~(obj->QObject());
}

/*********************************
 *    class     QObject */
/*
 *    function  dumpObjectTree
 *    flags:    
 */
ZEND_METHOD(QObject, dumpObjectTree){
			QObject *obj = (QObject) PHP_QT_FETCH();
			obj->dumpObjectTree();
			RETURN_NULL();
}

/*********************************
 *    class     QObject */
/*
 *    function  startTimer
 *    flags:    
 */
ZEND_METHOD(QObject, startTimer){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();

			
			QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_LONG(obj->startTimer((int) var_l_0));
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  inherits
 *    flags:    c
 */
ZEND_METHOD(QObject, inherits){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int* len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_0, &len_0) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();

			
			QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->inherits( var_0));
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  eventFilter
 *    flags:    v
 */
ZEND_METHOD(QObject, eventFilter){

	if (ZEND_NUM_ARGS() == 2){
		/* oo */
		zval* var_oo_0;   // default: 
		zval* var_oo_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oo", &var_oo_0, &var_oo_1) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);
			QObject* var_o_1 = (QObject*) php_qt_fetch(var_o_1);

			QString tmp_0(var_o_0->metaObject()->className());
			QString tmp_1(var_o_1->metaObject()->className());
			
			if(tmp_0 == "QObject*" && tmp_1 == "QEvent*") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->eventFilter((QObject*) var_o_0, (QEvent*) var_o_1));
			}
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  trUtf8
 *    flags:    s
 */
ZEND_METHOD(QObject, trUtf8){

	if (ZEND_NUM_ARGS() == 2){
		/* ss */
		char* var_ss_0;   // default: 
		int* len_ss_0;

		char* var_ss_1;   // default: 0
		int* len_ss_1;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ss|", &var_0, &len_0, &var_1, &len_1) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();

									
			QObject *obj = (QObject) PHP_QT_FETCH();
			QString return_object = (QString) obj->trUtf8( var_0 , var_1);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QObject_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
		}
	}
}

/*********************************
 *    class     QObject */
/*
 *    function  qt_property
 *    flags:    v
 */
ZEND_METHOD(QObject, qt_property){

	if (ZEND_NUM_ARGS() == 3){
		/* llo */
		long var_llo_0;    // default: 
		long var_llo_1;    // default: 
		zval* var_llo_2;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"llo", &var_llo_0, &var_llo_1, &var_llo_2) == SUCCESS) {
			QObject *obj = (QObject*) PHP_QT_FETCH();
			QObject* var_o_2 = (QObject*) php_qt_fetch(var_o_2);

			QString tmp_0(var_o_2->metaObject()->className());
			
			if(tmp_0 == "QVariant*") {
				QObject *obj = (QObject) PHP_QT_FETCH();
			RETURN_BOOL(obj->qt_property((int) var_llo_0, (int) var_llo_0, (QVariant*) var_o_2));
			}
		}
	}
}



ZEND_METHOD(QObject,__construct){

	QObject *QObject_ptr = new QObject();

	if(ZEND_NUM_ARGS() == 1){
		zval* param_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param_1) == FAILURE) {
			return;
		}
		 /*zval* parent QObject**/
		if(Z_TYPE_P(param_0) == IS_OBJECT) {
			QObject* tmp(Z_STRVAL_P(param_0));
			QObject_ptr = new QObject(tmp);
		}
	}

	if(ZEND_NUM_ARGS() == 2){
		zval* param_0;
		zval* param_1;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &param_1, &param_2) == FAILURE) {
			return;
		}
		 /*zval* dd QObjectPrivate&*/
		if(Z_TYPE_P(param_0) == IS_OBJECT) {
			QObjectPrivate& tmp(Z_STRVAL_P(param_0));
			QObject_ptr = new QObject(tmp);
		}
		 /*zval* parent QObject**/
		if(Z_TYPE_P(param_1) == IS_OBJECT) {
			QObject* tmp(Z_STRVAL_P(param_1));
			QObject_ptr = new QObject(tmp);
		}
	}

	PHP_QT_REGISTER(QObject_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QObject);

