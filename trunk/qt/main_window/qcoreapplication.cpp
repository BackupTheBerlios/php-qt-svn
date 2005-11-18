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

#include <iostream>
using namespace std;

#include <QCoreApplication>
#include "../php_qt.h"

zval* qcoreApplication = NULL;

/**
 *  Constructor
 */ 

ZEND_METHOD(QCoreApplication,__construct){
	int argc__;
	char *argv__[1];
    QCoreApplication *app;
    app = new QCoreApplication(argc__, argv__);
    PHP_QT_REGISTER(app);
	if(qcoreApplication == NULL)
		qcoreApplication = getThis();
}

/// @todo must be implemented
ZEND_METHOD(QCoreApplication,filterEvent){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

ZEND_METHOD(QCoreApplication,notify){
	QObject *receiver = NULL;
	QEvent *event = NULL;
	zval *ob1,*ob2;	
	
    if(ZEND_NUM_ARGS() != 1)
		return;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oo", &ob1,&ob2) == FAILURE)
		return;
	
	receiver = (QObject*) php_qt_fetch(ob1);
	event = (QEvent*) php_qt_fetch(ob2);

    QCoreApplication *o = (QCoreApplication*) PHP_QT_FETCH();
    RETURN_BOOL(o->notify(receiver,event));

}

/// @todo must be implemented
ZEND_METHOD(QCoreApplication,setEventFilter){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QCoreApplication,winEventFilter){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

/**
 *  Public slots functions
 */ 
PHP_QT_STATIC_METHOD(QCoreApplication, quit)

/**
 *  Static functions
 */ 
 
PHP_QT_STATIC_RETURN_METHOD(QCoreApplication, exec, RETURN_LONG)
  
ZEND_METHOD(QCoreApplication,addLibraryPath){
	zval *uservar;
	QCoreApplication *QCoreApplication_ptr;
	
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &uservar) == FAILURE) {
        return; 
    }
	
	if(getThis() != NULL) QCoreApplication_ptr = (QCoreApplication*) PHP_QT_FETCH();	

	if(Z_TYPE_P(uservar) == IS_STRING)
	{
		QString tmp(Z_STRVAL_P(uservar));
		if(getThis() != NULL)
			QCoreApplication_ptr->addLibraryPath(tmp);
		else
			QCoreApplication::addLibraryPath(tmp);
	}
	else
	{
		if(Z_TYPE_P(uservar) == IS_OBJECT)
		{
			QString *tmp = (QString*) php_qt_fetch(uservar);
			if(getThis() != NULL)
				QCoreApplication_ptr->addLibraryPath((const QString&)tmp);
			else
				QCoreApplication::addLibraryPath((const QString&)tmp);
		}
	}	
    RETURN_NULL();     
}

ZEND_METHOD(QCoreApplication,applicationDirPath){
	QString tmp;
	
	if(getThis() != NULL)
	{
		QCoreApplication *QCoreApplication_ptr = (QCoreApplication*) PHP_QT_FETCH();  
		tmp = QCoreApplication_ptr->applicationDirPath();
	}
	else
		tmp = QCoreApplication::applicationDirPath();
	
	RETURN_STRING(tmp.toLatin1().data(),tmp.length());
}

ZEND_METHOD(QCoreApplication,applicationFilePath){
	QString tmp;
	
	if(getThis() != NULL)
	{
		QCoreApplication *QCoreApplication_ptr = (QCoreApplication*) PHP_QT_FETCH();  
		tmp = QCoreApplication_ptr->applicationFilePath();
	}
	else
		tmp = QCoreApplication::applicationFilePath();
	
	RETURN_STRING(tmp.toLatin1().data(),tmp.length());
}

ZEND_METHOD(QCoreApplication,applicationName){
	QString tmp;
	
	if(getThis() != NULL)
	{
		QCoreApplication *QCoreApplication_ptr = (QCoreApplication*) PHP_QT_FETCH();  
		tmp = QCoreApplication_ptr->applicationName();
	}
	else
		tmp = QCoreApplication::applicationName();
	
	RETURN_STRING(tmp.toLatin1().data(),tmp.length());
}

PHP_QT_STATIC_RETURN_METHOD(QCoreApplication, argc, RETURN_LONG)

