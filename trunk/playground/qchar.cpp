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
 * QChar.cpp - QChar PHP implementation.
 * begin           : Fri Jan  6 00:06:34 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include "../php_qt.h"


/*		public enumSpecialCharacter:long {
			Null = 0x0000,
			Nbsp = 0x00a0,
			ReplacementCharacter = 0xfffd,
			ObjectReplacementCharacter = 0xfffc,
			ByteOrderMark = 0xfeff,
			ByteOrderSwapped = 0xfffe,
			ParagraphSeparator = 0x2029,
			LineSeparator = 0x2028
		}
*/

/*		public enumCategory:long {
			Category = 0,
			Category = 1,
			Category = 2,
			Category = 3,
			Category = 4,
			Category = 5,
			Category = 6,
			Category = 7,
			Category = 8,
			Category = 9,
			Category = 10,
			Category = 11,
			Category = 12,
			Category = 13,
			Category = 14,
			Category = 15,
			Category = 16,
			Category = 17,
			Category = 18,
			Category = 19,
			Category = 20,
			Category = 21,
			Category = 22,
			Category = 23,
			Category = 24,
			Category = 25,
			Category = 26,
			Category = 27,
			Category = 28,
			Category = 29,
			Category = 30,
			Punctuation_Dask = Punctuation_Dash
		}
*/

/*		public enumDirection:long {
			Direction = 0,
			Direction = 1,
			Direction = 2,
			Direction = 3,
			Direction = 4,
			Direction = 5,
			Direction = 6,
			Direction = 7,
			Direction = 8,
			Direction = 9,
			Direction = 10,
			Direction = 11,
			Direction = 12,
			Direction = 13,
			Direction = 14,
			Direction = 15,
			Direction = 16,
			Direction = 17,
			Direction = 18
		}
*/

/*		public enumDecomposition:long {
			Decomposition = 0,
			Decomposition = 1,
			Decomposition = 2,
			Decomposition = 3,
			Decomposition = 4,
			Decomposition = 5,
			Decomposition = 6,
			Decomposition = 7,
			Decomposition = 8,
			Decomposition = 9,
			Decomposition = 10,
			Decomposition = 11,
			Decomposition = 12,
			Decomposition = 13,
			Decomposition = 14,
			Decomposition = 15,
			Decomposition = 16,
			Decomposition = 17
		}
*/

/*		public enumJoining:long {
			Joining = 0,
			Joining = 1,
			Joining = 2,
			Joining = 3
		}
*/

/*		public enumCombiningClass:long {
			Combining_BelowLeftAttached = 200,
			Combining_BelowAttached = 202,
			Combining_BelowRightAttached = 204,
			Combining_LeftAttached = 208,
			Combining_RightAttached = 210,
			Combining_AboveLeftAttached = 212,
			Combining_AboveAttached = 214,
			Combining_AboveRightAttached = 216,
			Combining_BelowLeft = 218,
			Combining_Below = 220,
			Combining_BelowRight = 222,
			Combining_Left = 224,
			Combining_Right = 226,
			Combining_AboveLeft = 228,
			Combining_Above = 230,
			Combining_AboveRight = 232,
			Combining_DoubleBelow = 233,
			Combining_DoubleAbove = 234,
			Combining_IotaSubscript = 240
		}
*/

/*		public enumUnicodeVersion:long {
			UnicodeVersion = 0,
			UnicodeVersion = 1,
			UnicodeVersion = 2,
			UnicodeVersion = 3,
			UnicodeVersion = 4,
			UnicodeVersion = 5,
			UnicodeVersion = 6,
			UnicodeVersion = 7
		}
*/
/*********************************
 *    class     QChar */
/*
 *    function  combiningClass
 *    flags:    c
 */
ZEND_METHOD(QChar, combiningClass){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_CHAR* (obj->combiningClass());
}

/*********************************
 *    class     QChar */
/*
 *    function  isUpper
 *    flags:    c
 */
ZEND_METHOD(QChar, isUpper){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_BOOL(obj->isUpper());
}

/*********************************
 *    class     QChar */
/*
 *    function  joining
 *    flags:    c
 */
ZEND_METHOD(QChar, joining){
			QChar *obj = (QChar) PHP_QT_FETCH();
}

/*********************************
 *    class     QChar */
/*
 *    function  row
 *    flags:    c
 */
ZEND_METHOD(QChar, row){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_CHAR* (obj->row());
}

/*********************************
 *    class     QChar */
/*
 *    function  isSymbol
 *    flags:    c
 */
ZEND_METHOD(QChar, isSymbol){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_BOOL(obj->isSymbol());
}

/*********************************
 *    class     QChar */
