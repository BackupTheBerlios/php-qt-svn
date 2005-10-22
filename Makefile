# php-qt
# handmade makefile



DEFINES       = -DQT_NO_DEBUG -DQT_CORE_LIB -DQT_GUI_LIB -DQT_SHARED
CFLAGS_EXT        = -pipe  -W -D_REENTRANT $(DEFINES)
# -Wall
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/usr/include/qt4 -I. -I. -I.

#LIBS          = $(SUBLIBS) -L/usr/lib -L/tmp/buildd/qt4-x11-4.0.1/lib -lQtGui -L/usr/X11R6/lib -laudio -lXt -lpng -lSM -lICE -lXi -lXrender -lXrandr -lXcursor -lXinerama -lfreetype -lXext -lX11 -lm -lQtCore -lfontconfig -lz -ldl -lpthread
LIBS          = $(SUBLIBS) -L/usr/lib/qt4 -L/usr/lib -L/tmp/buildd/qt4-x11-4.0.1/lib -lQtGui -L/usr/X11R6/lib -laudio -lXt -lpng -lSM -lICE -lXi -lXrender -lXrandr -lXcursor -lXinerama -lfreetype -lXext -lX11 -lm -lQtCore -lfontconfig -lz -ldl -lpthread

# -L/usr/lib/ -L/usr/X11R6/lib/ -lqt -lXext -lX11 -lm 

srcdir = /home/moni/software/php-5.1.0RC1/ext/php_qt
builddir = /home/moni/software/php-5.1.0RC1/ext/php_qt
top_srcdir = /home/moni/software/php-5.1.0RC1/ext/php_qt
top_builddir = /home/moni/software/php-5.1.0RC1/ext/php_qt
SHLIB_SUFFIX_NAME = so
shared_objects_php_qt = php_qt.lo object_model.lo text_related.lo main_window.lo abstract_widgets.lo basic_widgets.lo 
# object_model.lo text_related.lo main_window.lo abstract_widgets.lo basic_widgets.lo 
PHP_MODULES = $(phplibdir)/php_qt.la
all_targets = $(PHP_MODULES)
install_targets = install-modules
prefix = /usr/local/lib/php5.1
exec_prefix = $(prefix)
libdir = ${exec_prefix}/lib
prefix = /usr/local/lib/php5.1
phplibdir = /home/moni/software/php-5.1.0RC1/ext/php_qt/modules
PHP_COMPILE =
CC = g++
CFLAGS = -g -O2 $(CFLAGS_EXT)
CFLAGS_CLEAN = $(CFLAGS)
CPP = gcc -E
CPPFLAGS = -DHAVE_CONFIG_H
CXX = g++
DEFS =
EXTENSION_DIR = /usr/local/lib/php5.1/lib/php/extensions/debug-non-zts-20050617
EXTRA_LDFLAGS =
EXTRA_LIBS = 
INCLUDES = -I/usr/local/lib/php5.1/include/php -I/usr/local/lib/php5.1/include/php/main -I/usr/local/lib/php5.1/include/php/Zend -I/usr/local/lib/php5.1/include/php/TSRM $(INCPATH)
LEX =
LEX_OUTPUT_ROOT =
LFLAGS =
LDFLAGS =
SHARED_LIBTOOL =
LIBTOOL = $(SHELL) $(top_builddir)/libtool
SHELL = /bin/sh
AWK = gawk
RE2C = exit 0;
mkinstalldirs = $(top_srcdir)/build/shtool mkdir -p
INSTALL = $(top_srcdir)/build/shtool install -c
INSTALL_DATA = $(INSTALL) -m 644

DEFS = -DPHP_ATOM_INC -I$(top_builddir)/include -I$(top_builddir)/main -I$(top_srcdir)
COMMON_FLAGS = $(DEFS) $(INCLUDES) $(EXTRA_INCLUDES) $(CPPFLAGS) $(PHP_FRAMEWORKPATH)


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

install-tester:
	@echo "Installing regression tester:     $(INSTALL_ROOT)$(PEAR_INSTALLDIR)/"
	@$(mkinstalldirs) $(INSTALL_ROOT)$(PEAR_INSTALLDIR)
	@$(INSTALL) -m 755 $(top_srcdir)/run-tests.php $(INSTALL_ROOT)$(PEAR_INSTALLDIR)

install-su: install-pear install-tester

test: 
	-@if test -x $(SAPI_CLI_PATH) && test ! -z $(SAPI_CLI_PATH); then \
		TEST_PHP_EXECUTABLE=$(top_builddir)/$(SAPI_CLI_PATH) \
		TEST_PHP_SRCDIR=$(top_srcdir) \
		CC="$(CC)" \
			$(top_builddir)/$(SAPI_CLI_PATH) -d 'open_basedir=' -d 'safe_mode=0' -d 'output_buffering=0' $(top_srcdir)/run-tests.php $(TESTS); \
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
	egrep define'.*include/php' configure|sed 's/.*>//'|xargs rm -f
	find . -name Makefile | xargs rm -f

.PHONY: all clean install distclean test
.NOEXPORT:

main_window.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/main_window.cpp
	$(LIBTOOL) --mode=compile $(CC)  -g -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -prefer-pic -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/main_window.cpp -o main_window.lo 

abstract_widgets.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/abstract_widgets.cpp
	$(LIBTOOL) --mode=compile $(CC)  -g -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -prefer-pic -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/abstract_widgets.cpp -o abstract_widgets.lo 

object_model.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/object_model.cpp
	$(LIBTOOL) --mode=compile $(CC)  -g -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -prefer-pic -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/object_model.cpp -o object_model.lo 

text_related.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/text_related.cpp
	$(LIBTOOL) --mode=compile $(CC)  -g -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -prefer-pic -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/text_related.cpp -o text_related.lo 

basic_widgets.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/basic_widgets.cpp
	$(LIBTOOL) --mode=compile $(CC)  -g -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -prefer-pic -c /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/basic_widgets.cpp -o basic_widgets.lo 

php_qt.lo: /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/php_qt.cpp
	$(LIBTOOL) --mode=compile $(CC)  -g -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -prefer-pic -c  /home/moni/software/php-5.1.0RC1/ext/php_qt/qt/php_qt.cpp  -o php_qt.lo 
#/home/moni/software/php-5.1.0RC1/ext/php_qt/qt/*.cpp
#	$(LIBTOOL) --mode=compile $(CC)  -g -I. -I/home/moni/software/php-5.1.0RC1/ext/php_qt $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -prefer-pic -c /home/moni/software/php-5.1.0RC1/ext/php_qt/php_qt.cpp  -o php_qt.lo 
$(phplibdir)/php_qt.la: ./php_qt.la
	$(LIBTOOL) --mode=install cp ./php_qt.la $(phplibdir)

./php_qt.la: $(shared_objects_php_qt) $(PHP_QT_SHARED_DEPENDENCIES)
	$(LIBTOOL) --mode=link $(CC) $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) -o $@ -export-dynamic -avoid-version -prefer-pic -module -rpath $(phplibdir) $(LIBS) $(EXTRA_LDFLAGS) $(shared_objects_php_qt) $(PHP_QT_SHARED_LIBADD)

