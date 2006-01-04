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
 * QDropEvent.cpp - QDropEvent PHP implementation.
 * begin           : Wed Jan  4 01:19:22 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include "../php_qt.h"

#include <QDropEvent>



/*********************************
 *    class     QDropEvent
 *    function  pos
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   const QPoint &
*********************************/
ZEND_METHOD(QDropEvent, pos){
	if (ZEND_NUM_ARGS() == 0){
		QDropEvent *o = (QDropEvent*) PHP_QT_FETCH();
		const QPoint & obj = (const QPoint &) o->pos();
		zend_class_entry *ce;                                   
		    object_init_ex(return_value, QDropEvent_ce_ptr);     
		    zend_rsrc_list_entry le;                            
		    le.ptr = &obj;                                       
		    php_qt_register(return_value,le);                   
		    return;                                             
	}
}


/*********************************
 *    class     QDropEvent
 *    function  mouseButtons
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   Qt::MouseButtons
*********************************/
ZEND_METHOD(QDropEvent, mouseButtons){
	if (ZEND_NUM_ARGS() == 0){
		QDropEvent *o = (QDropEvent*) PHP_QT_FETCH();
		Qt::MouseButtons obj = (Qt::MouseButtons) o->mouseButtons();
		zend_class_entry *ce;                                   
		    object_init_ex(return_value, QDropEvent_ce_ptr);     
		    zend_rsrc_list_entry le;                            
		    le.ptr = &obj;                                       
		    php_qt_register(return_value,le);                   
		    return;                                             
	}
}


/*********************************
 *    class     QDropEvent
 *    function  keyboardModifiers
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   Qt::KeyboardModifiers
*********************************/
ZEND_METHOD(QDropEvent, keyboardModifiers){
	if (ZEND_NUM_ARGS() == 0){
		QDropEvent *o = (QDropEvent*) PHP_QT_FETCH();
		Qt::KeyboardModifiers obj = (Qt::KeyboardModifiers) o->keyboardModifiers();
		zend_class_entry *ce;                                   
		    object_init_ex(return_value, QDropEvent_ce_ptr);     
		    zend_rsrc_list_entry le;                            
		    le.ptr = &obj;                                       
		    php_qt_register(return_value,le);                   
		    return;                                             
	}
}


/*********************************
 *    class     QDropEvent
 *    function  possibleActions
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   Qt::DropActions
*********************************/
ZEND_METHOD(QDropEvent, possibleActions){
	if (ZEND_NUM_ARGS() == 0){
		QDropEvent *o = (QDropEvent*) PHP_QT_FETCH();
		Qt::DropActions obj = (Qt::DropActions) o->possibleActions();
		zend_class_entry *ce;                                   
		    object_init_ex(return_value, QDropEvent_ce_ptr);     
		    zend_rsrc_list_entry le;                            
		    le.ptr = &obj;                                       
		    php_qt_register(return_value,le);                   
		    return;                                             
	}
}


/*********************************
 *    class     QDropEvent
 *    function  proposedAction
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   Qt::DropAction
*********************************/
ZEND_METHOD(QDropEvent, proposedAction){
	if (ZEND_NUM_ARGS() == 0){
		QDropEvent *o = (QDropEvent*) PHP_QT_FETCH();
		Qt::DropAction obj = (Qt::DropAction) o->proposedAction();
		zend_class_entry *ce;                                   
		    object_init_ex(return_value, QDropEvent_ce_ptr);     
		    zend_rsrc_list_entry le;                            
		    le.ptr = &obj;                                       
		    php_qt_register(return_value,le);                   
		    return;                                             
	}
}


/*********************************
 *    class     QDropEvent
 *    function  acceptProposedAction
 *    flags:    
 *
 *    @param   -

 *    @access   public
 *    @return   void
*********************************/
ZEND_METHOD(QDropEvent, acceptProposedAction){
	if (ZEND_NUM_ARGS() == 0){
		QDropEvent *o = (QDropEvent*) PHP_QT_FETCH();
		o->acceptProposedAction();
		RETURN_NULL();
	}
}


/*********************************
 *    class     QDropEvent
 *    function  dropAction
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   Qt::DropAction
*********************************/
ZEND_METHOD(QDropEvent, dropAction){
	if (ZEND_NUM_ARGS() == 0){
		QDropEvent *o = (QDropEvent*) PHP_QT_FETCH();
		Qt::DropAction obj = (Qt::DropAction) o->dropAction();
		zend_class_entry *ce;                                   
		    object_init_ex(return_value, QDropEvent_ce_ptr);     
		    zend_rsrc_list_entry le;                            
		    le.ptr = &obj;                                       
		    php_qt_register(return_value,le);                   
		    return;                                             
	}
}


/*********************************
 *    class     QDropEvent
 *    function  setDropAction
 *    flags:    
 *
 *    @param   Qt::DropAction
 *    @param   -

 *    @access   public
 *    @return   void
*********************************/
ZEND_METHOD(QDropEvent, setDropAction){
	if (ZEND_NUM_ARGS() == 1){
	// 
		zval* var_0;

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_0) == FAILURE) {
			RETURN_FALSE;
		}
		QObject* tmp_var_0 = (QObject*) php_qt_fetch(var_0);
		QDropEvent *o = (QDropEvent*) PHP_QT_FETCH();
		o->setDropAction( tmp_var_0);
		RETURN_NULL();
	}
}


