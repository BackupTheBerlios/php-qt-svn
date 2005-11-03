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
 */

/* define macros */
#define debug
#define object_hash_list


#include <QTextStream>
#define QOUT()                                              \
    extern QTextStream qout(stdout, QIODevice::WriteOnly);  \

#ifndef NOT_YET_IMPLEMENTED
#define NOT_YET_IMPLEMENTED { php_printf("%s(): functionality not yet implemented\n",get_active_function_name(TSRMLS_C));} 
#endif

//#define PHP_QT_REGISTER_OBJECT(list_entry)  zend_hash_update(HASH_OF(this_ptr),(char*)getThis(),strlen((char*)getThis()),(void*)&list_entry,sizeof(list_entry.ptr),NULL)
//#define PHP_QT_FETCH_OBJECT(list_entry)     zend_hash_find(HASH_OF(this_ptr),h_name,strlen(h_name),(void**)&list_entry)

#ifdef object_hash_list
#define PHP_QT_HASH_QOBJECT  "qobject_list"
#define PHP_QT_REGISTER_OBJECT(list_entry)  zend_hash_update(HASH_OF(this_ptr),PHP_QT_HASH_QOBJECT,strlen(PHP_QT_HASH_QOBJECT),(void*)&list_entry,sizeof(QObject),NULL)
#define PHP_QT_FETCH_OBJECT(list_entry)     zend_hash_find(HASH_OF(this_ptr),PHP_QT_HASH_QOBJECT,strlen(PHP_QT_HASH_QOBJECT),(void**)&list_entry)
#endif

#ifndef object_hash_list
#define PHP_QT_HASH_QOBJECT  "qobject_list"
//		zend_hash_apply_with_argument(&EG(regular_list), (apply_func_arg_t) clean_module_resource, (void *) &(ld->resource_id) TSRMLS_CC);
//#define PHP_QT_REGISTER_OBJECT(list_entry)  zend_hash_update(&EG(persistent_list),PHP_QT_HASH_QOBJECT,strlen(PHP_QT_HASH_QOBJECT),(void*)&list_entry,sizeof(QObject),NULL)
#define PHP_QT_REGISTER_OBJECT(list_entry)  zend_hash_add(&EG(persistent_list),PHP_QT_HASH_QOBJECT,strlen(PHP_QT_HASH_QOBJECT),(void*)&list_entry,sizeof(QObject),NULL)
#define PHP_QT_FETCH_OBJECT(list_entry)     zend_hash_find(&EG(persistent_list),PHP_QT_HASH_QOBJECT,strlen(PHP_QT_HASH_QOBJECT),(void**)&list_entry)
#endif

#define PHP_QT_REGISTER(object)     \
    zend_rsrc_list_entry le;        \
    le.ptr = object;                \
    php_qt_register(getThis(),le);  \

#define PHP_QT_FETCH() php_qt_fetch(getThis())

#define PHP_QT_METHOD(classname,function)                   \
ZEND_METHOD(classname,function){                            \
    classname *o = (classname*) PHP_QT_FETCH();             \
    o->function();                                          \
    RETURN_NULL();                                          \
}                                                           \

#define PHP_QT_RETURN_METHOD(classname,function,returntype) \
ZEND_METHOD(classname,function){                            \
    classname *o = (classname*) PHP_QT_FETCH();             \
    returntype(o->function());                              \
}                                                           \

#define PHP_QT_STATIC_METHOD(classname, function)           \
ZEND_METHOD(classname,function){                            \
    if(getThis() != NULL){                                  \
        classname *o = (classname*) PHP_QT_FETCH();         \
        o->function();                                      \
    } else classname::function();                           \
    RETURN_NULL();                                          \
}                                                           \


