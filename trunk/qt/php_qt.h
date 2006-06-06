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
#define MONITOR

#include <iostream>
using namespace std;

#include "defined.h"

#include <QTextStream>
#include <QVariant>
#include <QWidget>

#define QOUT()                                              \
    extern QTextStream qout(stdout, QIODevice::WriteOnly);  \

#ifndef NOT_YET_IMPLEMENTED
#define NOT_YET_IMPLEMENTED { php_printf("%s(): functionality not yet implemented\n",get_active_function_name(TSRMLS_C));} 
#endif

#define PHP_QT_HASH_QOBJECT  "qobject_list"
#define PHP_QT_REGISTER_OBJECT(list_entry)  zend_hash_update(HASH_OF(this_ptr),PHP_QT_HASH_QOBJECT,strlen(PHP_QT_HASH_QOBJECT),(void*)&list_entry,sizeof(QObject),NULL)
#define PHP_QT_FETCH_OBJECT(list_entry)     zend_hash_find(HASH_OF(this_ptr),PHP_QT_HASH_QOBJECT,strlen(PHP_QT_HASH_QOBJECT),(void**)&list_entry)

#define PHP_QT_DECLARE_PROPERTY(property)           \
    zend_declare_property_null(QObject_ce_ptr,property,strlen(property),ZEND_ACC_PROTECTED TSRMLS_CC);

#define PHP_QT_REGISTER(object)     \
    zend_rsrc_list_entry le;        \
    le.ptr = object;                \
    php_qt_register(getThis(),le);  \

#define PHP_QT_FETCH()  \
	php_qt_fetch(getThis()) \

#define PHP_QT_DESTRUCT(classname)              \
ZEND_METHOD(classname,__desctruct){             \
    classname *o = (classname*) PHP_QT_FETCH(); \
    o->~classname();                            \
}                                               \

