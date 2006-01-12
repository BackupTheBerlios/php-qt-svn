/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2004 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/
/*
 * Copyright (C) 2005 
 * Thomas Moenicke <tm@ippfp.org>, 
 * Jean-Luc Gyger <jean_luc.gyger@freesurf.ch>
 *
*/
/* $Id: header,v 1.15 2004/01/08 16:46:52 sniper Exp $ */

#ifndef PHP_PHP_QT_H
#define PHP_PHP_QT_H

extern zend_module_entry php_qt_module_entry;
#define phpext_php_qt_ptr &php_qt_module_entry

#ifdef ZTS
#include "TSRM.h"
#endif

//#include <QApplication>

PHP_MINIT_FUNCTION(php_qt);
PHP_MSHUTDOWN_FUNCTION(php_qt);
PHP_RINIT_FUNCTION(php_qt);
PHP_RSHUTDOWN_FUNCTION(php_qt);
PHP_MINFO_FUNCTION(php_qt);

PHP_FUNCTION(confirm_php_qt_compiled);	/* For testing, remove later. */

/* emulate SIGNAL(), SLOT() macros */
PHP_FUNCTION(SIGNAL);
PHP_FUNCTION(SLOT);

/* QObject */
ZEND_METHOD(QObject,__construct);
ZEND_METHOD(QObject,__destruct);
ZEND_METHOD(QObject,test);
ZEND_METHOD(QObject,blockSignals);
ZEND_METHOD(QObject,children);
ZEND_METHOD(QObject,connect);
ZEND_METHOD(QObject,disconnect);
ZEND_METHOD(QObject,dumpObjectInfo);
ZEND_METHOD(QObject,dumpObjectTree);
ZEND_METHOD(QObject,event);
ZEND_METHOD(QObject,eventFilter);
ZEND_METHOD(QObject,findChild);
ZEND_METHOD(QObject,findChildren);
ZEND_METHOD(QObject,inherits);
ZEND_METHOD(QObject,installEventFilter);
ZEND_METHOD(QObject,isWidgetType);
ZEND_METHOD(QObject,killTimer);
ZEND_METHOD(QObject,metaObject);
ZEND_METHOD(QObject,moveToThread);
ZEND_METHOD(QObject,objectName);
ZEND_METHOD(QObject,parent);
ZEND_METHOD(QObject,property);
ZEND_METHOD(QObject,removeEventFilter);
ZEND_METHOD(QObject,setObjectName);
ZEND_METHOD(QObject,setParent);
ZEND_METHOD(QObject,setProperty);
ZEND_METHOD(QObject,signalsBlocked);
ZEND_METHOD(QObject,startTimer);
ZEND_METHOD(QObject,thread);

/* QString */
ZEND_METHOD(QString,__construct);
ZEND_METHOD(QString,append);
ZEND_METHOD(QString,arg);
ZEND_METHOD(QString,at);
ZEND_METHOD(QString,capacity);
ZEND_METHOD(QString,chop);
ZEND_METHOD(QString,clear);
ZEND_METHOD(QString,compare);

/* QLatin1String */
ZEND_METHOD(QLatin1String,__construct);
ZEND_METHOD(QLatin1String,latin1);


