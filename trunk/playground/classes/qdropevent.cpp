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
 * begin           : Mon Jan  9 00:39:35 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QDropEvent>
#include "../php_qt.h"


/*********************************
 *    class     QDropEvent */
/*
 *    function  encodedData
 *    flags:    c
 */
ZEND_METHOD(QDropEvent, encodedData){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int len_s_0;


		/* const char* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_s_0, len_s_0) == SUCCESS) {
			QDropEvent *obj = (QDropEvent*) PHP_QT_FETCH();

			
			RETURN_BYTE[](obj->encodedData( (const char*) var_s_0));
		}
	}
}

/*********************************
 *    class     QDropEvent */
/*
 *    function  source
 *    flags:    c
 */
ZEND_METHOD(QDropEvent, source){
	if (ZEND_NUM_ARGS() == 0){
			QDropEvent *obj = (QDropEvent*) PHP_QT_FETCH();
			QWidget* return_object = (QWidget*) obj->source();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDropEvent_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QDropEvent */
/*
 *    function  keyboardModifiers
 *    flags:    c
 */
ZEND_METHOD(QDropEvent, keyboardModifiers){
	if (ZEND_NUM_ARGS() == 0){
			QDropEvent *obj = (QDropEvent*) PHP_QT_FETCH();
			Qt::KeyboardModifiers return_object = (Qt::KeyboardModifiers) obj->keyboardModifiers();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDropEvent_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QDropEvent */
/*
 *    function  setDropAction
 *    flags:    
 */
ZEND_METHOD(QDropEvent, setDropAction){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 

		/* int action,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDropEvent *obj = (QDropEvent*) PHP_QT_FETCH();

			
			obj->setDropAction((Qt::DropAction) var_l_0);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QDropEvent */
/*
 *    function  acceptProposedAction
 *    flags:    
 */
ZEND_METHOD(QDropEvent, acceptProposedAction){
	if (ZEND_NUM_ARGS() == 0){
			QDropEvent *obj = (QDropEvent*) PHP_QT_FETCH();
			obj->acceptProposedAction();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QDropEvent */
/*
 *    function  dropAction
 *    flags:    c
 */
ZEND_METHOD(QDropEvent, dropAction){
	if (ZEND_NUM_ARGS() == 0){
			QDropEvent *obj = (QDropEvent*) PHP_QT_FETCH();
			Qt::DropAction return_object = (Qt::DropAction) obj->dropAction();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDropEvent_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QDropEvent */
/*
 *    function  mimeData
 *    flags:    c
 */
ZEND_METHOD(QDropEvent, mimeData){
	if (ZEND_NUM_ARGS() == 0){
			QDropEvent *obj = (QDropEvent*) PHP_QT_FETCH();
			const QMimeData * return_object = (const QMimeData *) obj->mimeData();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDropEvent_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QDropEvent */
/*
 *    function  provides
 *    flags:    c
 */
ZEND_METHOD(QDropEvent, provides){

	if (ZEND_NUM_ARGS() == 1){
		/* s */
		char* var_s_0;   // default: 
		int len_s_0;


		/* const char* ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &var_s_0, len_s_0) == SUCCESS) {
			QDropEvent *obj = (QDropEvent*) PHP_QT_FETCH();

			
			RETURN_BOOL(obj->provides( (const char*) var_s_0));
		}
	}
}

/*********************************
 *    class     QDropEvent */
/*
 *    function  format
 *    flags:    c
 */
ZEND_METHOD(QDropEvent, format){

	if (ZEND_NUM_ARGS() == 1){
		/* l */
		long var_l_0;    // default: 0

		/* int n,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l|", &var_l_0) == SUCCESS) {
			QDropEvent *obj = (QDropEvent*) PHP_QT_FETCH();

			
			const char* return_object = (const char*) obj->format((int) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDropEvent_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QDropEvent */
/*
 *    function  mouseButtons
 *    flags:    c
 */
ZEND_METHOD(QDropEvent, mouseButtons){
	if (ZEND_NUM_ARGS() == 0){
			QDropEvent *obj = (QDropEvent*) PHP_QT_FETCH();
			Qt::MouseButtons return_object = (Qt::MouseButtons) obj->mouseButtons();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDropEvent_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QDropEvent */
/*
 *    function  proposedAction
 *    flags:    c
 */
ZEND_METHOD(QDropEvent, proposedAction){
	if (ZEND_NUM_ARGS() == 0){
			QDropEvent *obj = (QDropEvent*) PHP_QT_FETCH();
			Qt::DropAction return_object = (Qt::DropAction) obj->proposedAction();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDropEvent_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QDropEvent */
/*
 *    function  pos
 *    flags:    c
 */
ZEND_METHOD(QDropEvent, pos){
	if (ZEND_NUM_ARGS() == 0){
			QDropEvent *obj = (QDropEvent*) PHP_QT_FETCH();
			const QPoint & return_object = (const QPoint &) obj->pos();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDropEvent_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QDropEvent */
/*
 *    function  possibleActions
 *    flags:    c
 */
ZEND_METHOD(QDropEvent, possibleActions){
	if (ZEND_NUM_ARGS() == 0){
			QDropEvent *obj = (QDropEvent*) PHP_QT_FETCH();
			Qt::DropActions return_object = (Qt::DropActions) obj->possibleActions();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDropEvent_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}


PHP_QT_DESTRUCT(QDropEvent);

