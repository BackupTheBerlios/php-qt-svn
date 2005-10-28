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

#include <QObject>
#include "../php_qt.h"

ZEND_METHOD(QObject,__construct){

    QObject *QObject_ptr = new QObject();

    if(ZEND_NUM_ARGS() > 0){
        zval *object;

        if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o|", &object) == FAILURE) {
            return; 
        }
        QObject *tmp = (QObject*) php_qt_fetch(object);
        QObject_ptr->setParent(tmp);
        zend_update_property(Z_OBJCE_P(getThis()),getThis(),"parent",strlen("parent"),object TSRMLS_CC);
    }

    PHP_QT_REGISTER(QObject_ptr);
    RETURN_NULL();
}

ZEND_METHOD(QObject,__desctruct){

    QObject *o = (QObject*) PHP_QT_FETCH();
    o->~QObject();

}

/* nur intern */
ZEND_METHOD(QObject,test){

    zval* r_slot;
    MAKE_STD_ZVAL(r_slot);

//    QObject *o = (QObject*) PHP_QT_FETCH();

//    qout << o->objectName();
 //   qout << "\n";
//    RETURN_NULL();
}

ZEND_METHOD(QObject,blockSignals){

    bool *return_;
    if(zend_parse_parameters_ex(0,ZEND_NUM_ARGS() TSRMLS_CC,"b", &return_) == FAILURE) {
        RETURN_FALSE;
    }

    QObject *o = (QObject*) PHP_QT_FETCH();
    RETURN_BOOL(o->blockSignals(return_));

}

ZEND_METHOD(QObject,children){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

ZEND_METHOD(QObject,connect){

    zval *sender;
    zval *signal;
    zval *slot;
 
    int num_args = 0;
    num_args = ZEND_NUM_ARGS();
    
    QObject *receiver_ptr;

    if(num_args == 4){
        zval *receiver;
        if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ozoz", &sender, &signal, &receiver, &slot) == FAILURE) {
            RETURN_NULL(); 
        }
        receiver_ptr = (QObject*) php_qt_fetch(receiver);    
    } else {
        if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ozz", &sender, &signal, &slot) == FAILURE) {
            RETURN_NULL(); 
        }
        receiver_ptr = (QObject*) PHP_QT_FETCH();
    }

    QObject *sender_ptr = (QObject*) php_qt_fetch(sender);

    /* emulate Qt's SIGNAL(clicked()1) SLOT(show()2) Macros */

    zval* r_signal;
    zval *_two;
    MAKE_STD_ZVAL(_two);
    ZVAL_STRING(_two,"2",1);
    concat_function(r_signal,_two,signal);
    const char* __signal = Z_STRVAL_P(r_signal);

    zval* r_slot;
    zval *_one;
    MAKE_STD_ZVAL(_one);
    ZVAL_STRING(_one,"1",1);
    concat_function(r_slot,_one,slot);
    const char* __slot = Z_STRVAL_P(r_slot);

    if(num_args==4){
        RETURN_BOOL(QObject::connect((const QObject*) sender_ptr, (const char*) __signal, (const QObject*) receiver_ptr, (const char*)__slot));
    } else if(num_args==3){
        RETURN_BOOL(receiver_ptr->connect((const QObject*) sender_ptr, (const char*) __signal, (const char*)__slot));
    }

}

