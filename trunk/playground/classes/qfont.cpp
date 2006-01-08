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
 * QFont.cpp - QFont PHP implementation.
 * begin           : Sun Jan  8 12:02:25 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QFont>
#include "../php_qt.h"



/*		public enumStyleHint:long {
			StyleHint = 0,
			SansSerif = Helvetica,
			StyleHint = 2,
			Serif = Times,
			StyleHint = 4,
			TypeWriter = Courier,
			StyleHint = 6,
			Decorative = OldEnglish,
			StyleHint = 8,
			StyleHint = 9
		}
*/

/*		public enumStyleStrategy:long {
			PreferDefault = 0x0001,
			PreferBitmap = 0x0002,
			PreferDevice = 0x0004,
			PreferOutline = 0x0008,
			ForceOutline = 0x0010,
			PreferMatch = 0x0020,
			PreferQuality = 0x0040,
			PreferAntialias = 0x0080,
			NoAntialias = 0x0100,
			OpenGLCompatible = 0x0200
		}
*/

/*		public enumWeight:long {
			Light = 25,
			Normal = 50,
			DemiBold = 63,
			Bold = 75,
			Black = 87
		}
*/

/*		public enumStyle:long {
			Style = 0,
			Style = 1,
			Style = 2
		}
*/

/*		public enumStretch:long {
			UltraCondensed = 50,
			ExtraCondensed = 62,
			Condensed = 75,
			SemiCondensed = 87,
			Unstretched = 100,
			SemiExpanded = 112,
			Expanded = 125,
			ExtraExpanded = 150,
			UltraExpanded = 200
		}
*/
/*********************************
 *    class     QFont */
/*
 *    function  setOverline
 *    flags:    
 */
