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

#include <QPushButton>

#include "php_qt.h"

/* QPushButton */

ZEND_METHOD(QPushButton,__construct){

    if(ZEND_NUM_ARGS() > 0){
        char *string;
        int string_len;

	    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s",&string, &string_len) == FAILURE) {
            return;
        }
        QPushButton* QPushButton_ptr = new QPushButton(string);
        PHP_QT_REGISTER(QPushButton_ptr);

        RETURN_NULL();

// QIcon beachten
    } else {
    
        QPushButton* QPushButton_ptr = new QPushButton();
        PHP_QT_REGISTER(QPushButton_ptr);

        RETURN_NULL();
    }
}

ZEND_METHOD(QPushButton,autoDefault){

    QPushButton *o = (QPushButton*) PHP_QT_FETCH();
    RETURN_BOOL(o->autoDefault());

}

ZEND_METHOD(QPushButton,isDefault){

    QPushButton *o = (QPushButton*) PHP_QT_FETCH();
    RETURN_BOOL(o->isDefault());

}

ZEND_METHOD(QPushButton,isFlat){

    QPushButton *o = (QPushButton*) PHP_QT_FETCH();
    RETURN_BOOL(o->isFlat());

}

ZEND_METHOD(QPushButton,menu){
    zval* return_;
    return_ = zend_read_property(Z_OBJCE_P(getThis()),getThis(),"menu",strlen("menu"),1 TSRMLS_CC);
    RETURN_ZVAL(return_,1,0);
}

ZEND_METHOD(QPushButton,setAutoDefault){

    bool *b;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b", &b) == FAILURE) {
        return; 
    }

    QPushButton *o = (QPushButton*) PHP_QT_FETCH();
    o->setAutoDefault(*b);
    RETURN_NULL();

}

ZEND_METHOD(QPushButton,setDefault){

    bool *b;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b", &b) == FAILURE) {
        return; 
    }

    QPushButton *o = (QPushButton*) PHP_QT_FETCH();
    o->setDefault(b);
    RETURN_NULL();

}

ZEND_METHOD(QPushButton,setFlat){

    bool *b;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b", &b) == FAILURE) {
        return; 
    }

    QPushButton *o = (QPushButton*) PHP_QT_FETCH();
    o->setFlat(b);
    RETURN_NULL();

}


ZEND_METHOD(QPushButton,setMenu){

    zval *object;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
        return; 
    }
    QMenu *tmp = (QMenu*) php_qt_fetch(object);
    QPushButton *QPushButton_ptr = (QPushButton*) PHP_QT_FETCH();
    QPushButton_ptr->setMenu(tmp);
    zend_update_property(Z_OBJCE_P(getThis()),getThis(),"menu",strlen("menu"),object TSRMLS_CC);
    RETURN_NULL();

}



