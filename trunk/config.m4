dnl $Id$
dnl config.m4 for extension php_qt

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(php_qt, for php_qt support,
dnl Make sure that the comment is aligned:
dnl [  --with-php_qt             Include php_qt support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(php_qt, whether to enable php_qt support,
dnl Make sure that the comment is aligned:
[  --enable-php_qt           Enable php_qt support])

if test "$PHP_PHP_QT" != "no"; then

  PHP_REQUIRE_CXX

  PHP_ADD_MAKEFILE_FRAGMENT(Makefile.qt)

  PHP_ADD_INCLUDE(/usr/share/qt4/mkspecs/linux-g++)
  PHP_ADD_INCLUDE(/usr/include/qt4/QtGui)
  PHP_ADD_INCLUDE(/usr/include/qt4/QtCore)
  PHP_ADD_INCLUDE(/usr/include/qt4)

  PHP_NEW_EXTENSION(php_qt, \
  qt/main_window/qapplication.cpp \
  qt/abstract_widgets/qabstractbutton.cpp \
  qt/abstract_widgets/qwidget.cpp \
  qt/basic_widgets/qpushbutton.cpp \
  qt/object_model/qobject.cpp \
  qt/text_related/qstring.cpp \
  qt/text_related/qlatin1string.cpp \
  qt/text_related/qchar.cpp \
  qt/php_qt.cpp ,$ext_shared)

  PHP_ADD_BUILD_DIR($ext_builddir/qt)


fi
