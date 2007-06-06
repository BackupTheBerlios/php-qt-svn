
include_directories( 
    ${QT_INCLUDE_DIR} 
    ${CMAKE_SOURCE_DIR}/smoke
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PHP5_INCLUDE_DIR}
    ${PHP5_MAIN_INCLUDE_DIR}
    ${PHP5_TSRM_INCLUDE_DIR}
    ${PHP5_ZEND_INCLUDE_DIR}
    ${PHP5_REGEX_INCLUDE_DIR}
    ${PHP5_EXT_INCLUDE_DIR}
    ${PHP5_DATE_INCLUDE_DIR}
    ${PHP5_STANDARD_INCLUDE_DIR}
    )

set(phpqt_LIB_SRCS
    functions.cpp
    php_qt.cpp
    zend_handlers.cpp
    phpqt_internals.cpp
    smokephp.cpp
    qstring.cpp
    marshall_types.cpp
    handlers.cpp
    )

add_library(php_qt SHARED ${phpqt_LIB_SRCS})

target_link_libraries(php_qt ${QT_QTCORE_LIBRARY} QtSvg QtGui QtNetwork QtSql QtOpenGL QtXml QtUiTools ${QTDBUS_LIBRARY} ${QSCINTILLA_LIBRARIES} ${QWT_LIBRARIES} smokeqt)
set_target_properties(php_qt PROPERTIES PREFIX "")

install(TARGETS php_qt DESTINATION ${PHP5_EXTENSION_DIR}/ )
