srcdir = /home/moni/software/php-5.1.0RC1/ext/php_qt
builddir = /home/moni/software/php-5.1.0RC1/ext/php_qt
top_srcdir = /home/moni/software/php-5.1.0RC1/ext/php_qt
top_builddir = /home/moni/software/php-5.1.0RC1/ext/php_qt
EGREP = grep -E
SED = /bin/sed
CONFIGURE_COMMAND = './configure' '--enable-php_qt' '--with-prefix=/usr/local/lib/php5.1'
SHLIB_SUFFIX_NAME = so
RE2C = exit 0;
AWK = gawk
shared_objects_php_qt = qt/main_window/qapplication.lo qt/main_window/qcoreapplication.lo qt/abstract_widgets/qabstractbutton.lo qt/abstract_widgets/qwidget.lo qt/basic_widgets/qpushbutton.lo qt/layout_management/qlayoutitem.lo qt/object_model/qobject.lo qt/text_related/qstring.lo qt/text_related/qlatin1string.lo qt/text_related/qchar.lo qt/event/qevent.lo qt/php_qt.lo
PHP_MODULES = $(phplibdir)/php_qt.la
all_targets = $(PHP_MODULES)
install_targets = install-modules
prefix = /usr/local/lib/php5.1
exec_prefix = $(prefix)
libdir = ${exec_prefix}/lib
prefix = /usr/local/lib/php5.1
phplibdir = /home/moni/software/php-5.1.0RC1/ext/php_qt/modules
CC = gcc
CFLAGS = -g -O2
CFLAGS_CLEAN = $(CFLAGS)
CPP = gcc -E
CPPFLAGS = -DHAVE_CONFIG_H
CXX = g++
CXXFLAGS = -g -O2
EXTENSION_DIR = /usr/local/lib/php5.1/lib/php/extensions/debug-non-zts-20050617
PHP_EXECUTABLE = /usr/local/lib/php5.1/bin/php
EXTRA_LDFLAGS =
EXTRA_LIBS =
INCLUDES = -I/usr/local/lib/php5.1/include/php -I/usr/local/lib/php5.1/include/php/main -I/usr/local/lib/php5.1/include/php/TSRM -I/usr/local/lib/php5.1/include/php/Zend -I/usr/share/qt4/mkspecs/linux-g++ -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/usr/include/qt4
LFLAGS =
LDFLAGS =
SHARED_LIBTOOL =
LIBTOOL = $(SHELL) $(top_builddir)/libtool
SHELL = /bin/sh
mkinstalldirs = $(top_srcdir)/build/shtool mkdir -p
INSTALL = $(top_srcdir)/build/shtool install -c
INSTALL_DATA = $(INSTALL) -m 644

DEFS = -DPHP_ATOM_INC -I$(top_builddir)/include -I$(top_builddir)/main -I$(top_srcdir)
COMMON_FLAGS = $(DEFS) $(INCLUDES) $(EXTRA_INCLUDES) $(CPPFLAGS) $(PHP_FRAMEWORKPATH)

CORE_HEADERS = Zend/ TSRM/ include/ main/ main/streams/ regex/ ext/standard/
INSTALL_HEADERS = $(CORE_HEADERS) $(INSTALL_EXT_HEADERS)

all: $(all_targets) 
	@echo
	@echo "Build complete."
	@echo "(It is safe to ignore warnings about tempnam and tmpnam)."
	@echo
	
build-modules: $(PHP_MODULES)

libphp5.la: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) $(EXTRA_CFLAGS) -rpath $(phptempdir) $(EXTRA_LDFLAGS) $(LDFLAGS) $(PHP_RPATHS) $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@
	-@$(LIBTOOL) --silent --mode=install cp libphp5.la $(phptempdir)/libphp5.la >/dev/null 2>&1

