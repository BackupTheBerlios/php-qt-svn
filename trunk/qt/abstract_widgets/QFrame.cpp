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
 * begin           : Sun Dec 11 13:58:03 2005
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QFrame>
#include "../php_qt.h"




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
 *    function  metaObject
 *    flags:    cv
 *
 *    @param   -

 *    @access   public
 *    @return   QMetaObject *
*********************************/
ZEND_METHOD(QFrame, metaObject){
// marked as virtual, skipped
	php_printf("%s(): virtual functions are not yet implemented\n",get_active_function_name(TSRMLS_C));
}

/*********************************
 *    class     QFrame
 *    function  className
 *    flags:    cv
 *
 *    @param   -

 *    @access   public
 *    @return   const char *
*********************************/
ZEND_METHOD(QFrame, className){
// marked as virtual, skipped
	php_printf("%s(): virtual functions are not yet implemented\n",get_active_function_name(TSRMLS_C));
}

/*********************************
 *    class     QFrame
 *    function  qt_cast
 *    flags:    v
 *
 *    @param   const char*
 *    @param   -

 *    @access   public
 *    @return   void*
*********************************/
ZEND_METHOD(QFrame, qt_cast){
// marked as virtual, skipped
	php_printf("%s(): virtual functions are not yet implemented\n",get_active_function_name(TSRMLS_C));
}

/*********************************
 *    class     QFrame
 *    function  qt_invoke
 *    flags:    v
 *
 *    @param   int
 *    @param   QUObject*
 *    @param   -

 *    @access   public
 *    @return   bool
*********************************/
ZEND_METHOD(QFrame, qt_invoke){
// marked as virtual, skipped
	php_printf("%s(): virtual functions are not yet implemented\n",get_active_function_name(TSRMLS_C));
}

/*********************************
 *    class     QFrame
 *    function  qt_emit
 *    flags:    v
 *
 *    @param   int
 *    @param   QUObject*
 *    @param   -

 *    @access   public
 *    @return   bool
*********************************/
ZEND_METHOD(QFrame, qt_emit){
// marked as virtual, skipped
	php_printf("%s(): virtual functions are not yet implemented\n",get_active_function_name(TSRMLS_C));
}

/*********************************
 *    class     QFrame
 *    function  qt_property
 *    flags:    v
 *
 *    @param   int
 *    @param   int
 *    @param   QVariant*
 *    @param   -

 *    @access   public
 *    @return   bool
*********************************/
ZEND_METHOD(QFrame, qt_property){
// marked as virtual, skipped
	php_printf("%s(): virtual functions are not yet implemented\n",get_active_function_name(TSRMLS_C));
}
// skip qObject


ZEND_METHOD(QFrame,__construct){
	QFrame *QFrame_ptr = new QFrame();
	if(ZEND_NUM_ARGS() == 2){
		/*parent.Ptr, f*/
		zval* var0;
		long var1;
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ol", &var0, &var1) == FAILURE) {
			return;
		}
		//zend_update_property(Z_OBJCE_P(getThis()),getThis(),"parent",strlen("parent"), var0 TSRMLS_CC);
		//zend_update_property(Z_OBJCE_P(getThis()),getThis(),"f",strlen("f"), var1 TSRMLS_CC);
	}
	PHP_QT_REGISTER(QFrame_ptr);
	RETURN_NULL();
}

PHP_QT_DESTRUCT(QFrame);


/*********************************
 *    class     QFrame
 *    function  frameStyle
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   int
*********************************/
ZEND_METHOD(QFrame, frameStyle){
	QFrame *o = (QFrame*) PHP_QT_FETCH();
	RETURN_LONG(o->frameStyle());
}

/*********************************
 *    class     QFrame
 *    function  setFrameStyle
 *    flags:    
 *
 *    @param   int
 *    @param   -

 *    @access   public
 *    @return   void
*********************************/
ZEND_METHOD(QFrame, setFrameStyle){
	long var_0;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", var_0) == FAILURE) {
		RETURN_FALSE;
	}
	QFrame *o = (QFrame*) PHP_QT_FETCH();
	o->setFrameStyle( (int) var_0);
	RETURN_NULL();
}

