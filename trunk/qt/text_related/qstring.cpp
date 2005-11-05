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

#include <QString>
#include "../php_qt.h"

/**
 *  QString
 */

ZEND_METHOD(QString,__construct){

    char *string;
    int *string_len;
    QString *QString_ptr;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &string, &string_len) != FAILURE) {

        QString_ptr = new QString((const char*) string);
        zend_update_property_string(Z_OBJCE_P(getThis()),getThis(),"QString",strlen("QString"), string TSRMLS_DC);
        PHP_QT_REGISTER(QString_ptr);

    } else { 

        QString_ptr = new QString();
//        zend_update_property_string(Z_OBJCE_P(getThis()),getThis(),"QString",strlen("QString"), "");
        PHP_QT_REGISTER(QString_ptr);

    }

}

ZEND_METHOD(QString,append){

    const char *string; int *string_len;
    QString *QString_ptr = (QString *) PHP_QT_FETCH();

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &string, &string_len) != FAILURE) {

        QString_ptr->append(string);
        /* achtung: *2 */
        zend_update_property_stringl(Z_OBJCE_P(getThis()),getThis(),"QString",strlen("QString"), (char*) QString_ptr->data(), QString_ptr->size()*2 TSRMLS_DC);
    }

}

ZEND_METHOD(QString,arg){
    NOT_YET_IMPLEMENTED
}

ZEND_METHOD(QString,at){

    int *i;
    QString *QString_ptr = (QString *) PHP_QT_FETCH();

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &i) != FAILURE) {
        if((int) i > QString_ptr->size()){
            php_error(E_ERROR,"QString::at(size) size out of bounds");
            return;
        }

        char* l = (char *) &QString_ptr->at((int) i);
        RETURN_STRING(l,1);
    }

}

