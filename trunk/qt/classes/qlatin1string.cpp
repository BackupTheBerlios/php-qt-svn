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
 * QLatin1String.cpp - QLatin1String PHP implementation.
 * begin           : Tue Jun  6 22:42:56 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include "../php_qt.h"


#include <QLatin1String>
#include <QMetaMethod>
class QLatin1String_php_qt:public QLatin1String
{

public:
  QLatin1String_php_qt(zval * zend_ptr, const char *ss0);


  zval *zend_ptr;
};
QLatin1String_php_qt::QLatin1String_php_qt(zval * zend_ptr, const char *ss0):
QLatin1String(ss0)
{
  this->zend_ptr = zend_ptr;
}

/*!
 * method QLatin1String
 * 
 * @param: -
 * 
 * overloaded args:
 * @param	const char *ss0s0
 * 
 * @access	public
 * @return	
 * @flags	t
 */

ZEND_METHOD(QLatin1String, __construct)
{
  ///const char *ss0s0
  if (ZEND_NUM_ARGS() == 1) {
    PHP_QT_FETCH_1_ARGS();
    if (1 && Z_TYPE_P(arg_0) == IS_STRING) {
      if (getThis() == NULL) {
        php_error(E_ERROR, "method '__construct' is not static");
        RETURN_NULL();
      }
      /// try const char *ss0s0,
      QLatin1String_php_qt *selfpointer = new QLatin1String_php_qt(getThis(), (const char *)&Z_STRVAL_P(arg_0)[0]);

      PHP_QT_REGISTER(selfpointer);
      RETURN_NULL();
    }
  }
  php_error(E_ERROR, "could not parse argument in QLatin1String::QLatin1String(...) ");
}

/*!
 * method operator<
 * 
 * @param: -
 * 
 * overloaded args:
 * @param	const QString &ss0
 * 
 * @access	public
 * @return	bool
 * @flags	c
 */

/*!
 * method operator==
 * 
 * @param: -
 * 
 * overloaded args:
 * @param	const QString &ss0
 * 
 * @access	public
 * @return	bool
 * @flags	c
 */

/*!
 * method operator!=
 * 
 * @param: -
 * 
 * overloaded args:
 * @param	const QString &ss0
 * 
 * @access	public
 * @return	bool
 * @flags	c
 */

/*!
 * method operator>
 * 
 * @param: -
 * 
 * overloaded args:
 * @param	const QString &ss0
 * 
 * @access	public
 * @return	bool
 * @flags	c
 */

/*!
 * method operator<=
 * 
 * @param: -
 * 
 * overloaded args:
 * @param	const QString &ss0
 * 
 * @access	public
 * @return	bool
 * @flags	c
 */

/*!
 * method latin1
 * 
 * @param: -
 * @param: -
 * 
 * @access	public
 * @return	const char *
 * @flags	c
 */

ZEND_METHOD(QLatin1String, latin1)
{
  ///
  if (ZEND_NUM_ARGS() == 0) {
    PHP_QT_FETCH_0_ARGS();
    if (1) {
      if (getThis() == NULL) {
        php_error(E_ERROR, "method 'latin1' is not static");
        RETURN_NULL();
      }
      /// try 
      QLatin1String *selfpointer;

      if (getThis() != NULL) {
        selfpointer = static_cast < QLatin1String * >(PHP_QT_FETCH());
      }
      RETURN_STRING((char *)selfpointer->latin1(), 1);
    }
  }
  php_error(E_ERROR, "could not parse argument in QLatin1String::latin1(...) ");
}

/*!
 * method operator>=
 * 
 * @param: -
 * 
 * overloaded args:
 * @param	const QString &ss0
 * 
 * @access	public
 * @return	bool
 * @flags	c
 */