/* QCoreApplication */
//public members
ZEND_METHOD(QCoreApplication,__construct);
ZEND_METHOD(QCoreApplication,filterEvent);
ZEND_METHOD(QCoreApplication,notify);
ZEND_METHOD(QCoreApplication,setEventFilter);
ZEND_METHOD(QCoreApplication,winEventFilter);
//public slot
ZEND_METHOD(QCoreApplication,quit);
//public static members
ZEND_METHOD(QCoreApplication,exec);
ZEND_METHOD(QCoreApplication,addLibraryPath);
ZEND_METHOD(QCoreApplication,applicationDirPath); 
ZEND_METHOD(QCoreApplication,applicationFilePath);
ZEND_METHOD(QCoreApplication,applicationName);
ZEND_METHOD(QCoreApplication,argc); 
ZEND_METHOD(QCoreApplication,argv); 
ZEND_METHOD(QCoreApplication,closingDown); 
ZEND_METHOD(QCoreApplication,exit); 
ZEND_METHOD(QCoreApplication,flush); 
ZEND_METHOD(QCoreApplication,hasPendingEvents); 
ZEND_METHOD(QCoreApplication,installTranslator); 
ZEND_METHOD(QCoreApplication,instance); 
ZEND_METHOD(QCoreApplication,libraryPaths); 
ZEND_METHOD(QCoreApplication,organizationDomain); 
ZEND_METHOD(QCoreApplication,organizationName); 
ZEND_METHOD(QCoreApplication,postEvent); 
ZEND_METHOD(QCoreApplication,processEvents); //WARNING 2 Implemetation
ZEND_METHOD(QCoreApplication,removeLibraryPath); 
ZEND_METHOD(QCoreApplication,removePostedEvents); 
ZEND_METHOD(QCoreApplication,removeTranslator); 
ZEND_METHOD(QCoreApplication,sendEvent); 
ZEND_METHOD(QCoreApplication,sendPostedEvents); //WARNING 2 Implemetation
ZEND_METHOD(QCoreApplication,setApplicationName); 
ZEND_METHOD(QCoreApplication,setLibraryPaths); 
ZEND_METHOD(QCoreApplication,setOrganizationDomain); 
ZEND_METHOD(QCoreApplication,setOrganizationName); 
ZEND_METHOD(QCoreApplication,startingUp); 
ZEND_METHOD(QCoreApplication,translate); 


/* QApplication */
//public members
ZEND_METHOD(QApplication,__construct);
ZEND_METHOD(QApplication,commitData);
ZEND_METHOD(QApplication,inputContext);
ZEND_METHOD(QApplication,isSessionRestored);
ZEND_METHOD(QApplication,macEventFilter);
ZEND_METHOD(QApplication,qwsEventFilter);
ZEND_METHOD(QApplication,qwsSetCustomColors);
ZEND_METHOD(QApplication,saveState);
ZEND_METHOD(QApplication,sessionId);
ZEND_METHOD(QApplication,sessionKey);
ZEND_METHOD(QApplication,setInputContext);
ZEND_METHOD(QApplication,winFocus);
ZEND_METHOD(QApplication,x11EventFilter);
ZEND_METHOD(QApplication,x11ProcessEvent);
//public slots
ZEND_METHOD(QApplication,aboutQt); 
ZEND_METHOD(QApplication,closeAllWindows); 
//static public members
//ZEND_METHOD(QApplication,exec);
ZEND_METHOD(QApplication,beep); 
ZEND_METHOD(QApplication,colorSpec); 
ZEND_METHOD(QApplication,cursorFlashTime); 
ZEND_METHOD(QApplication,desktopSettingsAware); 
ZEND_METHOD(QApplication,doubleClickInterval); 
ZEND_METHOD(QApplication,isLeftToRight); 
ZEND_METHOD(QApplication,isRightToLeft); 
ZEND_METHOD(QApplication,keyboardInputInterval); 
ZEND_METHOD(QApplication,quitOnLastWindowClosed); 
ZEND_METHOD(QApplication,restoreOverrideCursor); 
ZEND_METHOD(QApplication,setDesktopSettingsAware); 
ZEND_METHOD(QApplication,setColorSpec); 
ZEND_METHOD(QApplication,setCursorFlashTime); 
ZEND_METHOD(QApplication,setDoubleClickInterval); 
ZEND_METHOD(QApplication,setKeyboardInputInterval); 
ZEND_METHOD(QApplication,setQuitOnLastWindowClosed); 
ZEND_METHOD(QApplication,setStartDragDistance); 
ZEND_METHOD(QApplication,setStartDragTime); 
ZEND_METHOD(QApplication,setWheelScrollLines); 
ZEND_METHOD(QApplication,startDragDistance); 
ZEND_METHOD(QApplication,startDragTime); 
ZEND_METHOD(QApplication,syncX); 
ZEND_METHOD(QApplication,wheelScrollLines); 
ZEND_METHOD(QApplication,activeModalWidget); 
ZEND_METHOD(QApplication,activePopupWidget); 
ZEND_METHOD(QApplication,activeWindow); 
ZEND_METHOD(QApplication,allWidgets); 
ZEND_METHOD(QApplication,changeOverrideCursor); 
ZEND_METHOD(QApplication,clipboard); 
ZEND_METHOD(QApplication,desktop); 
ZEND_METHOD(QApplication,focusWidget); 
ZEND_METHOD(QApplication,font); 
ZEND_METHOD(QApplication,fontMetrics); 
ZEND_METHOD(QApplication,globalStrut); 
ZEND_METHOD(QApplication,isEffectEnabled); 
ZEND_METHOD(QApplication,keyboardModifiers); 
ZEND_METHOD(QApplication,layoutDirection); 
ZEND_METHOD(QApplication,mouseButton); 
ZEND_METHOD(QApplication,overrideCursor); 
ZEND_METHOD(QApplication,palette); // WARNING 3 implementations
ZEND_METHOD(QApplication,qwsDecoration); 
ZEND_METHOD(QApplication,qwsSetDecoration); 
ZEND_METHOD(QApplication,setActiveWindow); 
ZEND_METHOD(QApplication,setEffectEnabled); 
ZEND_METHOD(QApplication,setFont); 
ZEND_METHOD(QApplication,setGlobalStrut); 
ZEND_METHOD(QApplication,setLayoutDirection); 
ZEND_METHOD(QApplication,setOverrideCursor); 
ZEND_METHOD(QApplication,setPalette); 
ZEND_METHOD(QApplication,setStyle); //WARNING 2 imlementation
ZEND_METHOD(QApplication,setWindowIcon); 
ZEND_METHOD(QApplication,style); 
ZEND_METHOD(QApplication,topLevelAt); //WARNING 2 imlementation
ZEND_METHOD(QApplication,topLevelWidgets); 
ZEND_METHOD(QApplication,type); 
ZEND_METHOD(QApplication,widgetAt); //WARNING 2 imlementation,
ZEND_METHOD(QApplication,windowIcon); 

