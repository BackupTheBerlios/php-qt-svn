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
 * QFrame.cpp - QFrame PHP implementation.
 * begin           : Thu Feb 23 16:34:20 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;
#include "../php_qt.h"


#include <QFrame>


/*		public enumShape:long {
			NoFrame = 0,
			Box = 0x0001,
			Panel = 0x0002,
			WinPanel = 0x0003,
			HLine = 0x0004,
			VLine = 0x0005,
			StyledPanel = 0x0006
		}
*/

/*		public enumShadow:long {
			Plain = 0x0010,
			Raised = 0x0020,
			Sunken = 0x0030
		}
*/

/*		public enum:long {
			Shadow_Mask = 0x00f0,
			Shape_Mask = 0x000f
		}
*/
/*********************************
 *    class     QFrame
 *    function  tr
 *    flags:    s
 *    access:    public
 *    return:    QString
 *    params:     const char *, const char * = 0 
 */
ZEND_METHOD(QFrame, tr){
		/* ss public*/

		/* const char* , const char* ,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();


			QString* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QString) obj->tr( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			} else {
				*return_object = (QString) QFrame::tr( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QFrame_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QFrame
 *    function  setLineWidth
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    int
 */
ZEND_METHOD(QFrame, setLineWidth){
		/* l public*/

		/* int ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();


			obj->setLineWidth((int) Z_LVAL_P(z_0));
			RETURN_NULL();
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QFrame
 *    function  frameWidth
 *    flags:    c
 *    access:    public
 *    return:    int
 *    params:    
 */
ZEND_METHOD(QFrame, frameWidth){
	if (ZEND_NUM_ARGS() == 0){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();
			RETURN_LONG(obj->frameWidth());
	}
}

/*********************************
 *    class     QFrame
 *    function  staticMetaObject
 *    flags:    s
 *    access:    public
 *    return:    QMetaObject*
 *    params:    
 */
ZEND_METHOD(QFrame, staticMetaObject){
}

/*********************************
 *    class     QFrame
 *    function  QFrame
 *    flags:    t
 *    access:    public
 *    return:    
 *    params:    QWidget* parent = 0, Qt::WFlags f = 0
 */
ZEND_METHOD(QFrame, __construct){
//qt_QWidget*
		/* ol public*/

		/* qt_QWidget* parent, int f,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT && Z_TYPE_P(z_1) == IS_LONG){
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(obj_z_0->inherits("QWidget")) {
				QFrame *QFrame_ptr = new QFrame((QWidget*) obj_z_0, (Qt::WFlags) Z_LVAL_P(z_1));
				PHP_QT_REGISTER(QFrame_ptr);
				RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QFrame
 *    function  midLineWidth
 *    flags:    c
 *    access:    public
 *    return:    int
 *    params:    
 */
ZEND_METHOD(QFrame, midLineWidth){
	if (ZEND_NUM_ARGS() == 0){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();
			RETURN_LONG(obj->midLineWidth());
	}
}

/*********************************
 *    class     QFrame
 *    function  frameShadow
 *    flags:    c
 *    access:    public
 *    return:    Shadow
 *    params:    
 */
ZEND_METHOD(QFrame, frameShadow){
	if (ZEND_NUM_ARGS() == 0){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();
			obj->frameShadow();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QFrame
 *    function  qObject
 *    flags:    
 *    access:    public
 *    return:    QObject*
 *    params:    
 */
ZEND_METHOD(QFrame, qObject){
}

/*********************************
 *    class     QFrame
 *    function  frameShape
 *    flags:    c
 *    access:    public
 *    return:    Shape
 *    params:    
 */
ZEND_METHOD(QFrame, frameShape){
	if (ZEND_NUM_ARGS() == 0){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();
			obj->frameShape();
			RETURN_NULL();
	}
}

/*********************************
 *    class     QFrame
 *    function  setFrameShape
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    Shape
 */
ZEND_METHOD(QFrame, setFrameShape){
		/* l public*/

		/* int ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();


			obj->setFrameShape((QFrame::Shape) Z_LVAL_P(z_0));
			RETURN_NULL();
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QFrame
 *    function  sizeHint
 *    flags:    c
 *    access:    public
 *    return:    QSize
 *    params:    
 */
ZEND_METHOD(QFrame, sizeHint){
	if (ZEND_NUM_ARGS() == 0){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();
			QSize* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QSize) obj->sizeHint();
			} else {
				php_error(E_ERROR,"Object not found");
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QFrame_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QFrame
 *    function  setFrameRect
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    const QRect &
 */
ZEND_METHOD(QFrame, setFrameRect){
//const QRect&
		/* o public*/

		/* const QRect& ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_OBJECT){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();
			QObject* obj_z_0 = (QObject*) php_qt_fetch(z_0);


			if(!strcmp(Z_OBJCE_P(z_0)->name,"QRect")) {
				obj->setFrameRect((const QRect&) *obj_z_0);
			RETURN_NULL();
			}
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QFrame
 *    function  setFrameStyle
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    int
 */
ZEND_METHOD(QFrame, setFrameStyle){
		/* l public*/

		/* int ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();


			obj->setFrameStyle((int) Z_LVAL_P(z_0));
			RETURN_NULL();
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QFrame
 *    function  lineWidth
 *    flags:    c
 *    access:    public
 *    return:    int
 *    params:    
 */
ZEND_METHOD(QFrame, lineWidth){
	if (ZEND_NUM_ARGS() == 0){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();
			RETURN_LONG(obj->lineWidth());
	}
}

/*********************************
 *    class     QFrame
 *    function  drawFrame
 *    flags:    
 *    access:    protected
 *    return:    void
 *    params:    QPainter *
 */
// method drawFrame is protected, skipped.

/*********************************
 *    class     QFrame
 *    function  setMidLineWidth
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    int
 */
ZEND_METHOD(QFrame, setMidLineWidth){
		/* l public*/

		/* int ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();


			obj->setMidLineWidth((int) Z_LVAL_P(z_0));
			RETURN_NULL();
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QFrame
 *    function  setFrameShadow
 *    flags:    
 *    access:    public
 *    return:    void
 *    params:    Shadow
 */
ZEND_METHOD(QFrame, setFrameShadow){
		/* l public*/

		/* int ,  */

	if (ZEND_NUM_ARGS() == 1){
		zval *z_0; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &z_0) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_LONG){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();


			obj->setFrameShadow((QFrame::Shadow) Z_LVAL_P(z_0));
			RETURN_NULL();
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QFrame
 *    function  trUtf8
 *    flags:    s
 *    access:    public
 *    return:    QString
 *    params:     const char *, const char * = 0 
 */
ZEND_METHOD(QFrame, trUtf8){
		/* ss public*/

		/* const char* , const char* ,  */

	if (ZEND_NUM_ARGS() == 2){
		zval *z_0; // define ZVAL
		zval *z_1; // define ZVAL
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz", &z_0, &z_1) == SUCCESS) {
			if(Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();


			QString* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QString) obj->trUtf8( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			} else {
				*return_object = (QString) QFrame::trUtf8( (const char*) Z_STRVAL_P(z_0) , (const char*) Z_STRVAL_P(z_1));
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QFrame_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			} else { php_error(E_ERROR,"argument not allowed"); }
		}
	}
}

/*********************************
 *    class     QFrame
 *    function  frameRect
 *    flags:    c
 *    access:    public
 *    return:    QRect
 *    params:    
 */
ZEND_METHOD(QFrame, frameRect){
	if (ZEND_NUM_ARGS() == 0){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();
			QRect* return_object;
			// check whether method call is static.
			if(getThis() != NULL){
				*return_object = (QRect) obj->frameRect();
			} else {
				php_error(E_ERROR,"Object not found");
			}
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QFrame_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QFrame
 *    function  frameStyle
 *    flags:    c
 *    access:    public
 *    return:    int
 *    params:    
 */
ZEND_METHOD(QFrame, frameStyle){
	if (ZEND_NUM_ARGS() == 0){
			QFrame *obj = (QFrame*) PHP_QT_FETCH();
			RETURN_LONG(obj->frameStyle());
	}
}


PHP_QT_DESTRUCT(QFrame);