ZEND_METHOD(QObject,disconnect){

    zval *sender;
    zval *signal;
    zval *receiver;
    zval *slot;
    
    const char* __signal;
    zval* r_signal;
    zval *_two;
    int num_args = 0;
    num_args = ZEND_NUM_ARGS() TSRMLS_CC;

    QObject *sender_ptr;

    if(num_args == 4){
        if(zend_parse_parameters(4 TSRMLS_CC,"ozoz", &sender, &signal, &receiver, &slot) == FAILURE) {
            RETURN_NULL(); 
        }

        MAKE_STD_ZVAL(_two);
        ZVAL_STRING(_two,"2",1);
        concat_function(r_signal,_two,signal);
        __signal = estrdup(Z_STRVAL_P(r_signal));

        sender_ptr = (QObject*) php_qt_fetch(sender);

    } else if(ZEND_NUM_ARGS() == 3){
        if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zoz", &signal, &receiver, &slot) == FAILURE) {
            RETURN_NULL(); 
        }

        MAKE_STD_ZVAL(_two);
        ZVAL_STRING(_two,"2",1);
        concat_function(r_signal,_two,signal);
        __signal = estrdup(Z_STRVAL_P(r_signal));
        QObject *sender_ptr = (QObject*) PHP_QT_FETCH();

    } else if(ZEND_NUM_ARGS() == 2){
        if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oz", &receiver, &slot) == FAILURE) {
            RETURN_NULL(); 
        }
        QObject *sender_ptr = (QObject*) PHP_QT_FETCH();
    }

    QObject *receiver_ptr = (QObject*) php_qt_fetch(receiver);

    /* emulate Qt's SIGNAL(clicked()) SLOT(show()) Macros */

    zval* r_slot;
    zval *_one;
    MAKE_STD_ZVAL(_one);
    ZVAL_STRING(_one,"1",1);
    concat_function(r_slot,_one,slot);
    const char* __slot = estrdup(Z_STRVAL_P(r_slot));

    if(ZEND_NUM_ARGS() ==4){
        RETURN_BOOL(QObject::disconnect((const QObject*) sender_ptr, (const char*) __signal, (const QObject*) receiver_ptr, (const char*)__slot));
    } else if(ZEND_NUM_ARGS() ==3){
        RETURN_BOOL(sender_ptr->disconnect((const char*) __signal, (const QObject*) receiver_ptr, (const char*)__slot));
    } else {
        RETURN_BOOL(sender_ptr->disconnect((const QObject*) receiver_ptr, (const char*)__slot));
    }

}

ZEND_METHOD(QObject,dumpObjectInfo){
    QObject *o = (QObject*) PHP_QT_FETCH();
    o->dumpObjectInfo();
    RETURN_NULL();
}

ZEND_METHOD(QObject,dumpObjectTree){
    QObject *o = (QObject*) PHP_QT_FETCH();
    o->dumpObjectTree();
    RETURN_NULL();
}

ZEND_METHOD(QObject,event){

    zval *object;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
            RETURN_FALSE; 
    }
    QObject *o = (QObject*) PHP_QT_FETCH();
    QEvent *tmp = (QEvent*) php_qt_fetch(object);
    RETURN_BOOL(o->event(tmp));

}

ZEND_METHOD(QObject,eventFilter){
    zval *object;
    zval *event;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oo", &object, &event) == FAILURE) {
            RETURN_NULL(); 
    }
    QObject *o = (QObject*) PHP_QT_FETCH();
    QObject *object_ = (QObject*) php_qt_fetch(object);
    QEvent *event_ = (QEvent*) php_qt_fetch(event);
    RETURN_BOOL(o->eventFilter(object_,event_));

}

ZEND_METHOD(QObject,findChild){

/*    zval *string;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &string) == FAILURE) {
            RETURN_NULL(); 
    }
    QObject *o = (QObject*) PHP_QT_FETCH();
    QString *string_ = (QString*) php_qt_fetch(string);

    QObject* $newObject = o->findChild<QObject *>();
*/
    NOT_YET_IMPLEMENTED  

    RETURN_NULL();
}

ZEND_METHOD(QObject,findChildren){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}


ZEND_METHOD(QObject,inherits){
    char *string;
    int *string_len;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &string, &string_len) == FAILURE) {
        RETURN_FALSE;
    }
    QObject *o = (QObject*) PHP_QT_FETCH();
    RETURN_BOOL(o->inherits(string));
}

ZEND_METHOD(QObject,installEventFilter){    

    zval *object;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
        return; 
    }
    QObject* tmp = (QObject*) php_qt_fetch(object);
    QObject *o = (QObject*) PHP_QT_FETCH();
    o->installEventFilter(tmp);

    RETURN_NULL();
}

