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

#include <QAbstractSlider>
#include <QSlider>
#include "../php_qt.h"


ZEND_METHOD(QAbstractSlider,__construct){
}

PHP_QT_RETURN_METHOD(QAbstractSlider,hasTracking,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QAbstractSlider,invertedAppearance,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QAbstractSlider,invertedControls,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QAbstractSlider,isSliderDown,RETURN_BOOL);
PHP_QT_RETURN_METHOD(QAbstractSlider,maximum,RETURN_LONG);
PHP_QT_RETURN_METHOD(QAbstractSlider,minimum,RETURN_LONG);
PHP_QT_RETURN_METHOD(QAbstractSlider,orientation,RETURN_LONG)
PHP_QT_RETURN_METHOD(QAbstractSlider,pageStep,RETURN_LONG);
PHP_QT_SETPROPERTY_BOOL_METHOD(QAbstractSlider,setInvertedAppearance,"invertedAppearance");
PHP_QT_SETPROPERTY_BOOL_METHOD(QAbstractSlider,setInvertedControls,"invertedControls");
PHP_QT_SETPROPERTY_LONG_METHOD(QAbstractSlider,setMaximum,"maximum");
PHP_QT_SETPROPERTY_LONG_METHOD(QAbstractSlider,setMinimum,"minimum");
PHP_QT_SETPROPERTY_LONG_METHOD(QAbstractSlider,setPageStep,"pageStep");

PHP_QT_SETLONG_2_METHOD(QAbstractSlider,setRange);

PHP_QT_SETPROPERTY_LONG_METHOD(QAbstractSlider,setSingleStep,"singleStep");
PHP_QT_SETPROPERTY_BOOL_METHOD(QAbstractSlider,setSliderDown,"sliderDown");
PHP_QT_SETPROPERTY_LONG_METHOD(QAbstractSlider,setSliderPosition,"sliderPosition");
PHP_QT_SETPROPERTY_BOOL_METHOD(QAbstractSlider,setTracking,"tracking");
PHP_QT_RETURN_METHOD(QAbstractSlider,singleStep,RETURN_LONG);
PHP_QT_RETURN_METHOD(QAbstractSlider,sliderPosition,RETURN_LONG);
PHP_QT_SET_LONGENUM_METHOD(QAbstractSlider,triggerAction,QAbstractSlider::SliderAction)
PHP_QT_RETURN_METHOD(QAbstractSlider,value,RETURN_LONG);

/* Slots */
PHP_QT_SET_LONGENUM_METHOD(QAbstractSlider,setOrientation,Qt::Orientation);
PHP_QT_SETPROPERTY_LONG_METHOD(QAbstractSlider,setValue,"value");

