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
 * QLCDNumber.cpp - QLCDNumber PHP implementation.
 * begin           : Wed Jan 11 20:29:53 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QLCDNumber>
#include "../php_qt.h"



/*		public enumMode:long {
			Mode = 0,
			Mode = 1,
			Mode = 2,
			Mode = 3
		}
*/

/*		public enumSegmentStyle:long {
			SegmentStyle = 0,
			SegmentStyle = 1,
			SegmentStyle = 2
		}
*/
/*********************************
 *    class     QLCDNumber */
/*
 *    function  tr
 *    flags:    s
 */
ZEND_METHOD(QLCDNumber, tr){

	if (ZEND_NUM_ARGS() == 2){
		/* ss */
		char* var_ss_0;   // default: 
		int len_ss_0;

		char* var_ss_1;   // default: 0
		int len_ss_1;


		/* const char* , const char* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ss|", &var_ss_0, len_ss_0, &var_ss_1, len_ss_1) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();

			
			QString return_object = (QString) obj->tr( (const char*) var_ss_0 , (const char*) var_ss_1);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLCDNumber_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  segmentStyle
 *    flags:    c
 */
ZEND_METHOD(QLCDNumber, segmentStyle){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			RETURN_LONG(obj->segmentStyle());
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  mode
 *    flags:    c
 */
ZEND_METHOD(QLCDNumber, mode){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			RETURN_LONG(obj->mode());
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  checkOverflow
 *    flags:    c
 */
ZEND_METHOD(QLCDNumber, checkOverflow){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int num,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();

			
			RETURN_BOOL(obj->checkOverflow((int) var_l_0));
		}
		/* o */
		zval* z_var_o_1;   // default: 

		/* double num,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_1) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			QObject* var_o_1 = (QObject*) php_qt_fetch(z_var_o_1);

			QString tmp_o_0(var_o_1->metaObject()->className());
			
			if(tmp_o_0 == "double") {
				RETURN_BOOL(obj->checkOverflow((double) var_o_1));
			}
		}
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  qt_invoke
 *    flags:    v
 */
ZEND_METHOD(QLCDNumber, qt_invoke){

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* z_var_lo_1;   // default: 

		/* int , QUObject* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo", &var_lo_0, &z_var_lo_1) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			QObject* var_lo_1 = (QObject*) php_qt_fetch(z_var_lo_1);

			QString tmp_lo_0(var_lo_1->metaObject()->className());
			
			if(tmp_lo_0 == "QUObject*") {
				RETURN_BOOL(obj->qt_invoke((int) var_lo_0, (QUObject*) var_lo_1));
			}
		}
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  staticMetaObject
 *    flags:    s
 */
ZEND_METHOD(QLCDNumber, staticMetaObject){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			QMetaObject* return_object = (QMetaObject*) obj->staticMetaObject();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLCDNumber_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  setOctMode
 *    flags:    l
 */
ZEND_METHOD(QLCDNumber, setOctMode){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			obj->setOctMode();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  display
 *    flags:    l
 */
ZEND_METHOD(QLCDNumber, display){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int num,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();

			
			obj->display((int) var_l_0);
			RETURN_NULL();
		}
		/* o */
		zval* z_var_o_1;   // default: 

		/* const QString& str,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_1) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			QObject* var_o_1 = (QObject*) php_qt_fetch(z_var_o_1);

			QString tmp_o_0(var_o_1->metaObject()->className());
			
			if(tmp_o_0 == "const QString&") {
				obj->display((const QString&) var_o_1);
			RETURN_NULL();
			}			
			if(tmp_o_0 == "double") {
				obj->display((double) var_o_1);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  setSegmentStyle
 *    flags:    
 */
ZEND_METHOD(QLCDNumber, setSegmentStyle){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		/* SegmentStyle ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "SegmentStyle") {
				obj->setSegmentStyle((SegmentStyle) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  setHexMode
 *    flags:    l
 */
ZEND_METHOD(QLCDNumber, setHexMode){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			obj->setHexMode();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  qObject
 *    flags:    
 */
ZEND_METHOD(QLCDNumber, qObject){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			QObject* return_object = (QObject*) obj->qObject();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLCDNumber_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  setSmallDecimalPoint
 *    flags:    l
 */
ZEND_METHOD(QLCDNumber, setSmallDecimalPoint){

	if (ZEND_NUM_ARGS() == 1){
		/* b */
		bool var_b_0;   // _default: 

		/* bool ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b", &var_b_0) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();

			
			obj->setSmallDecimalPoint((bool) var_b_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  sizeHint
 *    flags:    c
 */
ZEND_METHOD(QLCDNumber, sizeHint){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			QSize return_object = (QSize) obj->sizeHint();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLCDNumber_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  qt_cast
 *    flags:    v
 */
ZEND_METHOD(QLCDNumber, qt_cast){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int len_s_0;


		/* const char* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_s_0, len_s_0) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();

			
			obj->qt_cast( (const char*) var_s_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  metaObject
 *    flags:    cv
 */
ZEND_METHOD(QLCDNumber, metaObject){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			QMetaObject * return_object = (QMetaObject *) obj->metaObject();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLCDNumber_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  value
 *    flags:    c
 */
ZEND_METHOD(QLCDNumber, value){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			RETURN_DOUBLE(obj->value());
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  setDecMode
 *    flags:    l
 */
ZEND_METHOD(QLCDNumber, setDecMode){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			obj->setDecMode();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  qt_emit
 *    flags:    v
 */
ZEND_METHOD(QLCDNumber, qt_emit){

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* z_var_lo_1;   // default: 

		/* int , QUObject* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo", &var_lo_0, &z_var_lo_1) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			QObject* var_lo_1 = (QObject*) php_qt_fetch(z_var_lo_1);

			QString tmp_lo_0(var_lo_1->metaObject()->className());
			
			if(tmp_lo_0 == "QUObject*") {
				RETURN_BOOL(obj->qt_emit((int) var_lo_0, (QUObject*) var_lo_1));
			}
		}
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  className
 *    flags:    cv
 */
ZEND_METHOD(QLCDNumber, className){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			const char * return_object = (const char *) obj->className();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLCDNumber_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  intValue
 *    flags:    c
 */
ZEND_METHOD(QLCDNumber, intValue){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			RETURN_LONG(obj->intValue());
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  QLCDNumber
 *    flags:    t
 */
ZEND_METHOD(QLCDNumber, __construct){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 0

		/* QWidget* parent,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o|", &z_var_o_0) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "QWidget*") {
				QLCDNumber *QLCDNumber_ptr = new QLCDNumber((QWidget*) var_o_0);
			PHP_QT_REGISTER(QLCDNumber_ptr);
			RETURN_NULL();
			}
		}
	}

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* z_var_lo_1;   // default: 0

		/* uint numDigits, QWidget* parent,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo|", &var_lo_0, &z_var_lo_1) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			QObject* var_lo_1 = (QObject*) php_qt_fetch(z_var_lo_1);

			QString tmp_lo_0(var_lo_1->metaObject()->className());
			
			if(tmp_lo_0 == "QWidget*") {
				QLCDNumber *QLCDNumber_ptr = new QLCDNumber((uint) var_lo_0, (QWidget*) var_lo_1);
			PHP_QT_REGISTER(QLCDNumber_ptr);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  setNumDigits
 *    flags:    
 */
ZEND_METHOD(QLCDNumber, setNumDigits){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int nDigits,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();

			
			obj->setNumDigits((int) var_l_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  numDigits
 *    flags:    c
 */
ZEND_METHOD(QLCDNumber, numDigits){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			RETURN_LONG(obj->numDigits());
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  setMode
 *    flags:    
 */
ZEND_METHOD(QLCDNumber, setMode){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		/* Mode ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "Mode") {
				obj->setMode((Mode) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  trUtf8
 *    flags:    s
 */
ZEND_METHOD(QLCDNumber, trUtf8){

	if (ZEND_NUM_ARGS() == 2){
		/* ss */
		char* var_ss_0;   // default: 
		int len_ss_0;

		char* var_ss_1;   // default: 0
		int len_ss_1;


		/* const char* , const char* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ss|", &var_ss_0, len_ss_0, &var_ss_1, len_ss_1) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();

			
			QString return_object = (QString) obj->trUtf8( (const char*) var_ss_0 , (const char*) var_ss_1);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLCDNumber_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  qt_property
 *    flags:    v
 */
ZEND_METHOD(QLCDNumber, qt_property){

	if (ZEND_NUM_ARGS() == 3){
		/* llo */
		long var_llo_0;    // default: 
		long var_llo_1;    // default: 
		zval* z_var_llo_2;   // default: 

		/* int , int , QVariant* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"llo", &var_llo_0, &var_llo_1, &z_var_llo_2) == SUCCESS) {
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			QObject* var_llo_2 = (QObject*) php_qt_fetch(z_var_llo_2);

			QString tmp_llo_0(var_llo_2->metaObject()->className());
			
			if(tmp_llo_0 == "QVariant*") {
				RETURN_BOOL(obj->qt_property((int) var_llo_0, (int) var_llo_1, (QVariant*) var_llo_2));
			}
		}
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  smallDecimalPoint
 *    flags:    c
 */
ZEND_METHOD(QLCDNumber, smallDecimalPoint){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			RETURN_BOOL(obj->smallDecimalPoint());
	}
}

/*********************************
 *    class     QLCDNumber */
/*
 *    function  setBinMode
 *    flags:    l
 */
ZEND_METHOD(QLCDNumber, setBinMode){
	if (ZEND_NUM_ARGS() == 0){
			QLCDNumber *obj = (QLCDNumber*) PHP_QT_FETCH();
			obj->setBinMode();
			RETURN_NULL();
	}
}


PHP_QT_DESTRUCT(QLCDNumber);

