
m4_pattern_allow([AM_INIT_AUTOMAKE])dnl
m4_pattern_allow([AC_PACKAGE_TARNAME])dnl
m4_pattern_allow([AC_PACKAGE_VERSION])dnl
AM_INIT_AUTOMAKE([NO-DEFINE])

dnl This is so we can use kde-common

dnl includes kde build environment
KDE_CREATE_LIBS_ALIASES

AC_ENABLE_SHARED(yes)
AC_ENABLE_STATIC(no)
KDE_PROG_LIBTOOL

m4_pattern_allow([AC_PATH_QT])dnl
AC_PATH_QT()
AC_SUBST(all_includes)
AC_SUBST(all_libraries)

dnl =======================================================
dnl FILE: ./smoke/configure.in.in
dnl =======================================================

AC_ARG_WITH(
   smoke,
   [  --with-smoke@<:@=qt|kde@:>@   Smoke: build Smoke for qt+kde or qt only @<:@default:qt@:>@],
   [ kde_build_libsmoke="$withval" ],
   [ kde_build_libsmoke="qt" ]
)
AC_SUBST(kde_build_libsmoke)

dnl =======================================================
dnl FILE: ./smoke/kde/configure.in.in
dnl =======================================================


#AC_HAVE_GL
#KDE_HAVE_GL=yes;
#if test "X$GLLIB" = "X"; then
#    KDE_HAVE_GL=no
#fi
#
#AC_SUBST(KDE_HAVE_GL)   
#
#KDE_PREFIX=`$KDECONFIG --prefix --expandvars`
#AC_SUBST(KDE_PREFIX)
#
#if test "X$kde_build_libsmoke" = "Xkde" -o "X$kde_build_libsmoke" = "Xqt kde"; then
#
#    AC_CONFIG_FILES([ smoke/kde/qtguess.pl ], [
#        cd smoke/kde
#        perl qtguess.pl
#        cd ../..
#    ])
#    AC_CONFIG_FILES([ smoke/kde/generate.pl ], [
#        cd smoke/kde
#        perl generate.pl
#        cd ../..
#    ])
#fi

dnl =======================================================
dnl FILE: ./smoke/qt/configure.in.in
dnl =======================================================


#AC_HAVE_GL
#KDE_HAVE_GL=yes;
#if test "X$GLLIB" = "X"; then
#    KDE_HAVE_GL=no
#fi

#AC_SUBST(KDE_HAVE_GL)   

AC_ARG_WITH(
   threshold,
   [  --with-threshold@<:@=0..15@:>@  Smoke: Qt tests threshold Default:10 Lower=more tests],
   [ qt_test_threshold="$withval" ],
   [ qt_test_threshold=10 ]
)
AC_SUBST(qt_test_threshold)

if test "X$kde_build_libsmoke" = "Xqt" -o "X$kde_build_libsmoke" = "Xqt kde"; then

    AC_CONFIG_FILES([ smoke/qt/qtguess.pl ], [
        cd smoke/qt
        perl qtguess.pl
        cd ../..
    ])
    AC_CONFIG_FILES([ smoke/qt/generate.pl ], [
        cd smoke/qt
        perl generate.pl
        cd ../..
    ])
fi

AC_CONFIG_FILES([ smoke/Makefile ])
AC_CONFIG_FILES([ smoke/qt/Makefile ])

KDE_CREATE_SUBDIRSLIST
#AM_CONDITIONAL(smoke_SUBDIR_included, test "x$smoke_SUBDIR_included" = xyes)

PHP_ARG_WITH(php_qt, for php_qt,
[  --enable-php_qt         Enable PHP-Qt support])

if test "$PHP_PHP_QT" != "no"; then

  PHP_QT_DIR="$qt_incdir";
  smoke_libraries="$LIB_QTCORE \
		   $LIB_QTGUI \
		   $LIB_QTNETWORK \
		   $LIB_QTOPENGL \
		   $LIB_QTSQL \
		   $LIB_QTCORE \
		   $LIB_QTXML \
		   $GLLIB \
		   $LIBQSCINTILLA \
		    -lQtSvg \
		    -lQtUiTools \
		    -lsmokeqt"

  LDFLAGS="$LDFLAGS $all_libraries $USER_LDFLAGS $LIBQT $smoke_libraries"
  PHP_REQUIRE_CXX

  PHP_ADD_INCLUDE($PHP_QT_DIR/include)
  PHP_ADD_INCLUDE($PHP_QT_DIR)
  PHP_ADD_INCLUDE($PHP_QT_DIR/Qt3Support)
  PHP_ADD_INCLUDE($PHP_QT_DIR/QtAssistant)
  PHP_ADD_INCLUDE($PHP_QT_DIR/QtCore)
  PHP_ADD_INCLUDE($PHP_QT_DIR/QtDesigner)
  PHP_ADD_INCLUDE($PHP_QT_DIR/QtGui)
  PHP_ADD_INCLUDE($PHP_QT_DIR/QtNetwork)
  PHP_ADD_INCLUDE($PHP_QT_DIR/QtOpenGL)
  PHP_ADD_INCLUDE($PHP_QT_DIR/QtSql)
  PHP_ADD_INCLUDE($PHP_QT_DIR/QtSvg)
  PHP_ADD_INCLUDE($PHP_QT_DIR/QtTest)
  PHP_ADD_INCLUDE($PHP_QT_DIR/QtUiTools)
  PHP_ADD_INCLUDE($PHP_QT_DIR/QtXml)  
  PHP_ADD_INCLUDE(smoke/)

  PHP_ADD_SOURCES_X(smoke/qt, \
    x_1.cpp x_2.cpp x_3.cpp x_4.cpp x_5.cpp x_6.cpp x_7.cpp \
    x_8.cpp x_9.cpp x_10.cpp x_11.cpp x_12.cpp x_13.cpp x_14.cpp x_15.cpp \
    x_16.cpp x_17.cpp x_18.cpp x_19.cpp x_20.cpp \
    smokedata.cpp,,shared_objects_php_qt,yes)

  PHP_NEW_EXTENSION(php_qt, qt/smokephp.cpp qt/php_qt.cpp qt/functions.cpp,$ext_shared,cli)
  PHP_ADD_BUILD_DIR($ext_builddir/qt)

fi