/* QAbstractButton */
ZEND_METHOD(QAbstractButton,__construct);
ZEND_METHOD(QAbstractButton,autoExclusive);
ZEND_METHOD(QAbstractButton,autoRepeat);
ZEND_METHOD(QAbstractButton,isCheckable);
ZEND_METHOD(QAbstractButton,isChecked);
ZEND_METHOD(QAbstractButton,isDown);
ZEND_METHOD(QAbstractButton,setAutoExclusive);
ZEND_METHOD(QAbstractButton,setAutoRepeat);
ZEND_METHOD(QAbstractButton,setCheckable);
ZEND_METHOD(QAbstractButton,paintEvent);

/* QPushButton */
ZEND_METHOD(QPushButton,__construct);
ZEND_METHOD(QPushButton,autoDefault);
ZEND_METHOD(QPushButton,isDefault);
ZEND_METHOD(QPushButton,isFlat);
ZEND_METHOD(QPushButton,menu);
ZEND_METHOD(QPushButton,setAutoDefault);
ZEND_METHOD(QPushButton,setDefault);
ZEND_METHOD(QPushButton,setFlat);
ZEND_METHOD(QPushButton,setMenu);
ZEND_METHOD(QPushButton,paintEvent);

/* QWidget */
ZEND_METHOD(QWidget,__construct);
ZEND_METHOD(QWidget,show);
ZEND_METHOD(QWidget,hide);

