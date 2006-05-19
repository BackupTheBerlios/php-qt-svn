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
 * QDialog.cpp - QDialog PHP implementation.
 * begin           : Thu May 11 20:44:24 2006
 * generated by    : moni using kalyptus 0.9.
 */

#include <iostream>
using namespace std;

#include "../php_qt.h"


#include <QDialog>
#include <QMetaMethod>

class QDialog_moc : public QDialog
{
    public:
        QDialog_moc(zval* zend_ptr);

        zval* zend_ptr;
        QMetaObject* dynamicMetaObject;

        const QMetaObject* metaObject() const;
        int qt_metacall(QMetaObject::Call _c, int _id, void **_a);
        
};

const QMetaObject *QDialog_moc::metaObject() const
{
    return php_qt_getMocData(this->zend_ptr,"QDialog",&staticMetaObject);;
}

QDialog_moc::QDialog_moc(zval* zend_ptr)
{
    this->zend_ptr = zend_ptr;
    dynamicMetaObject = new QMetaObject;
    dynamicMetaObject = php_qt_getMocData(this->zend_ptr,"QDialog",&staticMetaObject);
}

int QDialog_moc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{

    QMetaObject* d = (QMetaObject*) this->metaObject();
    char* method_name = new char[strlen((d->method(_id)).signature())];
    strcpy(method_name,(char*) (d->method(_id)).signature());

    // breaks the string at the first bracket
    int i;
    for(i = 0; i < strlen(method_name); i++){
        if(method_name[i] == 40){
            method_name[i] = 0;
            break;
        }
    }

    // is a Slot
    if(d->method(_id).methodType() == QMetaMethod::Slot){

        int j = 0;
        zval** args[1];
        QList<QByteArray> qargs = d->method(_id).parameterTypes();

        for(i = 0; i < qargs.count(); i++){

            zval *arg;
            MAKE_STD_ZVAL(arg);

            // invoke to zend types
            if(!strncmp("int",(const char*) qargs[i],3)){
                ZVAL_LONG(arg, *reinterpret_cast< int*>(_a[i+1]));
            } else if(!strncmp("char*",(const char*) qargs[i],5)){
                ZVAL_STRING(arg, *reinterpret_cast< char**>(_a[i+1]), 1);
            } else if(!strncmp("bool",(const char*) qargs[i],4)){
                ZVAL_BOOL(arg, *reinterpret_cast< bool*>(_a[i+1]));
            } else if(!strncmp("double",(const char*) qargs[i],4)){
                ZVAL_DOUBLE(arg, *reinterpret_cast< double*>(_a[i+1]));
            } else {
                    // must be an object
                    zend_class_entry *ce;
                    object_init_ex(arg, QDialog_ce_ptr);
                    zend_rsrc_list_entry le;
                    le.ptr = *reinterpret_cast< QObject**>(_a[1]);
                    php_qt_register(arg, le);
                    
            }

            args[j++] = &arg;

        }

        php_qt_callmethod(this->zend_ptr, method_name, j, args);

    // is a signal
    } else {
        void *_b[] = { 0, _a[1] };
        QMetaObject::activate(this, d, 0, _b);
    }

    delete d;
    delete method_name;

    return _id;

}


/*		public enumDialogCode:long {
			DialogCode = 0,
			DialogCode = 1
		}
*/
/*!
 *    @class     QDialog
 *    @function  tr
 *
 *    @flags    s
 *    @access    public
 *    @return    QString
 *    @param     const char *, const char * = 0 
 */
