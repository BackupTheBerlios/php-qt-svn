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
 * QLayout.cpp - QLayout PHP implementation.
 * begin           : Thu Feb 23 16:36:28 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;
#include "../php_qt.h"


#include <QLayout>


/*		public enumSizeConstraint:long {
			SizeConstraint = 0,
			SizeConstraint = 1,
			SizeConstraint = 2,
			SizeConstraint = 3,
			SizeConstraint = 4,
			SizeConstraint = 5
		}
*/
/*********************************
 *    class     QLayout
 *    function  totalHeightForWidth
 *    flags:    c
 *    access:    public
 *    return:    int
 *    params:    int w
 */
ZEND_METHOD(QLayout, totalHeightForWidth){
		/* l public*/

		/* int w,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();


			RETURN_LONG(obj->totalHeightForWidth((int) Z_LVAL_P(z_0)));
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QLayout
 *    function  tr
 *    flags:    s
 *    access:    public
 *    return:    QString
 *    params:     const char *, const char * = 0 
 */
ZEND_METHOD(QLayout, tr){
		/* ss public*/

		/* const char* , const char* ,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();


			QString* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QString) obj->tr( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			} else {
				*return_object = (QString) QLayout::tr( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QLayout
 *    function  isEmpty
 *    flags:    c
 *    access:    public
 *    return:    bool
 *    params:    
 */
ZEND_METHOD(QLayout, isEmpty){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isEmpty());
	}
}

/*********************************
 *    class     QLayout
 *    function  setMargin
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    int
 */
ZEND_METHOD(QLayout, setMargin){
		/* l public*/

		/* int ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();


			obj->setMargin((int) Z_LVAL_P(z_0));
			RETURN_NULL();
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QLayout
 *    function  activate
 *    flags:    
 *    access:    public
 *    return:    bool
 *    params:    
 */
ZEND_METHOD(QLayout, activate){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			RETURN_BOOL(obj->activate());
	}
}

/*********************************
 *    class     QLayout
 *    function  setMenuBar
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    QWidget *w
 */
