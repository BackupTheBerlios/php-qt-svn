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


ZEND_METHOD(QBoxLayout,addItem)
{
	zval *object;
	QLayoutItem *layoutItem = NULL;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
		return;
	}
	QBoxLayout* obj = (QBoxLayout*) PHP_QT_FETCH();
	
	layoutItem = (QLayoutItem*) php_qt_fetch(object);
	
	obj->addItem(layoutItem);
	
	RETURN_NULL();
}

PHP_QT_RETURN_METHOD(QBoxLayout,count,RETURN_LONG)

ZEND_METHOD(QBoxLayout,takeAt)
{
	zval *object;
	long index;
		
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &index) == FAILURE) {
		return;
	}
	QBoxLayout* obj = (QBoxLayout*) PHP_QT_FETCH();
	
	PHP_QT_RET_OBJ(QLayoutItem,obj->takeAt(index));
}


ZEND_METHOD(QBoxLayout,itemAt)
{
	zval *object;
	long index;
		
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &index) == FAILURE) {
		return;
	}
	QBoxLayout* obj = (QBoxLayout*) PHP_QT_FETCH();
	
	PHP_QT_RET_OBJ(QLayoutItem,obj->itemAt(index));
}


ZEND_METHOD(QBoxLayout,addLayout)
{
	zval *object;
	QLayout *layout = NULL;
	long stretch=0;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o|l", &object, &stretch) == FAILURE) {
		return;
	}
	QBoxLayout* obj = (QBoxLayout*) PHP_QT_FETCH();
	
	layout = (QLayout*) php_qt_fetch(object);
	
	obj->addLayout(layout,stretch);
	
	RETURN_NULL();
}

PHP_QT_SETLONG_METHOD(QBoxLayout,addSpacing)

ZEND_METHOD(QBoxLayout,addStretch)
{
	long stretch=0;
	if(ZEND_NUM_ARGS() == 1)
	{
		if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &stretch) == FAILURE) {
			return;
		}
	}
	QBoxLayout* obj = (QBoxLayout*) PHP_QT_FETCH();
	
	obj->addStretch(stretch);
	
	RETURN_NULL();
}

PHP_QT_SETLONG_METHOD(QBoxLayout,addStrut)

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
    RETURN_LONG((long)obj->direction());
}

ZEND_METHOD(QBoxLayout,insertLayout)
{
	zval *object;
	QLayout *layout = NULL;
	long stretch=0;
	long index;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo|l",&index , &object, &stretch) == FAILURE) {
		return;
	}
	QBoxLayout* obj = (QBoxLayout*) PHP_QT_FETCH();
	
	layout = (QLayout*) php_qt_fetch(object);
	
	obj->insertLayout(index,layout,stretch);
	
	RETURN_NULL();
}

ZEND_METHOD(QBoxLayout,insertSpacing)
{
	long size;
	long index;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ll",&index , &size) == FAILURE) {
		return;
	}
	QBoxLayout* obj = (QBoxLayout*) PHP_QT_FETCH();
	
	obj->insertSpacing(index,size);
	
	RETURN_NULL();
}

ZEND_METHOD(QBoxLayout,insertStretch)
{
	long stretch=0;
	long index;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l|l",&index , &stretch) == FAILURE) {
		return;
	}
	QBoxLayout* obj = (QBoxLayout*) PHP_QT_FETCH();
	
	obj->insertStretch(index,stretch);
	
	RETURN_NULL();
}

ZEND_METHOD(QBoxLayout,insertWidget)
{
	zval *object;
	long stretch = 0;
	long alignment = 0;
	long index;
	QWidget *widget = NULL;
		
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lo|ll",index, &object, &stretch, &alignment) == FAILURE) {
		return;
	}
	QBoxLayout* obj = (QBoxLayout*) PHP_QT_FETCH();
	
	widget = (QWidget*) php_qt_fetch(object);
		
	obj->insertWidget(index,widget, stretch, (Qt::Alignment)alignment);
	
	RETURN_NULL();
}

PHP_QT_METHOD(QBoxLayout,invalidate)

ZEND_METHOD(QBoxLayout,setDirection)
{
	long direction;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l",&direction) == FAILURE) {
		return;
	}
	QBoxLayout* obj = (QBoxLayout*) PHP_QT_FETCH();
	
	obj->setDirection((QBoxLayout::Direction)direction);
	
	RETURN_NULL();
}

ZEND_METHOD(QBoxLayout,setStretchFactor)
{
	zval *object;
	long stretch = 0;
	QObject *o = NULL;
	
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ol", &object, &stretch) == FAILURE) {
		return;
	}
	QBoxLayout* obj = (QBoxLayout*) PHP_QT_FETCH();
	
	o = (QObject*) php_qt_fetch(object);

	QString tmp(o->metaObject()->className());
		
	if(tmp == "QWidget")
		RETURN_BOOL(obj->setStretchFactor((QWidget *)o, stretch))
	else
		RETURN_BOOL(obj->setStretchFactor((QLayout *)o, stretch))
}

ZEND_METHOD(QBoxLayout,insertItem)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,setGeometry)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QBoxLayout,sizeHint)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}