ZEND_METHOD(QWidget,acceptDrops);
ZEND_METHOD(QWidget,activateWindow);
ZEND_METHOD(QWidget,adjustSize);
ZEND_METHOD(QWidget,clearFocus);
ZEND_METHOD(QWidget,clearMask);
ZEND_METHOD(QWidget,grabKeyboard);
ZEND_METHOD(QWidget,grabMouse);
ZEND_METHOD(QWidget,hasFocus);
ZEND_METHOD(QWidget,hasMouseTracking);
ZEND_METHOD(QWidget,height);
ZEND_METHOD(QWidget,isActiveWindow);
ZEND_METHOD(QWidget,isEnabled);
ZEND_METHOD(QWidget,isFullScreen);
ZEND_METHOD(QWidget,isHidden);
ZEND_METHOD(QWidget,isMaximized);
ZEND_METHOD(QWidget,isMinimized);
ZEND_METHOD(QWidget,isModal);
ZEND_METHOD(QWidget,isVisible);
ZEND_METHOD(QWidget,isWindow);
ZEND_METHOD(QWidget,isWindowModified);
ZEND_METHOD(QWidget,maximumHeight);
ZEND_METHOD(QWidget,maximumWidth);
ZEND_METHOD(QWidget,minimumHeight);
ZEND_METHOD(QWidget,minimumWidth);
ZEND_METHOD(QWidget,releaseKeyboard);
ZEND_METHOD(QWidget,releaseMouse);
ZEND_METHOD(QWidget,underMouse);
ZEND_METHOD(QWidget,unsetCursor);
ZEND_METHOD(QWidget,unsetLayoutDirection);
ZEND_METHOD(QWidget,updateGeometry);
ZEND_METHOD(QWidget,updatesEnabled);
ZEND_METHOD(QWidget,width);
ZEND_METHOD(QWidget,x);
ZEND_METHOD(QWidget,y);
ZEND_METHOD(QWidget,accessibleDescription);
ZEND_METHOD(QWidget,accessibleName);
/*ZEND_METHOD(QWidget,accessibleName);
ZEND_METHOD(QWidget,backgroundRole);
ZEND_METHOD(QWidget,baseSize);
ZEND_METHOD(QWidget,childrenRecr);
ZEND_METHOD(QWidget,childrenRegion);
ZEND_METHOD(QWidget,contentsRect);
ZEND_METHOD(QWidget,contextMenuPolicy);
ZEND_METHOD(QWidget,cursor);
*/ZEND_METHOD(QWidget,ensurePolished);
/*ZEND_METHOD(QWidget,focusPolicy);
*/ZEND_METHOD(QWidget,focusProxy);
ZEND_METHOD(QWidget,focusWidget);
/*ZEND_METHOD(QWidget,font);
ZEND_METHOD(QWidget,fontInfo);
ZEND_METHOD(QWidget,fontMetrics);
ZEND_METHOD(QWidget,foregroundRole);
ZEND_METHOD(QWidget,frameGeometry);
ZEND_METHOD(QWidget,frameSize);
ZEND_METHOD(QWidget,geometry);
ZEND_METHOD(QWidget,getDC);
ZEND_METHOD(QWidget,inputContext);
ZEND_METHOD(QWidget,inputMethodQuery);
ZEND_METHOD(QWidget,layout);
ZEND_METHOD(QWidget,layoutDirection);
ZEND_METHOD(QWidget,mask);
ZEND_METHOD(QWidget,maximumSize);
ZEND_METHOD(QWidget,minimumSize);
ZEND_METHOD(QWidget,minimumSizeHint);
ZEND_METHOD(QWidget,nextInFocusChain);
ZEND_METHOD(QWidget,normalGeometry);
ZEND_METHOD(QWidget,paintEngine);
ZEND_METHOD(QWidget,palette);
*/ZEND_METHOD(QWidget,parentWidget);
/*ZEND_METHOD(QWidget,pos);
ZEND_METHOD(QWidget,rect);
ZEND_METHOD(QWidget,releaseDC);
*/
ZEND_METHOD(QWidget,resize);
ZEND_METHOD(QWidget,setAccessibleDescription);
ZEND_METHOD(QWidget,setAccessibleName);
ZEND_METHOD(QWidget,setGeometry);
ZEND_METHOD(QWidget,setFixedSize);
ZEND_METHOD(QWidget,setLayout);
/*ZEND_METHOD(QWidget,size);
ZEND_METHOD(QWidget,sizeHint);
ZEND_METHOD(QWidget,sizeIncrement);
ZEND_METHOD(QWidget,sizePolicy);
ZEND_METHOD(QWidget,statusTip);
ZEND_METHOD(QWidget,style);
ZEND_METHOD(QWidget,toolTip);
ZEND_METHOD(QWidget,visibleRegion);
ZEND_METHOD(QWidget,whatsThis);
*/ZEND_METHOD(QWidget,window);
/*ZEND_METHOD(QWidget,windowFlags);
ZEND_METHOD(QWidget,windowIcon);
ZEND_METHOD(QWidget,windowIconText);
ZEND_METHOD(QWidget,windowOpacity);
ZEND_METHOD(QWidget,windowRole);
ZEND_METHOD(QWidget,windowState);
ZEND_METHOD(QWidget,windowTitle);
ZEND_METHOD(QWidget,windowType);
ZEND_METHOD(QWidget,x11Info);
ZEND_METHOD(QWidget,x11PictureHandle);
*/