/*********************************
 *    class     QFrame
 *    function  frameWidth
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   int
*********************************/
ZEND_METHOD(QFrame, frameWidth){
	QFrame *o = (QFrame*) PHP_QT_FETCH();
	RETURN_LONG(o->frameWidth());
}

/*********************************
 *    class     QFrame
 *    function  sizeHint
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   QSize
*********************************/
ZEND_METHOD(QFrame, sizeHint){
	QFrame *o = (QFrame*) PHP_QT_FETCH();
	QSize obj = (QSize) o->sizeHint();
	zend_class_entry *ce;                                   
	    object_init_ex(return_value, QFrame_ce_ptr);     
	    zend_rsrc_list_entry le;                            
	    le.ptr = &obj;                                       
	    php_qt_register(return_value,le);                   
	    return;                                             
}

/*********************************
 *    class     QFrame
 *    function  frameShape
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   Shape
*********************************/
ZEND_METHOD(QFrame, frameShape){
	QFrame *o = (QFrame*) PHP_QT_FETCH();
}

/*********************************
 *    class     QFrame
 *    function  setFrameShape
 *    flags:    
 *
 *    @param   Shape
 *    @param   -

 *    @access   public
 *    @return   void
*********************************/
ZEND_METHOD(QFrame, setFrameShape){
	zval* var_0;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_0) == FAILURE) {
		RETURN_FALSE;
	}
	zend_update_property(Z_OBJCE_P(getThis()),getThis(),"frameShape",strlen("frameShape"),var_0 TSRMLS_CC);
}

/*********************************
 *    class     QFrame
 *    function  frameShadow
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   Shadow
*********************************/
ZEND_METHOD(QFrame, frameShadow){
	QFrame *o = (QFrame*) PHP_QT_FETCH();
}

/*********************************
 *    class     QFrame
 *    function  setFrameShadow
 *    flags:    
 *
 *    @param   Shadow
 *    @param   -

 *    @access   public
 *    @return   void
*********************************/
ZEND_METHOD(QFrame, setFrameShadow){
	zval* var_0;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_0) == FAILURE) {
		RETURN_FALSE;
	}
	zend_update_property(Z_OBJCE_P(getThis()),getThis(),"frameShadow",strlen("frameShadow"),var_0 TSRMLS_CC);
}

/*********************************
 *    class     QFrame
 *    function  lineWidth
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   int
*********************************/
ZEND_METHOD(QFrame, lineWidth){
	QFrame *o = (QFrame*) PHP_QT_FETCH();
	RETURN_LONG(o->lineWidth());
}

/*********************************
 *    class     QFrame
 *    function  setLineWidth
 *    flags:    
 *
 *    @param   int
 *    @param   -

 *    @access   public
 *    @return   void
*********************************/
ZEND_METHOD(QFrame, setLineWidth){
	long var_0;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", var_0) == FAILURE) {
		RETURN_FALSE;
	}
	zend_update_property_long(Z_OBJCE_P(getThis()),getThis(),"lineWidth",strlen("lineWidth"),var_0 TSRMLS_CC);
}

/*********************************
 *    class     QFrame
 *    function  midLineWidth
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   int
*********************************/
ZEND_METHOD(QFrame, midLineWidth){
	QFrame *o = (QFrame*) PHP_QT_FETCH();
	RETURN_LONG(o->midLineWidth());
}

/*********************************
 *    class     QFrame
 *    function  setMidLineWidth
 *    flags:    
 *
 *    @param   int
 *    @param   -

 *    @access   public
 *    @return   void
*********************************/
ZEND_METHOD(QFrame, setMidLineWidth){
	long var_0;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", var_0) == FAILURE) {
		RETURN_FALSE;
	}
	zend_update_property_long(Z_OBJCE_P(getThis()),getThis(),"midLineWidth",strlen("midLineWidth"),var_0 TSRMLS_CC);
}

