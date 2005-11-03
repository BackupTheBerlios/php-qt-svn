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

ZEND_METHOD(QBoxLayout,__construct){
	zval *object;
	long direction;
	QWidget *parent = NULL;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l|o", &direction, &object) == FAILURE) {
		return;
	}
	if(ZEND_NUM_ARGS()==2)
		parent = (QWidget*) php_qt_fetch(object);
	QBoxLayout* QBoxLayout_ptr = new QBoxLayout((QBoxLayout::Direction)direction,parent);
	PHP_QT_REGISTER(QBoxLayout_ptr);
	
	RETURN_NULL();
}

ZEND_METHOD(QBoxLayout,sizeHint)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,addItem)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,count)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,takeAt)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,setGeometry)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,addLayout)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,addSpacing)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,addStretch)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,addStrut)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,addWidget)
{
	zval *object;
	long stretch = 0;
	long alignment = 0;
	QWidget *widget = NULL;
	
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o|ll", &object, &stretch, &alignment) == FAILURE) {
		return;
	}
	QBoxLayout* obj = (QBoxLayout*) PHP_QT_FETCH();
	
	widget = (QWidget*) php_qt_fetch(object);
		
	obj->addWidget(widget, stretch, (Qt::Alignment)alignment);
	
	RETURN_NULL();
}

ZEND_METHOD(QBoxLayout, direction)
{
    QBoxLayout* obj = (QBoxLayout*) PHP_QT_FETCH();
	qDebug("%X", obj);
	obj->direction();
	RETURN_LONG(0);
    //RETURN_LONG((long)obj->direction());

}

ZEND_METHOD(QBoxLayout,insertLayout)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,insertSpacing)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,insertStretch)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,insertWidget)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

PHP_QT_METHOD(QBoxLayout,invalidate)

ZEND_METHOD(QBoxLayout,setDirection)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,setStretchFactor)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,insertItem)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}
