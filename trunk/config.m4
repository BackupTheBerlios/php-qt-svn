dnl $Id$
dnl config.m4 for extension php_qt


dnl runtime
PHP_ARG_WITH(qtlib,Qt runtime library,
[  --with-qtlib=DIR         Qt library binaries])

AC_MSG_CHECKING([for Qt binaries])

if test "$PHP_QTLIB" != "yes"; then

    if test -r "$PHP_QTLIB"; then
        AC_MSG_RESULT(found in $PHP_QTLIB)
    else 
        AC_MSG_ERROR([Please reinstall the Qt distribution] $PHP_QTLIB)
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


PHP_ARG_WITH(php_qt, for php_qt,
[  --with-php_qt=DIR        Include Qt support and look for headers in /usr/local/include/qt4 /usr/include/qt4 /usr/lib/qt4/include])

if test "$PHP_PHP_QT" != "no"; then

  SEARCH_OBJ="/Qt/qobject.h"

  SEARCH_PATH="/usr/local /usr /usr/lib/qt4"
  SEARCH_FOR="/include/qt4 /include"
  SEARCH_FOR_OTHER="/include/Qt/qobject.h"

  if test -r $PHP_PHP_QT/$SEARCH_FOR_OTHER; then 
    PHP_QT_DIR=$PHP_PHP_QT
    AC_MSG_RESULT(Qt header files found in $PHP_QT_DIR)
  else 
    AC_MSG_CHECKING([for Qt headers in default path])
    AC_MSG_RESULT(trying different pathes)
    for i in $SEARCH_PATH ; do
     for j in $SEARCH_FOR ; do
      AC_MSG_CHECKING(for $i$j$SEARCH_OBJ)
      if test -r $i$j/$SEARCH_OBJ; then
        PHP_QT_DIR=$i$j
        AC_MSG_RESULT(found)
      else
        AC_MSG_RESULT(not found)
      fi
     done
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

  PHP_ADD_INCLUDE($PHP_QT_DIR/QtGui)
  PHP_ADD_INCLUDE($PHP_QT_DIR/QtCore)
  PHP_ADD_INCLUDE($PHP_QT_DIR)

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

