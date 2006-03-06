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
 * QHBoxLayout.cpp - QHBoxLayout PHP implementation.
 * begin           : Thu Feb 23 16:39:38 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;
#include "../php_qt.h"


#include <QHBoxLayout>

/*********************************
 *    class     QHBoxLayout
 *    function  tr
 *    flags:    s
 *    access:    public
 *    return:    QString
 *    params:     const char *, const char * = 0 
 */
ZEND_METHOD(QHBoxLayout, tr){
		/* ss public*/

		/* const char* , const char* ,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING){
			QHBoxLayout *obj = (QHBoxLayout*) PHP_QT_FETCH();


			QString* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QString) obj->tr( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			} else {
				*return_object = (QString) QHBoxLayout::tr( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QHBoxLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QHBoxLayout
 *    function  staticMetaObject
 *    flags:    s
 *    access:    public
 *    return:    QMetaObject*
 *    params:    
 */
ZEND_METHOD(QHBoxLayout, staticMetaObject){
}

/*********************************
 *    class     QHBoxLayout
 *    function  qObject
 *    flags:    
 *    access:    public
 *    return:    QObject*
 *    params:    
 */
ZEND_METHOD(QHBoxLayout, qObject){
}

/*********************************
 *    class     QHBoxLayout
 *    function  QHBoxLayout
 *    flags:    
 *    access:    public
 *    return:    
 *    params:    
 */
ZEND_METHOD(QHBoxLayout, __construct){
	if (ZEND_NUM_ARGS() == 0){
			QHBoxLayout *QHBoxLayout_ptr = new QHBoxLayout();
				PHP_QT_REGISTER(QHBoxLayout_ptr);
				RETURN_NULL();
	}
}

/*********************************
 *    class     QHBoxLayout
 *    function  trUtf8
 *    flags:    s
 *    access:    public
 *    return:    QString
 *    params:     const char *, const char * = 0 
 */
ZEND_METHOD(QHBoxLayout, trUtf8){
		/* ss public*/

		/* const char* , const char* ,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING){
			QHBoxLayout *obj = (QHBoxLayout*) PHP_QT_FETCH();


			QString* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QString) obj->trUtf8( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			} else {
				*return_object = (QString) QHBoxLayout::trUtf8( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QHBoxLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}


PHP_QT_DESTRUCT(QHBoxLayout);