#define PHP_QT_RET_OBJ(classname,obj)                   \
zend_class_entry *ce;                                   \
if(obj != NULL) {                                       \
    object_init_ex(return_value, classname##_ce_ptr);   \
    zend_rsrc_list_entry le;                            \
    le.ptr = obj;                                       \
    php_qt_register(return_value,le);                   \
    return;                                             \
}                                                       \
else                                                    \
    RETURN_NULL();                                      \

/* default return macros */

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

#define PHP_QT_RETURN_OBJ_METHOD(classname, function, object_type)  \
ZEND_METHOD(classname,function){                                    \
    if(getThis() != NULL){                                          \
        classname *o = (classname*) PHP_QT_FETCH();                 \
        PHP_QT_RET_OBJ(object_type,o->function());                  \
    }                                                               \
    RETURN_NULL();                                                  \
} 

#define PHP_QT_RETURN_PROPERTY_OBJ_METHOD(classname,function)                                        \
ZEND_METHOD(classname,function){                                                                                  \
    zval* return_;                                                                                              \
    if(getThis() != NULL) {                                                                                     \
        return_ = zend_read_property(Z_OBJCE_P(getThis()),getThis(),#function,strlen(#function),1 TSRMLS_CC);         \
        RETURN_ZVAL(return_,1,0); \
    } else php_error(E_WARNING,"empty object");                                                                 \
}

/* static macros */

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

#define PHP_QT_STATIC_RETURN_METHOD(classname, function, returntype)  \
ZEND_METHOD(classname,function){                            \
  if(getThis() != NULL){                                    \
    classname *o = (classname*) PHP_QT_FETCH();             \
    returntype(o->function());                              \
  } else                                                    \
    returntype(classname::function());                      \
  }                                                         \

#define PHP_QT_STATIC_RETURN_OBJ_METHOD(classname, function, object_type) \
ZEND_METHOD(classname,function){                                \
    if(getThis() != NULL){                                      \
        classname *o = (classname*) PHP_QT_FETCH();             \
        PHP_QT_RET_OBJ(object_type,o->function());              \
    } else  {                                                   \
        PHP_QT_RET_OBJ(object_type,classname::function())       \
    }                                                           \
    RETURN_NULL();                                              \
} 


/* default set macros */

#define PHP_QT_SET_PROPERTY_OBJ_METHOD(classname,function,z_property,z_type)                 \
ZEND_METHOD(classname,function){                                                        \
    zval *object;                                                                       \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {      \
        return;                                                                         \
    }                                                                                   \
    z_type *tmp = (z_type*) php_qt_fetch(object);                               \
    classname *QObject_ptr = (classname*) PHP_QT_FETCH();                               \
    QObject_ptr->function((const z_type&) tmp);                                      \
    zend_update_property(Z_OBJCE_P(getThis()),getThis(),#z_property,strlen(#z_property),object TSRMLS_CC);    \
    RETURN_NULL();                              \
}                                               \

#define PHP_QT_SET_OBJ_METHOD(classname,function,z_type)                                \
ZEND_METHOD(classname,function){                                                        \
    zval *object;                                                                       \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {      \
        return;                                                                         \
    }                                                                                   \
    z_type *tmp = (z_type*) php_qt_fetch(object);                                       \
    classname *QObject_ptr = (classname*) PHP_QT_FETCH();                               \
    QObject_ptr->function((z_type*) tmp);                                               \
    RETURN_NULL();                                                                      \
}                                                                                       \

#define PHP_QT_SETBOOL_METHOD(classname,function)                               \
ZEND_METHOD(classname,function){                                                \
    zend_bool b;                                                                \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b",&b) == FAILURE) {    \
            return;                                                             \
    }                                                                           \
    classname* obj = (classname*) PHP_QT_FETCH();                               \
    obj->function(b);                                                           \
    RETURN_NULL();                                                              \
}                                                                               \

#define PHP_QT_SETLONG_METHOD(classname,function)                               \
ZEND_METHOD(classname,function){                                                \
    long l;                                                                     \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l",&l) == FAILURE) {    \
            return;                                                             \
    }                                                                           \
    classname* obj = (classname*) PHP_QT_FETCH();                               \
    obj->function(l);                                                           \
    RETURN_NULL();                                                              \
}                                                                               \

#define PHP_QT_SETPROPERTY_LONG_METHOD(classname,function,z_property)            \
    PHP_QT_SETPROPERTY_LONGENUM_METHOD(classname,function,int,z_property)        \

#define PHP_QT_SETPROPERTY_LONGENUM_METHOD(classname,function,type,property)    \
ZEND_METHOD(classname,function){                                                \
    long l;                                                                     \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l",&l) == FAILURE) {    \
            return;                                                             \
    }                                                                           \
    classname* obj = (classname*) PHP_QT_FETCH();                               \
    obj->function((type)l);                                                     \
    zend_update_property_long(Z_OBJCE_P(getThis()),getThis(),#property,strlen(#property),l TSRMLS_CC);    \
    RETURN_NULL();                                                              \
}                                                                               \

#define PHP_QT_SETPROPERTY_BOOL_METHOD(classname,function,z_property)           \
    PHP_QT_SETPROPERTY_BOOLENUM_METHOD(classname,function,bool,z_property)      \

#define PHP_QT_SETPROPERTY_BOOLENUM_METHOD(classname,function,type,property)    \
ZEND_METHOD(classname,function){                                                \
    long b;                                                                    \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b",&b) == FAILURE) {    \
            return;                                                             \
    }                                                                           \
    classname* obj = (classname*) PHP_QT_FETCH();                               \
    obj->function((type)b);                                                     \
    zend_update_property_bool(Z_OBJCE_P(getThis()),getThis(),#property,strlen(#property),b TSRMLS_CC);    \
    RETURN_NULL();                                                              \
}                                                                               \

#define PHP_QT_SET_LONGENUM_METHOD(classname,function,type)                          \
ZEND_METHOD(classname,function){                                                \
    zval l;                                                                     \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l",&l) == FAILURE) {    \
            return;                                                             \
    }                                                                           \
    classname* obj = (classname*) PHP_QT_FETCH();                               \
    obj->function((type)l.value.lval);\
    RETURN_NULL();                                                              \
}                                                                               \


#define PHP_QT_SETLONG_2_METHOD(classname,function)                             \
ZEND_METHOD(classname,function)                                                 \
{                                                                               \
    long val1, val2;                                                            \
    int num_args = 0;                                                           \
    num_args = ZEND_NUM_ARGS() TSRMLS_CC;                                       \
    if(num_args == 2){                                                          \
        if(zend_parse_parameters(num_args TSRMLS_CC,"ll", &val1, &val2) == FAILURE) {   \
            RETURN_NULL();                                                      \
        }                                                                       \
        classname *o = (classname*) PHP_QT_FETCH();                             \
        o->function(val1,val2);                                                 \
    }                                                                           \
}                                                                               \

/* abstract macros 
 * Note: macros sets properties */

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

#define PHP_QT_ABSTRACT_SETLONG_2_METHOD(classname,function,pseudo)     \
ZEND_METHOD(classname,function){                                                \
    long a, b;                                                                    \
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ll",&a,&b) == FAILURE) {    \
            return;                                                             \
    }                                                                           \
    pseudo* pseudo_ptr = (pseudo*) PHP_QT_FETCH();                                          \
    pseudo_ptr->function(a,b);                                                    \
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

//    zval** args = new zval*[ZEND_NUM_ARGS()*sizeof(zval)];          \

#define PHP_QT_FETCH_ARGS();                                        \
    zval** args = (zval**) malloc(ZEND_NUM_ARGS()*sizeof(zval));          \
    for(int i=0;i<ZEND_NUM_ARGS();i++){                             \
        zend_parse_parameters(1 TSRMLS_CC, "z", &args[i]);          \
    }                                                               

//     char* format = (char*) emalloc(ZEND_NUM_ARGS());    \

//#define PHP_QT_FETCH_ARGS();                                        \
//    zval* args[10];    \
//    string format = "";\
//    for(int i=0;i<ZEND_NUM_ARGS();i++){                             \
//        format += "z";                 \
//    }                                   \
//    cout << format << ",\n";\
//    zend_parse_parameters(1 TSRMLS_CC, (char*) format.data(), &args[0], &args[1], &args[2], &args[3], &args[4], &args[5], &args[6], &args[7], &args[8], &args[9]);          \

#define PHP_QT_FETCH_0_ARGS();                                        \

#define PHP_QT_FETCH_1_ARGS();                                        \
    zval* arg_0;    \
    zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, 1 TSRMLS_CC, "z", &arg_0);          

#define PHP_QT_FETCH_2_ARGS();                                        \
    zval* arg_0;    \
    zval* arg_1;    \
    zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, 2 TSRMLS_CC, "zz", &arg_0, &arg_1);          \

#define PHP_QT_FETCH_3_ARGS();                                        \
    zval* arg_0;    \
    zval* arg_1;    \
    zval* arg_2;    \
    zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, 3 TSRMLS_CC, "zzz", &arg_0, &arg_1, &arg_2);          

#define PHP_QT_FETCH_4_ARGS();                                        \
    zval* arg_0;    \
    zval* arg_1;    \
    zval* arg_2;    \
    zval* arg_3;    \
    zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, 4 TSRMLS_CC, "zzzz", &arg_0, &arg_1, &arg_2, &arg_3);          

#define PHP_QT_FETCH_5_ARGS();                                        \
    zval* arg_0;    \
    zval* arg_1;    \
    zval* arg_2;    \
    zval* arg_3;    \
    zval* arg_4;    \
    zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, 5 TSRMLS_CC, "zzzzz", &arg_0, &arg_1, &arg_2, &arg_3, &arg_4);          

#define PHP_QT_FETCH_6_ARGS();                                        \
    zval* arg_0;    \
    zval* arg_1;    \
    zval* arg_2;    \
    zval* arg_3;    \
    zval* arg_4;    \
    zval* arg_5;    \
    zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, 6 TSRMLS_CC, "zzzzzz", &arg_0, &arg_1, &arg_2, &arg_3, &arg_4, &arg_5);          

#define PHP_QT_FETCH_7_ARGS();                                        \
    zval* arg_0;    \
    zval* arg_1;    \
    zval* arg_2;    \
    zval* arg_3;    \
    zval* arg_4;    \
    zval* arg_5;    \
    zval* arg_6;    \
    zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, 7 TSRMLS_CC, "zzzzzzz", &arg_0, &arg_1, &arg_2, &arg_3, &arg_4, &arg_5, &arg_6);          

#define PHP_QT_FETCH_8_ARGS();                                        \
    zval* arg_0;    \
    zval* arg_1;    \
    zval* arg_2;    \
    zval* arg_3;    \
    zval* arg_4;    \
    zval* arg_5;    \
    zval* arg_6;    \
    zval* arg_7;    \
    zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, 8 TSRMLS_CC, "zzzzzzzz", &arg_0, &arg_1, &arg_2, &arg_3, &arg_4, &arg_5, &arg_6, &arg_7);          

#define PHP_QT_FETCH_9_ARGS();                                        \
    zval* arg_0;    \
    zval* arg_1;    \
    zval* arg_2;    \
    zval* arg_3;    \
    zval* arg_4;    \
    zval* arg_5;    \
    zval* arg_6;    \
    zval* arg_7;    \
    zval* arg_8;    \
    zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, 9 TSRMLS_CC, "zzzzzzzzz", &arg_0, &arg_1, &arg_2, &arg_3, &arg_4, &arg_5, &arg_6, &arg_7, &arg_8);          

