/*
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2005 Jean-Luc Gyger <jean_luc.gyger@freesurf.ch>
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

#include <QLineEdit>
#include "../php_qt.h"

/* QLineEdit */

ZEND_METHOD(QLineEdit,__construct){
    
	if(ZEND_NUM_ARGS() == 0){
		QLineEdit* QLineEdit_ptr = new QLineEdit();
		PHP_QT_REGISTER(QLineEdit_ptr);
		RETURN_NULL();	
	}

	if(ZEND_NUM_ARGS() == 2){
        char *string;
        int string_len;
        zval *parent;
		
		if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"so",&string, &string_len, &parent) == FAILURE) {
			return;
		}
		
		QLineEdit* QLineEdit_ptr = new QLineEdit(string,(QWidget*) php_qt_fetch(parent));
		PHP_QT_REGISTER(QLineEdit_ptr);
		RETURN_NULL();
	}

	if(ZEND_NUM_ARGS() == 1){
        zval *param;
		
		if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &param) == FAILURE) {
			return;
		}

		if(Z_TYPE_P(param) == IS_STRING) {
			QString tmp(Z_STRVAL_P(param));
			QLineEdit* QLineEdit_ptr = new QLineEdit(tmp);
			PHP_QT_REGISTER(QLineEdit_ptr);
			RETURN_NULL();
		}

		if(Z_TYPE_P(param) == IS_OBJECT) {
			QWidget *tmp = (QWidget*) php_qt_fetch(param);
			QLineEdit* QLineEdit_ptr = new QLineEdit(tmp);
			PHP_QT_REGISTER(QLineEdit_ptr);
			RETURN_NULL();
		}	
	}	
}

PHP_QT_DESTRUCT(QLineEdit);

PHP_QT_RETURN_METHOD(QLineEdit,alignment,RETURN_LONG);
PHP_QT_METHOD(QLineEdit,backspace);
//ZEND_METHOD(QLineEdit,createStandardContextMenu);
ZEND_METHOD(QLineEdit,cursorBackward) {
	QLineEdit *QLineEdit_ptr;
	zend_bool mark;
	long steps = 1;
		
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b|l", &mark,&steps) == FAILURE) {
        return; 
    }
	
	QLineEdit_ptr = (QLineEdit*) PHP_QT_FETCH();	

	QLineEdit_ptr->cursorBackward(mark, steps);
	return;
}

ZEND_METHOD(QLineEdit,cursorForward) {
	QLineEdit *QLineEdit_ptr;
	zend_bool mark;
	long steps = 1;
		
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"b|l", &mark,&steps) == FAILURE) {
        return; 
    }
	
	QLineEdit_ptr = (QLineEdit*) PHP_QT_FETCH();	

	QLineEdit_ptr->cursorForward(mark, steps);
	return;
}

PHP_QT_RETURN_METHOD(QLineEdit,cursorPosition,RETURN_LONG);
//ZEND_METHOD(QLineEdit,cursorPositionAt);
PHP_QT_SETBOOL_METHOD(QLineEdit,cursorWordBackward);
PHP_QT_SETBOOL_METHOD(QLineEdit,cursorWordForward);
PHP_QT_METHOD(QLineEdit,del);
PHP_QT_METHOD(QLineEdit,deselect);

ZEND_METHOD(QLineEdit,displayText){
	QString tmp;
			
	QLineEdit *QLineEdit_ptr = (QLineEdit*) PHP_QT_FETCH();  
	tmp = QLineEdit_ptr->displayText();
	
	RETURN_STRING(tmp.toLatin1().data(),tmp.length());    
}

PHP_QT_RETURN_METHOD(QLineEdit,dragEnabled,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QLineEdit,echoMode,RETURN_LONG);
PHP_QT_SETBOOL_METHOD(QLineEdit,end);
PHP_QT_RETURN_METHOD(QLineEdit,hasAcceptableInput,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QLineEdit,hasFrame,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QLineEdit,hasSelectedText,RETURN_BOOL);
PHP_QT_SETBOOL_METHOD(QLineEdit,home);
ZEND_METHOD(QLineEdit,inputMask){
	QString tmp;
			
	QLineEdit *QLineEdit_ptr = (QLineEdit*) PHP_QT_FETCH();  
	tmp = QLineEdit_ptr->inputMask();
	
	RETURN_STRING(tmp.toLatin1().data(),tmp.length());    
}

ZEND_METHOD(QLineEdit,insert){
	zval *uservar;
	QLineEdit *QLineEdit_ptr;
	
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &uservar) == FAILURE) {
        return; 
    }
	
	QLineEdit_ptr = (QLineEdit*) PHP_QT_FETCH();	

	if(Z_TYPE_P(uservar) == IS_STRING)
	{
		QString tmp(Z_STRVAL_P(uservar));
		QLineEdit_ptr->insert(tmp);
	}
	else
	{
		if(Z_TYPE_P(uservar) == IS_OBJECT)
		{
			QString *tmp = (QString*) php_qt_fetch(uservar);
			QLineEdit_ptr->insert((const QString&)tmp);
		}
	}	
	return;
}