#define PHP_QT_SETBOOL_STATIC_METHOD(classname, function)                    \
ZEND_METHOD(classname,function){                                             \
    zend_bool b;                                                             \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b",&b) == FAILURE) { \
            return;                                                          \
    }                                                                        \
    if(getThis() != NULL){                                                   \
        classname *o = (classname*) PHP_QT_FETCH();                          \
        o->function(b);                                                      \
    }else                                                                    \
        classname::function((bool) b);                                       \
    RETURN_NULL()                                                            \
}                                                                            \


#define PHP_QT_SETLONG_STATIC_METHOD(classname, function)                       \
ZEND_METHOD(classname,function){                                                \
    long l;                                                                     \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l",&l) == FAILURE) {    \
            return;                                                             \
    }                                                                           \
    if(getThis() != NULL){                                                      \
        classname *o = (classname*) PHP_QT_FETCH();                             \
        o->function(l);                                                         \
    }else                                                                       \
        classname::function(l);                                                 \
    RETURN_NULL()                                                               \
}                                                                               \


#define PHP_QT_RET_OBJ(classname,obj)                   \
zend_class_entry *ce;                                   \
if(obj != NULL) {                                       \
    object_init_ex(return_value, classname##_ce_ptr);   \
    zend_rsrc_list_entry le;                            \
    le.ptr = obj;                                       \
    php_qt_register(return_value,le);                   \
}                                                       \
else                                                    \
    RETURN_NULL();                                      \


#define PHP_QT_STATIC_RETURN_OBJ_METHOD(classname, function, object_type) \
ZEND_METHOD(classname,function){                               \
    if(getThis() != NULL){                                     \
        classname *o = (classname*) PHP_QT_FETCH();            \
        PHP_QT_RET_OBJ(object_type,o->function());             \
    } else  PHP_QT_RET_OBJ(object_type,classname::function())  \
    RETURN_NULL();                                             \
} 

#define PHP_QT_RETURN_OBJ_METHOD(classname, function, object_type) \
ZEND_METHOD(classname,function){                                   \
    classname *o = (classname*) PHP_QT_FETCH();                    \
    PHP_QT_RET_OBJ(object_type,o->function());                     \
    RETURN_NULL();                                                 \
} 

	
#define PHP_QT_STATIC_RETURN_METHOD(classname, function, returntype)  \
ZEND_METHOD(classname,function){                            \
  if(getThis() != NULL){                                    \
    classname *o = (classname*) PHP_QT_FETCH();             \
    returntype(o->function());                              \
  } else                                                    \
    returntype(classname::function());                      \
  }                                                         \

#define PHP_QT_SETBOOL_METHOD(classname,function)                               \
ZEND_METHOD(classname,function){                                                \
    zend_bool b;                                                                    \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b",&b) == FAILURE) {    \
            return;                                                             \
    }                                                                           \
    pseudo* pseudo_ptr = new pseudo();                                          \
    pseudo_ptr->function(b);                                                    \
    RETURN_NULL();                                                              \
}                                                                               \

#define PHP_QT_SETLONG_METHOD(classname,function)                               \
ZEND_METHOD(classname,function){                                                \
    long l;                                                                    \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l",&l) == FAILURE) {    \
            return;                                                             \
    }                                                                           \
    classname* obj = (classname*) PHP_QT_FETCH();                                            \
    obj->function(l);                                                    \
    RETURN_NULL();                                                              \
}                                                                               \


#define PHP_QT_ABSTRACT_SETBOOL_METHOD(classname,function,pseudo,name)          \
ZEND_METHOD(classname,function){                                                \
    zend_bool b;                                                                \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b",&b) == FAILURE) {    \
            return;                                                             \
    }                                                                           \
    zend_update_property_bool(Z_OBJCE_P(getThis()),getThis(), name, strlen(name), b TSRMLS_DC); \
    pseudo* pseudo_ptr = (pseudo*) PHP_QT_FETCH();                                          \
    pseudo_ptr->function((bool) b);                                             \
    RETURN_NULL();                                                              \
}                                                                     

#define PHP_QT_ABSTRACT_SETLONG_METHOD(classname,function,pseudo,name)     \
ZEND_METHOD(classname,function){                                                \
    long *b;                                                                    \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l",&b) == FAILURE) {    \
            return;                                                             \
    }                                                                           \
    zend_update_property_long(Z_OBJCE_P(getThis()),getThis(), name, strlen(name), (long)b TSRMLS_DC); \
    pseudo* pseudo_ptr = (pseudo*) PHP_QT_FETCH();                                          \
    pseudo_ptr->function(b);                                                    \
    RETURN_NULL();                                                              \
}                                                                     

#define PHP_QT_ABSTRACT_SETSTRING_METHOD(classname,function,pseudo,name)        \
ZEND_METHOD(classname,function){                                                \
    char *b;                                                                    \
    int *b_len;                                                                 \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s",&b,&b_len) == FAILURE) {    \
            return;                                                             \
    }                                                                           \
    zend_update_property_string(Z_OBJCE_P(getThis()),getThis(), name, strlen(name), (long)b TSRMLS_DC); \
    pseudo* pseudo_ptr = (pseudo*) PHP_QT_FETCH();                                          \
    pseudo_ptr->function(b);                                                    \
    RETURN_NULL();                                                              \
}                                                                     

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "zend_php_qt.h"

void* php_qt_fetch(zval* this_ptr);
void php_qt_register(zval* this_ptr, zend_rsrc_list_entry le);

void _register_QString();
void _register_QLatin1String();
void _register_QObject();
void _register_QApplication();
void _register_QCoreApplication();
void _register_QWidget();
void _register_QAbstractButton();
void _register_QPushButton();
void _register_QEvent();
void _register_QLayoutItem();

extern zend_class_entry *QWidget_ce_ptr;
extern zend_class_entry *QCoreApplication_ce_ptr;
extern zend_class_entry *QEvent_ce_ptr;
extern zend_class_entry *QLayoutItem_ce_ptr;
extern zend_class_entry *QLayout_ce_ptr;
extern zend_class_entry *QSpacerItem_ce_ptr;