/*
 *    function  category
 *    flags:    c
 */
ZEND_METHOD(QChar, category){
			QChar *obj = (QChar) PHP_QT_FETCH();
}

/*********************************
 *    class     QChar */
/*
 *    function  isPrint
 *    flags:    c
 */
ZEND_METHOD(QChar, isPrint){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_BOOL(obj->isPrint());
}

/*********************************
 *    class     QChar */
/*
 *    function  digitValue
 *    flags:    c
 */
ZEND_METHOD(QChar, digitValue){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_LONG(obj->digitValue());
}

/*********************************
 *    class     QChar */
/*
 *    function  mirroredChar
 *    flags:    c
 */
ZEND_METHOD(QChar, mirroredChar){
			QChar *obj = (QChar) PHP_QT_FETCH();
}

/*********************************
 *    class     QChar */
/*
 *    function  fromLatin1
 *    flags:    s
 */
ZEND_METHOD(QChar, fromLatin1){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int* len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_0, &len_0) == SUCCESS) {
			QChar *obj = (QChar*) PHP_QT_FETCH();

			
			QChar *obj = (QChar) PHP_QT_FETCH();
		}
	}
}

/*********************************
 *    class     QChar */
/*
 *    function  fromAscii
 *    flags:    s
 */
ZEND_METHOD(QChar, fromAscii){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int* len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_0, &len_0) == SUCCESS) {
			QChar *obj = (QChar*) PHP_QT_FETCH();

			
			QChar *obj = (QChar) PHP_QT_FETCH();
		}
	}
}

/*********************************
 *    class     QChar */
/*
 *    function  isSpace
 *    flags:    c
 */
ZEND_METHOD(QChar, isSpace){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_BOOL(obj->isSpace());
}

/*********************************
 *    class     QChar */
/*
 *    function  toUpper
 *    flags:    c
 */
ZEND_METHOD(QChar, toUpper){
			QChar *obj = (QChar) PHP_QT_FETCH();
}

/*********************************
 *    class     QChar */
/*
 *    function  decomposition
 *    flags:    c
 */
