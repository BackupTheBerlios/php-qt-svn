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
 * QDate.cpp - QDate PHP implementation.
 * begin           : Sun Jan 15 17:39:22 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include <QDate>
#include "../php_qt.h"


/*********************************
 *    class     QDate */
/*
 *    function  longDayName
 *    flags:    s
 */
ZEND_METHOD(QDate, longDayName){

	if (ZEND_NUM_ARGS() == 1){
		/* l public*/
		long var_l_0;    // default: 

		/* int weekday,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			QString return_object = (QString) obj->longDayName((int) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDate_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  dayOfWeek
 *    flags:    c
 */
ZEND_METHOD(QDate, dayOfWeek){
	if (ZEND_NUM_ARGS() == 0){
			QDate *obj = (QDate*) PHP_QT_FETCH();
			RETURN_LONG(obj->dayOfWeek());
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  daysInMonth
 *    flags:    c
 */
ZEND_METHOD(QDate, daysInMonth){
	if (ZEND_NUM_ARGS() == 0){
			QDate *obj = (QDate*) PHP_QT_FETCH();
			RETURN_LONG(obj->daysInMonth());
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  month
 *    flags:    c
 */
ZEND_METHOD(QDate, month){
	if (ZEND_NUM_ARGS() == 0){
			QDate *obj = (QDate*) PHP_QT_FETCH();
			RETURN_LONG(obj->month());
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  isValid
 *    flags:    c
 */
ZEND_METHOD(QDate, isValid){
	if (ZEND_NUM_ARGS() == 0){
			QDate *obj = (QDate*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isValid());
	}

	if (ZEND_NUM_ARGS() == 3){
		/* lll public*/
		long var_lll_0;    // default: 
		long var_lll_1;    // default: 
		long var_lll_2;    // default: 

		/* int y, int m, int d,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lll", &var_lll_0, &var_lll_1, &var_lll_2) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			RETURN_BOOL(obj->isValid((int) var_lll_0 ,(int) var_lll_1 ,(int) var_lll_2));
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  setYMD
 *    flags:    
 */
ZEND_METHOD(QDate, setYMD){

	if (ZEND_NUM_ARGS() == 3){
		/* lll public*/
		long var_lll_0;    // default: 
		long var_lll_1;    // default: 
		long var_lll_2;    // default: 

		/* int y, int m, int d,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lll", &var_lll_0, &var_lll_1, &var_lll_2) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			RETURN_BOOL(obj->setYMD((int) var_lll_0 ,(int) var_lll_1 ,(int) var_lll_2));
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  shortMonthName
 *    flags:    s
 */
ZEND_METHOD(QDate, shortMonthName){

	if (ZEND_NUM_ARGS() == 1){
		/* l public*/
		long var_l_0;    // default: 

		/* int month,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			QString return_object = (QString) obj->shortMonthName((int) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDate_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  toString
 *    flags:    c
 */
ZEND_METHOD(QDate, toString){

	if (ZEND_NUM_ARGS() == 1){
		/* l public*/
		long var_l_0;    // default: Qt::TextDate

		/* int f,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l|", &var_l_0) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			QString return_object = (QString) obj->toString((Qt::DateFormat) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDate_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
		/* o public*/
		zval* z_var_o_0;   // default: 

		/* const QString& format,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QString") {
				QString return_object = (QString) obj->toString((const QString&) var_o_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDate_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			}
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  isLeapYear
 *    flags:    s
 */
ZEND_METHOD(QDate, isLeapYear){

	if (ZEND_NUM_ARGS() == 1){
		/* l public*/
		long var_l_0;    // default: 

		/* int year,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			RETURN_BOOL(obj->isLeapYear((int) var_l_0));
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  fromJulianDay
 *    flags:    s
 */
ZEND_METHOD(QDate, fromJulianDay){

	if (ZEND_NUM_ARGS() == 1){
		/* l public*/
		long var_l_0;    // default: 

		/* int jd,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			QDate return_object = (QDate) obj->fromJulianDay((int) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDate_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  currentDate
 *    flags:    s
 */
ZEND_METHOD(QDate, currentDate){
	if (ZEND_NUM_ARGS() == 0){
			QDate *obj = (QDate*) PHP_QT_FETCH();
			QDate return_object = (QDate) obj->currentDate();
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDate_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  addDays
 *    flags:    c
 */
ZEND_METHOD(QDate, addDays){

	if (ZEND_NUM_ARGS() == 1){
		/* l public*/
		long var_l_0;    // default: 

		/* int days,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			QDate return_object = (QDate) obj->addDays((int) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDate_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  day
 *    flags:    c
 */
ZEND_METHOD(QDate, day){
	if (ZEND_NUM_ARGS() == 0){
			QDate *obj = (QDate*) PHP_QT_FETCH();
			RETURN_LONG(obj->day());
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  gregorianToJulian
 *    flags:    s
 */
ZEND_METHOD(QDate, gregorianToJulian){

	if (ZEND_NUM_ARGS() == 3){
		/* lll public*/
		long var_lll_0;    // default: 
		long var_lll_1;    // default: 
		long var_lll_2;    // default: 

		/* int y, int m, int d,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lll", &var_lll_0, &var_lll_1, &var_lll_2) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			RETURN_LONG(obj->gregorianToJulian((int) var_lll_0 ,(int) var_lll_1 ,(int) var_lll_2));
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  longMonthName
 *    flags:    s
 */
ZEND_METHOD(QDate, longMonthName){

	if (ZEND_NUM_ARGS() == 1){
		/* l public*/
		long var_l_0;    // default: 

		/* int month,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			QString return_object = (QString) obj->longMonthName((int) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDate_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  julianToGregorian
 *    flags:    s
 */
ZEND_METHOD(QDate, julianToGregorian){

	if (ZEND_NUM_ARGS() == 4){
		/* llll public*/
		long var_llll_0;    // default: 
		long var_llll_1;    // default: 
		long var_llll_2;    // default: 
		long var_llll_3;    // default: 

		/* unsigned int jd, int y, int m, int d,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"llll", &var_llll_0, &var_llll_1, &var_llll_2, &var_llll_3) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			obj->julianToGregorian((uint) var_llll_0 ,(int&) var_llll_1 ,(int&) var_llll_2 ,(int&) var_llll_3);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  QDate
 *    flags:    
 */
ZEND_METHOD(QDate, __construct){
	if (ZEND_NUM_ARGS() == 0){
			QDate *QDate_ptr = new QDate();
			PHP_QT_REGISTER(QDate_ptr);
			RETURN_NULL();
	}

	if (ZEND_NUM_ARGS() == 3){
		/* lll public*/
		long var_lll_0;    // default: 
		long var_lll_1;    // default: 
		long var_lll_2;    // default: 

		/* int y, int m, int d,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"lll", &var_lll_0, &var_lll_1, &var_lll_2) == SUCCESS) {

			
			QDate *QDate_ptr = new QDate((int) var_lll_0 ,(int) var_lll_1 ,(int) var_lll_2);
			PHP_QT_REGISTER(QDate_ptr);
			RETURN_NULL();
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  shortDayName
 *    flags:    s
 */
ZEND_METHOD(QDate, shortDayName){

	if (ZEND_NUM_ARGS() == 1){
		/* l public*/
		long var_l_0;    // default: 

		/* int weekday,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			QString return_object = (QString) obj->shortDayName((int) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDate_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  fromString
 *    flags:    s
 */
ZEND_METHOD(QDate, fromString){

	if (ZEND_NUM_ARGS() == 2){
		/* ol public*/
		zval* z_var_ol_0;   // default: 
		long var_ol_1;    // default: Qt::TextDate

		/* const QString& s, int f,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"ol|", &z_var_ol_0, &var_ol_1) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();
			QObject* var_ol_0 = (QObject*) php_qt_fetch(z_var_ol_0);

			QString tmp_ol_0(var_ol_0->metaObject()->className());
			
			if(tmp_ol_0 == "const QString") {
				QDate return_object = (QDate) obj->fromString((const QString&) var_ol_0, (Qt::DateFormat) var_ol_1);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDate_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			}
		}
		/* oo public*/
		zval* z_var_oo_0;   // default: 
		zval* z_var_oo_1;   // default: 

		/* const QString& s, const QString& format,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"oo", &z_var_oo_0, &z_var_oo_1) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();
			QObject* var_oo_0 = (QObject*) php_qt_fetch(z_var_oo_0);
			QObject* var_oo_1 = (QObject*) php_qt_fetch(z_var_oo_1);

			QString tmp_oo_0(var_oo_0->metaObject()->className());
			QString tmp_oo_1(var_oo_1->metaObject()->className());
			
			if(tmp_oo_0 == "const QString" && tmp_oo_1 == "const QString") {
				QDate return_object = (QDate) obj->fromString((const QString&) var_oo_0, (const QString&) var_oo_1);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDate_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
			}
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  dayOfYear
 *    flags:    c
 */
ZEND_METHOD(QDate, dayOfYear){
	if (ZEND_NUM_ARGS() == 0){
			QDate *obj = (QDate*) PHP_QT_FETCH();
			RETURN_LONG(obj->dayOfYear());
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  weekNumber
 *    flags:    c
 */
ZEND_METHOD(QDate, weekNumber){

	if (ZEND_NUM_ARGS() == 1){
		/* l public*/
		long var_l_0;    // default: 0

		/* int* yearNum,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l|", &var_l_0) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			RETURN_LONG(obj->weekNumber((int*) var_l_0));
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  addMonths
 *    flags:    c
 */
ZEND_METHOD(QDate, addMonths){

	if (ZEND_NUM_ARGS() == 1){
		/* l public*/
		long var_l_0;    // default: 

		/* int months,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			QDate return_object = (QDate) obj->addMonths((int) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDate_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  toJulianDay
 *    flags:    c
 */
ZEND_METHOD(QDate, toJulianDay){
	if (ZEND_NUM_ARGS() == 0){
			QDate *obj = (QDate*) PHP_QT_FETCH();
			RETURN_LONG(obj->toJulianDay());
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  addYears
 *    flags:    c
 */
ZEND_METHOD(QDate, addYears){

	if (ZEND_NUM_ARGS() == 1){
		/* l public*/
		long var_l_0;    // default: 

		/* int years,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"l", &var_l_0) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();

			
			QDate return_object = (QDate) obj->addYears((int) var_l_0);
				zend_class_entry *ce;                                   
				object_init_ex(return_value, QDate_ce_ptr);     
				zend_rsrc_list_entry le;                            
				le.ptr = (void*) &return_object;                                       
				php_qt_register(return_value,le);                   
				return;                                             
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  daysTo
 *    flags:    c
 */
ZEND_METHOD(QDate, daysTo){

	if (ZEND_NUM_ARGS() == 1){
		/* o public*/
		zval* z_var_o_0;   // default: 

		/* const QDate& ,  */
		if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o", &z_var_o_0) == SUCCESS) {
			QDate *obj = (QDate*) PHP_QT_FETCH();
			QObject* var_o_0 = (QObject*) php_qt_fetch(z_var_o_0);

			QString tmp_o_0(var_o_0->metaObject()->className());
			
			if(tmp_o_0 == "const QDate") {
				RETURN_LONG(obj->daysTo((const QDate&) var_o_0));
			}
		}
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  isNull
 *    flags:    c
 */
ZEND_METHOD(QDate, isNull){
	if (ZEND_NUM_ARGS() == 0){
			QDate *obj = (QDate*) PHP_QT_FETCH();
			RETURN_BOOL(obj->isNull());
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  year
 *    flags:    c
 */
ZEND_METHOD(QDate, year){
	if (ZEND_NUM_ARGS() == 0){
			QDate *obj = (QDate*) PHP_QT_FETCH();
			RETURN_LONG(obj->year());
	}
}

/*********************************
 *    class     QDate */
/*
 *    function  daysInYear
 *    flags:    c
 */
ZEND_METHOD(QDate, daysInYear){
	if (ZEND_NUM_ARGS() == 0){
			QDate *obj = (QDate*) PHP_QT_FETCH();
			RETURN_LONG(obj->daysInYear());
	}
}


PHP_QT_DESTRUCT(QDate);

