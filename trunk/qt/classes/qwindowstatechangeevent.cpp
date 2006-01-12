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
 * QWindowStateChangeEvent.cpp - QWindowStateChangeEvent PHP implementation.
 * begin           : Wed Jan 11 20:29:53 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QWindowStateChangeEvent>
#include "../php_qt.h"


/*********************************
 *    class     QWindowStateChangeEvent */
/*
 *    function  oldState
 *    flags:    c
 */
ZEND_METHOD(QWindowStateChangeEvent, oldState){
	if (ZEND_NUM_ARGS() == 0){
			QWindowStateChangeEvent *obj = (QWindowStateChangeEvent*) PHP_QT_FETCH();
			Qt::WindowStates return_object = (Qt::WindowStates) obj->oldState();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QWindowStateChangeEvent_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}


PHP_QT_DESTRUCT(QWindowStateChangeEvent);
