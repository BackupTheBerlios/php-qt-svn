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
 * QClipboardEvent.cpp - QClipboardEvent PHP implementation.
 * begin           : Tue Jun  6 22:42:56 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include "../php_qt.h"


#include <QClipboardEvent>
/// DEBUG:destructor skipped.
#include <QMetaMethod>
class QClipboardEvent_php_qt:public QClipboardEvent
{

public:
  QClipboardEvent_php_qt(zval * zend_ptr, QEventPrivate * datas0);


  zval *zend_ptr;
};

QClipboardEvent_php_qt::QClipboardEvent_php_qt(zval * zend_ptr, QEventPrivate * datas0):QClipboardEvent(datas0)
{
  this->zend_ptr = zend_ptr;
}

/*!
 * method QClipboardEvent
 * 
 * @param: -
 * 
 * overloaded args:
 * @param	QEventPrivate *datas0s0
 * 
 * @access	public
 * @return	
 * @flags	
 */

ZEND_METHOD(QClipboardEvent, __construct)
{
  ///QEventPrivate *datas0s0
  if (ZEND_NUM_ARGS() == 1) {
    PHP_QT_FETCH_1_ARGS();
    if (1 && Z_TYPE_P(arg_0) == IS_OBJECT) {
#ifdef PHP_QT_QEventPrivate
      if (inherits(Z_OBJCE_P(arg_0), 0)) {
        if (getThis() == NULL) {
          php_error(E_ERROR, "method '__construct' is not static");
          RETURN_NULL();
        }
        /// try QEventPrivate *datas0s0,
        QEventPrivate *
          cpp_arg_0 = static_cast < QEventPrivate * >(php_qt_fetch(arg_0));
        QClipboardEvent_php_qt *
          selfpointer = new QClipboardEvent_php_qt(getThis(), (QEventPrivate *) cpp_arg_0);

        PHP_QT_REGISTER(selfpointer);
        RETURN_NULL();
      }
#endif

    }
  }
  php_error(E_ERROR, "could not parse argument in QClipboardEvent::QClipboardEvent(...) ");
}

/*!
 * method data
 * 
 * @param: -
 * @param: -
 * 
 * @access	public
 * @return	QEventPrivate *
 * @flags	
 */

ZEND_METHOD(QClipboardEvent, data)
{
  ///
#ifdef PHP_QT_QEventPrivate     // return type

  if (ZEND_NUM_ARGS() == 0) {
    PHP_QT_FETCH_0_ARGS();
    if (1) {
      if (getThis() == NULL) {
        php_error(E_ERROR, "method 'data' is not static");
        RETURN_NULL();
      }
      /// try 
      QClipboardEvent *
        selfpointer;

      if (getThis() != NULL) {
        selfpointer = static_cast < QClipboardEvent * >(PHP_QT_FETCH());
      }
      zend_class_entry *
        ce;

      object_init_ex(return_value, QString_ce_ptr);
      zend_rsrc_list_entry
        le;

      le.ptr = static_cast < QEventPrivate * >(selfpointer->data());
      php_qt_register(return_value, le);
      return;
    }
  }
#endif // return type

  php_error(E_ERROR, "could not parse argument in QClipboardEvent::data(...) ");
}
