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
 * Attribute.cpp - Attribute PHP implementation.
 * begin           : Fri Jan  6 00:06:34 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include "../php_qt.h"



ZEND_METHOD(Attribute,__construct){

	Attribute *Attribute_ptr = new Attribute();

	if(ZEND_NUM_ARGS() == 4){
		zval* param_0;
		zval* param_1;
		zval* param_2;
		zval* param_3;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zzzz", &param_1, &param_2, &param_3, &param_4) == FAILURE) {
			return;
		}
		 /*AttributeType t AttributeType*/
		if(Z_TYPE_P(param_0) == IS_) {
			AttributeType tmp(Z_STRVAL_P(param_0));
			Attribute_ptr = new Attribute(tmp);
		}
		 /*long s int*/
		if(Z_TYPE_P(param_1) == IS_LONG) {
			int tmp(Z_STRVAL_P(param_1));
			Attribute_ptr = new Attribute(tmp);
		}
		 /*long l int*/
		if(Z_TYPE_P(param_2) == IS_LONG) {
			int tmp(Z_STRVAL_P(param_2));
			Attribute_ptr = new Attribute(tmp);
		}
		 /*zval* val QVariant*/
		if(Z_TYPE_P(param_3) == IS_OBJECT) {
			QVariant tmp(Z_STRVAL_P(param_3));
			Attribute_ptr = new Attribute(tmp);
		}
	}

	PHP_QT_REGISTER(Attribute_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(Attribute);

