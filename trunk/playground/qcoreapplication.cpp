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
 * QCoreApplication.cpp - QCoreApplication PHP implementation.
 * begin           : Fri Jan  6 00:06:34 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include "../php_qt.h"

#include <QCoreApplication>



/*		public enumEncoding:long {
			Encoding = 0,
			Encoding = 1
		}
*/
/*********************************
 *    class     QCoreApplication */
/*
 *    function  removeTranslator
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, removeTranslator){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "QTranslator*") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->removeTranslator((QTranslator*) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  tr
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, tr){

	if (ZEND_NUM_ARGS() == 2){
		/* ss */
		char* var_ss_0;   // default: 
		int* len_ss_0;

		char* var_ss_1;   // default: 0
		int* len_ss_1;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ss|", &var_0, &len_0, &var_1, &len_1) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();

			
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			QString return_object = (QString) obj->tr( var_0 , var_1);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  installTranslator
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, installTranslator){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "QTranslator*") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->installTranslator((QTranslator*) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  startingUp
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, startingUp){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			RETURN_BOOL(obj->startingUp());
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  exit
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, exit){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 0

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l|", &var_l_0) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();

			
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->exit((int) var_l_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  qt_invoke
 *    flags:    v
 */
ZEND_METHOD(QCoreApplication, qt_invoke){

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* var_lo_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo", &var_lo_0, &var_lo_1) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_1 = (QObject*) php_qt_fetch(var_o_1);

			QString tmp_0(var_o_1->metaObject()->className());
			
			if(tmp_0 == "QUObject*") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			RETURN_BOOL(obj->qt_invoke((int) var_lo_0, (QUObject*) var_o_1));
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  addLibraryPath
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, addLibraryPath){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "const QString&") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->addLibraryPath((const QString&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  setOrganizationDomain
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, setOrganizationDomain){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "const QString&") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->setOrganizationDomain((const QString&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  argv
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, argv){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			char ** return_object = (char **) obj->argv();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  qt_cast
 *    flags:    v
 */
ZEND_METHOD(QCoreApplication, qt_cast){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int* len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_0, &len_0) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();

			
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->qt_cast( var_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  libraryPaths
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, libraryPaths){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			QStringList return_object = (QStringList) obj->libraryPaths();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  exec
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, exec){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			RETURN_LONG(obj->exec());
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  metaObject
 *    flags:    cv
 */
ZEND_METHOD(QCoreApplication, metaObject){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			QMetaObject * return_object = (QMetaObject *) obj->metaObject();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  setLibraryPaths
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, setLibraryPaths){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "const QStringList&") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->setLibraryPaths((const QStringList&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  bool
 *    flags:    
 */
ZEND_METHOD(QCoreApplication, bool){

	if (ZEND_NUM_ARGS() == 2){
		/* oo */
		zval* var_oo_0;   // default: 
		zval* var_oo_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oo", &var_oo_0, &var_oo_1) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);
			QObject* var_o_1 = (QObject*) php_qt_fetch(var_o_1);

			QString tmp_0(var_o_0->metaObject()->className());
			QString tmp_1(var_o_1->metaObject()->className());
			
			if(tmp_0 == "* EventFilter)(void*" && tmp_1 == "long*") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			RETURN_INTPTR(obj->bool((* EventFilter)(void*) var_o_0, (long*) var_o_1));
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  removeLibraryPath
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, removeLibraryPath){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "const QString&") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->removeLibraryPath((const QString&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  organizationName
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, organizationName){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			QString return_object = (QString) obj->organizationName();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  setOrganizationName
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, setOrganizationName){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "const QString&") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->setOrganizationName((const QString&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  event
 *    flags:    
 */
ZEND_METHOD(QCoreApplication, event){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "QEvent*") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			RETURN_BOOL(obj->event((QEvent*) var_o_0));
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  instance
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, instance){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			QCoreApplication * return_object = (QCoreApplication *) obj->instance();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  organizationDomain
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, organizationDomain){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			QString return_object = (QString) obj->organizationDomain();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  qt_emit
 *    flags:    v
 */
ZEND_METHOD(QCoreApplication, qt_emit){

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* var_lo_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo", &var_lo_0, &var_lo_1) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_1 = (QObject*) php_qt_fetch(var_o_1);

			QString tmp_0(var_o_1->metaObject()->className());
			
			if(tmp_0 == "QUObject*") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			RETURN_BOOL(obj->qt_emit((int) var_lo_0, (QUObject*) var_o_1));
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  hasPendingEvents
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, hasPendingEvents){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			RETURN_BOOL(obj->hasPendingEvents());
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  sendPostedEvents
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, sendPostedEvents){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->sendPostedEvents();
			RETURN_NULL();

	if (ZEND_NUM_ARGS() == 2){
		/* ol */
		zval* var_ol_0;   // default: 
		long var_ol_1;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ol", &var_ol_0, &var_ol_1) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "QObject*") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->sendPostedEvents((QObject*) var_o_0, (int) var_ol_1);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  className
 *    flags:    cv
 */
ZEND_METHOD(QCoreApplication, className){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			const char * return_object = (const char *) obj->className();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  applicationName
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, applicationName){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			QString return_object = (QString) obj->applicationName();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  flush
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, flush){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->flush();
			RETURN_NULL();
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  processEvents
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, processEvents){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: QEventLoop::AllEvents

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o|", &var_o_0) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "QEventLoop::ProcessEventsFlags") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->processEvents((QEventLoop::ProcessEventsFlags) var_o_0);
			RETURN_NULL();
			}
		}
	}

	if (ZEND_NUM_ARGS() == 2){
		/* ol */
		zval* var_ol_0;   // default: 
		long var_ol_1;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ol", &var_ol_0, &var_ol_1) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "QEventLoop::ProcessEventsFlags") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->processEvents((QEventLoop::ProcessEventsFlags) var_o_0, (int) var_ol_1);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  translate
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, translate){

	if (ZEND_NUM_ARGS() == 4){
		/* ssso */
		char* var_ssso_0;   // default: 
		int* len_ssso_0;

		char* var_ssso_1;   // default: 
		int* len_ssso_1;

		char* var_ssso_2;   // default: 0
		int* len_ssso_2;

		zval* var_ssso_3;   // default: DefaultCodec

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"sss|o|", &var_0, &len_0, &var_1, &len_1, &var_2, &len_2, &var_ssso_3) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_3 = (QObject*) php_qt_fetch(var_o_3);

			QString tmp_0(var_o_3->metaObject()->className());
			
			if(tmp_0 == "Encoding") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			QString return_object = (QString) obj->translate((const char*) var_ssso_0, (const char*) var_ssso_0, (const char*) var_ssso_0, (Encoding) var_o_3);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  applicationDirPath
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, applicationDirPath){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			QString return_object = (QString) obj->applicationDirPath();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  setEventFilter
 *    flags:    
 */
ZEND_METHOD(QCoreApplication, setEventFilter){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "EventFilter") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			RETURN_INTPTR(obj->setEventFilter((EventFilter) var_o_0));
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  staticMetaObject
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, staticMetaObject){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			QMetaObject* return_object = (QMetaObject*) obj->staticMetaObject();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  qObject
 *    flags:    
 */
ZEND_METHOD(QCoreApplication, qObject){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			QObject* return_object = (QObject*) obj->qObject();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  notify
 *    flags:    v
 */
ZEND_METHOD(QCoreApplication, notify){

	if (ZEND_NUM_ARGS() == 2){
		/* oo */
		zval* var_oo_0;   // default: 
		zval* var_oo_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oo", &var_oo_0, &var_oo_1) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);
			QObject* var_o_1 = (QObject*) php_qt_fetch(var_o_1);

			QString tmp_0(var_o_0->metaObject()->className());
			QString tmp_1(var_o_1->metaObject()->className());
			
			if(tmp_0 == "QObject*" && tmp_1 == "QEvent*") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			RETURN_BOOL(obj->notify((QObject*) var_o_0, (QEvent*) var_o_1));
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  argc
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, argc){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			RETURN_LONG(obj->argc());
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  quit
 *    flags:    sl
 */
ZEND_METHOD(QCoreApplication, quit){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->quit();
			RETURN_NULL();
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  QCoreApplication
 *    flags:    
 */
ZEND_METHOD(QCoreApplication, QCoreApplication){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			RETURN_~(obj->QCoreApplication());
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  watchUnixSignal
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, watchUnixSignal){

	if (ZEND_NUM_ARGS() == 2){
		/* lb */
		long var_lb_0;    // default: 
		bool* var_lb_1;   // _default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lb", &var_lb_0, &var_lb_1) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();

			
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->watchUnixSignal((int) var_lb_0 ,(bool) var_lb_1);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  removePostedEvents
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, removePostedEvents){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "QObject*") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->removePostedEvents((QObject*) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  applicationFilePath
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, applicationFilePath){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			QString return_object = (QString) obj->applicationFilePath();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  setApplicationName
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, setApplicationName){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_o_0) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(var_o_0);

			QString tmp_0(var_o_0->metaObject()->className());
			
			if(tmp_0 == "const QString&") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			obj->setApplicationName((const QString&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  trUtf8
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, trUtf8){

	if (ZEND_NUM_ARGS() == 2){
		/* ss */
		char* var_ss_0;   // default: 
		int* len_ss_0;

		char* var_ss_1;   // default: 0
		int* len_ss_1;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ss|", &var_0, &len_0, &var_1, &len_1) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();

			
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			QString return_object = (QString) obj->trUtf8( var_0 , var_1);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  qt_property
 *    flags:    v
 */
ZEND_METHOD(QCoreApplication, qt_property){

	if (ZEND_NUM_ARGS() == 3){
		/* llo */
		long var_llo_0;    // default: 
		long var_llo_1;    // default: 
		zval* var_llo_2;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"llo", &var_llo_0, &var_llo_1, &var_llo_2) == SUCCESS) {
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* var_o_2 = (QObject*) php_qt_fetch(var_o_2);

			QString tmp_0(var_o_2->metaObject()->className());
			
			if(tmp_0 == "QVariant*") {
				QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			RETURN_BOOL(obj->qt_property((int) var_llo_0, (int) var_llo_0, (QVariant*) var_o_2));
			}
		}
	}
}

/*********************************
 *    class     QCoreApplication */
/*
 *    function  closingDown
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, closingDown){
			QCoreApplication *obj = (QCoreApplication) PHP_QT_FETCH();
			RETURN_BOOL(obj->closingDown());
}



ZEND_METHOD(QCoreApplication,__construct){

	QCoreApplication *QCoreApplication_ptr = new QCoreApplication();

	if(ZEND_NUM_ARGS() == 2){
		zval* param_0;
		zval* param_1;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &param_1, &param_2) == FAILURE) {
			return;
		}
		 /*long argc int&*/
		if(Z_TYPE_P(param_0) == IS_LONG) {
			int& tmp(Z_STRVAL_P(param_0));
			QCoreApplication_ptr = new QCoreApplication(tmp);
		}
		 /*char argv char***/
		if(Z_TYPE_P(param_1) == IS_STRING) {
			char** tmp(Z_STRVAL_P(param_1));
			QCoreApplication_ptr = new QCoreApplication(tmp);
		}
	}

	if(ZEND_NUM_ARGS() == 1){
		zval* param_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param_1) == FAILURE) {
			return;
		}
		 /*zval* p QCoreApplicationPrivate&*/
		if(Z_TYPE_P(param_0) == IS_OBJECT) {
			QCoreApplicationPrivate& tmp(Z_STRVAL_P(param_0));
			QCoreApplication_ptr = new QCoreApplication(tmp);
		}
	}

	PHP_QT_REGISTER(QCoreApplication_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QCoreApplication);

