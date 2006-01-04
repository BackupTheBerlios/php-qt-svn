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
 * QDragEnterEvent.cpp - QDragEnterEvent PHP implementation.
 * begin           : Wed Jan  4 01:19:22 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include "../php_qt.h"

#include <QDragEnterEvent>


	}
}


ZEND_METHOD(QDragEnterEvent,__construct){

	QDragEnterEvent *QDragEnterEvent_ptr = new QDragEnterEvent();

	if(ZEND_NUM_ARGS() == 5){
		zval* param_0;
		zval* param_1;
		zval* param_2;
		zval* param_3;
		zval* param_4;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zzzzz", &param_1, &param_2, &param_3, &param_4, &param_5) == FAILURE) {
			return;
		}
		 /*long pos QPoint&*/
		if(Z_TYPE_P(param_0) == IS_LONG) {
			QPoint& tmp(Z_STRVAL_P(param_0));
			QDragEnterEvent_ptr = new QDragEnterEvent(tmp);
		}
		 /*zval* actions Qt::DropActions*/
		if(Z_TYPE_P(param_1) == IS_OBJECT) {
			Qt::DropActions tmp(Z_STRVAL_P(param_1));
			QDragEnterEvent_ptr = new QDragEnterEvent(tmp);
		}
		 /*zval* data QMimeData**/
		if(Z_TYPE_P(param_2) == IS_OBJECT) {
			QMimeData* tmp(Z_STRVAL_P(param_2));
			QDragEnterEvent_ptr = new QDragEnterEvent(tmp);
		}
		 /*zval* buttons Qt::MouseButtons*/
		if(Z_TYPE_P(param_3) == IS_OBJECT) {
			Qt::MouseButtons tmp(Z_STRVAL_P(param_3));
			QDragEnterEvent_ptr = new QDragEnterEvent(tmp);
		}
		 /*zval* modifiers Qt::KeyboardModifiers*/
		if(Z_TYPE_P(param_4) == IS_OBJECT) {
			Qt::KeyboardModifiers tmp(Z_STRVAL_P(param_4));
			QDragEnterEvent_ptr = new QDragEnterEvent(tmp);
		}
	}

	PHP_QT_REGISTER(QDragEnterEvent_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QDragEnterEvent);

