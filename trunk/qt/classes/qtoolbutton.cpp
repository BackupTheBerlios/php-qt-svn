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
 * QToolButton.cpp - QToolButton PHP implementation.
 * begin           : Thu May 11 21:32:50 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include "../php_qt.h"


#include <QToolButton>


/*		public enumToolButtonPopupMode:long {
			ToolButtonPopupMode = 0,
			ToolButtonPopupMode = 1,
			ToolButtonPopupMode = 2
		}
*/
/*!
 *    @class     QToolButton
 *    @function  tr
 *
 *    @flags    s
 *    @access    public
 *    @return    QString
 *    @param     const char *, const char * = 0 
 */
ZEND_METHOD(QToolButton, tr)
{
/*! ss public*/
/*! const char* , const char* ,  */
  if (ZEND_NUM_ARGS() == 2) {
    zval *z_0;                  /// define ZVAL
    zval *z_1;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "zz", &z_0, &z_1) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING) {
        QToolButton *obj = (QToolButton *) PHP_QT_FETCH();

        QString *return_object;

        if (getThis() != NULL) {
/// return value is object: QString
          *return_object = static_cast < QString > (obj->tr((const char *)Z_STRVAL_P(z_0), (const char *)Z_STRVAL_P(z_1)));
/// check whether method call is static.
        } else {
          return_object = (QString *) malloc(sizeof (QToolButton::tr((const char *)Z_STRVAL_P(z_0), (const char *)Z_STRVAL_P(z_1))));   /// memory allocation
          *return_object = static_cast < QString > (QToolButton::tr((const char *)Z_STRVAL_P(z_0), (const char *)Z_STRVAL_P(z_1)));
        } zend_class_entry *ce;

        object_init_ex(return_value, QToolButton_ce_ptr);
        zend_rsrc_list_entry le;

        le.ptr = return_object;
        php_qt_register(return_value, le);
        return;
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL
    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_STRING) {
        QString *return_object;

        if (getThis() != NULL) {
/// return value is object: QString
          QToolButton *obj = static_cast<QToolButton *>(PHP_QT_FETCH());
          *return_object = static_cast < QString > (obj->tr((const char *)Z_STRVAL_P(z_0)));
/// check whether method call is static.
        } else {
          return_object = (QString *) malloc(sizeof (QToolButton::tr((const char *)Z_STRVAL_P(z_0))));   /// memory allocation
          *return_object = static_cast < QString > (QToolButton::tr((const char *)Z_STRVAL_P(z_0)));
        } zend_class_entry *ce;

        object_init_ex(return_value, QToolButton_ce_ptr);
        zend_rsrc_list_entry le;

        le.ptr = return_object;
        php_qt_register(return_value, le);
        return;
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QToolButton
 *    @function  defaultAction
 *
 *    @flags    c
 *    @access    public
 *    @return    QAction *
 *    @param    
 */
ZEND_METHOD(QToolButton, defaultAction)
{
  if (ZEND_NUM_ARGS() == 0) {
    QAction **return_object;

    if (getThis() != NULL) {
      QToolButton *obj = (QToolButton *) PHP_QT_FETCH();

/// return: pointer

/// return value is object: QAction *
      *return_object = static_cast < QAction * >(obj->defaultAction());
    } else {                    /// END getThis(), static
      php_error(E_ERROR, "Object not found");
    }
    zend_class_entry *ce;

    object_init_ex(return_value, QToolButton_ce_ptr);
    zend_rsrc_list_entry le;

    le.ptr = return_object[0];
    php_qt_register(return_value, le);
    return;
  }
}

/*!
 *    @class     QToolButton
 *    @function  showMenu
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    
 */
ZEND_METHOD(QToolButton, showMenu)
{
  if (ZEND_NUM_ARGS() == 0) {
    void *return_object;

    if (getThis() != NULL) {
      QToolButton *obj = (QToolButton *) PHP_QT_FETCH();

      obj->showMenu();
      RETURN_NULL();
    }                           /// END getThis(), NULL
  }
}

/*!
 *    @class     QToolButton
 *    @function  autoRaise
 *
 *    @flags    c
 *    @access    public
 *    @return    bool
 *    @param    
 */
ZEND_METHOD(QToolButton, autoRaise)
{
  if (ZEND_NUM_ARGS() == 0) {
    bool *return_object;

    if (getThis() != NULL) {
      QToolButton *obj = (QToolButton *) PHP_QT_FETCH();

      RETURN_BOOL(obj->autoRaise());
    }                           /// 5 END getThis(), simple types
  }
}

/*!
 *    @class     QToolButton
 *    @function  staticMetaObject
 *
 *    @flags    s
 *    @access    public
 *    @return    QMetaObject*
 *    @param    
 */
ZEND_METHOD(QToolButton, staticMetaObject)
{
}

/*!
 *    @class     QToolButton
 *    @function  arrowType
 *
 *    @flags    c
 *    @access    public
 *    @return    Qt::ArrowType
 *    @param    
 */
ZEND_METHOD(QToolButton, arrowType)
{
  if (ZEND_NUM_ARGS() == 0) {
    Qt::ArrowType * return_object;
    if (getThis() != NULL) {
      QToolButton *obj = (QToolButton *) PHP_QT_FETCH();

      RETURN_LONG(obj->arrowType());
    }                           /// 5 END getThis(), simple types
  }
}

/*!
 *    @class     QToolButton
 *    @function  setDefaultAction
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    QAction *
 */
ZEND_METHOD(QToolButton, setDefaultAction)
{
///qt_QAction*
/*! o public*/
/*! qt_QAction* ,  */
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_OBJECT) {
        QToolButton *obj = (QToolButton *) PHP_QT_FETCH();
        QObject *obj_z_0 = (QObject *) php_qt_fetch(z_0);

        if (obj_z_0->inherits("QAction")) {
          void *return_object;

          if (getThis() != NULL) {
            obj->setDefaultAction((QAction *) obj_z_0);
            RETURN_NULL();
          }                     /// END getThis(), NULL
        }
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QToolButton
 *    @function  popupMode
 *
 *    @flags    c
 *    @access    public
 *    @return    ToolButtonPopupMode
 *    @param    
 */
ZEND_METHOD(QToolButton, popupMode)
{
/*  if (ZEND_NUM_ARGS() == 0) {
    ToolButtonPopupMode *return_object;

    if (getThis() != NULL) {
      QToolButton *obj = (QToolButton *) PHP_QT_FETCH();

      obj->popupMode();
      RETURN_NULL();
    }                           /// END getThis(), NULL
  }*/
}

/*!
 *    @class     QToolButton
 *    @function  qObject
 *
 *    @flags    
 *    @access    public
 *    @return    QObject*
 *    @param    
 */
ZEND_METHOD(QToolButton, qObject)
{
}

/*!
 *    @class     QToolButton
 *    @function  minimumSizeHint
 *
 *    @flags    c
 *    @access    public
 *    @return    QSize
 *    @param    
 */
ZEND_METHOD(QToolButton, minimumSizeHint)
{
  if (ZEND_NUM_ARGS() == 0) {
    QSize *return_object;

    if (getThis() != NULL) {
      QToolButton *obj = (QToolButton *) PHP_QT_FETCH();

/// return value is object: QSize
      *return_object = static_cast < QSize > (obj->minimumSizeHint());
    } else {                    /// END getThis(), static
      php_error(E_ERROR, "Object not found");
    }
    zend_class_entry *ce;

    object_init_ex(return_value, QToolButton_ce_ptr);
    zend_rsrc_list_entry le;

    le.ptr = return_object;
    php_qt_register(return_value, le);
    return;
  }
}

/*!
 *    @class     QToolButton
 *    @function  sizeHint
 *
 *    @flags    c
 *    @access    public
 *    @return    QSize
 *    @param    
 */
ZEND_METHOD(QToolButton, sizeHint)
{
  if (ZEND_NUM_ARGS() == 0) {
    QSize *return_object;

    if (getThis() != NULL) {
      QToolButton *obj = (QToolButton *) PHP_QT_FETCH();

/// return value is object: QSize
      *return_object = static_cast < QSize > (obj->sizeHint());
    } else {                    /// END getThis(), static
      php_error(E_ERROR, "Object not found");
    }
    zend_class_entry *ce;

    object_init_ex(return_value, QToolButton_ce_ptr);
    zend_rsrc_list_entry le;

    le.ptr = return_object;
    php_qt_register(return_value, le);
    return;
  }
}

/*!
 *    @class     QToolButton
 *    @function  QToolButton
 *
 *    @flags    t
 *    @access    public
 *    @return    
 *    @param    QWidget * parent=0
 */
ZEND_METHOD(QToolButton, __construct)
{
///QWidget*
/*! o public*/
/*! QWidget* parent,  */

  if (ZEND_NUM_ARGS() == 0) {

    QToolButton *QToolButton_ptr = new QToolButton();
    PHP_QT_REGISTER(QToolButton_ptr);
    RETURN_NULL();

  }                             /// END ZEND_NUM_ARGS

  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_OBJECT) {
        QObject *obj_z_0 = (QObject *) php_qt_fetch(z_0);

        if (obj_z_0->inherits("QWidget")) {
          QToolButton *QToolButton_ptr = new QToolButton((QWidget *) obj_z_0);

          PHP_QT_REGISTER(QToolButton_ptr);
          RETURN_NULL();
        }
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QToolButton
 *    @function  menu
 *
 *    @flags    c
 *    @access    public
 *    @return    QMenu*
 *    @param    
 */
ZEND_METHOD(QToolButton, menu)
{
  if (ZEND_NUM_ARGS() == 0) {
    QMenu **return_object;

    if (getThis() != NULL) {
      QToolButton *obj = (QToolButton *) PHP_QT_FETCH();

/// return: pointer

/// return value is object: QMenu*
      *return_object = static_cast < QMenu * >(obj->menu());
    } else {                    /// END getThis(), static
      php_error(E_ERROR, "Object not found");
    }
    zend_class_entry *ce;

    object_init_ex(return_value, QToolButton_ce_ptr);
    zend_rsrc_list_entry le;

    le.ptr = return_object[0];
    php_qt_register(return_value, le);
    return;
  }
}

/*!
 *    @class     QToolButton
 *    @function  nextCheckState
 *
 *    @flags    
 *    @access    protected
 *    @return    void
 *    @param    
 */
// method nextCheckState is protected, skipped.

/*!
 *    @class     QToolButton
 *    @function  triggered
 *
 *    @flags    
 *    @access    public
 *    @return    Q_SIGNALS: void
 *    @param    QAction *
 */
ZEND_METHOD(QToolButton, triggered)
{
///qt_QAction*
/*! o public*/
/*! qt_QAction* ,  */
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_OBJECT) {
        QToolButton *obj = (QToolButton *) PHP_QT_FETCH();
        QObject *obj_z_0 = (QObject *) php_qt_fetch(z_0);

        if (obj_z_0->inherits("QAction")) {
          void *return_object;

          if (getThis() != NULL) {
//            obj->triggered((QAction *) obj_z_0);
            RETURN_NULL();
          }                     /// END getThis(), NULL
        }
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QToolButton
 *    @function  event
 *
 *    @flags    
 *    @access    protected
 *    @return    bool
 *    @param    QEvent *e
 */
// method event is protected, skipped.

/*!
 *    @class     QToolButton
 *    @function  toolButtonStyle
 *
 *    @flags    c
 *    @access    public
 *    @return    Qt::ToolButtonStyle
 *    @param    
 */
ZEND_METHOD(QToolButton, toolButtonStyle)
{
  if (ZEND_NUM_ARGS() == 0) {
    Qt::ToolButtonStyle * return_object;
    if (getThis() != NULL) {
      QToolButton *obj = (QToolButton *) PHP_QT_FETCH();

      obj->toolButtonStyle();
      RETURN_NULL();
    }                           /// END getThis(), NULL
  }
}

/*!
 *    @class     QToolButton
 *    @function  setPopupMode
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    ToolButtonPopupMode mode
 */
ZEND_METHOD(QToolButton, setPopupMode)
{
///ToolButtonPopupMode
/*! o public*/
/*! ToolButtonPopupMode mode,  */
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_OBJECT) {
        QToolButton *obj = (QToolButton *) PHP_QT_FETCH();
        QObject *obj_z_0 = (QObject *) php_qt_fetch(z_0);

        if (obj_z_0->inherits("ToolButtonPopupMode")) {
          void *return_object;

          if (getThis() != NULL) {
//            obj->setPopupMode((ToolButtonPopupMode) obj_z_0);
            RETURN_NULL();
          }                     /// END getThis(), NULL
        }
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QToolButton
 *    @function  setToolButtonStyle
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    Qt::ToolButtonStyle style
 */
ZEND_METHOD(QToolButton, setToolButtonStyle)
{
///Qt::ToolButtonStyle
/*! o public*/
/*! Qt::ToolButtonStyle style,  */
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_OBJECT) {
        QToolButton *obj = (QToolButton *) PHP_QT_FETCH();
        QObject *obj_z_0 = (QObject *) php_qt_fetch(z_0);

        if (obj_z_0->inherits("Qt::ToolButtonStyle")) {
          void *return_object;

          if (getThis() != NULL) {
  //          obj->setToolButtonStyle((Qt::ToolButtonStyle) obj_z_0);
            RETURN_NULL();
          }                     /// END getThis(), NULL
        }
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QToolButton
 *    @function  trUtf8
 *
 *    @flags    s
 *    @access    public
 *    @return    QString
 *    @param     const char *, const char * = 0 
 */
ZEND_METHOD(QToolButton, trUtf8)
{
/*! ss public*/
/*! const char* , const char* ,  */
  if (ZEND_NUM_ARGS() == 2) {
    zval *z_0;                  /// define ZVAL
    zval *z_1;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "zz", &z_0, &z_1) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING) {
        QToolButton *obj = (QToolButton *) PHP_QT_FETCH();

        QString *return_object;

        if (getThis() != NULL) {
/// return value is object: QString
          *return_object = static_cast < QString > (obj->trUtf8((const char *)Z_STRVAL_P(z_0), (const char *)Z_STRVAL_P(z_1)));
/// check whether method call is static.
        } else {
          return_object = (QString *) malloc(sizeof (QToolButton::trUtf8((const char *)Z_STRVAL_P(z_0), (const char *)Z_STRVAL_P(z_1))));       /// memory allocation
          *return_object = static_cast < QString > (QToolButton::trUtf8((const char *)Z_STRVAL_P(z_0), (const char *)Z_STRVAL_P(z_1)));
        } zend_class_entry *ce;

        object_init_ex(return_value, QToolButton_ce_ptr);
        zend_rsrc_list_entry le;

        le.ptr = return_object;
        php_qt_register(return_value, le);
        return;
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QToolButton
 *    @function  setMenu
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    QMenu* menu
 */
ZEND_METHOD(QToolButton, setMenu)
{
///QMenu*
/*! o public*/
/*! QMenu* menu,  */
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_OBJECT) {
        QToolButton *obj = (QToolButton *) PHP_QT_FETCH();
        QObject *obj_z_0 = (QObject *) php_qt_fetch(z_0);

        if (obj_z_0->inherits("QMenu")) {
          void *return_object;

          if (getThis() != NULL) {
            obj->setMenu((QMenu *) obj_z_0);
            RETURN_NULL();
          }                     /// END getThis(), NULL
        }
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QToolButton
 *    @function  setAutoRaise
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    bool enable
 */
ZEND_METHOD(QToolButton, setAutoRaise)
{
/*! l public*/
/*! int enable,  */
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_LONG) {
        QToolButton *obj = (QToolButton *) PHP_QT_FETCH();

        void *return_object;

        if (getThis() != NULL) {
          obj->setAutoRaise((bool) Z_LVAL_P(z_0));
          RETURN_NULL();
        }                       /// END getThis(), NULL
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QToolButton
 *    @function  setArrowType
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    Qt::ArrowType type
 */
ZEND_METHOD(QToolButton, setArrowType)
{
/*! l public*/
/*! int type,  */
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_LONG) {
        QToolButton *obj = (QToolButton *) PHP_QT_FETCH();

        void *return_object;

        if (getThis() != NULL) {
          obj->setArrowType((Qt::ArrowType) Z_LVAL_P(z_0));
          RETURN_NULL();
        }                       /// END getThis(), NULL
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}


PHP_QT_DESTRUCT(QToolButton);