/*
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2005 Jean-Luc Gyger <jean_luc.gyger@freesurf.ch>
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
 */

#include <iostream>
using namespace std;

#include <QLineEdit>
#include "../php_qt.h"

/* QLineEdit */

ZEND_METHOD(QLineEdit,__construct){
    
	if(ZEND_NUM_ARGS() == 0){
		QLineEdit* QLineEdit_ptr = new QLineEdit();
		PHP_QT_REGISTER(QLineEdit_ptr);
		RETURN_NULL();	
	}

	if(ZEND_NUM_ARGS() == 2){
        char *string;
        int string_len;
        zval *parent;
		
		if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"so",&string, &string_len, &parent) == FAILURE) {
			return;
		}
		
		QLineEdit* QLineEdit_ptr = new QLineEdit(string,(QWidget*) php_qt_fetch(parent));
		PHP_QT_REGISTER(QLineEdit_ptr);
		RETURN_NULL();
	}

	if(ZEND_NUM_ARGS() == 1){
        zval *param;
		
		if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param) == FAILURE) {
			return;
		}

		if(Z_TYPE_P(param) == IS_STRING) {
			QString tmp(Z_STRVAL_P(param));
			QLineEdit* QLineEdit_ptr = new QLineEdit(tmp);
			PHP_QT_REGISTER(QLineEdit_ptr);
			RETURN_NULL();
		}

		if(Z_TYPE_P(param) == IS_OBJECT) {
			QWidget *tmp = (QWidget*) php_qt_fetch(param);
			QLineEdit* QLineEdit_ptr = new QLineEdit(tmp);
			PHP_QT_REGISTER(QLineEdit_ptr);
			RETURN_NULL();
		}
			
	}	
		
}