/// @todo must be implemented
ZEND_METHOD(QCoreApplication,argv){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

PHP_QT_STATIC_RETURN_METHOD(QCoreApplication, closingDown, RETURN_BOOL)
PHP_QT_SETLONG_STATIC_METHOD(QCoreApplication,exit)
PHP_QT_STATIC_METHOD(QCoreApplication, flush)
PHP_QT_STATIC_RETURN_METHOD(QCoreApplication, hasPendingEvents, RETURN_BOOL)

/// @todo must be implemented
ZEND_METHOD(QCoreApplication,installTranslator){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

ZEND_METHOD(QCoreApplication,instance){
	RETURN_ZVAL(qcoreApplication, 1, 0)
} 


/// @todo must be implemented
ZEND_METHOD(QCoreApplication,libraryPaths){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

ZEND_METHOD(QCoreApplication,organizationDomain){
	QString tmp;
	
	if(getThis() != NULL)
	{
		QCoreApplication *QCoreApplication_ptr = (QCoreApplication*) PHP_QT_FETCH();  
		tmp = QCoreApplication_ptr->organizationDomain();
	}
	else
		tmp = QCoreApplication::organizationDomain();
	
	RETURN_STRING(tmp.toLatin1().data(),tmp.length());    
}

ZEND_METHOD(QCoreApplication,organizationName){
	QString tmp;
	
	if(getThis() != NULL)
	{
		QCoreApplication *QCoreApplication_ptr = (QCoreApplication*) PHP_QT_FETCH();  
		tmp = QCoreApplication_ptr->organizationName();
	}
	else
		tmp = QCoreApplication::organizationName();
	
	RETURN_STRING(tmp.toLatin1().data(),tmp.length() ); 
}

ZEND_METHOD(QCoreApplication,postEvent){
	QObject *receiver = NULL;
	QEvent *event = NULL;
	zval *ob1,*ob2;	
	
    if(ZEND_NUM_ARGS() != 1)
		return;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oo", &ob1,&ob2) == FAILURE)
		return;
	
	receiver = (QObject*) php_qt_fetch(ob1);
	event = (QEvent*) php_qt_fetch(ob2);

	if(getThis() != NULL)
	{
    	QCoreApplication *o = (QCoreApplication*) PHP_QT_FETCH();
    	o->postEvent(receiver,event); 
	}
	else
	{
		QCoreApplication::postEvent(receiver,event);
	}
	
	RETURN_NULL();
}

/// @todo must be implemented
ZEND_METHOD(QCoreApplication,processEvents){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}


ZEND_METHOD(QCoreApplication,removeLibraryPath){
	zval *uservar;
	QCoreApplication *QCoreApplication_ptr;
	
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &uservar) == FAILURE) {
        return; 
    }
	
	if(getThis() != NULL) QCoreApplication_ptr = (QCoreApplication*) PHP_QT_FETCH();	
	
	if(Z_TYPE_P(uservar) == IS_STRING)
	{
		QString tmp(Z_STRVAL_P(uservar));
		if(getThis() != NULL)
			QCoreApplication_ptr->removeLibraryPath(tmp);
		else
			QCoreApplication::removeLibraryPath(tmp);
	}
	else
	{
		if(Z_TYPE_P(uservar) == IS_OBJECT)
		{
			QString *tmp = (QString*) php_qt_fetch(uservar);
			if(getThis() != NULL)
				QCoreApplication_ptr->removeLibraryPath((const QString&)tmp);
			else
				QCoreApplication::removeLibraryPath((const QString&)tmp);
		}
	}   
	
	RETURN_NULL();  
}

ZEND_METHOD(QCoreApplication,removePostedEvents){
	zval *object;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &object) == FAILURE) {
		return;
	}
	
	QObject *receiver = (QObject*) php_qt_fetch(object);

	if(getThis() != NULL)
	{
		QCoreApplication *QCoreApplication_ptr = (QCoreApplication*) PHP_QT_FETCH();
		QCoreApplication_ptr->removePostedEvents(receiver);
		
	}
	else
	{
		QCoreApplication::removePostedEvents(receiver);
	}
		
    RETURN_NULL();    
}

