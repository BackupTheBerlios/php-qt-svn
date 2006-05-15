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

#include <QMetaMethod>

class QObject_moc : public QObject
{
    public:
        QObject_moc(zval* zend_ptr);

        zval* zend_ptr;
        QMetaObject* dynamicMetaObject;

        const QMetaObject* metaObject() const;
        int qt_metacall(QMetaObject::Call _c, int _id, void **_a);
        QObject* protected_sender() const;
        
};

QObject *QObject_moc::protected_sender() const
{
    return this->sender();
}

const QMetaObject *QObject_moc::metaObject() const
{
    return php_qt_getMocData(this->zend_ptr,"QObject",&staticMetaObject);;
}

QObject_moc::QObject_moc(zval* zend_ptr)
{
    this->zend_ptr = zend_ptr;
    dynamicMetaObject = new QMetaObject;
    dynamicMetaObject = php_qt_getMocData(this->zend_ptr,"QObject",&staticMetaObject);
//    cout << dynamicMetaObject->indexOfSignal("valueChanged(int)")<<"\n";
}

int QObject_moc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{

    QMetaObject* d = (QMetaObject*) this->metaObject();
    char* method_name = new char[strlen((d->method(_id)).signature())];
    strcpy(method_name,(char*) (d->method(_id)).signature());

    // breaks the string at the first bracket
    int i;
    for(i = 0; i < strlen(method_name); i++){
        if(method_name[i] == 40){
            method_name[i] = 0;
            break;
        }
    }

    // is a Slot
    if(d->method(_id).methodType() == QMetaMethod::Slot){
        int j = 0;
        zval** args[1];
        QList<QByteArray> qargs = d->method(_id).parameterTypes();
        for(i = 0; i < qargs.count(); i++){

            zval *arg;
            MAKE_STD_ZVAL(arg);

            // invoke to zend types
            if(!strncmp("int",(const char*) qargs[i],3)){
                ZVAL_LONG(arg, *reinterpret_cast< int*>(_a[i+1]));
            } else if(!strncmp("char*",(const char*) qargs[i],5)){
                ZVAL_STRING(arg, *reinterpret_cast< char**>(_a[i+1]), 1);
            } else if(!strncmp("bool",(const char*) qargs[i],4)){
                ZVAL_BOOL(arg, *reinterpret_cast< bool*>(_a[i+1]));
            } else if(!strncmp("double",(const char*) qargs[i],4)){
                ZVAL_DOUBLE(arg, *reinterpret_cast< double*>(_a[i+1]));
            } else {
                    // must be an object
                    zend_class_entry *ce;
                    object_init_ex(arg, QObject_ce_ptr);
                    zend_rsrc_list_entry le;
                    le.ptr = *reinterpret_cast< QObject**>(_a[1]);
                    php_qt_register(arg, le);
                    
            }

            args[j++] = &arg;

        }

        php_qt_callmethod(this->zend_ptr, method_name, j, args);

    // is a signal
    } else {
        void *_b[] = { 0, _a[1] };
        QMetaObject::activate(this, d, 0, _b);
    }

    delete d;
    delete method_name;

    return _id;

}


ZEND_METHOD(QObject,__construct){

    QObject *QObject_ptr = new QObject_moc(getThis());

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
            php_error(E_ERROR,"connect failed\n");
            RETURN_NULL(); 
        }
        receiver_ptr = static_cast<QObject*>(php_qt_fetch(receiver));    
    } else {
        if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ozz", &sender, &signal, &slot) == FAILURE) {
            php_error(E_ERROR,"connect failed\n");
            RETURN_NULL(); 
        }
        if(getThis() == NULL){
            php_error(E_ERROR,"zend object lost, cannot connect Signals/Slots. connect() should not be called statically without a this argument.\n");
        }
        receiver_ptr = static_cast<QObject*>(PHP_QT_FETCH());
    }

    QObject *sender_ptr = static_cast<QObject*>(php_qt_fetch(sender));

    const char* __signal = Z_STRVAL_P(signal);
    const char* __slot = Z_STRVAL_P(slot);

    if(num_args==4){
        RETURN_BOOL(QObject::connect(static_cast<const QObject*>(sender_ptr), __signal, static_cast<const QObject*>(receiver_ptr), __slot));
    } else if(num_args==3){
        RETURN_BOOL(receiver_ptr->connect(static_cast<const QObject*>(sender_ptr), __signal, __slot));
    }

}