ZEND_METHOD(QObject,isWidgetType){    
        QObject *o = (QObject*) PHP_QT_FETCH();
        RETURN_BOOL(o->isWidgetType());
}

ZEND_METHOD(QObject,killTimer){
    long *id_;
    if(zend_parse_parameters_ex(0,ZEND_NUM_ARGS() TSRMLS_CC,"l", &id_) == FAILURE) {
        return;
    }
    QObject *o = (QObject*) PHP_QT_FETCH();
    o->killTimer((int)id_);

    RETURN_NULL();
}

ZEND_METHOD(QObject,metaObject){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

ZEND_METHOD(QObject,moveToThread){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

ZEND_METHOD(QObject,objectName){
    zval* return_;
    return_ = zend_read_property(Z_OBJCE_P(getThis()),getThis(),"objectName",strlen("objectName"),1 TSRMLS_CC);
    RETURN_ZVAL(return_,1,0);
}

ZEND_METHOD(QObject,parent){
    zval* return_;
    return_ = zend_read_property(Z_OBJCE_P(getThis()),getThis(),"parent",strlen("parent"),1 TSRMLS_CC);
    RETURN_ZVAL(return_,1,0);
}

ZEND_METHOD(QObject,property){
    zval* return_;
    return_ = zend_read_property(Z_OBJCE_P(getThis()),getThis(),"property",strlen("property"),1 TSRMLS_CC);
    RETURN_ZVAL(return_,1,0);
}

ZEND_METHOD(QObject,removeEventFilter){    

    zval *object;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
        return; 
    }
    QObject* tmp = (QObject*) php_qt_fetch(object);
    QObject *o = (QObject*) PHP_QT_FETCH();
    o->removeEventFilter(tmp);

    RETURN_NULL();

}

ZEND_METHOD(QObject,setObjectName){
    zval *object;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
        return; 
    }
    QString *tmp = (QString*) php_qt_fetch(object);
    QObject *QObject_ptr = (QObject*) PHP_QT_FETCH();
    QObject_ptr->setObjectName((const QString&)tmp);
    zend_update_property(Z_OBJCE_P(getThis()),getThis(),"objectName",strlen("objectName"),object TSRMLS_CC);
    RETURN_NULL();
}

ZEND_METHOD(QObject,setParent){

    zval *object;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
        return; 
    }
    QObject *tmp = (QObject*) php_qt_fetch(object);
    QObject *QObject_ptr = (QObject*) PHP_QT_FETCH();
    QObject_ptr->setParent(tmp);
    zend_update_property(Z_OBJCE_P(getThis()),getThis(),"parent",strlen("parent"),object TSRMLS_CC);
    RETURN_NULL();

}

ZEND_METHOD(QObject,setProperty){

    char *string;
    zval *object;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"so", &string, &object) == FAILURE) {
        return; 
    }
    QVariant *qvariant_ = (QVariant*) php_qt_fetch(object);
    QObject *QObject_ptr = (QObject*) PHP_QT_FETCH();
    QObject_ptr->setProperty((const char*) string,(const QVariant&) qvariant_);
    zend_update_property(Z_OBJCE_P(getThis()),getThis(),"property",strlen("property"),object TSRMLS_CC);

    RETURN_NULL();    
}

ZEND_METHOD(QObject,signalsBlocked){
    QObject *o = (QObject*) PHP_QT_FETCH();
    RETURN_BOOL(o->signalsBlocked());
}

ZEND_METHOD(QObject,startTimer){    
    long *interval;
    if(zend_parse_parameters_ex(0,ZEND_NUM_ARGS() TSRMLS_CC,"l", &interval) == FAILURE) {
        return;
    }

    QObject *o = (QObject*) PHP_QT_FETCH();
    RETURN_LONG((long)o->startTimer((int)interval));
}

ZEND_METHOD(QObject,thread){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