ZEND_METHOD(QDialog, tr)
{
/*! ss public*/
/*! const char* , const char* ,  */
  if (ZEND_NUM_ARGS() == 2) {
    zval *z_0;                  /// define ZVAL
    zval *z_1;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "zz", &z_0, &z_1) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING) {
        QDialog *obj = (QDialog *) PHP_QT_FETCH();

        QString *return_object;

        if (getThis() != NULL) {
/// return value is object: QString
          *return_object = static_cast < QString > (obj->tr((const char *)Z_STRVAL_P(z_0), (const char *)Z_STRVAL_P(z_1)));
/// check whether method call is static.
        } else {
          return_object = (QString *) malloc(sizeof (QDialog::tr((const char *)Z_STRVAL_P(z_0), (const char *)Z_STRVAL_P(z_1))));       /// memory allocation
          *return_object = static_cast < QString > (QDialog::tr((const char *)Z_STRVAL_P(z_0), (const char *)Z_STRVAL_P(z_1)));
        } zend_class_entry *ce;

        object_init_ex(return_value, QString_ce_ptr);
        zend_rsrc_list_entry le;

        le.ptr = return_object;
        php_qt_register(return_value, le);
        return;
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARG
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_STRING) {
        QString *return_object = new QString;
        if (getThis() != NULL) {
/// return value is object: QString
            QDialog *obj = static_cast<QDialog *>(PHP_QT_FETCH());
            *return_object = static_cast < QString > (obj->tr((const char *)Z_STRVAL_P(z_0)));
/// check whether method call is static.
        } else {
            *return_object = static_cast < QString > (QDialog::tr((const char *)Z_STRVAL_P(z_0)));
        } 
            zend_class_entry *ce;
            object_init_ex(return_value, QString_ce_ptr);
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
 *    @class     QDialog
 *    @function  setSizeGripEnabled
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    bool
 */
ZEND_METHOD(QDialog, setSizeGripEnabled)
{
/*! l public*/
/*! int ,  */
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_LONG) {
        QDialog *obj = (QDialog *) PHP_QT_FETCH();

        void *return_object;

        if (getThis() != NULL) {
          obj->setSizeGripEnabled((bool) Z_LVAL_P(z_0));
          RETURN_NULL();
        }                       /// END getThis(), NULL
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QDialog
 *    @function  setModal
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    bool modal
 */
ZEND_METHOD(QDialog, setModal)
{
/*! l public*/
/*! int modal,  */
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_LONG) {
        QDialog *obj = (QDialog *) PHP_QT_FETCH();

        void *return_object;

        if (getThis() != NULL) {
          obj->setModal((bool) Z_LVAL_P(z_0));
          RETURN_NULL();
        }                       /// END getThis(), NULL
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QDialog
 *    @function  exec
 *
 *    @flags    
 *    @access    public
 *    @return    int
 *    @param    
 */
ZEND_METHOD(QDialog, exec)
{
  if (ZEND_NUM_ARGS() == 0) {
    int *return_object;

    if (getThis() != NULL) {
      QDialog *obj = (QDialog *) PHP_QT_FETCH();

      RETURN_LONG(obj->exec());
    }                           /// 5 END getThis(), simple types
  }
}

/*!
 *    @class     QDialog
 *    @function  showExtension
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    bool
 */
ZEND_METHOD(QDialog, showExtension)
{
/*! l public*/
/*! int ,  */
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_LONG) {
        QDialog *obj = (QDialog *) PHP_QT_FETCH();

        void *return_object;

        if (getThis() != NULL) {
          obj->showExtension((bool) Z_LVAL_P(z_0));
          RETURN_NULL();
        }                       /// END getThis(), NULL
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QDialog
 *    @function  rejected
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    
 */
ZEND_METHOD(QDialog, rejected)
{
/*  if (ZEND_NUM_ARGS() == 0) {
    void *return_object;

    if (getThis() != NULL) {
      QDialog *obj = (QDialog *) PHP_QT_FETCH();

      obj->rejected();
      RETURN_NULL();
    }                           /// END getThis(), NULL
  }*/
}

/*!
 *    @class     QDialog
 *    @function  isSizeGripEnabled
 *
 *    @flags    c
 *    @access    public
 *    @return    bool
 *    @param    
 */
ZEND_METHOD(QDialog, isSizeGripEnabled)
{
  if (ZEND_NUM_ARGS() == 0) {
    bool *return_object;

    if (getThis() != NULL) {
      QDialog *obj = (QDialog *) PHP_QT_FETCH();

      RETURN_BOOL(obj->isSizeGripEnabled());
    }                           /// 5 END getThis(), simple types
  }
}

/*!
 *    @class     QDialog
 *    @function  event
 *
 *    @flags    
 *    @access    public
 *    @return    bool
 *    @param    QEvent *
 */
ZEND_METHOD(QDialog, event)
{
///qt_QEvent*
/*! o public*/
/*! qt_QEvent* ,  */
/*  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_OBJECT) {
        QDialog *obj = (QDialog *) PHP_QT_FETCH();
        QObject *obj_z_0 = (QObject *) php_qt_fetch(z_0);

        if (!strcmp(Z_OBJCE_P(z_0)->name, "QEvent")) {
          bool *return_object;

          if (getThis() != NULL) {
            RETURN_BOOL(obj->event((QEvent *) obj_z_0));
          }                     /// 5 END getThis(), simple types
        }
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS*/
}

/*!
 *    @class     QDialog
 *    @function  adjustPosition
 *
 *    @flags    
 *    @access    protected
 *    @return    void
 *    @param    QWidget*
 */
// method adjustPosition is protected, skipped.

/*!
 *    @class     QDialog
 *    @function  setExtension
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    QWidget* extension
 */
ZEND_METHOD(QDialog, setExtension)
{
///QWidget*
/*! o public*/
/*! QWidget* extension,  */
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_OBJECT) {
        QDialog *obj = (QDialog *) PHP_QT_FETCH();
        QObject *obj_z_0 = (QObject *) php_qt_fetch(z_0);

        if (obj_z_0->inherits("QWidget")) {
          void *return_object;

          if (getThis() != NULL) {
            obj->setExtension((QWidget *) obj_z_0);
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
 *    @class     QDialog
 *    @function  finished
 *
 *    @flags    
 *    @access    public
 *    @return    Q_SIGNALS: void
 *    @param    int result
 */
ZEND_METHOD(QDialog, finished)
{
/*! l public*/
/*! int result,  */
/*  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_LONG) {
        QDialog *obj = (QDialog *) PHP_QT_FETCH();

        void *return_object;

        if (getThis() != NULL) {
          obj->finished((int)Z_LVAL_P(z_0));
          RETURN_NULL();
        }                       /// END getThis(), NULL
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS*/
}

/*!
 *    @class     QDialog
 *    @function  result
 *
 *    @flags    c
 *    @access    public
 *    @return    int
 *    @param    
 */
ZEND_METHOD(QDialog, result)
{
  if (ZEND_NUM_ARGS() == 0) {
    int *return_object;

    if (getThis() != NULL) {
      QDialog *obj = (QDialog *) PHP_QT_FETCH();

      RETURN_LONG(obj->result());
    }                           /// 5 END getThis(), simple types
  }
}

/*!
 *    @class     QDialog
 *    @function  orientation
 *
 *    @flags    c
 *    @access    public
 *    @return    Qt::Orientation
 *    @param    
 */
ZEND_METHOD(QDialog, orientation)
{
  if (ZEND_NUM_ARGS() == 0) {
    Qt::Orientation * return_object;
    if (getThis() != NULL) {
      QDialog *obj = (QDialog *) PHP_QT_FETCH();

      RETURN_LONG(obj->orientation());
    }                           /// 5 END getThis(), simple types
  }
}

/*!
 *    @class     QDialog
 *    @function  QDialog
 *
 *    @flags    t
 *    @access    public
 *    @return    
 *    @param    QWidget *parent = 0, Qt::WFlags f = 0
 */
ZEND_METHOD(QDialog, __construct)
{
///QWidget*
/*! ol public*/
/*! QWidget* parent, int f,  */

  if (ZEND_NUM_ARGS() == 0) {

    QDialog_moc *QDialog_ptr = new QDialog_moc(getThis());

    PHP_QT_REGISTER(QDialog_ptr);
    RETURN_NULL();
                                /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS

  if (ZEND_NUM_ARGS() == 2) {
    zval *z_0;                  /// define ZVAL
    zval *z_1;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "zz", &z_0, &z_1) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_OBJECT && Z_TYPE_P(z_1) == IS_LONG) {
        QObject *obj_z_0 = (QObject *) php_qt_fetch(z_0);

        if (obj_z_0->inherits("QWidget")) {
          QDialog *QDialog_ptr = new QDialog((QWidget *) obj_z_0, (Qt::WFlags) Z_LVAL_P(z_1));

          PHP_QT_REGISTER(QDialog_ptr);
          RETURN_NULL();
        }
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QDialog
 *    @function  staticMetaObject
 *
 *    @flags    s
 *    @access    public
 *    @return    QMetaObject*
 *    @param    
 */
ZEND_METHOD(QDialog, staticMetaObject)
{
}

/*!
 *    @class     QDialog
 *    @function  qObject
 *
 *    @flags    
 *    @access    public
 *    @return    QObject*
 *    @param    
 */
ZEND_METHOD(QDialog, qObject)
{
}

/*!
 *    @class     QDialog
 *    @function  sizeHint
 *
 *    @flags    c
 *    @access    public
 *    @return    QSize
 *    @param    
 */
ZEND_METHOD(QDialog, sizeHint)
{
  if (ZEND_NUM_ARGS() == 0) {
    QSize *return_object;

    if (getThis() != NULL) {
      QDialog *obj = (QDialog *) PHP_QT_FETCH();

/// return value is object: QSize
      *return_object = static_cast < QSize > (obj->sizeHint());
    } else {                    /// END getThis(), static
      php_error(E_ERROR, "Object not found");
    }
    zend_class_entry *ce;

    object_init_ex(return_value, QDialog_ce_ptr);
    zend_rsrc_list_entry le;

    le.ptr = return_object;
    php_qt_register(return_value, le);
    return;
  }
}

/*!
 *    @class     QDialog
 *    @function  minimumSizeHint
 *
 *    @flags    c
 *    @access    public
 *    @return    QSize
 *    @param    
 */
ZEND_METHOD(QDialog, minimumSizeHint)
{
  if (ZEND_NUM_ARGS() == 0) {
    QSize *return_object;

    if (getThis() != NULL) {
      QDialog *obj = (QDialog *) PHP_QT_FETCH();

/// return value is object: QSize
      *return_object = static_cast < QSize > (obj->minimumSizeHint());
    } else {                    /// END getThis(), static
      php_error(E_ERROR, "Object not found");
    }
    zend_class_entry *ce;

    object_init_ex(return_value, QDialog_ce_ptr);
    zend_rsrc_list_entry le;

    le.ptr = return_object;
    php_qt_register(return_value, le);
    return;
  }
}

/*!
 *    @class     QDialog
 *    @function  extension
 *
 *    @flags    c
 *    @access    public
 *    @return    QWidget*
 *    @param    
 */
ZEND_METHOD(QDialog, extension)
{
  if (ZEND_NUM_ARGS() == 0) {
    QWidget **return_object;

    if (getThis() != NULL) {
      QDialog *obj = (QDialog *) PHP_QT_FETCH();

/// return: pointer

/// return value is object: QWidget*
      *return_object = static_cast < QWidget * >(obj->extension());
    } else {                    /// END getThis(), static
      php_error(E_ERROR, "Object not found");
    }
    zend_class_entry *ce;

    object_init_ex(return_value, QDialog_ce_ptr);
    zend_rsrc_list_entry le;

    le.ptr = return_object[0];
    php_qt_register(return_value, le);
    return;
  }
}

/*!
 *    @class     QDialog
 *    @function  setOrientation
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    Qt::Orientation orientation
 */
ZEND_METHOD(QDialog, setOrientation)
{
/*! l public*/
/*! int orientation,  */
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_LONG) {
        QDialog *obj = (QDialog *) PHP_QT_FETCH();

        void *return_object;

        if (getThis() != NULL) {
          obj->setOrientation((Qt::Orientation) Z_LVAL_P(z_0));
          RETURN_NULL();
        }                       /// END getThis(), NULL
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QDialog
 *    @function  setVisible
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    bool visible
 */
ZEND_METHOD(QDialog, setVisible)
{
/*! l public*/
/*! int visible,  */
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_LONG) {
        QDialog *obj = (QDialog *) PHP_QT_FETCH();

        void *return_object;

        if (getThis() != NULL) {
          obj->setVisible((bool) Z_LVAL_P(z_0));
          RETURN_NULL();
        }                       /// END getThis(), NULL
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QDialog
 *    @function  setResult
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    int r
 */
ZEND_METHOD(QDialog, setResult)
{
/*! l public*/
/*! int r,  */
  if (ZEND_NUM_ARGS() == 1) {
    zval *z_0;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "z", &z_0) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_LONG) {
        QDialog *obj = (QDialog *) PHP_QT_FETCH();

        void *return_object;

        if (getThis() != NULL) {
          obj->setResult((int)Z_LVAL_P(z_0));
          RETURN_NULL();
        }                       /// END getThis(), NULL
      } else {
        php_error(E_ERROR, "argument not allowed");
      }                         /// END check of argument types
    }                           /// END zend_parse_parameters
  }                             /// END ZEND_NUM_ARGS
}

/*!
 *    @class     QDialog
 *    @function  eventFilter
 *
 *    @flags    
 *    @access    protected
 *    @return    bool
 *    @param    QObject *, QEvent *
 */
// method eventFilter is protected, skipped.

/*!
 *    @class     QDialog
 *    @function  accepted
 *
 *    @flags    
 *    @access    public
 *    @return    void
 *    @param    
 */
ZEND_METHOD(QDialog, accepted)
{
/*  if (ZEND_NUM_ARGS() == 0) {
    void *return_object;

    if (getThis() != NULL) {
      QDialog *obj = (QDialog *) PHP_QT_FETCH();

      obj->accepted();
      RETURN_NULL();
    }                           /// END getThis(), NULL
  }*/
}

/*!
 *    @class     QDialog
 *    @function  trUtf8
 *
 *    @flags    s
 *    @access    public
 *    @return    QString
 *    @param     const char *, const char * = 0 
 */
ZEND_METHOD(QDialog, trUtf8)
{
/*! ss public*/
/*! const char* , const char* ,  */
  if (ZEND_NUM_ARGS() == 2) {
    zval *z_0;                  /// define ZVAL
    zval *z_1;                  /// define ZVAL

    if (zend_parse_parameters(ZEND_NUM_ARGS()TSRMLS_CC, "zz", &z_0, &z_1) == SUCCESS) {
      if (Z_TYPE_P(z_0) == IS_STRING && Z_TYPE_P(z_1) == IS_STRING) {
        QDialog *obj = (QDialog *) PHP_QT_FETCH();

        QString *return_object;

        if (getThis() != NULL) {
/// return value is object: QString
          *return_object = static_cast < QString > (obj->trUtf8((const char *)Z_STRVAL_P(z_0), (const char *)Z_STRVAL_P(z_1)));
/// check whether method call is static.
        } else {
          return_object = (QString *) malloc(sizeof (QDialog::trUtf8((const char *)Z_STRVAL_P(z_0), (const char *)Z_STRVAL_P(z_1))));   /// memory allocation
          *return_object = static_cast < QString > (QDialog::trUtf8((const char *)Z_STRVAL_P(z_0), (const char *)Z_STRVAL_P(z_1)));
        } zend_class_entry *ce;

        object_init_ex(return_value, QDialog_ce_ptr);
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


PHP_QT_DESTRUCT(QDialog);
