static zend_function_entry QDate_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QDate(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QDate",QDate_methods);
    QDate_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QDateTime_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QDateTime(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QDateTime",QDateTime_methods);
    QDateTime_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QTime_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QTime(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QTime",QTime_methods);
    QTime_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
