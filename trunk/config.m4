
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

#AC_ARG_WITH(
#   smoke,
#   [  --with-smoke@<:@=qt|kde@:>@   Smoke: build Smoke for qt+kde or qt only @<:@default:qt@:>@],
#   [ kde_build_libsmoke="$withval" ],
#   [ kde_build_libsmoke="qt" ]
#)
#AC_SUBST(kde_build_libsmoke)

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

#AC_ARG_WITH(
#   threshold,
#   [  --with-threshold@<:@=0..15@:>@  Smoke: Qt tests threshold Default:10 Lower=more tests],
#   [ qt_test_threshold="$withval" ],
#   [ qt_test_threshold=10 ]
#)
#AC_SUBST(qt_test_threshold)
#
#if test "X$kde_build_libsmoke" = "Xqt" -o "X$kde_build_libsmoke" = "Xqt kde"; then
#
#    AC_CONFIG_FILES([ smoke/qt/qtguess.pl ], [
#        cd smoke/qt
#        perl qtguess.pl
#        cd ../..
#    ])
#    AC_CONFIG_FILES([ smoke/qt/generate.pl ], [
#        cd smoke/qt
#        perl generate.pl
#        cd ../..
#    ])
#fi


KDE_CREATE_SUBDIRSLIST
#AM_CONDITIONAL(smoke_SUBDIR_included, test "x$smoke_SUBDIR_included" = xyes)

AC_OUTPUT

PHP_ARG_WITH(php_qt, for php_qt,
[  --enable-php_qt         Enable PHP-Qt support])

if test "$PHP_PHP_QT" != "no"; then

  PHP_QT_DIR="$qt_incdir";
  LDFLAGS="$LDFLAGS $all_libraries $USER_LDFLAGS $LIBQT"
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
#  PHP_ADD_INCLUDE(smoke/)

  PHP_NEW_EXTENSION(php_qt, \
  qt/object_model/qobject.cpp \
  qt/text_related/qstring.cpp \
  qt/event/qevent.cpp \
	qt/classes/qapplication.cpp \
	qt/classes/qcoreapplication.cpp \
	qt/classes/qwidget.cpp \
	qt/classes/qabstractslider.cpp \
	qt/classes/qframe.cpp \
	qt/classes/qlineedit.cpp \
	qt/classes/qslider.cpp \
	qt/classes/qlayoutitem.cpp \
	qt/classes/qlayout.cpp \
	qt/classes/qboxlayout.cpp \
	qt/classes/qhboxlayout.cpp \
	qt/classes/qvboxlayout.cpp \
	qt/classes/qlatin1string.cpp \
	qt/classes/qchar.cpp \
	qt/classes/qactionevent.cpp \
	qt/classes/qabstractbutton.cpp \
	qt/classes/qcharref.cpp \
	qt/classes/qchildevent.cpp \
	qt/classes/qclipboardevent.cpp \
	qt/classes/qcloseevent.cpp \
	qt/classes/qcontextmenuevent.cpp \
	qt/classes/qdate.cpp \
	qt/classes/qdatetime.cpp \
	qt/classes/qdialog.cpp \
	qt/classes/qdragenterevent.cpp \
	qt/classes/qdragleaveevent.cpp \
	qt/classes/qdragmoveevent.cpp \
	qt/classes/qdragresponseevent.cpp \
	qt/classes/qdropevent.cpp \
	qt/classes/qfileopenevent.cpp \
	qt/classes/qfocusevent.cpp \
	qt/classes/qfont.cpp \
	qt/classes/qgridlayout.cpp \
	qt/classes/qhelpevent.cpp \
	qt/classes/qhideevent.cpp \
	qt/classes/qhoverevent.cpp \
	qt/classes/qicondragevent.cpp \
	qt/classes/qinputevent.cpp \
	qt/classes/qinputmethodevent.cpp \
	qt/classes/qkeyevent.cpp \
	qt/classes/qlabel.cpp \
	qt/classes/qlatin1char.cpp \
	qt/classes/qlcdnumber.cpp \
	qt/classes/qmouseevent.cpp \
	qt/classes/qmoveevent.cpp \
	qt/classes/qobjectdata.cpp \
	qt/classes/qobjectuserdata.cpp \
	qt/classes/qpaintdevice.cpp \
	qt/classes/qpaintevent.cpp \
	qt/classes/qpainter.cpp \
	qt/classes/qpushbutton.cpp \
	qt/classes/qresizeevent.cpp \
	qt/classes/qshortcutevent.cpp \
	qt/classes/qshowevent.cpp \
	qt/classes/qspaceritem.cpp \
	qt/classes/qstatustipevent.cpp \
	qt/classes/qtabletevent.cpp \
	qt/classes/qtime.cpp \
	qt/classes/qtimer.cpp \
	qt/classes/qtimerevent.cpp \
	qt/classes/qtoolbarchangeevent.cpp \
	qt/classes/qtoolbutton.cpp \
	qt/classes/qwhatsthisclickedevent.cpp \
	qt/classes/qwheelevent.cpp \
	qt/classes/qwidgetdata.cpp \
	qt/classes/qwidgetitem.cpp \
	qt/classes/qwindowstatechangeevent.cpp \
  qt/php_qt.cpp \
  qt/inheritance.cpp \
  ,$ext_shared,cli)
  PHP_ADD_BUILD_DIR($ext_builddir/qt)

#  PHP_ADD_SOURCES_X(smoke/qt, \
#    x_1.cpp x_2.cpp x_3.cpp x_4.cpp x_5.cpp x_6.cpp x_7.cpp \
#    x_8.cpp x_9.cpp x_10.cpp x_11.cpp x_12.cpp x_13.cpp x_14.cpp x_15.cpp \
#    x_16.cpp x_17.cpp x_18.cpp x_19.cpp x_20.cpp \
#    smokedata.cpp,,shared_objects_php_qt,yes)
#  PHP_ADD_BUILD_DIR($ext_builddir/smoke)


fi