ZEND_METHOD(QLayout, setMenuBar){
//qt_QWidget*
		/* o public*/

		/* qt_QWidget* w,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(obj_z_0->inherits("QWidget")) {
				obj->setMenuBar((QWidget*) obj_z_0);
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QLayout
 *    function  layout
 *    flags:    
 *    access:    public
 *    return:    QLayout *
 *    params:    
 */
ZEND_METHOD(QLayout, layout){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QLayout ** return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QLayout *) obj->layout();
			} else {
				php_error(E_ERROR,"Object not found");
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayout
 *    function  totalMaximumSize
 *    flags:    c
 *    access:    public
 *    return:    QSize
 *    params:    
 */
ZEND_METHOD(QLayout, totalMaximumSize){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QSize* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QSize) obj->totalMaximumSize();
			} else {
				php_error(E_ERROR,"Object not found");
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayout
 *    function  sizeConstraint
 *    flags:    c
 *    access:    public
 *    return:    SizeConstraint
 *    params:    
 */
ZEND_METHOD(QLayout, sizeConstraint){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			obj->sizeConstraint();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QLayout
 *    function  geometry
 *    flags:    c
 *    access:    public
 *    return:    QRect
 *    params:    
 */
ZEND_METHOD(QLayout, geometry){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QRect* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QRect) obj->geometry();
			} else {
				php_error(E_ERROR,"Object not found");
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayout
 *    function  invalidate
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    
 */
ZEND_METHOD(QLayout, invalidate){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			obj->invalidate();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QLayout
 *    function  setGeometry
 *    flags:    p
 *    access:    public
 *    return:    void
 *    params:    const QRect&
 */
ZEND_METHOD(QLayout, setGeometry){
//const QRect&
		/* o public*/

		/* const QRect& ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(!strcmp(Z_OBJCE_P(z_0)->name,"QRect")) {
				obj->setGeometry((const QRect&) *obj_z_0);
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QLayout
 *    function  setAlignment
 *    flags:    
 *    access:    public
 *    return:    bool
 *    params:    QWidget *w, Qt::Alignment alignment
 */
ZEND_METHOD(QLayout, setAlignment){
//qt_QWidget*
		/* ol public*/

		/* qt_QWidget* w, int alignment,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT && Z_TYPE_P(z_1) == IS_LONG){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(obj_z_0->inherits("QWidget")) {
				RETURN_BOOL(obj->setAlignment((QWidget*) obj_z_0, (Qt::Alignment) Z_LVAL_P(z_1)));
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QLayout
 *    function  removeWidget
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    QWidget *w
 */
ZEND_METHOD(QLayout, removeWidget){
//qt_QWidget*
		/* o public*/

		/* qt_QWidget* w,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(obj_z_0->inherits("QWidget")) {
				obj->removeWidget((QWidget*) obj_z_0);
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QLayout
 *    function  setEnabled
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    bool
 */
ZEND_METHOD(QLayout, setEnabled){
		/* l public*/

		/* int ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();


			obj->setEnabled((bool) Z_LVAL_P(z_0));
			RETURN_NULL();
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QLayout
 *    function  addWidget
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    QWidget *w
 */
ZEND_METHOD(QLayout, addWidget){
//qt_QWidget*
		/* o public*/

		/* qt_QWidget* w,  */
	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){

			    QLayout *obj = static_cast<QLayout*>(PHP_QT_FETCH());
			    QWidget* obj_z_0 = static_cast<QWidget*>(php_qt_fetch(z_0));

//			if(obj_z_0->inherits("QWidget")) {
				obj->addWidget(obj_z_0);
			    RETURN_NULL();
//			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QLayout
 *    function  removeItem
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    QLayoutItem *
 */
ZEND_METHOD(QLayout, removeItem){
//qt_QLayoutItem*
		/* o public*/

		/* qt_QLayoutItem* ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(obj_z_0->inherits("QLayoutItem")) {
				obj->removeItem((QLayoutItem*) obj_z_0);
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QLayout
 *    function  staticMetaObject
 *    flags:    s
 *    access:    public
 *    return:    QMetaObject*
 *    params:    
 */
ZEND_METHOD(QLayout, staticMetaObject){
}

/*********************************
 *    class     QLayout
 *    function  qObject
 *    flags:    
 *    access:    public
 *    return:    QObject*
 *    params:    
 */
ZEND_METHOD(QLayout, qObject){
}

/*********************************
 *    class     QLayout
 *    function  totalMinimumSize
 *    flags:    c
 *    access:    public
 *    return:    QSize
 *    params:    
 */
ZEND_METHOD(QLayout, totalMinimumSize){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QSize* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QSize) obj->totalMinimumSize();
			} else {
				php_error(E_ERROR,"Object not found");
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayout
 *    function  minimumSize
 *    flags:    c
 *    access:    public
 *    return:    QSize
 *    params:    
 */
ZEND_METHOD(QLayout, minimumSize){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QSize* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QSize) obj->minimumSize();
			} else {
				php_error(E_ERROR,"Object not found");
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayout
 *    function  setSpacing
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    int
 */
ZEND_METHOD(QLayout, setSpacing){
		/* l public*/

		/* int ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();


			obj->setSpacing((int) Z_LVAL_P(z_0));
			RETURN_NULL();
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QLayout
 *    function  isEnabled
 *    flags:    c
 *    access:    public
 *    return:    bool
 *    params:    
 */
ZEND_METHOD(QLayout, isEnabled){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isEnabled());
	}
}

/*********************************
 *    class     QLayout
 *    function  setSizeConstraint
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    SizeConstraint
 */
ZEND_METHOD(QLayout, setSizeConstraint){
		/* l public*/

		/* int ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();


			obj->setSizeConstraint((QLayout::SizeConstraint) Z_LVAL_P(z_0));
			RETURN_NULL();
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QLayout
 *    function  menuBar
 *    flags:    c
 *    access:    public
 *    return:    QWidget *
 *    params:    
 */
ZEND_METHOD(QLayout, menuBar){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QWidget ** return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QWidget *) obj->menuBar();
			} else {
				php_error(E_ERROR,"Object not found");
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayout
 *    function  totalSizeHint
 *    flags:    c
 *    access:    public
 *    return:    QSize
 *    params:    
 */
ZEND_METHOD(QLayout, totalSizeHint){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QSize* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QSize) obj->totalSizeHint();
			} else {
				php_error(E_ERROR,"Object not found");
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayout
 *    function  closestAcceptableSize
 *    flags:    s
 *    access:    public
 *    return:    QSize
 *    params:    const QWidget *w, const QSize &s
 */
ZEND_METHOD(QLayout, closestAcceptableSize){
//const QWidget*
//const QSize&
		/* oo public*/

		/* const QWidget* w, const QSize& s,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT && Z_TYPE_P(z_1) == IS_OBJECT){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);
			QObject* obj_z_1 = (QObject*) php_qt_fetch(z_1);


			if(obj_z_0->inherits("QWidget") && obj_z_1->inherits("QSize")) {
				QSize* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QSize) obj->closestAcceptableSize((const QWidget*) obj_z_0, (const QSize&) *obj_z_1);
			} else {
				*return_object = (QSize) QLayout::closestAcceptableSize((const QWidget*) obj_z_0, (const QSize&) *obj_z_1);
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QLayout
 *    function  parentWidget
 *    flags:    c
 *    access:    public
 *    return:    QWidget *
 *    params:    
 */
ZEND_METHOD(QLayout, parentWidget){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QWidget ** return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QWidget *) obj->parentWidget();
			} else {
				php_error(E_ERROR,"Object not found");
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayout
 *    function  trUtf8
 *    flags:    s
 *    access:    public
 *    return:    QString
 *    params:     const char *, const char * = 0 
 */
ZEND_METHOD(QLayout, trUtf8){
		/* ss public*/

		/* const char* , const char* ,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();


			QString* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QString) obj->trUtf8( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			} else {
				*return_object = (QString) QLayout::trUtf8( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QLayout
 *    function  maximumSize
 *    flags:    c
 *    access:    public
 *    return:    QSize
 *    params:    
 */
ZEND_METHOD(QLayout, maximumSize){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			QSize* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QSize) obj->maximumSize();
			} else {
				php_error(E_ERROR,"Object not found");
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QLayout_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QLayout
 *    function  margin
 *    flags:    c
 *    access:    public
 *    return:    int
 *    params:    
 */
ZEND_METHOD(QLayout, margin){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			RETURN_LONG(obj->margin());
	}
}

/*********************************
 *    class     QLayout
 *    function  expandingDirections
 *    flags:    c
 *    access:    public
 *    return:    Qt::Orientations
 *    params:    
 */
ZEND_METHOD(QLayout, expandingDirections){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			obj->expandingDirections();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QLayout
 *    function  spacing
 *    flags:    c
 *    access:    public
 *    return:    int
 *    params:    
 */
ZEND_METHOD(QLayout, spacing){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			RETURN_LONG(obj->spacing());
	}
}

/*********************************
 *    class     QLayout
 *    function  update
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    
 */
ZEND_METHOD(QLayout, update){
	if (ZEND_NUM_ARGS() == 0){
			QLayout *obj = (QLayout*) PHP_QT_FETCH();
			obj->update();
			RETURN_NULL();
	}
}


PHP_QT_DESTRUCT(QLayout);

