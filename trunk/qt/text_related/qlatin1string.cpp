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

#include <QLatin1String>
#include "../php_qt.h"

static zend_class_entry *QLatin1String_ce_ptr;

/**
 *  QLatin1String
 */

ZEND_METHOD(QLatin1String,__construct){

    char *string; int *string_len;
    QLatin1String* QLatin1String_ptr;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &string, &string_len) == FAILURE) {
        return; }

    zend_update_property_string(Z_OBJCE_P(getThis()),getThis(),"QLatin1String",strlen("QLatin1String"), string TSRMLS_DC);

    QLatin1String_ptr = new QLatin1String(string);
    PHP_QT_REGISTER(QLatin1String_ptr);

}

ZEND_METHOD(QLatin1String,latin1){

    zval *string;
    QLatin1String* QLatin1String_ptr = (QLatin1String*) PHP_QT_FETCH();;
    
    string = zend_read_property(Z_OBJCE_P(getThis()),getThis(),"QLatin1String",strlen("QLatin1String"),1 TSRMLS_DC);

    RETURN_STRING(Z_STRVAL_P(string),1);

}

