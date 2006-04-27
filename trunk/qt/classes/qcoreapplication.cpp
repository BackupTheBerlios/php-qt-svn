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
 * QCoreApplication.cpp - QCoreApplication PHP implementation.
 * begin           : Thu Feb 23 15:23:15 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;
#include "../php_qt.h"


#include <QCoreApplication>
#include <QStringList>


/*		public enumEncoding:long {
			Encoding = 0,
			Encoding = 1
		}
*/
/*********************************
 *    class     QCoreApplication
 *    function  removeTranslator
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, removeTranslator){
//qt_QTranslator*
		/* o public*/

		/* qt_QTranslator* ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(obj_z_0->inherits("QTranslator")) {
				obj->removeTranslator((QTranslator*) obj_z_0);
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  tr
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, tr){
		/* ss public*/

		/* const char* , const char* ,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();


			QString* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QString) obj->tr( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			} else {
				*return_object = (QString) QCoreApplication::tr( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QCoreApplication_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  installTranslator
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, installTranslator){
//qt_QTranslator*
		/* o public*/

		/* qt_QTranslator* ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(obj_z_0->inherits("QTranslator")) {
				obj->installTranslator((QTranslator*) obj_z_0);
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  startingUp
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, startingUp){
	if (ZEND_NUM_ARGS() == 0){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			RETURN_BOOL(obj->startingUp());
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  exit
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, exit){
		/* l public*/

		/* int retcode,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();


			obj->exit((int) Z_LVAL_P(z_0));
			RETURN_NULL();
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  addLibraryPath
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, addLibraryPath){
//const QString&
		/* o public*/

		/* const QString& ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(!strcmp(Z_OBJCE_P(z_0)->name,"QString")) {
				obj->addLibraryPath((const QString&) *obj_z_0);
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  setOrganizationDomain
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, setOrganizationDomain){
//const QString&
		/* o public*/

		/* const QString& orgDomain,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(!strcmp(Z_OBJCE_P(z_0)->name,"QString")) {
				obj->setOrganizationDomain((const QString&) *obj_z_0);
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  argv
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, argv){
	if (ZEND_NUM_ARGS() == 0){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			char *** return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (char **) obj->argv();
			} else {
				*return_object = (char **) QCoreApplication::argv();
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QCoreApplication_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  libraryPaths
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, libraryPaths){
	if (ZEND_NUM_ARGS() == 0){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QStringList* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QStringList) obj->libraryPaths();
			} else {
				*return_object = (QStringList) QCoreApplication::libraryPaths();
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QCoreApplication_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  exec
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, exec){
	if (ZEND_NUM_ARGS() == 0){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			RETURN_LONG(obj->exec());
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  setLibraryPaths
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, setLibraryPaths){
//const QStringList&
		/* o public*/

		/* const QStringList& ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(!strcmp(Z_OBJCE_P(z_0)->name,"QStringList")) {
				obj->setLibraryPaths((const QStringList&) *obj_z_0);
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  removeLibraryPath
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, removeLibraryPath){
//const QString&
		/* o public*/

		/* const QString& ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(!strcmp(Z_OBJCE_P(z_0)->name,"QString")) {
				obj->removeLibraryPath((const QString&) *obj_z_0);
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  organizationName
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, organizationName){
	if (ZEND_NUM_ARGS() == 0){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QString* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QString) obj->organizationName();
			} else {
				*return_object = (QString) QCoreApplication::organizationName();
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QCoreApplication_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  setOrganizationName
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, setOrganizationName){
//const QString&
		/* o public*/

		/* const QString& orgName,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(!strcmp(Z_OBJCE_P(z_0)->name,"QString")) {
				obj->setOrganizationName((const QString&) *obj_z_0);
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  event
 *    flags:    
 */
ZEND_METHOD(QCoreApplication, event){
		/* o protected*/
}