/* QEvent */
ZEND_METHOD(QEvent,__construct);
ZEND_METHOD(QEvent,accept);
ZEND_METHOD(QEvent,ignore);
ZEND_METHOD(QEvent,isAccepted);
ZEND_METHOD(QEvent,setAccepted);
ZEND_METHOD(QEvent,spontaneous);
ZEND_METHOD(QEvent,type);

/* QLayoutItem */
ZEND_METHOD(QLayoutItem,__construct);
ZEND_METHOD(QLayoutItem,alignment);
ZEND_METHOD(QLayoutItem,hasHeightForWidth);
ZEND_METHOD(QLayoutItem,heightForWidth);
ZEND_METHOD(QLayoutItem,invalidate);
ZEND_METHOD(QLayoutItem,layout);
ZEND_METHOD(QLayoutItem,minimumHeightForWidth);
ZEND_METHOD(QLayoutItem,setAlignment);
ZEND_METHOD(QLayoutItem,spacerItem);
ZEND_METHOD(QLayoutItem,widget);
ZEND_METHOD(QLayoutItem,expandingDirections);//abstract
ZEND_METHOD(QLayoutItem,geometry);//abstract
ZEND_METHOD(QLayoutItem,isEmpty);//abstract
ZEND_METHOD(QLayoutItem,maximumSize);//abstract
ZEND_METHOD(QLayoutItem,minimumSize);//abstract
ZEND_METHOD(QLayoutItem,setGeometry);//abstract
ZEND_METHOD(QLayoutItem,sizeHint);//abstract

/* QLayout */
ZEND_METHOD(QLayout,__construct);
ZEND_METHOD(QLayout,expandingDirections);
ZEND_METHOD(QLayout,geometry);
ZEND_METHOD(QLayout,isEmpty);
ZEND_METHOD(QLayout,maximumSize);
ZEND_METHOD(QLayout,minimumSize);
ZEND_METHOD(QLayout,addItem);
ZEND_METHOD(QLayout,count);
ZEND_METHOD(QLayout,takeAt);
ZEND_METHOD(QLayout,itemAt);
ZEND_METHOD(QLayout,activate);
ZEND_METHOD(QLayout,addWidget);
ZEND_METHOD(QLayout,indexOf);
ZEND_METHOD(QLayout,isEnabled);
ZEND_METHOD(QLayout,margin);
ZEND_METHOD(QLayout,menuBar);
ZEND_METHOD(QLayout,parentWidget);
ZEND_METHOD(QLayout,removeItem);
ZEND_METHOD(QLayout,removeWidget);
ZEND_METHOD(QLayout,setAlignment);
ZEND_METHOD(QLayout,setEnabled);
ZEND_METHOD(QLayout,setMargin);
ZEND_METHOD(QLayout,setMenuBar);
ZEND_METHOD(QLayout,setSizeConstraint);
ZEND_METHOD(QLayout,setSpacing);
ZEND_METHOD(QLayout,sizeConstraint);
ZEND_METHOD(QLayout,spacing);
ZEND_METHOD(QLayout,update);
ZEND_METHOD(QLayout,closestAcceptableSize);
//ZEND_METHOD(QLayout,addChildLayout);
//ZEND_METHOD(QLayout,addChildWidget);
//ZEND_METHOD(QLayout,alignmentRect);

/* QLayoutBox */
ZEND_METHOD(QBoxLayout,__construct);
ZEND_METHOD(QBoxLayout,sizeHint);
ZEND_METHOD(QBoxLayout,addItem);
ZEND_METHOD(QBoxLayout,count);
ZEND_METHOD(QBoxLayout,takeAt);
ZEND_METHOD(QBoxLayout,setGeometry);
ZEND_METHOD(QBoxLayout,addLayout);	
ZEND_METHOD(QBoxLayout,addSpacing);	
ZEND_METHOD(QBoxLayout,addStretch);	
ZEND_METHOD(QBoxLayout,addStrut);
ZEND_METHOD(QBoxLayout,addWidget);
ZEND_METHOD(QBoxLayout,direction);	
ZEND_METHOD(QBoxLayout,insertLayout);	
ZEND_METHOD(QBoxLayout,insertSpacing);
ZEND_METHOD(QBoxLayout,insertStretch);	
ZEND_METHOD(QBoxLayout,insertWidget);	
ZEND_METHOD(QBoxLayout,invalidate);
ZEND_METHOD(QBoxLayout,setDirection);	
ZEND_METHOD(QBoxLayout,setStretchFactor);	
ZEND_METHOD(QBoxLayout,insertItem);	
ZEND_METHOD(QBoxLayout,itemAt);

