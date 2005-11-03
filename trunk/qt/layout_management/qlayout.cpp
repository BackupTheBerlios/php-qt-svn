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

#include <QLayout>
#include "../php_qt.h"

ZEND_METHOD(QLayout,__construct){}
ZEND_METHOD(QLayout,expandingDirections){}
ZEND_METHOD(QLayout,geometry){}
ZEND_METHOD(QLayout,isEmpty){}
ZEND_METHOD(QLayout,maximumSize){}
ZEND_METHOD(QLayout,minimumSize){}
ZEND_METHOD(QLayout,sizeHint){} //abstract
ZEND_METHOD(QLayout,addItem){} //abstract
ZEND_METHOD(QLayout,count){} //abstract
ZEND_METHOD(QLayout,takeAt){} //abstract
