lib_LTLIBRARIES = libsmokekde.la

# set the include path for X, qt and KDE
INCLUDES         = -I$(srcdir)/.. $(all_includes)

EXTRA_DIST=generate.pl.in qtguess.pl.in qt_smoke.h Makefile.am

# the library search path. 
libsmokekde_la_LDFLAGS = -version-info 3:3:2 -no-undefined $(all_libraries) $(GLINC) $(KDE_RPATH)

# the libraries to link against.
libsmokekde_la_LIBADD   = $(LIB_KHTML) -lkjs -lfontconfig $(LIB_KMDI) $(LIB_KNS) $(LIB_KSPELL) $(LIB_KUTILS) $(LIB_KDEPRINT) $(GLLIB)

x_sources =  x_1.cpp x_2.cpp x_3.cpp x_4.cpp x_5.cpp x_6.cpp x_7.cpp \
   x_8.cpp x_9.cpp x_10.cpp x_11.cpp x_12.cpp x_13.cpp x_14.cpp x_15.cpp \
   x_16.cpp x_17.cpp x_18.cpp x_19.cpp x_20.cpp

# which sources should be compiled for perlqtkde
libsmokekde_la_SOURCES = smokedata.cpp $(x_sources)

$(x_sources): smokedata.cpp

smokedata.cpp:
	perl generate.pl