ZEND_METHOD(QChar, decomposition){
			QChar *obj = (QChar) PHP_QT_FETCH();
			QString return_object = (QString) obj->decomposition();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QChar_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QChar */
/*
 *    function  toLatin1
 *    flags:    c
 */
ZEND_METHOD(QChar, toLatin1){
			QChar *obj = (QChar) PHP_QT_FETCH();
}

/*********************************
 *    class     QChar */
/*
 *    function  isPunct
 *    flags:    c
 */
ZEND_METHOD(QChar, isPunct){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_BOOL(obj->isPunct());
}

/*********************************
 *    class     QChar */
/*
 *    function  isDigit
 *    flags:    c
 */
ZEND_METHOD(QChar, isDigit){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_BOOL(obj->isDigit());
}

/*********************************
 *    class     QChar */
/*
 *    function  decompositionTag
 *    flags:    c
 */
ZEND_METHOD(QChar, decompositionTag){
			QChar *obj = (QChar) PHP_QT_FETCH();
}

/*********************************
 *    class     QChar */
/*
 *    function  isLower
 *    flags:    c
 */
ZEND_METHOD(QChar, isLower){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_BOOL(obj->isLower());
}

/*********************************
 *    class     QChar */
/*
 *    function  direction
 *    flags:    c
 */
ZEND_METHOD(QChar, direction){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_LONG(obj->direction());
}

/*********************************
 *    class     QChar */
/*
 *    function  hasMirrored
 *    flags:    c
 */
ZEND_METHOD(QChar, hasMirrored){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_BOOL(obj->hasMirrored());
}

/*********************************
 *    class     QChar */
/*
 *    function  toLower
 *    flags:    c
 */
ZEND_METHOD(QChar, toLower){
			QChar *obj = (QChar) PHP_QT_FETCH();
}

/*********************************
 *    class     QChar */
/*
 *    function  unicode
 *    flags:    c
 */
ZEND_METHOD(QChar, unicode){
			QChar *obj = (QChar) PHP_QT_FETCH();
			QChar *obj = (QChar) PHP_QT_FETCH();
			ushort & return_object = (ushort &) obj->unicode();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QChar_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QChar */
/*
 *    function  isLetter
 *    flags:    c
 */
ZEND_METHOD(QChar, isLetter){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_BOOL(obj->isLetter());
}

/*********************************
 *    class     QChar */
/*
 *    function  setRow
 *    flags:    
 */
ZEND_METHOD(QChar, setRow){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int* len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_0, &len_0) == SUCCESS) {
			QChar *obj = (QChar*) PHP_QT_FETCH();

			
			QChar *obj = (QChar) PHP_QT_FETCH();
			obj->setRow( var_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QChar */
/*
 *    function  isLetterOrNumber
 *    flags:    c
 */
ZEND_METHOD(QChar, isLetterOrNumber){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_BOOL(obj->isLetterOrNumber());
}

/*********************************
 *    class     QChar */
/*
 *    function  cell
 *    flags:    c
 */
ZEND_METHOD(QChar, cell){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_CHAR* (obj->cell());
}

/*********************************
 *    class     QChar */
/*
 *    function  isNumber
 *    flags:    c
 */
ZEND_METHOD(QChar, isNumber){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_BOOL(obj->isNumber());
}

/*********************************
 *    class     QChar */
/*
 *    function  setCell
 *    flags:    
 */
ZEND_METHOD(QChar, setCell){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int* len_s_0;


		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_0, &len_0) == SUCCESS) {
			QChar *obj = (QChar*) PHP_QT_FETCH();

			
			QChar *obj = (QChar) PHP_QT_FETCH();
			obj->setCell( var_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QChar */
/*
 *    function  unicodeVersion
 *    flags:    c
 */
ZEND_METHOD(QChar, unicodeVersion){
			QChar *obj = (QChar) PHP_QT_FETCH();
}

/*********************************
 *    class     QChar */
/*
 *    function  toAscii
 *    flags:    c
 */
ZEND_METHOD(QChar, toAscii){
			QChar *obj = (QChar) PHP_QT_FETCH();
}

/*********************************
 *    class     QChar */
/*
 *    function  isMark
 *    flags:    c
 */
ZEND_METHOD(QChar, isMark){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_BOOL(obj->isMark());
}

/*********************************
 *    class     QChar */
/*
 *    function  isNull
 *    flags:    c
 */
ZEND_METHOD(QChar, isNull){
			QChar *obj = (QChar) PHP_QT_FETCH();
			RETURN_BOOL(obj->isNull());
}



ZEND_METHOD(QChar,__construct){

	QChar *QChar_ptr = new QChar();

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
		 /*char*  c char*/
		if(Z_TYPE_P(param_0) == IS_STRING) {
			char tmp(Z_STRVAL_P(param_0));
			QChar_ptr = new QChar(tmp);
		}
	}

	if(ZEND_NUM_ARGS() == 1){
		zval* param_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param_1) == FAILURE) {
			return;
		}
		 /*QLatin1Char ch QLatin1Char*/
		if(Z_TYPE_P(param_0) == IS_) {
			QLatin1Char tmp(Z_STRVAL_P(param_0));
			QChar_ptr = new QChar(tmp);
		}
	}

	if(ZEND_NUM_ARGS() == 2){
		zval* param_0;
		zval* param_1;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &param_1, &param_2) == FAILURE) {
			return;
		}
		 /*char*  c uchar*/
		if(Z_TYPE_P(param_0) == IS_STRING) {
			uchar tmp(Z_STRVAL_P(param_0));
			QChar_ptr = new QChar(tmp);
		}
		 /*char*  r uchar*/
		if(Z_TYPE_P(param_1) == IS_STRING) {
			uchar tmp(Z_STRVAL_P(param_1));
			QChar_ptr = new QChar(tmp);
		}
	}

	if(ZEND_NUM_ARGS() == 1){
		zval* param_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param_1) == FAILURE) {
			return;
		}
		 /*ushort rc ushort*/
		if(Z_TYPE_P(param_0) == IS_LONG) {
			ushort tmp(Z_STRVAL_P(param_0));
			QChar_ptr = new QChar(tmp);
		}
	}

	if(ZEND_NUM_ARGS() == 1){
		zval* param_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param_1) == FAILURE) {
			return;
		}
		 /*short rc short*/
		if(Z_TYPE_P(param_0) == IS_short) {
			short tmp(Z_STRVAL_P(param_0));
			QChar_ptr = new QChar(tmp);
		}
	}

	if(ZEND_NUM_ARGS() == 1){
		zval* param_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param_1) == FAILURE) {
			return;
		}
		 /*long rc uint*/
		if(Z_TYPE_P(param_0) == IS_LONG) {
			uint tmp(Z_STRVAL_P(param_0));
			QChar_ptr = new QChar(tmp);
		}
	}

	if(ZEND_NUM_ARGS() == 1){
		zval* param_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param_1) == FAILURE) {
			return;
		}
		 /*SpecialCharacter sc SpecialCharacter*/
		if(Z_TYPE_P(param_0) == IS_) {
			SpecialCharacter tmp(Z_STRVAL_P(param_0));
			QChar_ptr = new QChar(tmp);
		}
	}

	PHP_QT_REGISTER(QChar_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QChar);