ZEND_METHOD(QObject,disconnect){

    zval *sender;
    zval *signal;
    zval *receiver;
    zval *slot;
    
    const char* __signal;

    int num_args = 0;
    num_args = ZEND_NUM_ARGS() TSRMLS_CC;

    QObject *sender_ptr;

    if(num_args == 4){
        if(zend_parse_parameters(4 TSRMLS_CC,"ozoz", &sender, &signal, &receiver, &slot) == FAILURE) {
            RETURN_NULL(); 
        }
        __signal = Z_STRVAL_P(signal);
        sender_ptr = (QObject*) php_qt_fetch(sender);

    } else if(ZEND_NUM_ARGS() == 3){
        if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zoz", &signal, &receiver, &slot) == FAILURE) {
            RETURN_NULL(); 
        }

        __signal = Z_STRVAL_P(signal);
        QObject *sender_ptr = (QObject*) PHP_QT_FETCH();

    } else if(ZEND_NUM_ARGS() == 2){
        if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oz", &receiver, &slot) == FAILURE) {
            RETURN_NULL(); 
        }
        QObject *sender_ptr = (QObject*) PHP_QT_FETCH();
    }

    QObject *receiver_ptr = (QObject*) php_qt_fetch(receiver);

    // emulate Qt's SIGNAL(clicked()) SLOT(show()) Macros
    const char* __slot = Z_STRVAL_P(slot);

    if(ZEND_NUM_ARGS() ==4){
        RETURN_BOOL(QObject::disconnect((const QObject*) sender_ptr, __signal, (const QObject*) receiver_ptr, __slot));
    } else if(ZEND_NUM_ARGS() ==3){
        RETURN_BOOL(sender_ptr->disconnect(__signal, (const QObject*) receiver_ptr, __slot));
    } else {
        RETURN_BOOL(sender_ptr->disconnect((const QObject*) receiver_ptr, __slot));
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
    long id_;
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

/*ZEND_METHOD(QObject,objectName){
    zval* return_;
    return_ = zend_read_property(Z_OBJCE_P(getThis()),getThis(),"objectName",strlen("objectName"),1 TSRMLS_CC);
    RETURN_ZVAL(return_,1,0);
}*/

/*ZEND_METHOD(QObject,parent){
    zval* return_;
    return_ = zend_read_property(Z_OBJCE_P(getThis()),getThis(),"parent",strlen("parent"),1 TSRMLS_CC);
    RETURN_ZVAL(return_,1,0);
}*/

// TODO
ZEND_METHOD(QObject,property){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();
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

/*ZEND_METHOD(QObject,setObjectName){
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
*/
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
    long interval;
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

PHP_QT_RETURN_PROPERTY_OBJ_METHOD(QObject,objectName);
PHP_QT_SET_PROPERTY_OBJ_METHOD(QObject,setObjectName,objectName,QString);
PHP_QT_RETURN_PROPERTY_OBJ_METHOD(QObject,parent);
//PHP_QT_SET_PROPERTY_OBJ_METHOD(QObject,setParent,QObject);
//PHP_QT_RETURN_OBJ_METHOD(QObject,property,QVariant);

ZEND_METHOD(QObject,tr){

  if (ZEND_NUM_ARGS() == 1) {

    char *str;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s", &str) == FAILURE) {
        return; 
    }
    
    QString *return_object;

    if (getThis() != NULL) {
      QObject *obj = (QObject *) PHP_QT_FETCH();
      *return_object = static_cast < QString > (obj->tr(str));
    } else {
      php_error(E_ERROR, "Object not found");
    }
    zend_class_entry *ce;

    object_init_ex(return_value, QString_ce_ptr);
    zend_rsrc_list_entry le;

    le.ptr = return_object;
    php_qt_register(return_value, le);
    return;

  }

}

ZEND_METHOD(QObject,sender){

    QObject *return_object;

    if (getThis() != NULL) {
      QObject_moc *obj = (QObject_moc *) PHP_QT_FETCH();
      return_object = obj->protected_sender();
    } else {
      php_error(E_ERROR, "Object not found");
    }
    zend_class_entry *ce;

    object_init_ex(return_value, QObject_ce_ptr);
    zend_rsrc_list_entry le;

    le.ptr = return_object;
    php_qt_register(return_value, le);
    return;


}

