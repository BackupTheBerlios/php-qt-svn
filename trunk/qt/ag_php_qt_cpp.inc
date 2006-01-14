static zend_function_entry QActionEvent_methods[] = {
	ZEND_ME(QActionEvent,action,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QActionEvent,before,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QActionEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QActionEvent",QActionEvent_methods);
    QActionEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QChar_methods[] = {
	ZEND_ME(QChar,combiningClass,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,isUpper,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,joining,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,row,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar, __construct,NULL,ZEND_ACC_PUBLIC);
	ZEND_ME(QChar,isSymbol,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,category,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,isPrint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,digitValue,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,mirroredChar,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,fromLatin1,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QChar,fromAscii,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QChar,isSpace,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,toLatin1,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,toUpper,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,decomposition,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,isPunct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,isDigit,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,decompositionTag,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,isLower,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,direction,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,hasMirrored,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,toLower,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,unicode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,isLetter,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,setRow,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,isLetterOrNumber,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,cell,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,isNumber,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,setCell,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,unicodeVersion,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,toAscii,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,isMark,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,isNull,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QChar(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QChar",QChar_methods);
    QChar_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QCharRef_methods[] = {
	ZEND_ME(QCharRef,isDigit,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,combiningClass,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,decompositionTag,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,joining,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,direction,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,hasMirrored,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,toLower,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,unicode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,row,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,setRow,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,category,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,isLetter,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,cell,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,digitValue,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,isPrint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,isLetterOrNumber,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,mirroredChar,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,setCell,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,isNumber,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,unicodeVersion,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,isSpace,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,toLatin1,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,toAscii,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,decomposition,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,toUpper,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,isMark,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,isPunct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCharRef,isNull,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QCharRef(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QCharRef",QCharRef_methods);
    QCharRef_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QClipboardEvent_methods[] = {
	ZEND_ME(QClipboardEvent,data,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QClipboardEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QClipboardEvent",QClipboardEvent_methods);
    QClipboardEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QCloseEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QCloseEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QCloseEvent",QCloseEvent_methods);
    QCloseEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QContextMenuEvent_methods[] = {
	ZEND_ME(QContextMenuEvent,y,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QContextMenuEvent,reason,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QContextMenuEvent,globalY,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QContextMenuEvent,pos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QContextMenuEvent,x,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QContextMenuEvent,globalPos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QContextMenuEvent,globalX,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QContextMenuEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QContextMenuEvent",QContextMenuEvent_methods);
    QContextMenuEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QInputEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QDate_methods[] = {
	ZEND_ME(QDate,longDayName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,dayOfWeek,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,daysInMonth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,month,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,isValid,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,setYMD,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,shortMonthName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,toString,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,isLeapYear,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,fromJulianDay,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,currentDate,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,addDays,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,day,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,gregorianToJulian,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,longMonthName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,julianToGregorian,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate, __construct,NULL,ZEND_ACC_PUBLIC);
	ZEND_ME(QDate,shortDayName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,fromString,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,dayOfYear,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,weekNumber,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,addMonths,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,toJulianDay,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,addYears,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,daysTo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,isNull,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,year,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,daysInYear,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QDate(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QDate",QDate_methods);
    QDate_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QDateTime_methods[] = {
	ZEND_ME(QDateTime,time,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,date,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,isValid,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,toString,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,toTime_t,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,setTime_t,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,addDays,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,secsTo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,toTimeSpec,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,fromString,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDateTime,timeSpec,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,setTime,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,addMonths,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime, __construct,NULL,ZEND_ACC_PUBLIC);
	ZEND_ME(QDateTime,addSecs,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,setDate,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,currentDateTime,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDateTime,daysTo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,addYears,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,isNull,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,toUTC,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,toLocalTime,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,setTimeSpec,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QDateTime(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QDateTime",QDateTime_methods);
    QDateTime_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QDragEnterEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QDragEnterEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QDragEnterEvent",QDragEnterEvent_methods);
    QDragEnterEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QDragMoveEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QDragLeaveEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QDragLeaveEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QDragLeaveEvent",QDragLeaveEvent_methods);
    QDragLeaveEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QDragMoveEvent_methods[] = {
	ZEND_ME(QDragMoveEvent,accept,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDragMoveEvent,answerRect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDragMoveEvent,ignore,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QDragMoveEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QDragMoveEvent",QDragMoveEvent_methods);
    QDragMoveEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QDropEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QDragResponseEvent_methods[] = {
	ZEND_ME(QDragResponseEvent,dragAccepted,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QDragResponseEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QDragResponseEvent",QDragResponseEvent_methods);
    QDragResponseEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QDropEvent_methods[] = {
	ZEND_ME(QDropEvent,encodedData,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDropEvent,source,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDropEvent,keyboardModifiers,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDropEvent,setDropAction,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDropEvent,acceptProposedAction,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDropEvent,dropAction,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDropEvent,mimeData,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDropEvent,provides,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDropEvent,format,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDropEvent,mouseButtons,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDropEvent,proposedAction,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDropEvent,pos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDropEvent,possibleActions,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QDropEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QDropEvent",QDropEvent_methods);
    QDropEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);
	zend_do_inheritance(QDropEvent_ce_ptr, QMimeSource_ce_ptr TSRMLS_CC);


}
static zend_function_entry QFileOpenEvent_methods[] = {
	ZEND_ME(QFileOpenEvent,file,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QFileOpenEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QFileOpenEvent",QFileOpenEvent_methods);
    QFileOpenEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QFocusEvent_methods[] = {
	ZEND_ME(QFocusEvent,lostFocus,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFocusEvent,reason,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFocusEvent,gotFocus,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QFocusEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QFocusEvent",QFocusEvent_methods);
    QFocusEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QFont_methods[] = {
	ZEND_ME(QFont,setOverline,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,insertSubstitution,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QFont,stretch,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,styleStrategy,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,setKerning,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,underline,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,removeSubstitution,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QFont,substitute,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QFont,setBold,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,resolve,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,fixedPitch,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,italic,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,pixelSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,insertSubstitutions,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QFont,key,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,setStrikeOut,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,weight,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,pointSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,cleanup,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QFont,fromString,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,exactMatch,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,setWeight,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,styleHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,handle,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,setStyle,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,rawName,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,setUnderline,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,family,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,isCopyOf,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,rawMode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,substitutes,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QFont,setStretch,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,initialize,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QFont,toString,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,defaultFamily,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,setRawMode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,kerning,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,setStyleHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,substitutions,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QFont,setFamily,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont, __construct,NULL,ZEND_ACC_PUBLIC);
	ZEND_ME(QFont,bold,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,style,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,setPointSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,setRawName,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,setStyleStrategy,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,cacheStatistics,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QFont,setPixelSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,setFixedPitch,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,setItalic,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,strikeOut,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,lastResortFont,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,lastResortFamily,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,overline,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,pointSizeF,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFont,setPointSizeF,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QFont(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QFont",QFont_methods);
    QFont_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QGridLayout_methods[] = {
	ZEND_ME(QGridLayout,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QGridLayout,addLayout,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout, __construct,NULL,ZEND_ACC_PUBLIC);
	ZEND_ME(QGridLayout,qt_invoke,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,addItem,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,rowMinimumHeight,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,setOriginCorner,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,qt_cast,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,metaObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,count,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,originCorner,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,invalidate,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,setGeometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,qt_emit,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,setRowStretch,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,getItemPosition,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,setDefaultPositioning,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,className,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,columnStretch,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,addWidget,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,takeAt,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QGridLayout,itemAt,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,minimumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,sizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,setColumnMinimumWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,heightForWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,hasHeightForWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,setColumnStretch,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,rowCount,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,columnMinimumWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,cellRect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,columnCount,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,setRowMinimumHeight,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QGridLayout,maximumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,qt_property,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,minimumHeightForWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,expandingDirections,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,rowStretch,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QGridLayout(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QGridLayout",QGridLayout_methods);
    QGridLayout_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QLayout_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QHelpEvent_methods[] = {
	ZEND_ME(QHelpEvent,y,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QHelpEvent,globalY,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QHelpEvent,pos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QHelpEvent,x,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QHelpEvent,globalPos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QHelpEvent,globalX,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QHelpEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QHelpEvent",QHelpEvent_methods);
    QHelpEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QHideEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QHideEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QHideEvent",QHideEvent_methods);
    QHideEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QHoverEvent_methods[] = {
	ZEND_ME(QHoverEvent,oldPos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QHoverEvent,pos,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QHoverEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QHoverEvent",QHoverEvent_methods);
    QHoverEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QIconDragEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QIconDragEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QIconDragEvent",QIconDragEvent_methods);
    QIconDragEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QInputEvent_methods[] = {
	ZEND_ME(QInputEvent,modifiers,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QInputEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QInputEvent",QInputEvent_methods);
    QInputEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QInputMethodEvent_methods[] = {
	ZEND_ME(QInputMethodEvent,commitString,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QInputMethodEvent,replacementStart,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QInputMethodEvent,setCommitString,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QInputMethodEvent,replacementLength,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QInputMethodEvent,preeditString,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QInputMethodEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QInputMethodEvent",QInputMethodEvent_methods);
    QInputMethodEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QKeyEvent_methods[] = {
	ZEND_ME(QKeyEvent,count,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QKeyEvent,text,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QKeyEvent,isAutoRepeat,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QKeyEvent,modifiers,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QKeyEvent,key,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QKeyEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QKeyEvent",QKeyEvent_methods);
    QKeyEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QInputEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QLabel_methods[] = {
	ZEND_ME(QLabel,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QLabel,setMargin,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,clear,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,qt_invoke,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,setBuddy,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,movie,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,hasScaledContents,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,qt_cast,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,metaObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,setScaledContents,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,event,NULL,ZEND_ACC_PROTECTED)
	ZEND_ME(QLabel,indent,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,qt_emit,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,pixmap,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,setAlignment,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,className,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,buddy,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,textFormat,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,setMovie,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,setPicture,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,setNum,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,wordWrap,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QLabel,setTextFormat,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,setText,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,text,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,alignment,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,sizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,minimumSizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,heightForWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,setPixmap,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,picture,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,setWordWrap,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QLabel,qt_property,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel, __construct,NULL,ZEND_ACC_PUBLIC);
	ZEND_ME(QLabel,setIndent,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,margin,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QLabel(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLabel",QLabel_methods);
    QLabel_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QFrame_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QLatin1Char_methods[] = {
	ZEND_ME(QLatin1Char,unicode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLatin1Char, __construct,NULL,ZEND_ACC_PUBLIC);
	ZEND_ME(QLatin1Char,toLatin1,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QLatin1Char(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLatin1Char",QLatin1Char_methods);
    QLatin1Char_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QMouseEvent_methods[] = {
	ZEND_ME(QMouseEvent,x,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QMouseEvent,globalX,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QMouseEvent,globalPos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QMouseEvent,y,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QMouseEvent,globalY,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QMouseEvent,pos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QMouseEvent,button,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QMouseEvent,buttons,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QMouseEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QMouseEvent",QMouseEvent_methods);
    QMouseEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QInputEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QMoveEvent_methods[] = {
	ZEND_ME(QMoveEvent,oldPos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QMoveEvent,pos,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QMoveEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QMoveEvent",QMoveEvent_methods);
    QMoveEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QObjectData_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QObjectData(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QObjectData",QObjectData_methods);
    QObjectData_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QObjectUserData_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QObjectUserData(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QObjectUserData",QObjectUserData_methods);
    QObjectUserData_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QPaintEvent_methods[] = {
	ZEND_ME(QPaintEvent,rect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPaintEvent,region,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QPaintEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QPaintEvent",QPaintEvent_methods);
    QPaintEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QPainter_methods[] = {
	ZEND_ME(QPainter,eraseRect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setClipPath,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,matrixEnabled,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,shear,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,save,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,resetMatrix,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,initFrom,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,fontInfo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setLayoutDirection,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setBrushOrigin,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,pen,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawRects,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawPath,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,fillPath,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,rotate,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawPie,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,translate,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setCompositionMode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setWindow,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,fontMetrics,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawPixmap,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawPolyline,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,deviceMatrix,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawLine,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,fillRect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,boundingRect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setClipRect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawImage,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawTiledPixmap,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,layoutDirection,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,background,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawPolygon,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,device,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setClipRegion,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,restoreRedirected,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QPainter,setMatrixEnabled,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawPoints,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawRoundRect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawConvexPolygon,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setMatrix,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawPicture,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,restore,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,font,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,matrix,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,viewport,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,viewTransformEnabled,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawText,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawChord,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,clipRegion,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,end,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,brushOrigin,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setViewTransformEnabled,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,scale,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setPen,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setBackgroundMode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,window,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,paintEngine,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setRenderHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,brush,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,strokePath,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setBrush,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawPoint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter, __construct,NULL,ZEND_ACC_PUBLIC);
	ZEND_ME(QPainter,setRedirected,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QPainter,compositionMode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setFont,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,begin,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setViewport,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawEllipse,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawArc,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setBackground,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,isActive,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawRect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawLines,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,renderHints,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,backgroundMode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,redirected,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QPainter,hasClipping,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,drawTextItem,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,setClipping,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPainter,clipPath,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QPainter(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QPainter",QPainter_methods);
    QPainter_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QResizeEvent_methods[] = {
	ZEND_ME(QResizeEvent,oldSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QResizeEvent,size,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QResizeEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QResizeEvent",QResizeEvent_methods);
    QResizeEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QShortcutEvent_methods[] = {
	ZEND_ME(QShortcutEvent,shortcutId,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QShortcutEvent,isAmbiguous,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QShortcutEvent,key,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QShortcutEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QShortcutEvent",QShortcutEvent_methods);
    QShortcutEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QShowEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QShowEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QShowEvent",QShowEvent_methods);
    QShowEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QStatusTipEvent_methods[] = {
	ZEND_ME(QStatusTipEvent,tip,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QStatusTipEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QStatusTipEvent",QStatusTipEvent_methods);
    QStatusTipEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QTabletEvent_methods[] = {
	ZEND_ME(QTabletEvent,hiResGlobalX,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,pressure,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,hiResGlobalPos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,tangentialPressure,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,x,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,globalX,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,globalPos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,y,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,uniqueId,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,hiResGlobalY,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,pos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,xTilt,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,rotation,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,pointerType,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,yTilt,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,device,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,globalY,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTabletEvent,z,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QTabletEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QTabletEvent",QTabletEvent_methods);
    QTabletEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QInputEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QTime_methods[] = {
	ZEND_ME(QTime,hour,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,isValid,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,elapsed,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,toString,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,msec,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,secsTo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,restart,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,fromString,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QTime,second,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime, __construct,NULL,ZEND_ACC_PUBLIC);
	ZEND_ME(QTime,addSecs,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,addMSecs,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,currentTime,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QTime,minute,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,setHMS,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,isNull,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,msecsTo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,start,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QTime(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QTime",QTime_methods);
    QTime_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QTimer_methods[] = {
	ZEND_ME(QTimer,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QTimer,qt_invoke,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QTimer,setInterval,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,timerId,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,singleShot,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QTimer,qt_cast,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,metaObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,stop,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,isActive,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer, __construct,NULL,ZEND_ACC_PUBLIC);
	ZEND_ME(QTimer,qt_emit,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,interval,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,setSingleShot,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,className,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QTimer,qt_property,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,isSingleShot,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,start,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QTimer(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QTimer",QTimer_methods);
    QTimer_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QObject_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QToolBarChangeEvent_methods[] = {
	ZEND_ME(QToolBarChangeEvent,toggle,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QToolBarChangeEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QToolBarChangeEvent",QToolBarChangeEvent_methods);
    QToolBarChangeEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QWhatsThisClickedEvent_methods[] = {
	ZEND_ME(QWhatsThisClickedEvent,href,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QWhatsThisClickedEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QWhatsThisClickedEvent",QWhatsThisClickedEvent_methods);
    QWhatsThisClickedEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QWheelEvent_methods[] = {
	ZEND_ME(QWheelEvent,orientation,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWheelEvent,x,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWheelEvent,globalX,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWheelEvent,globalPos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWheelEvent,y,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWheelEvent,delta,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWheelEvent,globalY,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWheelEvent,pos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWheelEvent,buttons,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QWheelEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QWheelEvent",QWheelEvent_methods);
    QWheelEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QInputEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QWidgetData_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QWidgetData(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QWidgetData",QWidgetData_methods);
    QWidgetData_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QWidgetItem_methods[] = {
	ZEND_ME(QWidgetItem,hasHeightForWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem,isEmpty,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem,setGeometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem, __construct,NULL,ZEND_ACC_PUBLIC);
	ZEND_ME(QWidgetItem,minimumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem,sizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem,maximumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem,heightForWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem,widget,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem,expandingDirections,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem,geometry,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QWidgetItem(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QWidgetItem",QWidgetItem_methods);
    QWidgetItem_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QLayoutItem_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QWindowStateChangeEvent_methods[] = {
	ZEND_ME(QWindowStateChangeEvent,oldState,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QWindowStateChangeEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QWindowStateChangeEvent",QWindowStateChangeEvent_methods);
    QWindowStateChangeEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