PHP_QT_RETURN_METHOD(QLineEdit,isModified,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QLineEdit,isReadOnly,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QLineEdit,isRedoAvailable,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QLineEdit,isUndoAvailable,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QLineEdit,maxLength,RETURN_LONG);
//PHP_QT_RETURN_METHOD(QLineEdit,minimumSizeHint);
ZEND_METHOD(QLineEdit,selectedText){
	QString tmp;
			
	QLineEdit *QLineEdit_ptr = (QLineEdit*) PHP_QT_FETCH();  
	tmp = QLineEdit_ptr->selectedText();
	
	RETURN_STRING(tmp.toLatin1().data(),tmp.length());    
}

PHP_QT_RETURN_METHOD(QLineEdit,selectionStart,RETURN_LONG);

ZEND_METHOD(QLineEdit,setAlignment) {
	QLineEdit *QLineEdit_ptr;
	long alignment;
		
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &alignment) == FAILURE) {
        return; 
    }
	
	QLineEdit_ptr = (QLineEdit*) PHP_QT_FETCH();	

	QLineEdit_ptr->setAlignment((Qt::Alignment)alignment);
	return;

}

PHP_QT_SETLONG_METHOD(QLineEdit,setCursorPosition);

PHP_QT_SETBOOL_METHOD(QLineEdit,setDragEnabled);

ZEND_METHOD(QLineEdit,setEchoMode) {
	QLineEdit *QLineEdit_ptr;
	long echomode;
		
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &echomode) == FAILURE) {
        return; 
    }
	
	QLineEdit_ptr = (QLineEdit*) PHP_QT_FETCH();	

	QLineEdit_ptr->setEchoMode((QLineEdit::EchoMode)echomode);
	return;

}

PHP_QT_SETBOOL_METHOD(QLineEdit,setFrame);

ZEND_METHOD(QLineEdit,setInputMask){
	zval *uservar;
	QLineEdit *QLineEdit_ptr;
	
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &uservar) == FAILURE) {
        return; 
    }
	
	QLineEdit_ptr = (QLineEdit*) PHP_QT_FETCH();	

	if(Z_TYPE_P(uservar) == IS_STRING)
	{
		QString tmp(Z_STRVAL_P(uservar));
		QLineEdit_ptr->setInputMask(tmp);
	}
	else
	{
		if(Z_TYPE_P(uservar) == IS_OBJECT)
		{
			QString *tmp = (QString*) php_qt_fetch(uservar);
			QLineEdit_ptr->setInputMask((const QString&)tmp);
		}
	}	
	return;
}

PHP_QT_SETLONG_METHOD(QLineEdit,setMaxLength);

PHP_QT_SETBOOL_METHOD(QLineEdit,setModified);
PHP_QT_SETBOOL_METHOD(QLineEdit,setReadOnly);
ZEND_METHOD(QLineEdit,setSelection) {
	QLineEdit *QLineEdit_ptr;
	long start;
	long length;
		
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ll", &start, &length) == FAILURE) {
        return; 
    }
	
	QLineEdit_ptr = (QLineEdit*) PHP_QT_FETCH();	

	QLineEdit_ptr->setSelection( start, length );
	return;

}

//ZEND_METHOD(QLineEdit,setValidator);
//ZEND_METHOD(QLineEdit,sizeHint);

ZEND_METHOD(QLineEdit,text){
	QString tmp;
			
	QLineEdit *QLineEdit_ptr = (QLineEdit*) PHP_QT_FETCH();  
	tmp = QLineEdit_ptr->text();
	
	RETURN_STRING(tmp.toLatin1().data(),tmp.length());    
}

//ZEND_METHOD(QLineEdit,validator);
PHP_QT_METHOD(QLineEdit,clear);
PHP_QT_METHOD(QLineEdit,copy);
PHP_QT_METHOD(QLineEdit,cut);
PHP_QT_METHOD(QLineEdit,paste);
PHP_QT_METHOD(QLineEdit,redo);
PHP_QT_METHOD(QLineEdit,selectAll);

ZEND_METHOD(QLineEdit,setText){
	zval *uservar;
	QLineEdit *QLineEdit_ptr;
	
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"z", &uservar) == FAILURE) {
        return; 
    }
	
	QLineEdit_ptr = (QLineEdit*) PHP_QT_FETCH();	

	if(Z_TYPE_P(uservar) == IS_STRING)
	{
		QString tmp(Z_STRVAL_P(uservar));
		QLineEdit_ptr->setText(tmp);
	}
	else
	{
		if(Z_TYPE_P(uservar) == IS_OBJECT)
		{
			QString *tmp = (QString*) php_qt_fetch(uservar);
			QLineEdit_ptr->setText((const QString&)tmp);
		}
	}	
	return;
}

PHP_QT_METHOD(QLineEdit,undo);
//ZEND_METHOD(QLineEdit,contextMenuEvent);
//ZEND_METHOD(QLineEdit,keyPressEvent);