libs/libphp5.bundle: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(CC) $(MH_BUNDLE_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) $(EXTRA_LDFLAGS) $(PHP_GLOBAL_OBJS:.lo=.o) $(PHP_SAPI_OBJS:.lo=.o) $(PHP_FRAMEWORKS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@ && cp $@ libs/libphp5.so

install: $(all_targets) $(install_targets)

install-sapi: $(OVERALL_TARGET)
	@echo "Installing PHP SAPI module:       $(PHP_SAPI)"
	-@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
	-@if test ! -r $(phptempdir)/libphp5.$(SHLIB_SUFFIX_NAME); then \
		for i in 0.0.0 0.0 0; do \
			if test -r $(phptempdir)/libphp5.$(SHLIB_SUFFIX_NAME).$$i; then \
				$(LN_S) $(phptempdir)/libphp5.$(SHLIB_SUFFIX_NAME).$$i $(phptempdir)/libphp5.$(SHLIB_SUFFIX_NAME); \
				break; \
			fi; \
		done; \
	fi
	@$(INSTALL_IT)

install-modules: build-modules
	@test -d modules && \
	$(mkinstalldirs) $(INSTALL_ROOT)$(EXTENSION_DIR)
	@echo "Installing shared extensions:     $(INSTALL_ROOT)$(EXTENSION_DIR)/"
	@rm -f modules/*.la >/dev/null 2>&1
	@$(INSTALL) modules/* $(INSTALL_ROOT)$(EXTENSION_DIR)

install-su: install-pear

test: all 
	-@if test ! -z $(PHP_EXECUTABLE) && test -x $(PHP_EXECUTABLE); then \
		TEST_PHP_EXECUTABLE=$(PHP_EXECUTABLE) \
		TEST_PHP_SRCDIR=$(top_srcdir) \
		CC="$(CC)" \
			$(PHP_EXECUTABLE) -d 'open_basedir=' -d 'safe_mode=0' -d 'output_buffering=0' -d 'memory_limit=-1' $(top_srcdir)/run-tests.php -d 'extension_dir=modules/' -d `( . $(PHP_MODULES) ; echo extension=$$dlname)` tests/; \
	elif test ! -z $(SAPI_CLI_PATH) && test -x $(SAPI_CLI_PATH); then \
		TEST_PHP_EXECUTABLE=$(top_builddir)/$(SAPI_CLI_PATH) \
		TEST_PHP_SRCDIR=$(top_srcdir) \
		CC="$(CC)" \
			$(top_builddir)/$(SAPI_CLI_PATH) -d 'open_basedir=' -d 'safe_mode=0' -d 'output_buffering=0' -d 'memory_limit=-1' $(top_srcdir)/run-tests.php $(TESTS); \
	else \
		echo "ERROR: Cannot run tests without CLI sapi."; \
	fi

clean:
	find . -name \*.lo -o -name \*.o | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f 
	find . -name \*.so | xargs rm -f
	find . -name .libs -a -type d|xargs rm -rf
	rm -f libphp5.la $(SAPI_CLI_PATH) $(OVERALL_TARGET) modules/* libs/*

distclean: clean
	rm -f config.cache config.log config.status Makefile.objects Makefile.fragments libtool main/php_config.h stamp-h php5.spec sapi/apache/libphp5.module buildmk.stamp
	$(EGREP) define'.*include/php' $(top_srcdir)/configure | $(SED) 's/.*>//'|xargs rm -f
	find . -name Makefile | xargs rm -f

.PHONY: all clean install distclean test
.NOEXPORT:
LDFLAGS          = $(SUBLIBS) -L/usr/lib/qt4 -L/usr/lib -L/tmp/buildd/qt4-x11-4.0.1/lib -lQtGui -L/usr/X11R6/lib -laudio -lXt -lpng -lSM -lICE -lXi -lXrender -lXrandr -lXcursor -lXinerama -lfreetype -lXext -lX11 -lm -lQtCore -lfontconfig -lz -ldl -lpthread

qt/main_window/qapplication.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/main_window/qapplication.cpp
	$(LIBTOOL) --mode=compile $(CXX)  -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CXXFLAGS_CLEAN) $(EXTRA_CXXFLAGS)  -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/main_window/qapplication.cpp -o qt/main_window/qapplication.lo 
qt/main_window/qcoreapplication.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/main_window/qcoreapplication.cpp
	$(LIBTOOL) --mode=compile $(CXX)  -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CXXFLAGS_CLEAN) $(EXTRA_CXXFLAGS)  -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/main_window/qcoreapplication.cpp -o qt/main_window/qcoreapplication.lo 
qt/abstract_widgets/qabstractbutton.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/abstract_widgets/qabstractbutton.cpp
	$(LIBTOOL) --mode=compile $(CXX)  -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CXXFLAGS_CLEAN) $(EXTRA_CXXFLAGS)  -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/abstract_widgets/qabstractbutton.cpp -o qt/abstract_widgets/qabstractbutton.lo 
qt/abstract_widgets/qwidget.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/abstract_widgets/qwidget.cpp
	$(LIBTOOL) --mode=compile $(CXX)  -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CXXFLAGS_CLEAN) $(EXTRA_CXXFLAGS)  -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/abstract_widgets/qwidget.cpp -o qt/abstract_widgets/qwidget.lo 
qt/basic_widgets/qpushbutton.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/basic_widgets/qpushbutton.cpp
	$(LIBTOOL) --mode=compile $(CXX)  -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CXXFLAGS_CLEAN) $(EXTRA_CXXFLAGS)  -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/basic_widgets/qpushbutton.cpp -o qt/basic_widgets/qpushbutton.lo 
qt/layout_management/qlayoutitem.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/layout_management/qlayoutitem.cpp
	$(LIBTOOL) --mode=compile $(CXX)  -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CXXFLAGS_CLEAN) $(EXTRA_CXXFLAGS)  -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/layout_management/qlayoutitem.cpp -o qt/layout_management/qlayoutitem.lo 
qt/object_model/qobject.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/object_model/qobject.cpp
	$(LIBTOOL) --mode=compile $(CXX)  -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CXXFLAGS_CLEAN) $(EXTRA_CXXFLAGS)  -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/object_model/qobject.cpp -o qt/object_model/qobject.lo 
qt/text_related/qstring.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/text_related/qstring.cpp
	$(LIBTOOL) --mode=compile $(CXX)  -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CXXFLAGS_CLEAN) $(EXTRA_CXXFLAGS)  -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/text_related/qstring.cpp -o qt/text_related/qstring.lo 
qt/text_related/qlatin1string.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/text_related/qlatin1string.cpp
	$(LIBTOOL) --mode=compile $(CXX)  -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CXXFLAGS_CLEAN) $(EXTRA_CXXFLAGS)  -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/text_related/qlatin1string.cpp -o qt/text_related/qlatin1string.lo 
qt/text_related/qchar.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/text_related/qchar.cpp
	$(LIBTOOL) --mode=compile $(CXX)  -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CXXFLAGS_CLEAN) $(EXTRA_CXXFLAGS)  -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/text_related/qchar.cpp -o qt/text_related/qchar.lo 
qt/event/qevent.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/event/qevent.cpp
	$(LIBTOOL) --mode=compile $(CXX)  -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CXXFLAGS_CLEAN) $(EXTRA_CXXFLAGS)  -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/event/qevent.cpp -o qt/event/qevent.lo 
qt/php_qt.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/php_qt.cpp
	$(LIBTOOL) --mode=compile $(CXX)  -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CXXFLAGS_CLEAN) $(EXTRA_CXXFLAGS)  -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/php_qt.cpp -o qt/php_qt.lo 
$(phplibdir)/php_qt.la: ./php_qt.la
	$(LIBTOOL) --mode=install cp ./php_qt.la $(phplibdir)

./php_qt.la: $(shared_objects_php_qt) $(PHP_QT_SHARED_DEPENDENCIES)
	$(LIBTOOL) --mode=link $(CC) $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) -o $@ -export-dynamic -avoid-version -prefer-pic -module -rpath $(phplibdir) $(EXTRA_LDFLAGS) $(shared_objects_php_qt) $(PHP_QT_SHARED_LIBADD)

