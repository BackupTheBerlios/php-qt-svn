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
Make sure that the comment is aligned:
[  --enable-php_qt           Enable php_qt support])

if test "$PHP_PHP_QT" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-php_qt -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/php_qt.h"  # you most likely want to change this
  dnl if test -r $PHP_PHP_QT/$SEARCH_FOR; then # path given as parameter
  dnl   PHP_QT_DIR=$PHP_PHP_QT
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for php_qt files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       PHP_QT_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$PHP_QT_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the php_qt distribution])
  dnl fi

  dnl # --with-php_qt -> add include path
  dnl PHP_ADD_INCLUDE($PHP_QT_DIR/include)

  dnl # --with-php_qt -> check for lib and symbol presence
  dnl LIBNAME=php_qt # you may want to change this
  dnl LIBSYMBOL=php_qt # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $PHP_QT_DIR/lib, PHP_QT_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_PHP_QTLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong php_qt lib version or lib not found])
  dnl ],[
  dnl   -L$PHP_QT_DIR/lib -lm -ldl
  dnl ])
  dnl
  dnl PHP_SUBST(PHP_QT_SHARED_LIBADD)

  PHP_NEW_EXTENSION(php_qt, php_qt.c, $ext_shared)
fi
