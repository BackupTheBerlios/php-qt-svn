/*
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2005 Thomas Moenicke <tm@ippfp.org>
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

#include <QWidget>
#include <QPushButton>

#include "php_qt.h"


ZEND_METHOD(QWidget,__construct){

    if(ZEND_NUM_ARGS() == 1){
        zval *object;

	    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
            return;
        }
        QWidget *parent = (QWidget*) php_qt_fetch(object);
        QWidget* QWidget_ptr = new QWidget(parent);
        PHP_QT_REGISTER(QWidget_ptr);

        RETURN_NULL();

    } else if(ZEND_NUM_ARGS() == 0){

        QWidget* QWidget_ptr = new QWidget();
        PHP_QT_REGISTER(QWidget_ptr);

        RETURN_NULL();

    }
}
 
ZEND_METHOD(QWidget,isVisible){
    QWidget *o = (QWidget*) PHP_QT_FETCH();
    RETURN_BOOL(o->isVisible());
}

ZEND_METHOD(QWidget,isHidden){
    QWidget *o = (QWidget*) PHP_QT_FETCH();
    RETURN_BOOL(o->isHidden());
}

ZEND_METHOD(QWidget,show){
    QWidget *o = (QWidget*) PHP_QT_FETCH();
    o->show();
    RETURN_NULL();
}

ZEND_METHOD(QWidget,hide){
    QWidget *o = (QWidget*) PHP_QT_FETCH();
    o->hide();
    RETURN_NULL();
}



ZEND_METHOD(QAbstractButton,__construct){

    if(ZEND_NUM_ARGS() > 0){
        zval *object;

	    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o",&object) == FAILURE) {
            return;
        }
        QAbstractButton* parent = (QAbstractButton*) php_qt_fetch(object);
        /* dirty, we cannot instanciate QAbstractButton directly */
        QAbstractButton* QAbstractButton_ptr = new QPushButton(parent);
        PHP_QT_REGISTER(QAbstractButton_ptr);

        RETURN_NULL();

    } else {

        QAbstractButton* QAbstractButton_ptr = new QPushButton(); 
        PHP_QT_REGISTER(QAbstractButton_ptr);

        RETURN_NULL();
    }
}

PHP_QT_SIMPLE_METHOD(QAbstractButton,autoExclusive,RETURN_BOOL);
PHP_QT_SIMPLE_METHOD(QAbstractButton,autoRepeat,RETURN_BOOL);
PHP_QT_SIMPLE_METHOD(QAbstractButton,isCheckable,RETURN_BOOL);
PHP_QT_SIMPLE_METHOD(QAbstractButton,isChecked,RETURN_BOOL);
PHP_QT_SIMPLE_METHOD(QAbstractButton,isDown,RETURN_BOOL);

PHP_QT_ABSTRACT_SETBOOL_METHOD(QAbstractButton,setAutoExclusive,QPushButton,"autoExclusive");
PHP_QT_ABSTRACT_SETBOOL_METHOD(QAbstractButton,setAutoRepeat,QPushButton,"autoRepeat");
PHP_QT_ABSTRACT_SETBOOL_METHOD(QAbstractButton,setCheckable,QPushButton,"checkable");
PHP_QT_ABSTRACT_SETBOOL_METHOD(QAbstractButton,setDown,QPushButton,"down");

