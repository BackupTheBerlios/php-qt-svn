static zend_function_entry QDate_methods[] = {
	ZEND_ME(QDate,longDayName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,isValid,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,setYMD,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,shortMonthName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,toString,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,toString,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,isLeapYear,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,fromJulianDay,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,addDays,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,gregorianToJulian,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,longMonthName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,julianToGregorian,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,shortDayName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,fromString,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,fromString,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDate,weekNumber,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,addMonths,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,addYears,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDate,daysTo,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QDate(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QDate",QDate_methods);
    QDate_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QDateTime_methods[] = {
	ZEND_ME(QDateTime,toString,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,toString,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,setTime_t,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,addDays,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,secsTo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,toTimeSpec,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,fromString,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDateTime,fromString,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QDateTime,setTime,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,addMonths,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,addSecs,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,setDate,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,daysTo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,addYears,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QDateTime,setTimeSpec,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QDateTime(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QDateTime",QDateTime_methods);
    QDateTime_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QTime_methods[] = {
	ZEND_ME(QTime,isValid,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QTime,toString,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,toString,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,secsTo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,fromString,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QTime,fromString,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QTime,addSecs,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,addMSecs,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,setHMS,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTime,msecsTo,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QTime(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QTime",QTime_methods);
    QTime_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