/*********************************
 *    class     QDropEvent
 *    function  source
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   QWidget*
*********************************/
ZEND_METHOD(QDropEvent, source){
	if (ZEND_NUM_ARGS() == 0){
		QDropEvent *o = (QDropEvent*) PHP_QT_FETCH();
		QWidget* obj = (QWidget*) o->source();
		zend_class_entry *ce;                                   
		    object_init_ex(return_value, QDropEvent_ce_ptr);     
		    zend_rsrc_list_entry le;                            
		    le.ptr = &obj;                                       
		    php_qt_register(return_value,le);                   
		    return;                                             
	}
}


/*********************************
 *    class     QDropEvent
 *    function  mimeData
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   const QMimeData *
*********************************/
ZEND_METHOD(QDropEvent, mimeData){
	if (ZEND_NUM_ARGS() == 0){
		QDropEvent *o = (QDropEvent*) PHP_QT_FETCH();
		const QMimeData * obj = (const QMimeData *) o->mimeData();
		zend_class_entry *ce;                                   
		    object_init_ex(return_value, QDropEvent_ce_ptr);     
		    zend_rsrc_list_entry le;                            
		    le.ptr = &obj;                                       
		    php_qt_register(return_value,le);                   
		    return;                                             
	}
}


/*********************************
 *    class     QDropEvent
 *    function  format
 *    flags:    c
 *
 *    @param   int
 *    @param   -

 *    @access   public
 *    @return   const char*
*********************************/
ZEND_METHOD(QDropEvent, format){
	if (ZEND_NUM_ARGS() == 1){
	// 0
		long var_0;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_0) == FAILURE) {
			RETURN_FALSE;
		}
		QDropEvent *o = (QDropEvent*) PHP_QT_FETCH();
		const char* obj = (const char*) o->format((int) var_0);
		zend_class_entry *ce;                                   
		    object_init_ex(return_value, QDropEvent_ce_ptr);     
		    zend_rsrc_list_entry le;                            
		    le.ptr = &obj;                                       
		    php_qt_register(return_value,le);                   
		    return;                                             
	}
}


/*********************************
 *    class     QDropEvent
 *    function  encodedData
 *    flags:    c
 *
 *    @param   const char*
 *    @param   -

 *    @access   public
 *    @return   QByteArray
*********************************/
ZEND_METHOD(QDropEvent, encodedData){
	if (ZEND_NUM_ARGS() == 1){
	// 
		char* var_0;
		int* len_0;

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_0, &len_0) == FAILURE) {
			RETURN_FALSE;
		}
		QDropEvent *o = (QDropEvent*) PHP_QT_FETCH();
		RETURN_BYTE[](o->encodedData( var_0));
	}
}


/*********************************
 *    class     QDropEvent
 *    function  provides
 *    flags:    c
 *
 *    @param   const char*
 *    @param   -

 *    @access   public
 *    @return   bool
*********************************/
ZEND_METHOD(QDropEvent, provides){
	if (ZEND_NUM_ARGS() == 1){
	// 
		char* var_0;
		int* len_0;

		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_0, &len_0) == FAILURE) {
			RETURN_FALSE;
		}
		QDropEvent *o = (QDropEvent*) PHP_QT_FETCH();
		RETURN_BOOL(o->provides( var_0));

	}
}


ZEND_METHOD(QDropEvent,__construct){

	QDropEvent *QDropEvent_ptr = new QDropEvent();

	if(ZEND_NUM_ARGS() == 6){
		zval* param_0;
		zval* param_1;
		zval* param_2;
		zval* param_3;
		zval* param_4;
		zval* param_5;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zzzzzz", &param_1, &param_2, &param_3, &param_4, &param_5, &param_6) == FAILURE) {
			return;
		}
		 /*long pos QPoint&*/
		if(Z_TYPE_P(param_0) == IS_LONG) {
			QPoint& tmp(Z_STRVAL_P(param_0));
			QDropEvent_ptr = new QDropEvent(tmp);
		}
		 /*zval* actions Qt::DropActions*/
		if(Z_TYPE_P(param_1) == IS_OBJECT) {
			Qt::DropActions tmp(Z_STRVAL_P(param_1));
			QDropEvent_ptr = new QDropEvent(tmp);
		}
		 /*zval* data QMimeData**/
		if(Z_TYPE_P(param_2) == IS_OBJECT) {
			QMimeData* tmp(Z_STRVAL_P(param_2));
			QDropEvent_ptr = new QDropEvent(tmp);
		}
		 /*zval* buttons Qt::MouseButtons*/
		if(Z_TYPE_P(param_3) == IS_OBJECT) {
			Qt::MouseButtons tmp(Z_STRVAL_P(param_3));
			QDropEvent_ptr = new QDropEvent(tmp);
		}
		 /*zval* modifiers Qt::KeyboardModifiers*/
		if(Z_TYPE_P(param_4) == IS_OBJECT) {
			Qt::KeyboardModifiers tmp(Z_STRVAL_P(param_4));
			QDropEvent_ptr = new QDropEvent(tmp);
		}
		 /*long type Type*/
		if(Z_TYPE_P(param_5) == IS_LONG) {
			Type tmp(Z_STRVAL_P(param_5));
			QDropEvent_ptr = new QDropEvent(tmp);
		}
	}

	PHP_QT_REGISTER(QDropEvent_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QDropEvent);

