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
 * QObjectData.cpp - QObjectData PHP implementation.
 * begin           : Fri Jan  6 00:06:34 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include "../php_qt.h"

/*********************************
 *    class     QObjectData */
/*
 *    function  QObjectData
 *    flags:    pv
 */
ZEND_METHOD(QObjectData, QObjectData){
			QObjectData *obj = (QObjectData) PHP_QT_FETCH();
			RETURN_~(obj->QObjectData());
}



ZEND_METHOD(QObjectData,__construct){

	QObjectData *QObjectData_ptr = new QObjectData();

	PHP_QT_REGISTER(QObjectData_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QObjectData);