/*********************************
 *    class     QCoreApplication
 *    function  instance
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, instance){
	if (ZEND_NUM_ARGS() == 0){

			QCoreApplication ** return_object;
			// check whether method call is static.
			if(getThis() != NULL){
			    QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
				*return_object = static_cast<QCoreApplication*>(obj->instance());
			} else {
                return_object = (QCoreApplication **) malloc(sizeof(QCoreApplication::instance()));
				*return_object = static_cast<QCoreApplication *>(QCoreApplication::instance());
			}
			zend_class_entry *ce;                                   
			object_init_ex(return_value, QCoreApplication_ce_ptr);     
			zend_rsrc_list_entry le;                            
			le.ptr = return_object[0];
			php_qt_register(return_value,le);                   
			return;                                             
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  organizationDomain
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, organizationDomain){
	if (ZEND_NUM_ARGS() == 0){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QString* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QString) obj->organizationDomain();
			} else {
				*return_object = (QString) QCoreApplication::organizationDomain();
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QCoreApplication_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  hasPendingEvents
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, hasPendingEvents){
	if (ZEND_NUM_ARGS() == 0){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			RETURN_BOOL(obj->hasPendingEvents());
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  sendPostedEvents
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, sendPostedEvents){
//qt_QObject*
		/* ol public*/

		/* qt_QObject* receiver, int event_type,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT && Z_TYPE_P(z_1) == IS_LONG){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(obj_z_0->inherits("QObject")) {
				obj->sendPostedEvents((QObject*) obj_z_0, (int) Z_LVAL_P(z_1));
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  applicationName
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, applicationName){
	if (ZEND_NUM_ARGS() == 0){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QString* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QString) obj->applicationName();
			} else {
				*return_object = (QString) QCoreApplication::applicationName();
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QCoreApplication_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  flush
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, flush){
	if (ZEND_NUM_ARGS() == 0){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			obj->flush();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  processEvents
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, processEvents){
		/* l public*/

		/* unsigned int flags,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();


			obj->processEvents((QEventLoop::ProcessEventsFlags) Z_LVAL_P(z_0));
			RETURN_NULL();
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  translate
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, translate){
		/* sssl public*/

		/* const char* context, const char* key, const char* comment, int encoding,  */

	if (ZEND_NUM_ARGS() == 4){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		zval *z_2; // define ZVAL
		zval *z_3; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zzzz", &z_0, &z_1, &z_2, &z_3) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING && Z_TYPE_P(z_2) == IS_STRING && Z_TYPE_P(z_3) == IS_LONG){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();


			QString* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QString) obj->translate( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1) , (const char*) Z_STRVAL_P(z_2) ,(QCoreApplication::Encoding) Z_LVAL_P(z_3));
			} else {
				*return_object = (QString) QCoreApplication::translate( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1) , (const char*) Z_STRVAL_P(z_2) ,(QCoreApplication::Encoding) Z_LVAL_P(z_3));
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QCoreApplication_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  applicationDirPath
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, applicationDirPath){
	if (ZEND_NUM_ARGS() == 0){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QString* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QString) obj->applicationDirPath();
			} else {
				*return_object = (QString) QCoreApplication::applicationDirPath();
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QCoreApplication_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  staticMetaObject
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, staticMetaObject){
}

/*********************************
 *    class     QCoreApplication
 *    function  qObject
 *    flags:    
 */
ZEND_METHOD(QCoreApplication, qObject){
}

/*********************************
 *    class     QCoreApplication
 *    function  argc
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, argc){
	if (ZEND_NUM_ARGS() == 0){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			RETURN_LONG(obj->argc());
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  quit
 *    flags:    sl
 */
ZEND_METHOD(QCoreApplication, quit){
	if (ZEND_NUM_ARGS() == 0){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			obj->quit();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  QCoreApplication
 *    flags:    
 */
ZEND_METHOD(QCoreApplication, __construct){
		/* ll public*/

		/* int argc, char* * argv,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG && Z_TYPE_P(z_1) == IS_LONG){


			QCoreApplication *QCoreApplication_ptr = new QCoreApplication((int&) Z_LVAL_P(z_0) ,(char* *) Z_LVAL_P(z_1));
				PHP_QT_REGISTER(QCoreApplication_ptr);
				RETURN_NULL();
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  watchUnixSignal
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, watchUnixSignal){
		/* ll public*/

		/* int signal, int watch,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG && Z_TYPE_P(z_1) == IS_LONG){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();


			obj->watchUnixSignal((int) Z_LVAL_P(z_0) ,(bool) Z_LVAL_P(z_1));
			RETURN_NULL();
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  removePostedEvents
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, removePostedEvents){
//qt_QObject*
		/* o public*/

		/* qt_QObject* receiver,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(obj_z_0->inherits("QObject")) {
				obj->removePostedEvents((QObject*) obj_z_0);
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  applicationFilePath
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, applicationFilePath){
	if (ZEND_NUM_ARGS() == 0){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QString* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QString) obj->applicationFilePath();
			} else {
				*return_object = (QString) QCoreApplication::applicationFilePath();
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QCoreApplication_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  setApplicationName
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, setApplicationName){
//const QString&
		/* o public*/

		/* const QString& application,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(!strcmp(Z_OBJCE_P(z_0)->name,"QString")) {
				obj->setApplicationName((const QString&) *obj_z_0);
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  trUtf8
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, trUtf8){
		/* ss public*/

		/* const char* , const char* ,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();


			QString* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QString) obj->trUtf8( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			} else {
				*return_object = (QString) QCoreApplication::trUtf8( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QCoreApplication_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QCoreApplication
 *    function  closingDown
 *    flags:    s
 */
ZEND_METHOD(QCoreApplication, closingDown){
	if (ZEND_NUM_ARGS() == 0){
			QCoreApplication *obj = (QCoreApplication*) PHP_QT_FETCH();
			RETURN_BOOL(obj->closingDown());
	}
}


PHP_QT_DESTRUCT(QCoreApplication);