/* QVLayoutBox */
ZEND_METHOD(QVBoxLayout,__construct);

/* QHLayoutBox */
ZEND_METHOD(QHBoxLayout,__construct);


/* QAbstractSlider */
ZEND_METHOD(QAbstractSlider,__construct);
ZEND_METHOD(QAbstractSlider,hasTracking);
ZEND_METHOD(QAbstractSlider,invertedAppearance);
ZEND_METHOD(QAbstractSlider,invertedControls);
ZEND_METHOD(QAbstractSlider,isSliderDown);
ZEND_METHOD(QAbstractSlider,maximum);
ZEND_METHOD(QAbstractSlider,minimum);
ZEND_METHOD(QAbstractSlider,orientation);
ZEND_METHOD(QAbstractSlider,pageStep);
ZEND_METHOD(QAbstractSlider,setInvertedAppearance);
ZEND_METHOD(QAbstractSlider,setInvertedControls);
ZEND_METHOD(QAbstractSlider,setMaximum);
ZEND_METHOD(QAbstractSlider,setMinimum);
ZEND_METHOD(QAbstractSlider,setPageStep);
ZEND_METHOD(QAbstractSlider,setRange);
ZEND_METHOD(QAbstractSlider,setSingleStep);
ZEND_METHOD(QAbstractSlider,setSliderDown);
ZEND_METHOD(QAbstractSlider,setSliderPosition);
ZEND_METHOD(QAbstractSlider,setTracking);
ZEND_METHOD(QAbstractSlider,singleStep);
ZEND_METHOD(QAbstractSlider,sliderPosition);
ZEND_METHOD(QAbstractSlider,triggerAction);
ZEND_METHOD(QAbstractSlider,value);

/* Slots */
ZEND_METHOD(QAbstractSlider,setOrientation);
ZEND_METHOD(QAbstractSlider,setValue);


/* QLineEdit */
ZEND_METHOD(QLineEdit,__construct);
ZEND_METHOD(QLineEdit,alignment);
ZEND_METHOD(QLineEdit,backspace);
//ZEND_METHOD(QLineEdit,createStandardContextMenu);
ZEND_METHOD(QLineEdit,cursorBackward);
ZEND_METHOD(QLineEdit,cursorForward);
ZEND_METHOD(QLineEdit,cursorPosition);
//ZEND_METHOD(QLineEdit,cursorPositionAt);
ZEND_METHOD(QLineEdit,cursorWordBackward);
ZEND_METHOD(QLineEdit,cursorWordForward);
ZEND_METHOD(QLineEdit,del);
ZEND_METHOD(QLineEdit,deselect);
ZEND_METHOD(QLineEdit,displayText);
ZEND_METHOD(QLineEdit,dragEnabled);
ZEND_METHOD(QLineEdit,echoMode);
ZEND_METHOD(QLineEdit,end);
ZEND_METHOD(QLineEdit,hasAcceptableInput);
ZEND_METHOD(QLineEdit,hasFrame);
ZEND_METHOD(QLineEdit,hasSelectedText);
ZEND_METHOD(QLineEdit,home);
ZEND_METHOD(QLineEdit,inputMask);
ZEND_METHOD(QLineEdit,insert);
ZEND_METHOD(QLineEdit,isModified);
ZEND_METHOD(QLineEdit,isReadOnly);
ZEND_METHOD(QLineEdit,isRedoAvailable);
ZEND_METHOD(QLineEdit,isUndoAvailable);
ZEND_METHOD(QLineEdit,maxLength);
//ZEND_METHOD(QLineEdit,minimumSizeHint);
ZEND_METHOD(QLineEdit,selectedText);
ZEND_METHOD(QLineEdit,selectionStart);
ZEND_METHOD(QLineEdit,setAlignment);
ZEND_METHOD(QLineEdit,setCursorPosition);
ZEND_METHOD(QLineEdit,setDragEnabled);
ZEND_METHOD(QLineEdit,setEchoMode);
ZEND_METHOD(QLineEdit,setFrame);
ZEND_METHOD(QLineEdit,setInputMask);
ZEND_METHOD(QLineEdit,setMaxLength);
ZEND_METHOD(QLineEdit,setModified);
ZEND_METHOD(QLineEdit,setReadOnly);
ZEND_METHOD(QLineEdit,setSelection);
//ZEND_METHOD(QLineEdit,setValidator);
//ZEND_METHOD(QLineEdit,sizeHint);
ZEND_METHOD(QLineEdit,text);
//ZEND_METHOD(QLineEdit,validator);
ZEND_METHOD(QLineEdit,clear);
ZEND_METHOD(QLineEdit,copy);
ZEND_METHOD(QLineEdit,cut);
ZEND_METHOD(QLineEdit,paste);
ZEND_METHOD(QLineEdit,redo);
ZEND_METHOD(QLineEdit,selectAll);
ZEND_METHOD(QLineEdit,setText);
ZEND_METHOD(QLineEdit,undo);
//ZEND_METHOD(QLineEdit,contextMenuEvent);
//ZEND_METHOD(QLineEdit,keyPressEvent);



