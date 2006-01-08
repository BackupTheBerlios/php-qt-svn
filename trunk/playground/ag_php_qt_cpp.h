static zend_function_entry QAbstractButton_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QAbstractButton(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QAbstractButton",QAbstractButton_methods);
    QAbstractButton_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QWidget_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QAbstractSlider_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QAbstractSlider(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QAbstractSlider",QAbstractSlider_methods);
    QAbstractSlider_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QWidget_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QActionEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QActionEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QActionEvent",QActionEvent_methods);
    QActionEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QApplication_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QApplication(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QApplication",QApplication_methods);
    QApplication_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QCoreApplication_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QBoxLayout_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QBoxLayout(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QBoxLayout",QBoxLayout_methods);
    QBoxLayout_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QLayout_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QChar_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QChar(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QChar",QChar_methods);
    QChar_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QCharRef_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QCharRef(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QCharRef",QCharRef_methods);
    QCharRef_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QClipboardEvent_methods[] = {

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

    {NULL,NULL,NULL}
};

void _register_QContextMenuEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QContextMenuEvent",QContextMenuEvent_methods);
    QContextMenuEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QInputEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QCoreApplication_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QCoreApplication(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QCoreApplication",QCoreApplication_methods);
    QCoreApplication_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QObject_ce_ptr,NULL TSRMLS_CC);


}
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

    {NULL,NULL,NULL}
};

void _register_QDragMoveEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QDragMoveEvent",QDragMoveEvent_methods);
    QDragMoveEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QDropEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QDragResponseEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QDragResponseEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QDragResponseEvent",QDragResponseEvent_methods);
    QDragResponseEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QDropEvent_methods[] = {

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

    {NULL,NULL,NULL}
};

void _register_QFileOpenEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QFileOpenEvent",QFileOpenEvent_methods);
    QFileOpenEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QFocusEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QFocusEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QFocusEvent",QFocusEvent_methods);
    QFocusEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QFont_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QFont(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QFont",QFont_methods);
    QFont_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QFrame_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QFrame(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QFrame",QFrame_methods);
    QFrame_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QWidget_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QGridLayout_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QGridLayout(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QGridLayout",QGridLayout_methods);
    QGridLayout_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QLayout_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QHBoxLayout_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QHBoxLayout(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QHBoxLayout",QHBoxLayout_methods);
    QHBoxLayout_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QBoxLayout_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QHelpEvent_methods[] = {

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

    {NULL,NULL,NULL}
};

void _register_QInputEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QInputEvent",QInputEvent_methods);
    QInputEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QInputMethodEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QInputMethodEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QInputMethodEvent",QInputMethodEvent_methods);
    QInputMethodEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry Attribute_methods[] = {

    {NULL,NULL,NULL}
};

void _register_Attribute(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"Attribute",Attribute_methods);
    Attribute_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QKeyEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QKeyEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QKeyEvent",QKeyEvent_methods);
    QKeyEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QInputEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QLCDNumber_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QLCDNumber(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLCDNumber",QLCDNumber_methods);
    QLCDNumber_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QFrame_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QLabel_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QLabel(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLabel",QLabel_methods);
    QLabel_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QFrame_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QLatin1Char_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QLatin1Char(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLatin1Char",QLatin1Char_methods);
    QLatin1Char_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QLatin1String_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QLatin1String(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLatin1String",QLatin1String_methods);
    QLatin1String_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QLayout_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QLayout(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLayout",QLayout_methods);
    QLayout_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QLayoutItem_ce_ptr,NULL TSRMLS_CC);
	zend_do_inheritance(QLayout_ce_ptr, QObject_ce_ptr TSRMLS_CC);


}
static zend_function_entry QLayoutItem_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QLayoutItem(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLayoutItem",QLayoutItem_methods);
    QLayoutItem_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QLineEdit_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QLineEdit(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLineEdit",QLineEdit_methods);
    QLineEdit_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QWidget_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QMouseEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QMouseEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QMouseEvent",QMouseEvent_methods);
    QMouseEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QInputEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QMoveEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QMoveEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QMoveEvent",QMoveEvent_methods);
    QMoveEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QObject_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QObject(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QObject",QObject_methods);
    QObject_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

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

    {NULL,NULL,NULL}
};

void _register_QPaintEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QPaintEvent",QPaintEvent_methods);
    QPaintEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QPainter_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QPainter(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QPainter",QPainter_methods);
    QPainter_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QPushButton_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QPushButton(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QPushButton",QPushButton_methods);
    QPushButton_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QAbstractButton_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QResizeEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QResizeEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QResizeEvent",QResizeEvent_methods);
    QResizeEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QShortcutEvent_methods[] = {

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
static zend_function_entry QSlider_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QSlider(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QSlider",QSlider_methods);
    QSlider_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QAbstractSlider_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QSpacerItem_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QSpacerItem(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QSpacerItem",QSpacerItem_methods);
    QSpacerItem_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QLayoutItem_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QStatusTipEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QStatusTipEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QStatusTipEvent",QStatusTipEvent_methods);
    QStatusTipEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QString_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QString(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QString",QString_methods);
    QString_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QTabletEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QTabletEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QTabletEvent",QTabletEvent_methods);
    QTabletEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QInputEvent_ce_ptr,NULL TSRMLS_CC);


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
static zend_function_entry QTimer_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QTimer(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QTimer",QTimer_methods);
    QTimer_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QObject_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QToolBarChangeEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QToolBarChangeEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QToolBarChangeEvent",QToolBarChangeEvent_methods);
    QToolBarChangeEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QVBoxLayout_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QVBoxLayout(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QVBoxLayout",QVBoxLayout_methods);
    QVBoxLayout_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QBoxLayout_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QWhatsThisClickedEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QWhatsThisClickedEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QWhatsThisClickedEvent",QWhatsThisClickedEvent_methods);
    QWhatsThisClickedEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QWheelEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QWheelEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QWheelEvent",QWheelEvent_methods);
    QWheelEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QInputEvent_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QWidget_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QWidget(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QWidget",QWidget_methods);
    QWidget_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QObject_ce_ptr,NULL TSRMLS_CC);
	zend_do_inheritance(QWidget_ce_ptr, QPaintDevice_ce_ptr TSRMLS_CC);


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

    {NULL,NULL,NULL}
};

void _register_QWidgetItem(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QWidgetItem",QWidgetItem_methods);
    QWidgetItem_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QLayoutItem_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QWindowStateChangeEvent_methods[] = {

    {NULL,NULL,NULL}
};

void _register_QWindowStateChangeEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QWindowStateChangeEvent",QWindowStateChangeEvent_methods);
    QWindowStateChangeEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


}
