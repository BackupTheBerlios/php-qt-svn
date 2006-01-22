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
 * QContextMenuEvent.cpp - QContextMenuEvent PHP implementation.
 * begin           : Sun Jan 22 19:46:39 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QContextMenuEvent>
#include "../php_qt.h"



/*		public enumReason:long {
			Reason = 0,
			Reason = 0,
			Reason = 0,
		}
*/
/*********************************
 *    class     QContextMenuEvent */
/*
 *    function  y
 *    flags:    c
 */
ZEND_METHOD(QContextMenuEvent, y){
	if (ZEND_NUM_ARGS() == 0){
			QContextMenuEvent *obj = (QContextMenuEvent*) PHP_QT_FETCH();
			RETURN_LONG(obj->y());
	}
}

/*********************************
 *    class     QContextMenuEvent */
/*
 *    function  reason
 *    flags:    c
 */
ZEND_METHOD(QContextMenuEvent, reason){
	if (ZEND_NUM_ARGS() == 0){
			QContextMenuEvent *obj = (QContextMenuEvent*) PHP_QT_FETCH();
			obj->reason();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QContextMenuEvent */
/*
 *    function  globalY
 *    flags:    c
 */
ZEND_METHOD(QContextMenuEvent, globalY){
	if (ZEND_NUM_ARGS() == 0){
			QContextMenuEvent *obj = (QContextMenuEvent*) PHP_QT_FETCH();
			RETURN_LONG(obj->globalY());
	}
}

/*********************************
 *    class     QContextMenuEvent */
/*
 *    function  pos
 *    flags:    c
 */
ZEND_METHOD(QContextMenuEvent, pos){
	if (ZEND_NUM_ARGS() == 0){
			QContextMenuEvent *obj = (QContextMenuEvent*) PHP_QT_FETCH();
				const QPoint& return_object = (const QPoint&) obj->pos();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QContextMenuEvent_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QContextMenuEvent */
/*
 *    function  x
 *    flags:    c
 */
ZEND_METHOD(QContextMenuEvent, x){
	if (ZEND_NUM_ARGS() == 0){
			QContextMenuEvent *obj = (QContextMenuEvent*) PHP_QT_FETCH();
			RETURN_LONG(obj->x());
	}
}

/*********************************
 *    class     QContextMenuEvent */
/*
 *    function  globalPos
 *    flags:    c
 */
ZEND_METHOD(QContextMenuEvent, globalPos){
	if (ZEND_NUM_ARGS() == 0){
			QContextMenuEvent *obj = (QContextMenuEvent*) PHP_QT_FETCH();
				const QPoint& return_object = (const QPoint&) obj->globalPos();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QContextMenuEvent_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QContextMenuEvent */
/*
 *    function  globalX
 *    flags:    c
 */
ZEND_METHOD(QContextMenuEvent, globalX){
	if (ZEND_NUM_ARGS() == 0){
			QContextMenuEvent *obj = (QContextMenuEvent*) PHP_QT_FETCH();
			RETURN_LONG(obj->globalX());
	}
}


PHP_QT_DESTRUCT(QContextMenuEvent);

