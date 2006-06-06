/*
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2006
 * Thomas Moenicke <tm@ippfp.org>,
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
 * QHelpEvent.cpp - QHelpEvent PHP implementation.
 * begin           : Tue Jun  6 22:42:56 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include "../php_qt.h"


#include <QHelpEvent>
/// DEBUG:destructor skipped.
#include <QMetaMethod>
class QHelpEvent_php_qt:public QHelpEvent
{

public:
  QHelpEvent_php_qt(zval * zend_ptr, Type types0, const QPoint & poss1, const QPoint & globalPoss2);


  zval *zend_ptr;
};
QHelpEvent_php_qt::QHelpEvent_php_qt(zval * zend_ptr, Type types0, const QPoint & poss1, const QPoint & globalPoss2):
QHelpEvent(types0, poss1, globalPoss2)
{
  this->zend_ptr = zend_ptr;
}

/*!
 * method y
 * 
 * @param: -
 * @param: -
 * 
 * @access	public
 * @return	int
 * @flags	c
 */

ZEND_METHOD(QHelpEvent, y)
{
  ///
  if (ZEND_NUM_ARGS() == 0) {
    PHP_QT_FETCH_0_ARGS();
    if (1) {
      if (getThis() == NULL) {
        php_error(E_ERROR, "method 'y' is not static");
        RETURN_NULL();
      }
      /// try 
      QHelpEvent *selfpointer;

      if (getThis() != NULL) {
        selfpointer = static_cast < QHelpEvent * >(PHP_QT_FETCH());
      }
      RETURN_LONG(selfpointer->y());
    }
  }
  php_error(E_ERROR, "could not parse argument in QHelpEvent::y(...) ");
}

/*!
 * method QHelpEvent
 * 
 * @param: -
 * 
 * overloaded args:
 * @param	Type types0s0
 * @param	const QPoint &poss1s1
 * @param	const QPoint &globalPoss2s2
 * 
 * @access	public
 * @return	
 * @flags	
 */

ZEND_METHOD(QHelpEvent, __construct)
{
// notice: unknown argument Type types0s0, skipped
  php_error(E_ERROR, "could not parse argument in QHelpEvent::QHelpEvent(...) ");
}

/*!
 * method pos
 * 
 * @param: -
 * @param: -
 * 
 * @access	public
 * @return	const QPoint&
 * @flags	c
 */

ZEND_METHOD(QHelpEvent, pos)
{
  ///
#ifdef PHP_QT_QPoint            // return type

  if (ZEND_NUM_ARGS() == 0) {
    PHP_QT_FETCH_0_ARGS();
    if (1) {
      if (getThis() == NULL) {
        php_error(E_ERROR, "method 'pos' is not static");
        RETURN_NULL();
      }
      /// try 
      QHelpEvent *selfpointer;

      if (getThis() != NULL) {
        selfpointer = static_cast < QHelpEvent * >(PHP_QT_FETCH());
      }
      zend_class_entry *ce;

      object_init_ex(return_value, QString_ce_ptr);
      zend_rsrc_list_entry le;

      le.ptr = &const_cast < QPoint & >(selfpointer->pos());
      php_qt_register(return_value, le);
      return;
    }
  }
#endif // return type

  php_error(E_ERROR, "could not parse argument in QHelpEvent::pos(...) ");
}

/*!
 * method globalPos
 * 
 * @param: -
 * @param: -
 * 
 * @access	public
 * @return	const QPoint&
 * @flags	c
 */

ZEND_METHOD(QHelpEvent, globalPos)
{
  ///
#ifdef PHP_QT_QPoint            // return type

  if (ZEND_NUM_ARGS() == 0) {
    PHP_QT_FETCH_0_ARGS();
    if (1) {
      if (getThis() == NULL) {
        php_error(E_ERROR, "method 'globalPos' is not static");
        RETURN_NULL();
      }
      /// try 
      QHelpEvent *selfpointer;

      if (getThis() != NULL) {
        selfpointer = static_cast < QHelpEvent * >(PHP_QT_FETCH());
      }
      zend_class_entry *ce;

      object_init_ex(return_value, QString_ce_ptr);
      zend_rsrc_list_entry le;

      le.ptr = &const_cast < QPoint & >(selfpointer->globalPos());
      php_qt_register(return_value, le);
      return;
    }
  }
#endif // return type

  php_error(E_ERROR, "could not parse argument in QHelpEvent::globalPos(...) ");
}

/*!
 * method globalX
 * 
 * @param: -
 * @param: -
 * 
 * @access	public
 * @return	int
 * @flags	c
 */

ZEND_METHOD(QHelpEvent, globalX)
{
  ///
  if (ZEND_NUM_ARGS() == 0) {
    PHP_QT_FETCH_0_ARGS();
    if (1) {
      if (getThis() == NULL) {
        php_error(E_ERROR, "method 'globalX' is not static");
        RETURN_NULL();
      }
      /// try 
      QHelpEvent *selfpointer;

      if (getThis() != NULL) {
        selfpointer = static_cast < QHelpEvent * >(PHP_QT_FETCH());
      }
      RETURN_LONG(selfpointer->globalX());
    }
  }
  php_error(E_ERROR, "could not parse argument in QHelpEvent::globalX(...) ");
}

/*!
 * method x
 * 
 * @param: -
 * @param: -
 * 
 * @access	public
 * @return	int
 * @flags	c
 */

ZEND_METHOD(QHelpEvent, x)
{
  ///
  if (ZEND_NUM_ARGS() == 0) {
    PHP_QT_FETCH_0_ARGS();
    if (1) {
      if (getThis() == NULL) {
        php_error(E_ERROR, "method 'x' is not static");
        RETURN_NULL();
      }
      /// try 
      QHelpEvent *selfpointer;

      if (getThis() != NULL) {
        selfpointer = static_cast < QHelpEvent * >(PHP_QT_FETCH());
      }
      RETURN_LONG(selfpointer->x());
    }
  }
  php_error(E_ERROR, "could not parse argument in QHelpEvent::x(...) ");
}

/*!
 * method globalY
 * 
 * @param: -
 * @param: -
 * 
 * @access	public
 * @return	int
 * @flags	c
 */

ZEND_METHOD(QHelpEvent, globalY)
{
  ///
  if (ZEND_NUM_ARGS() == 0) {
    PHP_QT_FETCH_0_ARGS();
    if (1) {
      if (getThis() == NULL) {
        php_error(E_ERROR, "method 'globalY' is not static");
        RETURN_NULL();
      }
      /// try 
      QHelpEvent *selfpointer;

      if (getThis() != NULL) {
        selfpointer = static_cast < QHelpEvent * >(PHP_QT_FETCH());
      }
      RETURN_LONG(selfpointer->globalY());
    }
  }
  php_error(E_ERROR, "could not parse argument in QHelpEvent::globalY(...) ");
}
