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
 * QCharRef.cpp - QCharRef PHP implementation.
 * begin           : Sun Jan  8 12:02:25 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QCharRef>
#include "../php_qt.h"


/*********************************
 *    class     QCharRef */
/*
 *    function  isDigit
 *    flags:    c
 */
ZEND_METHOD(QCharRef, isDigit){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isDigit());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  combiningClass
 *    flags:    c
 */
ZEND_METHOD(QCharRef, combiningClass){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_CHAR* (obj->combiningClass());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  decompositionTag
 *    flags:    c
 */
ZEND_METHOD(QCharRef, decompositionTag){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_LONG(obj->decompositionTag());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  joining
 *    flags:    c
 */
ZEND_METHOD(QCharRef, joining){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_LONG(obj->joining());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  direction
 *    flags:    c
 */
ZEND_METHOD(QCharRef, direction){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_LONG(obj->direction());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  hasMirrored
 *    flags:    c
 */
ZEND_METHOD(QCharRef, hasMirrored){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_BOOL(obj->hasMirrored());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  toLower
 *    flags:    c
 */
ZEND_METHOD(QCharRef, toLower){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
}

/*********************************
 *    class     QCharRef */
/*
 *    function  unicode
 *    flags:    c
 */
ZEND_METHOD(QCharRef, unicode){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
}

/*********************************
 *    class     QCharRef */
/*
 *    function  row
 *    flags:    c
 */
ZEND_METHOD(QCharRef, row){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_CHAR* (obj->row());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  setRow
 *    flags:    
 */
ZEND_METHOD(QCharRef, setRow){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_s_0, len_s_0) == SUCCESS) {
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QCharRef */
/*
 *    function  category
 *    flags:    c
 */
ZEND_METHOD(QCharRef, category){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_LONG(obj->category());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  isLetter
 *    flags:    c
 */
ZEND_METHOD(QCharRef, isLetter){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isLetter());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  cell
 *    flags:    c
 */
ZEND_METHOD(QCharRef, cell){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_CHAR* (obj->cell());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  digitValue
 *    flags:    c
 */
ZEND_METHOD(QCharRef, digitValue){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_LONG(obj->digitValue());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  isPrint
 *    flags:    c
 */
ZEND_METHOD(QCharRef, isPrint){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isPrint());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  isLetterOrNumber
 *    flags:    
 */
ZEND_METHOD(QCharRef, isLetterOrNumber){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isLetterOrNumber());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  mirroredChar
 *    flags:    c
 */
ZEND_METHOD(QCharRef, mirroredChar){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
}

/*********************************
 *    class     QCharRef */
/*
 *    function  setCell
 *    flags:    
 */
ZEND_METHOD(QCharRef, setCell){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_s_0, len_s_0) == SUCCESS) {
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QCharRef */
/*
 *    function  isNumber
 *    flags:    c
 */
ZEND_METHOD(QCharRef, isNumber){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isNumber());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  unicodeVersion
 *    flags:    c
 */
ZEND_METHOD(QCharRef, unicodeVersion){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			QChar::UnicodeVersion return_object = (QChar::UnicodeVersion) obj->unicodeVersion();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCharRef_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QCharRef */
/*
 *    function  isSpace
 *    flags:    c
 */
ZEND_METHOD(QCharRef, isSpace){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isSpace());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  toLatin1
 *    flags:    c
 */
ZEND_METHOD(QCharRef, toLatin1){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
}

/*********************************
 *    class     QCharRef */
/*
 *    function  toAscii
 *    flags:    c
 */
ZEND_METHOD(QCharRef, toAscii){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
}

/*********************************
 *    class     QCharRef */
/*
 *    function  decomposition
 *    flags:    c
 */
ZEND_METHOD(QCharRef, decomposition){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			QString return_object = (QString) obj->decomposition();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCharRef_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QCharRef */
/*
 *    function  toUpper
 *    flags:    c
 */
ZEND_METHOD(QCharRef, toUpper){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
}

/*********************************
 *    class     QCharRef */
/*
 *    function  isMark
 *    flags:    c
 */
ZEND_METHOD(QCharRef, isMark){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isMark());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  isPunct
 *    flags:    c
 */
ZEND_METHOD(QCharRef, isPunct){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isPunct());
}

/*********************************
 *    class     QCharRef */
/*
 *    function  isNull
 *    flags:    c
 */
ZEND_METHOD(QCharRef, isNull){
			QCharRef *obj = (QCharRef*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isNull());
}



ZEND_METHOD(QCharRef,__construct){

	QCharRef *QCharRef_ptr = new QCharRef();

	PHP_QT_REGISTER(QCharRef_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QCharRef);
