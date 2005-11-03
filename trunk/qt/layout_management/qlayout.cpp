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
PHP_QT_RETURN_METHOD(QLayout,expandingDirections,RETURN_LONG)
PHP_QT_RETURN_METHOD(QLayout,isEmpty,RETURN_BOOL)
PHP_QT_RETURN_METHOD(QLayout,activate,RETURN_BOOL)
PHP_QT_RETURN_METHOD(QLayout,isEnabled,RETURN_BOOL)
PHP_QT_RETURN_METHOD(QLayout,margin,RETURN_LONG)
PHP_QT_RETURN_OBJ_METHOD(QLayout,menuBar,QWidget)
PHP_QT_RETURN_OBJ_METHOD(QLayout,parentWidget,QWidget)
PHP_QT_SETBOOL_METHOD(QLayout,setEnabled)
PHP_QT_SETLONG_METHOD(QLayout,setMargin)
PHP_QT_SETLONG_METHOD(QLayout,setSpacing)
PHP_QT_RETURN_METHOD(QLayout,sizeConstraint,RETURN_LONG)
PHP_QT_RETURN_METHOD(QLayout,spacing,RETURN_LONG)
PHP_QT_METHOD(QLayout,update)

ZEND_METHOD(QLayout,setAlignment){
	zval *object;
	QObject *ob = NULL;
	long alignment;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ol", &object, &alignment) == FAILURE) {
		return;
	}
	QLayout* obj = (QLayout*) PHP_QT_FETCH();
	
	ob = (QObject*) php_qt_fetch(object);
	QString tmp(ob->metaObject()->className());
		
	if(tmp == "QWidget")
		obj->setAlignment((QWidget*)ob,(Qt::Alignment)alignment);
	else
		obj->setAlignment((QLayout*)ob,(Qt::Alignment)alignment);
	
	RETURN_NULL();
}


/*ZEND_METHOD(QLayout,addChildWidget)
{
	zval *object;
	QWidget *widget = NULL;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
		return;
	}
	QLayout* obj = (QLayout*) PHP_QT_FETCH();
	
	widget = (QWidget*) php_qt_fetch(object);
		
	obj->addChildWidget(widget);
	
	RETURN_NULL();
}


ZEND_METHOD(QLayout,addChildLayout)
{
	zval *object;
	QLayout *layout = NULL;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
		return;
	}
	QLayout* obj = (QLayout*) PHP_QT_FETCH();
	
	layout = (QLayout*) php_qt_fetch(object);
		
	obj->addChildLayout(layoutItem);
	
	RETURN_NULL();
}
*/

ZEND_METHOD(QLayout,setSizeConstraint)
{
	long constraint;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &constraint) == FAILURE) {
		return;
	}
	QLayout* obj = (QLayout*) PHP_QT_FETCH();
			
	obj->setSizeConstraint((QLayout::SizeConstraint)constraint);
	
	RETURN_NULL();
}


ZEND_METHOD(QLayout,setMenuBar)
{
	zval *object;
	QWidget *widget = NULL;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
		return;
	}
	QLayout* obj = (QLayout*) PHP_QT_FETCH();
	
	widget = (QWidget*) php_qt_fetch(object);
		
	obj->setMenuBar(widget);
	
	RETURN_NULL();
}

ZEND_METHOD(QLayout,removeWidget)
{
	zval *object;
	QWidget *widget = NULL;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
		return;
	}
	QLayout* obj = (QLayout*) PHP_QT_FETCH();
	
	widget = (QWidget*) php_qt_fetch(object);
		
	obj->removeWidget(widget);
	
	RETURN_NULL();
}


ZEND_METHOD(QLayout,removeItem)
{
	zval *object;
	QLayoutItem *layoutItem = NULL;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
		return;
	}
	QLayout* obj = (QLayout*) PHP_QT_FETCH();
	
	layoutItem = (QLayoutItem*) php_qt_fetch(object);
		
	obj->removeItem(layoutItem);
	
	RETURN_NULL();
}

ZEND_METHOD(QLayout,addWidget)
{
	zval *object;
	QWidget *widget = NULL;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
		return;
	}
	QLayout* obj = (QLayout*) PHP_QT_FETCH();
	
	widget = (QWidget*) php_qt_fetch(object);
		
	obj->addWidget(widget);
	
	RETURN_NULL();
}

ZEND_METHOD(QLayout,indexOf)
{
	zval *object;
	QWidget *widget = NULL;
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
		return;
	}
	QBoxLayout* obj = (QBoxLayout*) PHP_QT_FETCH();
	
	widget = (QWidget*) php_qt_fetch(object);
	
	RETURN_LONG(obj->indexOf(widget));
}



ZEND_METHOD(QLayout,geometry)
{
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QLayout,maximumSize){
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QLayout,minimumSize){
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

ZEND_METHOD(QLayout,closestAcceptableSize){
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}

/*
ZEND_METHOD(QLayout,alignmentRect){
    NOT_YET_IMPLEMENTED
    RETURN_NULL(); 
}
*/

ZEND_METHOD(QLayout,itemAt){} //abstract
ZEND_METHOD(QLayout,sizeHint){} //abstract
ZEND_METHOD(QLayout,addItem){} //abstract
ZEND_METHOD(QLayout,count){} //abstract
ZEND_METHOD(QLayout,takeAt){} //abstract