/* QSlider */
ZEND_METHOD(QSlider,__construct);
ZEND_METHOD(QSlider,setTickInterval);
ZEND_METHOD(QSlider,setTickPosition);
ZEND_METHOD(QSlider,tickInterval);
ZEND_METHOD(QSlider,tickPosition);

/* QFrame */
ZEND_METHOD(QFrame, __construct);
ZEND_METHOD(QFrame, metaObject);
ZEND_METHOD(QFrame, className);
ZEND_METHOD(QFrame, qt_cast);
ZEND_METHOD(QFrame, qt_invoke);
ZEND_METHOD(QFrame, qt_emit);
ZEND_METHOD(QFrame, qt_property);
ZEND_METHOD(QFrame, frameStyle);
ZEND_METHOD(QFrame, setFrameStyle);
ZEND_METHOD(QFrame, frameWidth);
ZEND_METHOD(QFrame, sizeHint);
ZEND_METHOD(QFrame, frameShape);
ZEND_METHOD(QFrame, frameShadow);
ZEND_METHOD(QFrame, lineWidth);
ZEND_METHOD(QFrame, midLineWidth);
ZEND_METHOD(QFrame, frameRect);
ZEND_METHOD(QFrame, staticMetaObject);
ZEND_METHOD(QFrame, tr);
ZEND_METHOD(QFrame, trUtf8);
ZEND_METHOD(QFrame, drawFrame);

/* QLCDNumber */
ZEND_METHOD(QLCDNumber, __construct);
ZEND_METHOD(QLCDNumber, smallDecimalPoint);
ZEND_METHOD(QLCDNumber, numDigits);
ZEND_METHOD(QLCDNumber, checkOverflow);
ZEND_METHOD(QLCDNumber, mode);
ZEND_METHOD(QLCDNumber, segmentStyle);
ZEND_METHOD(QLCDNumber, value);
ZEND_METHOD(QLCDNumber, intValue);
ZEND_METHOD(QLCDNumber, sizeHint);
ZEND_METHOD(QLCDNumber, setHexMode);
ZEND_METHOD(QLCDNumber, setDecMode);
ZEND_METHOD(QLCDNumber, setOctMode);
ZEND_METHOD(QLCDNumber, setBinMode);
ZEND_METHOD(QLCDNumber, staticMetaObject);
ZEND_METHOD(QLCDNumber, tr);
ZEND_METHOD(QLCDNumber, trUtf8);

#include "ag_zend_php_qt.inc"

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(php_qt)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(php_qt)
*/

/* In every utility function you add that needs to use variables 
   in php_php_qt_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as PHP_QT_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define PHP_QT_G(v) TSRMG(php_qt_globals_id, zend_php_qt_globals *, v)
#else
#define PHP_QT_G(v) (php_qt_globals.v)
#endif

#endif	/* PHP_PHP_QT_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
