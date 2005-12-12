dnl $Id$
dnl config.m4 for extension php_qt


PHP_ARG_WITH(prefix,,
[  --with-prefix=DIR    php prefix])

if test "$PHP_PREFIX" != "no"; then
 if test "$PHP_PREFIX" != "yes"; then
    $prefix=$PHP_PREFIX
 fi
fi

dnl runtime
PHP_ARG_WITH(qtlib,Qt runtime library,
[  --with-qtlib=DIR    qt runtime library])

AC_MSG_CHECKING([for Qt runtime])

if test "$PHP_QTLIB" != "yes"; then

    if test -z "$PHP_QTLIB"; then
        AC_MSG_RESULT(found in $PHP_QTLIB)
    else 
        AC_MSG_ERROR([Please reinstall the Qt distribution])
    fi

  PHP_ADD_LIBPATH($PHP_QTLIB/lib/qt4 )
  PHP_ADD_LIBPATH($PHP_QTLIB/lib)
  PHP_ADD_LIBPATH(/tmp/buildd/qt4-x11-4.0.1/lib)
  PHP_ADD_LIBPATH($PHP_QTLIB/X11R6/lib)

else
    if test "$PHP_QTLIB" != "no"; then
        PHP_ADD_LIBPATH(/usr/lib/qt4 )
        PHP_ADD_LIBPATH(/usr/lib)
        PHP_ADD_LIBPATH(/tmp/buildd/qt4-x11-4.0.1/lib)
        PHP_ADD_LIBPATH(/usr/X11R6/lib)
        AC_MSG_RESULT([default path])
    else
        AC_MSG_RESULT([skipped])
    fi
fi


dnl build
PHP_ARG_WITH(php_qt, for php_qt support,
[  --with-php_qt=DIR           Include Qt support])

if test "$PHP_PHP_QT" != "no"; then

  SEARCH_PATH="/usr/local /usr"
  SEARCH_FOR="/include/qt4/Qt/qobject.h"
  SEARCH_FOR_OTHER="/include/Qt/qobject.h"
  if test -r $PHP_PHP_QT/$SEARCH_FOR_OTHER; then 
    PHP_QT_DIR=$PHP_PHP_QT
    AC_MSG_RESULT(Qt header files found in $PHP_QT_DIR)
  else 
    AC_MSG_CHECKING([for Qt files in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        PHP_QT_DIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done
  fi

  if test -z "$PHP_QT_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the Qt distribution])
  fi

  PHP_ADD_INCLUDE($PHP_QT_DIR/include)


  dnl from qmake
  LDFLAGS="$LDFLAGS -lQtGui -laudio -lXt -lpng -lSM -lICE -lXi -lXrender -lXrandr -lXcursor -lXinerama -lfreetype -lXext -lX11 -lm -lQtCore -lfontconfig -lz -ldl -lpthread"

  PHP_REQUIRE_CXX

  if test -r $PHP_PHP_QT/$SEARCH_FOR_OTHER; then 
    PHP_ADD_INCLUDE($PHP_QT_DIR/mkspecs/linux-g++)
    PHP_ADD_INCLUDE($PHP_QT_DIR/include/QtGui)
    PHP_ADD_INCLUDE($PHP_QT_DIR/include/QtCore)
    PHP_ADD_INCLUDE($PHP_QT_DIR/include/)
  else
    PHP_ADD_INCLUDE($PHP_QT_DIR/share/qt4/mkspecs/linux-g++)
    PHP_ADD_INCLUDE($PHP_QT_DIR/include/qt4/QtGui)
    PHP_ADD_INCLUDE($PHP_QT_DIR/include/qt4/QtCore)
    PHP_ADD_INCLUDE($PHP_QT_DIR/include/qt4)
  fi

  PHP_NEW_EXTENSION(php_qt, \
  qt/main_window/qapplication.cpp \
  qt/main_window/qcoreapplication.cpp \
  qt/abstract_widgets/qabstractbutton.cpp \
  qt/abstract_widgets/qwidget.cpp \
  qt/abstract_widgets/qabstractslider.cpp \
  qt/abstract_widgets/QFrame.cpp \
  qt/basic_widgets/qlineedit.cpp \
  qt/basic_widgets/qpushbutton.cpp \
  qt/basic_widgets/qslider.cpp \
  qt/basic_widgets/QLCDNumber.cpp \
  qt/layout_management/qlayoutitem.cpp \
  qt/layout_management/qlayout.cpp \
  qt/layout_management/qboxlayout.cpp \
  qt/layout_management/qhboxlayout.cpp \
  qt/layout_management/qvboxlayout.cpp \
  qt/object_model/qobject.cpp \
  qt/text_related/qstring.cpp \
  qt/text_related/qlatin1string.cpp \
  qt/text_related/qchar.cpp \
  qt/event/qevent.cpp \
  qt/php_qt.cpp,$ext_shared)

  PHP_ADD_BUILD_DIR($ext_builddir/qt)

fi

