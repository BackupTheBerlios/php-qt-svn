
PROJECT(PHP-Qt)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(kdebindings_SOURCE_DIR ${PHP-Qt_SOURCE_DIR})



find_package(Perl REQUIRED)	# for kalyptus
find_package(Qt4 REQUIRED)	# for kalyptus

include(FindPHP5)

IF(NOT PHP5_FOUND)
    MESSAGE(FATAL_ERROR "PHP5 could not be found!")
ENDIF(NOT PHP5_FOUND)

add_subdirectory(smoke)
add_subdirectory(php_qt)