ZEND_METHOD(QFont, setOverline){

	if (ZEND_NUM_ARGS() == 1){
		/* b */
		long* var_b_0;   // _default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b", &var_b_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  insertSubstitution
 *    flags:    s
 */
ZEND_METHOD(QFont, insertSubstitution){

	if (ZEND_NUM_ARGS() == 2){
		/* oo */
		zval* z_var_oo_0;   // default: 
		zval* z_var_oo_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oo", &z_var_oo_0, &z_var_oo_1) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QObject* var_oo_0 = (QObject*) php_qt_fetch(z_var_oo_0);
			QObject* var_oo_1 = (QObject*) php_qt_fetch(z_var_oo_1);

			QString tmp_oo_0(var_oo_0->metaObject()->className());
			QString tmp_oo_1(var_oo_1->metaObject()->className());
			
			if(tmp_oo_0 == "const QString&" && tmp_oo_1 == "const QString&") {
				obj->insertSubstitution((const QString&) var_oo_0, (const QString&) var_oo_1);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  stretch
 *    flags:    c
 */
ZEND_METHOD(QFont, stretch){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_LONG(obj->stretch());
}

/*********************************
 *    class     QFont */
/*
 *    function  styleStrategy
 *    flags:    c
 */
ZEND_METHOD(QFont, styleStrategy){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_LONG(obj->styleStrategy());
}

/*********************************
 *    class     QFont */
/*
 *    function  setKerning
 *    flags:    
 */
ZEND_METHOD(QFont, setKerning){

	if (ZEND_NUM_ARGS() == 1){
		/* b */
		long* var_b_0;   // _default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b", &var_b_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  underline
 *    flags:    c
 */
ZEND_METHOD(QFont, underline){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_BOOL(obj->underline());
}

/*********************************
 *    class     QFont */
/*
 *    function  removeSubstitution
 *    flags:    s
 */
ZEND_METHOD(QFont, removeSubstitution){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QString&") {
				obj->removeSubstitution((const QString&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  substitute
 *    flags:    s
 */
ZEND_METHOD(QFont, substitute){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QString&") {
				QString return_object = (QString) obj->substitute((const QString&) var_o_0);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QFont_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
			}
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  setBold
 *    flags:    
 */
ZEND_METHOD(QFont, setBold){

	if (ZEND_NUM_ARGS() == 1){
		/* b */
		long* var_b_0;   // _default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b", &var_b_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  resolve
 *    flags:    c
 */
ZEND_METHOD(QFont, resolve){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_LONG(obj->resolve());

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();

			
		}
		/* o */
		zval* z_var_o_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_1) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QObject* var_o_1 = (QObject*) php_qt_fetch(z_var_o_1);

			QString tmp_o_0(var_o_1->metaObject()->className());
			
			if(tmp_o_0 == "const QFont&") {
				QFont return_object = (QFont) obj->resolve((const QFont&) var_o_1);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QFont_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
			}
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  fixedPitch
 *    flags:    c
 */
ZEND_METHOD(QFont, fixedPitch){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_BOOL(obj->fixedPitch());
}

/*********************************
 *    class     QFont */
/*
 *    function  italic
 *    flags:    c
 */
ZEND_METHOD(QFont, italic){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_BOOL(obj->italic());
}

/*********************************
 *    class     QFont */
/*
 *    function  pixelSize
 *    flags:    c
 */
ZEND_METHOD(QFont, pixelSize){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_LONG(obj->pixelSize());
}

/*********************************
 *    class     QFont */
/*
 *    function  insertSubstitutions
 *    flags:    s
 */
ZEND_METHOD(QFont, insertSubstitutions){

	if (ZEND_NUM_ARGS() == 2){
		/* oo */
		zval* z_var_oo_0;   // default: 
		zval* z_var_oo_1;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oo", &z_var_oo_0, &z_var_oo_1) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QObject* var_oo_0 = (QObject*) php_qt_fetch(z_var_oo_0);
			QObject* var_oo_1 = (QObject*) php_qt_fetch(z_var_oo_1);

			QString tmp_oo_0(var_oo_0->metaObject()->className());
			QString tmp_oo_1(var_oo_1->metaObject()->className());
			
			if(tmp_oo_0 == "const QString&" && tmp_oo_1 == "const QStringList&") {
				obj->insertSubstitutions((const QString&) var_oo_0, (const QStringList&) var_oo_1);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  key
 *    flags:    c
 */
ZEND_METHOD(QFont, key){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QString return_object = (QString) obj->key();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QFont_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QFont */
/*
 *    function  setStrikeOut
 *    flags:    
 */
ZEND_METHOD(QFont, setStrikeOut){

	if (ZEND_NUM_ARGS() == 1){
		/* b */
		long* var_b_0;   // _default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b", &var_b_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  weight
 *    flags:    c
 */
ZEND_METHOD(QFont, weight){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_LONG(obj->weight());
}

/*********************************
 *    class     QFont */
/*
 *    function  pointSize
 *    flags:    c
 */
ZEND_METHOD(QFont, pointSize){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_LONG(obj->pointSize());
}

/*********************************
 *    class     QFont */
/*
 *    function  cleanup
 *    flags:    s
 */
ZEND_METHOD(QFont, cleanup){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			obj->cleanup();
			RETURN_NULL();
}

/*********************************
 *    class     QFont */
/*
 *    function  fromString
 *    flags:    
 */
ZEND_METHOD(QFont, fromString){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QString&") {
				RETURN_BOOL(obj->fromString((const QString&) var_o_0));
			}
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  exactMatch
 *    flags:    c
 */
ZEND_METHOD(QFont, exactMatch){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_BOOL(obj->exactMatch());
}

/*********************************
 *    class     QFont */
/*
 *    function  setWeight
 *    flags:    
 */
ZEND_METHOD(QFont, setWeight){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  styleHint
 *    flags:    c
 */
ZEND_METHOD(QFont, styleHint){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_LONG(obj->styleHint());
}

/*********************************
 *    class     QFont */
/*
 *    function  handle
 *    flags:    c
 */
ZEND_METHOD(QFont, handle){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			Qt::HANDLE return_object = (Qt::HANDLE) obj->handle();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QFont_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QFont */
/*
 *    function  setStyle
 *    flags:    
 */
ZEND_METHOD(QFont, setStyle){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "Style") {
				obj->setStyle((Style) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  rawName
 *    flags:    c
 */
ZEND_METHOD(QFont, rawName){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QString return_object = (QString) obj->rawName();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QFont_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QFont */
/*
 *    function  setUnderline
 *    flags:    
 */
ZEND_METHOD(QFont, setUnderline){

	if (ZEND_NUM_ARGS() == 1){
		/* b */
		long* var_b_0;   // _default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b", &var_b_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  family
 *    flags:    c
 */
ZEND_METHOD(QFont, family){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QString return_object = (QString) obj->family();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QFont_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QFont */
/*
 *    function  isCopyOf
 *    flags:    c
 */
ZEND_METHOD(QFont, isCopyOf){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QFont&") {
				RETURN_BOOL(obj->isCopyOf((const QFont&) var_o_0));
			}
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  rawMode
 *    flags:    c
 */
ZEND_METHOD(QFont, rawMode){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_BOOL(obj->rawMode());
}

/*********************************
 *    class     QFont */
/*
 *    function  substitutes
 *    flags:    s
 */
ZEND_METHOD(QFont, substitutes){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QString&") {
				QStringList return_object = (QStringList) obj->substitutes((const QString&) var_o_0);
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QFont_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
			}
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  setStretch
 *    flags:    
 */
ZEND_METHOD(QFont, setStretch){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  initialize
 *    flags:    s
 */
ZEND_METHOD(QFont, initialize){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			obj->initialize();
			RETURN_NULL();
}

/*********************************
 *    class     QFont */
/*
 *    function  toString
 *    flags:    c
 */
ZEND_METHOD(QFont, toString){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QString return_object = (QString) obj->toString();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QFont_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QFont */
/*
 *    function  defaultFamily
 *    flags:    c
 */
ZEND_METHOD(QFont, defaultFamily){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QString return_object = (QString) obj->defaultFamily();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QFont_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QFont */
/*
 *    function  setRawMode
 *    flags:    
 */
ZEND_METHOD(QFont, setRawMode){

	if (ZEND_NUM_ARGS() == 1){
		/* b */
		long* var_b_0;   // _default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b", &var_b_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  kerning
 *    flags:    c
 */
ZEND_METHOD(QFont, kerning){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_BOOL(obj->kerning());
}

/*********************************
 *    class     QFont */
/*
 *    function  setStyleHint
 *    flags:    
 */
ZEND_METHOD(QFont, setStyleHint){

	if (ZEND_NUM_ARGS() == 2){
		/* lo */
		long var_lo_0;    // default: 
		zval* z_var_lo_1;   // default: PreferDefault

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo|", &var_lo_0, &z_var_lo_1) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QObject* var_lo_1 = (QObject*) php_qt_fetch(z_var_lo_1);

			QString tmp_lo_0(var_lo_1->metaObject()->className());
			
			if(tmp_lo_0 == "StyleStrategy") {
				obj->setStyleHint((StyleHint) var_lo_0, (StyleStrategy) var_lo_1);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  substitutions
 *    flags:    s
 */
ZEND_METHOD(QFont, substitutions){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QStringList return_object = (QStringList) obj->substitutions();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QFont_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QFont */
/*
 *    function  setFamily
 *    flags:    
 */
ZEND_METHOD(QFont, setFamily){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QString&") {
				obj->setFamily((const QString&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  QFont
 *    flags:    
 */
ZEND_METHOD(QFont, QFont){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_~(obj->QFont());
}

/*********************************
 *    class     QFont */
/*
 *    function  bold
 *    flags:    c
 */
ZEND_METHOD(QFont, bold){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_BOOL(obj->bold());
}

/*********************************
 *    class     QFont */
/*
 *    function  style
 *    flags:    c
 */
ZEND_METHOD(QFont, style){
			QFont *obj = (QFont*) PHP_QT_FETCH();
}

/*********************************
 *    class     QFont */
/*
 *    function  setPointSize
 *    flags:    
 */
ZEND_METHOD(QFont, setPointSize){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  setRawName
 *    flags:    
 */
ZEND_METHOD(QFont, setRawName){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QString&") {
				obj->setRawName((const QString&) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  setStyleStrategy
 *    flags:    
 */
ZEND_METHOD(QFont, setStyleStrategy){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "StyleStrategy") {
				obj->setStyleStrategy((StyleStrategy) var_o_0);
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  cacheStatistics
 *    flags:    s
 */
ZEND_METHOD(QFont, cacheStatistics){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			obj->cacheStatistics();
			RETURN_NULL();
}

/*********************************
 *    class     QFont */
/*
 *    function  setPixelSize
 *    flags:    
 */
ZEND_METHOD(QFont, setPixelSize){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  setFixedPitch
 *    flags:    
 */
ZEND_METHOD(QFont, setFixedPitch){

	if (ZEND_NUM_ARGS() == 1){
		/* b */
		long* var_b_0;   // _default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b", &var_b_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  setItalic
 *    flags:    
 */
ZEND_METHOD(QFont, setItalic){

	if (ZEND_NUM_ARGS() == 1){
		/* b */
		long* var_b_0;   // _default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b", &var_b_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();

			
		}
	}
}

/*********************************
 *    class     QFont */
/*
 *    function  strikeOut
 *    flags:    c
 */
ZEND_METHOD(QFont, strikeOut){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_BOOL(obj->strikeOut());
}

/*********************************
 *    class     QFont */
/*
 *    function  lastResortFont
 *    flags:    c
 */
ZEND_METHOD(QFont, lastResortFont){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QString return_object = (QString) obj->lastResortFont();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QFont_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QFont */
/*
 *    function  lastResortFamily
 *    flags:    c
 */
ZEND_METHOD(QFont, lastResortFamily){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QString return_object = (QString) obj->lastResortFamily();
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QFont_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = &return_object;                                       
			php_qt_register(return_value,le);                   
			return;                                             
}

/*********************************
 *    class     QFont */
/*
 *    function  overline
 *    flags:    c
 */
ZEND_METHOD(QFont, overline){
			QFont *obj = (QFont*) PHP_QT_FETCH();
			RETURN_BOOL(obj->overline());
}

/*********************************
 *    class     QFont */
/*
 *    function  pointSizeF
 *    flags:    c
 */
ZEND_METHOD(QFont, pointSizeF){
			QFont *obj = (QFont*) PHP_QT_FETCH();
}

/*********************************
 *    class     QFont */
/*
 *    function  setPointSizeF
 *    flags:    
 */
ZEND_METHOD(QFont, setPointSizeF){

	if (ZEND_NUM_ARGS() == 1){
		/* o */
		zval* z_var_o_0;   // default: 

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QFont *obj = (QFont*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "qreal") {
				obj->setPointSizeF((qreal) var_o_0);
			RETURN_NULL();
			}
		}
	}
}



ZEND_METHOD(QFont,__construct){

	QFont *QFont_ptr = new QFont();

	if(ZEND_NUM_ARGS() == 0){
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"") == FAILURE) {
			return;
		}
	}

	if(ZEND_NUM_ARGS() == 4){
		zval* param_0;
		zval* param_1;
		zval* param_2;
		zval* param_3;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zzzz", &param_1, &param_2, &param_3, &param_4) == FAILURE) {
			return;
		}
		 /*zval* family QString&*/
		if(Z_TYPE_P(param_0) == IS_OBJECT) {
			QString& tmp(Z_STRVAL_P(param_0));
			QFont_ptr = new QFont(tmp);
		}
		 /*long pointSize int*/
		if(Z_TYPE_P(param_1) == IS_LONG) {
			int tmp(Z_STRVAL_P(param_1));
			QFont_ptr = new QFont(tmp);
		}
		 /*long weight int*/
		if(Z_TYPE_P(param_2) == IS_LONG) {
			int tmp(Z_STRVAL_P(param_2));
			QFont_ptr = new QFont(tmp);
		}
		 /*bool italic bool*/
		if(Z_TYPE_P(param_3) == IS_BOOL) {
			bool tmp(Z_STRVAL_P(param_3));
			QFont_ptr = new QFont(tmp);
		}
	}

	if(ZEND_NUM_ARGS() == 2){
		zval* param_0;
		zval* param_1;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &param_1, &param_2) == FAILURE) {
			return;
		}
		 /*zval* arg1 QFont&*/
		if(Z_TYPE_P(param_0) == IS_OBJECT) {
			QFont& tmp(Z_STRVAL_P(param_0));
			QFont_ptr = new QFont(tmp);
		}
		 /*long pd QPaintDevice**/
		if(Z_TYPE_P(param_1) == IS_LONG) {
			QPaintDevice* tmp(Z_STRVAL_P(param_1));
			QFont_ptr = new QFont(tmp);
		}
	}

	if(ZEND_NUM_ARGS() == 1){
		zval* param_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param_1) == FAILURE) {
			return;
		}
		 /*zval* arg1 QFont&*/
		if(Z_TYPE_P(param_0) == IS_OBJECT) {
			QFont& tmp(Z_STRVAL_P(param_0));
			QFont_ptr = new QFont(tmp);
		}
	}

	PHP_QT_REGISTER(QFont_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QFont);