#define PHP_QT_FETCH_10_ARGS();                                        \
    zval* arg_0;    \
    zval* arg_1;    \
    zval* arg_2;    \
    zval* arg_3;    \
    zval* arg_4;    \
    zval* arg_5;    \
    zval* arg_6;    \
    zval* arg_7;    \
    zval* arg_8;    \
    zval* arg_9;    \
    zend_parse_parameters_ex(ZEND_PARSE_PARAMS_QUIET, 10 TSRMLS_CC, "zzzzzzzzzz", &arg_0, &arg_1, &arg_2, &arg_3, &arg_4, &arg_5, &arg_6, &arg_7, &arg_8, &arg_9);          


#define PHP_QT_REGISTER_MOC(object)     \
    zend_rsrc_list_entry le;        \
    le.ptr = object;                \
    php_qt_register_moc(this->zend_ptr,le);  \

#define PHP_QT_FETCH_MOC()  \
	php_qt_fetch_moc(this->zend_ptr) \


#define PHP_QT_MOC(classname)                                               \
const QMetaObject * classname##_php_qt::metaObject() const                  \
{                                                                           \
    QMetaObject* d = php_qt_getMocData(this->zend_ptr,#classname,&staticMetaObject); \
}                                                                           \
                                                                            \
int classname##_php_qt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)    \
{                                                                           \
    int _id2 = _id;                                                         \
    _id = classname::qt_metacall(_c,_id,_a);                                \
    QMetaObject* d = (QMetaObject*) classname##_php_qt::metaObject();       \
    if (_id < 0)                                                            \
        return _id;                                                         \
    else _id = _id2;                                                        \
    if (_c == QMetaObject::InvokeMetaMethod) {                              \
     QMetaObject* d = (QMetaObject*) this->metaObject();                    \
     char* method_name = new char[strlen((d->method(_id)).signature())];    \
     strcpy(method_name,(char*) (d->method(_id)).signature());              \
     int i;                                                                 \
     for(i = 0; i < strlen(method_name); i++){                              \
        if(method_name[i] == 40){                                           \
            method_name[i] = 0;                                             \
            break;                                                          \
        }                                                                   \
     }                                                                      \
     if(d->method(_id).methodType() == QMetaMethod::Slot){                  \
        int j = 0;                                                          \
        zval** args[1];                                                     \
        QList<QByteArray> qargs = d->method(_id).parameterTypes();          \
        for(i = 0; i < qargs.count(); i++){                                 \
            zval *arg;                                                      \
            MAKE_STD_ZVAL(arg);                                             \
            if(!strncmp("int",(const char*) qargs[i],3)){                   \
                ZVAL_LONG(arg, *reinterpret_cast< int*>(_a[i+1]));          \
            } else if(!strncmp("char*",(const char*) qargs[i],5)){          \
                ZVAL_STRING(arg, *reinterpret_cast< char**>(_a[i+1]), 1);   \
            } else if(!strncmp("bool",(const char*) qargs[i],4)){           \
                ZVAL_BOOL(arg, *reinterpret_cast< bool*>(_a[i+1]));         \
            } else if(!strncmp("double",(const char*) qargs[i],4)){         \
                ZVAL_DOUBLE(arg, *reinterpret_cast< double*>(_a[i+1]));     \
            } else {                                                        \
                    zend_class_entry *ce;                                   \
                    object_init_ex(arg, classname##_ce_ptr);                \
                    zend_rsrc_list_entry le;                                \
                    le.ptr = *reinterpret_cast< classname **>(_a[1]);       \
                    php_qt_register(arg, le);                               \
            }                                                               \
            args[j++] = &arg;                                               \
        }                                                                   \
        php_qt_callmethod(this->zend_ptr, method_name, j, args);            \
     } else {                                                               \
        void *_b[] = { 0, _a[1] };                                          \
        QMetaObject::activate(this, d, 0, _b);                              \
     }                                                                      \
     delete d;                                                              \
     delete method_name;                                                    \
    }                                                                       \
    return _id;                                                             \
}                                                                           

#define RETURN_VOID(a) \
a; \
return;

#define RETURN_ARRAY(a)\
a; \
return;

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "zend_php_qt.h"

struct moc {
    char* stringdata; 
    uint* signature;
};

void* php_qt_fetch(zval* this_ptr);
void php_qt_register(zval* this_ptr, zend_rsrc_list_entry le);
void php_qt_setObject(zval* this_ptr, void* obj);
static void destroy_php_qt_hashtable(zend_rsrc_list_entry *rsrc);

void* php_qt_fetch_moc(zval* this_ptr);
void php_qt_register_moc(zval* this_ptr, zend_rsrc_list_entry le);

void php_qt_callmethod(zval* zend_ptr, char* methodname, zend_uint param_count, zval** params[]);
QMetaObject* php_qt_getMocData(zval* this_ptr, char* classname, const QMetaObject* superdata);
zval* invokeToQString(zval* arg);
bool inherits(zend_class_entry* ace, uint objectId, int recursion = 0);

extern int le_php_qt_hashtype;
extern HashTable php_qt_objptr_hash;

void _register_QObject();
void _register_QEvent();



//extern zend_class_entry *QObject_ce_ptr;
extern zend_class_entry *QEvent_ce_ptr;

extern zend_class_entry *QCharRef_ce_ptr;
void    _register_QCharRef();
extern zend_class_entry *QLatin1String_ce_ptr;
void    _register_QLatin1String();

#include "ag_extern_zend_class_entry.inc"