/// @todo must be implemented
ZEND_METHOD(QCoreApplication,removeTranslator){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

ZEND_METHOD(QCoreApplication,sendEvent){
	QObject *receiver = NULL;
	QEvent *event = NULL;
	zval *ob1,*ob2;	
	
    if(ZEND_NUM_ARGS() != 1)
		return;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oo", &ob1,&ob2) == FAILURE)
		return;
	
	receiver = (QObject*) php_qt_fetch(ob1);
	event = (QEvent*) php_qt_fetch(ob2);

	if(getThis() != NULL)
	{
    	QCoreApplication *o = (QCoreApplication*) PHP_QT_FETCH();
    	RETURN_BOOL(o->sendEvent(receiver,event)); 
	}
	else
	{
		RETURN_BOOL(QCoreApplication::sendEvent(receiver,event));
	}
}


ZEND_METHOD(QCoreApplication,sendPostedEvents){
	
	if(ZEND_NUM_ARGS() == 2)
	{
		zval *object;
		long event_type;
		QObject *receiver;
		
		if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ol", &object, &event_type) == FAILURE) 
			return;
			
		receiver = (QObject*) php_qt_fetch(object);
	
		if(getThis() != NULL)
		{
			QCoreApplication *QCoreApplication_ptr = (QCoreApplication*) PHP_QT_FETCH();
			QCoreApplication_ptr->sendPostedEvents(receiver,event_type);
			
		}
		else
		{
			QCoreApplication::sendPostedEvents(receiver,event_type);
		}
	}
	
	if(ZEND_NUM_ARGS() == 0)
	{
		if(getThis() != NULL)
		{
			QCoreApplication *QCoreApplication_ptr = (QCoreApplication*) PHP_QT_FETCH();
			QCoreApplication_ptr->sendPostedEvents();
			
		}
		else
		{
			QCoreApplication::sendPostedEvents();
		}	
	}
		
    RETURN_NULL();    
}

ZEND_METHOD(QCoreApplication,setApplicationName){
	zval *uservar;
	QCoreApplication *QCoreApplication_ptr;
	
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &uservar) == FAILURE) {
        return; 
    }
	
	if(getThis() != NULL) QCoreApplication_ptr = (QCoreApplication*) PHP_QT_FETCH();	
	
	if(Z_TYPE_P(uservar) == IS_STRING)
	{
		QString tmp(Z_STRVAL_P(uservar));
		if(getThis() != NULL)
			QCoreApplication_ptr->setApplicationName(tmp);
		else
			QCoreApplication::setApplicationName(tmp);
	}
	else
	{
		if(Z_TYPE_P(uservar) == IS_OBJECT)
		{
			QString *tmp = (QString*) php_qt_fetch(uservar);
			if(getThis() != NULL)
				QCoreApplication_ptr->setApplicationName((const QString&)tmp);
			else
				QCoreApplication::setApplicationName((const QString&)tmp);
		}
	}   
    RETURN_NULL();  
}

/// @todo must be implemented
ZEND_METHOD(QCoreApplication,setLibraryPaths){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

ZEND_METHOD(QCoreApplication,setOrganizationDomain){
	zval *uservar;
	QCoreApplication *QCoreApplication_ptr;
	
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &uservar) == FAILURE) {
        return; 
    }
	
	if(getThis() != NULL) QCoreApplication_ptr = (QCoreApplication*) PHP_QT_FETCH();	
	
	if(Z_TYPE_P(uservar) == IS_STRING)
	{
		QString tmp(Z_STRVAL_P(uservar));
		if(getThis() != NULL)
			QCoreApplication_ptr->setOrganizationDomain(tmp);
		else
			QCoreApplication::setOrganizationDomain(tmp);
	}
	else
	{
		if(Z_TYPE_P(uservar) == IS_OBJECT)
		{
			QString *tmp = (QString*) php_qt_fetch(uservar);
			if(getThis() != NULL)
				QCoreApplication_ptr->setOrganizationDomain((const QString&)tmp);
			else
				QCoreApplication::setOrganizationDomain((const QString&)tmp);
		}
	}   
    RETURN_NULL();  
}

ZEND_METHOD(QCoreApplication,setOrganizationName){
	zval *uservar;
	QCoreApplication *QCoreApplication_ptr;
	
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &uservar) == FAILURE) {
        return; 
    }

	if(getThis() != NULL) QCoreApplication_ptr = (QCoreApplication*) PHP_QT_FETCH();	

		
	if(Z_TYPE_P(uservar) == IS_STRING)
	{
		QString tmp(Z_STRVAL_P(uservar));
		if(getThis() != NULL)
			QCoreApplication_ptr->setOrganizationName(tmp);
		else
			QCoreApplication::setOrganizationName(tmp);
	}
	else
	{
		if(Z_TYPE_P(uservar) == IS_OBJECT)
		{
			QString *tmp = (QString*) php_qt_fetch(uservar);
			if(getThis() != NULL)
				QCoreApplication_ptr->setOrganizationName((const QString&)tmp);
			else
				QCoreApplication::setOrganizationName((const QString&)tmp);
		}
	}   
    RETURN_NULL();      
}

PHP_QT_STATIC_RETURN_METHOD(QCoreApplication, startingUp, RETURN_BOOL)

/// @todo must be implemented
ZEND_METHOD(QCoreApplication,translate){
    NOT_YET_IMPLEMENTED
    RETURN_NULL();    
}

