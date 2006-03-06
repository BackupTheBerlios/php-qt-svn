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
 * QPushButton.cpp - QPushButton PHP implementation.
 * begin           : Sun Jan 22 19:46:39 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QPushButton>
#include "../php_qt.h"


/*********************************
 *    class     QPushButton */
/*
 *    function  tr
 *    flags:    s
 */
ZEND_METHOD(QPushButton, tr){
		/* ss public*/

		/* const char* , const char* ,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING){
			QPushButton *obj = (QPushButton*) PHP_QT_FETCH();


				QString return_object = (QString) obj->tr( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QPushButton_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			}
		}
	}
}

/*********************************
 *    class     QPushButton */
/*
 *    function  showMenu
 *    flags:    l
 */
ZEND_METHOD(QPushButton, showMenu){
	if (ZEND_NUM_ARGS() == 0){
			QPushButton *obj = (QPushButton*) PHP_QT_FETCH();
			obj->showMenu();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QPushButton */
/*
 *    function  setFlat
 *    flags:    
 */
ZEND_METHOD(QPushButton, setFlat){
		/* l public*/

		/* int ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QPushButton *obj = (QPushButton*) PHP_QT_FETCH();


			obj->setFlat((bool) Z_LVAL_P(z_0));
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QPushButton */
/*
 *    function  qt_invoke
 *    flags:    v
 */
ZEND_METHOD(QPushButton, qt_invoke){
}

/*********************************
 *    class     QPushButton */
/*
 *    function  staticMetaObject
 *    flags:    s
 */
ZEND_METHOD(QPushButton, staticMetaObject){
}

/*********************************
 *    class     QPushButton */
/*
 *    function  qObject
 *    flags:    
 */
ZEND_METHOD(QPushButton, qObject){
}

/*********************************
 *    class     QPushButton */
/*
 *    function  isDefault
 *    flags:    c
 */
ZEND_METHOD(QPushButton, isDefault){
	if (ZEND_NUM_ARGS() == 0){
			QPushButton *obj = (QPushButton*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isDefault());
	}
}

/*********************************
 *    class     QPushButton */
/*
 *    function  setAutoDefault
 *    flags:    
 */
ZEND_METHOD(QPushButton, setAutoDefault){
		/* l public*/

		/* int ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QPushButton *obj = (QPushButton*) PHP_QT_FETCH();


			obj->setAutoDefault((bool) Z_LVAL_P(z_0));
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QPushButton */
/*
 *    function  sizeHint
 *    flags:    c
 */
ZEND_METHOD(QPushButton, sizeHint){
	if (ZEND_NUM_ARGS() == 0){
			QPushButton *obj = (QPushButton*) PHP_QT_FETCH();
				QSize return_object = (QSize) obj->sizeHint();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QPushButton_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QPushButton */
/*
 *    function  qt_cast
 *    flags:    v
 */
ZEND_METHOD(QPushButton, qt_cast){
}

/*********************************
 *    class     QPushButton */
/*
 *    function  metaObject
 *    flags:    cv
 */
ZEND_METHOD(QPushButton, metaObject){
	if (ZEND_NUM_ARGS() == 0){
			QPushButton *obj = (QPushButton*) PHP_QT_FETCH();
				QMetaObject * return_object = (QMetaObject *) obj->metaObject();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QPushButton_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QPushButton */
/*
 *    function  menu
 *    flags:    c
 */
ZEND_METHOD(QPushButton, menu){
	if (ZEND_NUM_ARGS() == 0){
			QPushButton *obj = (QPushButton*) PHP_QT_FETCH();
				QMenu* return_object = (QMenu*) obj->menu();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QPushButton_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QPushButton */
/*
 *    function  setDefault
 *    flags:    
 */
ZEND_METHOD(QPushButton, setDefault){
		/* l public*/

		/* int ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QPushButton *obj = (QPushButton*) PHP_QT_FETCH();


			obj->setDefault((bool) Z_LVAL_P(z_0));
			RETURN_NULL();
			}
		}
	}
}

/*********************************
 *    class     QPushButton */
/*
 *    function  qt_emit
 *    flags:    v
 */
ZEND_METHOD(QPushButton, qt_emit){
}

/*********************************
 *    class     QPushButton */
/*
 *    function  QPushButton
 *    flags:    t
 */
ZEND_METHOD(QPushButton, __construct){
		/* o public*/

		/* qt_QWidget* parent,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(obj_z_0->inherits("QWidget")) {
				QPushButton *QPushButton_ptr = new QPushButton((QWidget*) obj_z_0);
				PHP_QT_REGISTER(QPushButton_ptr);
				RETURN_NULL();
			}
			} else if(Z_TYPE_P(z_0) == IS_STRING) { 
				QPushButton *QPushButton_ptr = new QPushButton((const char*) Z_STRVAL_P(z_0));
				PHP_QT_REGISTER(QPushButton_ptr);
				RETURN_NULL();
			}
		}
	}
		/* oo public*/

		/* const QString& text, qt_QWidget* parent,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT && Z_TYPE_P(z_1) == IS_OBJECT){
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);
			QObject* obj_z_1 = (QObject*) php_qt_fetch(z_1);

			if(!(strcmp(Z_OBJCE_P(z_0)->name,"QString")) && obj_z_1->inherits("QWidget")) {
				QPushButton *QPushButton_ptr = new QPushButton((const QString&) obj_z_0, (QWidget*) obj_z_1);
				PHP_QT_REGISTER(QPushButton_ptr);
				RETURN_NULL();
			} 
			} else if(Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_OBJECT){

			  QObject* obj_z_1 = (QObject*) php_qt_fetch(z_1);

			if(obj_z_1->inherits("QWidget")) {
				QPushButton *QPushButton_ptr = new QPushButton((const char*) Z_STRVAL_P(z_0), (QWidget*) obj_z_1);
				PHP_QT_REGISTER(QPushButton_ptr);
				RETURN_NULL();
			} 
			}
		}
	}
		/* ooo public*/

		/* const QIcon& icon, const QString& text, qt_QWidget* parent,  */

	if (ZEND_NUM_ARGS() == 3){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		zval *z_2; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zzz", &z_0, &z_1, &z_2) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT && Z_TYPE_P(z_1) == IS_OBJECT && Z_TYPE_P(z_2) == IS_OBJECT){
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);
			QObject* obj_z_1 = (QObject*) php_qt_fetch(z_1);
			QObject* obj_z_2 = (QObject*) php_qt_fetch(z_2);


			if(obj_z_0->inherits("QIcon") && Z_OBJCE_P(z_1)->name == "QString" && obj_z_2->inherits("QWidget")) {
				QPushButton *QPushButton_ptr = new QPushButton((const QIcon&) obj_z_0, (const QString&) obj_z_1, (QWidget*) obj_z_2);
				PHP_QT_REGISTER(QPushButton_ptr);
				RETURN_NULL();
			}
			}
		}
	}
}

/*********************************
 *    class     QPushButton */
/*
 *    function  className
 *    flags:    cv
 */
ZEND_METHOD(QPushButton, className){
}

/*********************************
 *    class     QPushButton */
/*
 *    function  autoDefault
 *    flags:    c
 */
ZEND_METHOD(QPushButton, autoDefault){
	if (ZEND_NUM_ARGS() == 0){
			QPushButton *obj = (QPushButton*) PHP_QT_FETCH();
			RETURN_BOOL(obj->autoDefault());
	}
}

/*********************************
 *    class     QPushButton */
/*
 *    function  trUtf8
 *    flags:    s
 */
ZEND_METHOD(QPushButton, trUtf8){
		/* ss public*/

		/* const char* , const char* ,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING){
			QPushButton *obj = (QPushButton*) PHP_QT_FETCH();


				QString return_object = (QString) obj->trUtf8( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QPushButton_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			}
		}
	}
}

/*********************************
 *    class     QPushButton */
/*
 *    function  isFlat
 *    flags:    c
 */
ZEND_METHOD(QPushButton, isFlat){
	if (ZEND_NUM_ARGS() == 0){
			QPushButton *obj = (QPushButton*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isFlat());
	}
}

/*********************************
 *    class     QPushButton */
/*
 *    function  qt_property
 *    flags:    v
 */
ZEND_METHOD(QPushButton, qt_property){
}

/*********************************
 *    class     QPushButton */
/*
 *    function  setMenu
 *    flags:    
 */
ZEND_METHOD(QPushButton, setMenu){
		/* o public*/

		/* QMenu* menu,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QPushButton *obj = (QPushButton*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(obj_z_0->inherits("QMenu")) {
				obj->setMenu((QMenu*) obj_z_0);
			RETURN_NULL();
			}
			}
		}
	}
}


PHP_QT_DESTRUCT(QPushButton);