/*********************************
 *    class     QFrame
 *    function  frameRect
 *    flags:    c
 *
 *    @param   -

 *    @access   public
 *    @return   QRect
*********************************/
ZEND_METHOD(QFrame, frameRect){
	QFrame *o = (QFrame*) PHP_QT_FETCH();
	QRect obj = (QRect) o->frameRect();
	zend_class_entry *ce;                                   
	    object_init_ex(return_value, QFrame_ce_ptr);     
	    zend_rsrc_list_entry le;                            
	    le.ptr = &obj;                                       
	    php_qt_register(return_value,le);                   
	    return;                                             
}

/*********************************
 *    class     QFrame
 *    function  setFrameRect
 *    flags:    
 *
 *    @param   const QRect&
 *    @param   -

 *    @access   public
 *    @return   void
*********************************/
ZEND_METHOD(QFrame, setFrameRect){
	zval* var_0;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &var_0) == FAILURE) {
		RETURN_FALSE;
	}
	zend_update_property(Z_OBJCE_P(getThis()),getThis(),"frameRect",strlen("frameRect"),var_0 TSRMLS_CC);
}

/*********************************
 *    class     QFrame
 *    function  staticMetaObject
 *    flags:    s
 *
 *    @param   -

 *    @access   public
 *    @return   QMetaObject*
*********************************/
ZEND_METHOD(QFrame, staticMetaObject){
/*	QFrame *o = (QFrame*) PHP_QT_FETCH();
	QMetaObject* obj = (QMetaObject*) o->staticMetaObject();
	zend_class_entry *ce;                                   
	    object_init_ex(return_value, QFrame_ce_ptr);     
	    zend_rsrc_list_entry le;                            
	    le.ptr = obj;                                       
	    php_qt_register(return_value,le);                   */
	    return;                                             
}

/*********************************
 *    class     QFrame
 *    function  tr
 *    flags:    s
 *
 *    @param   const char*
 *    @param   const char*
 *    @param   -

 *    @access   public
 *    @return   QString
*********************************/
ZEND_METHOD(QFrame, tr){
	char* var_0;
	int* len_0;

	char* var_1;
	int* len_1;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ss", &var_0, &len_0, &var_1, &len_1) == FAILURE) {
		RETURN_FALSE;
	}
	QFrame *o = (QFrame*) PHP_QT_FETCH();
	QString obj = (QString) o->tr( var_0,  var_1);
	zend_class_entry *ce;                                   
	    object_init_ex(return_value, QFrame_ce_ptr);     
	    zend_rsrc_list_entry le;                            
	    le.ptr = &obj;                                       
	    php_qt_register(return_value,le);                   
	    return;                                             
}

/*********************************
 *    class     QFrame
 *    function  trUtf8
 *    flags:    s
 *
 *    @param   const char*
 *    @param   const char*
 *    @param   -

 *    @access   public
 *    @return   QString
*********************************/
ZEND_METHOD(QFrame, trUtf8){
	char* var_0;
	int* len_0;

	char* var_1;
	int* len_1;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ss", &var_0, &len_0, &var_1, &len_1) == FAILURE) {
		RETURN_FALSE;
	}
	QFrame *o = (QFrame*) PHP_QT_FETCH();
	QString obj = (QString) o->trUtf8( var_0,  var_1);
	zend_class_entry *ce;                                   
	    object_init_ex(return_value, QFrame_ce_ptr);     
	    zend_rsrc_list_entry le;                            
	    le.ptr = &obj;                                       
	    php_qt_register(return_value,le);                   
	    return;                                             
}

/*********************************
 *    class     QFrame
 *    function  drawFrame
 *    flags:    
 *
 *    @param   QPainter*
 *    @param   -

 *    @access   protected
 *    @return   void
*********************************/
ZEND_METHOD(QFrame, drawFrame){
	long var_0;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", var_0) == FAILURE) {
		RETURN_FALSE;
	}
	QFrame *o = (QFrame*) PHP_QT_FETCH();
//	o->drawFrame( (QPainter*) var_0);
	RETURN_NULL();
}
