static zend_function_entry QAbstractButton_methods[] = {
	ZEND_ME(QAbstractButton,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QAbstractButton,setAutoRepeat,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,isDown,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,setAutoExclusive,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,setIconSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,setIcon,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,autoExclusive,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,toggle,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,setCheckable,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,setDown,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,shortcut,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,icon,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,setChecked,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,setShortcut,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,animateClick,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QAbstractButton,autoRepeat,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,group,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,setText,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,text,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,isChecked,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,iconSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,isCheckable,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,click,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractButton,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)

    {NULL,NULL,NULL}
};

void _register_QAbstractButton(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QAbstractButton",QAbstractButton_methods);
    QAbstractButton_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QWidget_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QAbstractSlider_methods[] = {
	ZEND_ME(QAbstractSlider,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QAbstractSlider,setMaximum,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,setInvertedAppearance,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,value,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,setSliderDown,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,triggerAction,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,setRange,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,singleStep,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,setTracking,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,sliderPosition,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,setMinimum,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,minimum,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,setPageStep,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,setSliderPosition,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,invertedAppearance,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,maximum,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,orientation,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,setValue,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QAbstractSlider,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,invertedControls,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,setSingleStep,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,isSliderDown,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,setOrientation,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,pageStep,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,hasTracking,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,setInvertedControls,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QAbstractSlider,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)

    {NULL,NULL,NULL}
};

void _register_QAbstractSlider(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QAbstractSlider",QAbstractSlider_methods);
    QAbstractSlider_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QWidget_ce_ptr,NULL TSRMLS_CC);


}
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
static zend_function_entry QCoreApplication_methods[] = {
	ZEND_ME(QCoreApplication,removeTranslator,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,installTranslator,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,startingUp,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,exit,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,addLibraryPath,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,setOrganizationDomain,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,argv,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,libraryPaths,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,exec,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,setLibraryPaths,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,removeLibraryPath,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,organizationName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,setOrganizationName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,instance,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,organizationDomain,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,hasPendingEvents,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,sendPostedEvents,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,applicationName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,flush,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,processEvents,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,translate,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,applicationDirPath,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCoreApplication,argc,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,quit,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QCoreApplication,watchUnixSignal,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,removePostedEvents,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,applicationFilePath,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,setApplicationName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QCoreApplication,closingDown,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)

    {NULL,NULL,NULL}
};

void _register_QCoreApplication(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QCoreApplication",QCoreApplication_methods);
    QCoreApplication_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QObject_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QApplication_methods[] = {
	ZEND_ME(QApplication,sessionKey,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QApplication,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,clipboard,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,startDragTime,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,sessionId,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QApplication,isSessionRestored,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QApplication,setColorSpec,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setStartDragDistance,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setLayoutDirection,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,keyboardInputInterval,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,allWidgets,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setCursorFlashTime,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setWheelScrollLines,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setEffectEnabled,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setStyle,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,isRightToLeft,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setDesktopSettingsAware,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,inputContext,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QApplication,palette,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,desktopSettingsAware,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,fontMetrics,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,desktop,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,colorSpec,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,quitOnLastWindowClosed,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QApplication,wheelScrollLines,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,mouseButtons,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,topLevelWidgets,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QApplication,aboutQt,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,layoutDirection,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,windowIcon,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,style,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,activeModalWidget,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setKeyboardInputInterval,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,restoreOverrideCursor,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setDoubleClickInterval,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,activeWindow,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setActiveWindow,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,widgetAt,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,isEffectEnabled,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setPalette,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,doubleClickInterval,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,font,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,globalStrut,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setGlobalStrut,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,exec,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,changeOverrideCursor,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setWindowIcon,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,keyboardModifiers,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,beep,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,overrideCursor,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,isLeftToRight,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,syncX,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,type,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setOverrideCursor,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,focusWidget,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,topLevelAt,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,cursorFlashTime,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,startDragDistance,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,closeAllWindows,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setFont,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,notify,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QApplication,setStartDragTime,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,activePopupWidget,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,setInputContext,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QApplication,setQuitOnLastWindowClosed,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QApplication,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)

    {NULL,NULL,NULL}
};

void _register_QApplication(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QApplication",QApplication_methods);
    QApplication_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QCoreApplication_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QBoxLayout_methods[] = {
	ZEND_ME(QBoxLayout,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QBoxLayout,addLayout,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,setStretchFactor,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,setDirection,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,addItem,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,insertSpacing,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,count,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,invalidate,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,setGeometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,addWidget,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,addStrut,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,takeAt,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QBoxLayout,itemAt,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,direction,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,minimumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,sizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,heightForWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,addSpacing,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,addStretch,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,hasHeightForWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,insertStretch,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,insertWidget,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,insertLayout,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QBoxLayout,maximumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,minimumHeightForWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,expandingDirections,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QBoxLayout(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QBoxLayout",QBoxLayout_methods);
    QBoxLayout_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QLayout_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QChar_methods[] = {
	ZEND_ME(QChar,combiningClass,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,isUpper,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,joining,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar,row,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChar, __construct,NULL,ZEND_ACC_PUBLIC)
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
static zend_function_entry QChildEvent_methods[] = {
	ZEND_ME(QChildEvent,polished,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChildEvent,removed,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChildEvent,added,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QChildEvent,child,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QChildEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QChildEvent",QChildEvent_methods);
    QChildEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


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
	ZEND_ME(QDate, __construct,NULL,ZEND_ACC_PUBLIC)
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
	ZEND_ME(QDateTime, __construct,NULL,ZEND_ACC_PUBLIC)
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
static zend_function_entry QEvent_methods[] = {
	ZEND_ME(QEvent,accept,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QEvent,spontaneous,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QEvent,type,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QEvent,ignore,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QEvent,isAccepted,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QEvent,setAccepted,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QEvent",QEvent_methods);
    QEvent_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

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
	ZEND_ME(QFont, __construct,NULL,ZEND_ACC_PUBLIC)
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
static zend_function_entry QFrame_methods[] = {
	ZEND_ME(QFrame,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QFrame,setLineWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,frameWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QFrame, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,midLineWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,frameShadow,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,frameShape,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,setFrameShape,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,sizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,setFrameRect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,setFrameStyle,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,lineWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,setMidLineWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,setFrameShadow,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QFrame,frameRect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QFrame,frameStyle,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QFrame(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QFrame",QFrame_methods);
    QFrame_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QWidget_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QGridLayout_methods[] = {
	ZEND_ME(QGridLayout,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QGridLayout,addLayout,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,addItem,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,rowMinimumHeight,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,setOriginCorner,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,count,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,originCorner,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,invalidate,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,setGeometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,setRowStretch,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,getItemPosition,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QGridLayout,setDefaultPositioning,NULL,ZEND_ACC_PUBLIC)
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
static zend_function_entry QHBoxLayout_methods[] = {
	ZEND_ME(QHBoxLayout,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QHBoxLayout,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QHBoxLayout,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QHBoxLayout, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QHBoxLayout,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)

    {NULL,NULL,NULL}
};

void _register_QHBoxLayout(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QHBoxLayout",QHBoxLayout_methods);
    QHBoxLayout_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QBoxLayout_ce_ptr,NULL TSRMLS_CC);


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
static zend_function_entry QLCDNumber_methods[] = {
	ZEND_ME(QLCDNumber,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QLCDNumber,segmentStyle,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,mode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,checkOverflow,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QLCDNumber,setOctMode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,display,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,setSegmentStyle,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,setHexMode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,setSmallDecimalPoint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,sizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,value,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,setDecMode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,intValue,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,setNumDigits,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,numDigits,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,setMode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QLCDNumber,smallDecimalPoint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLCDNumber,setBinMode,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QLCDNumber(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLCDNumber",QLCDNumber_methods);
    QLCDNumber_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QFrame_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QLabel_methods[] = {
	ZEND_ME(QLabel,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QLabel,setMargin,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,clear,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,setBuddy,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,movie,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,hasScaledContents,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,setScaledContents,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,indent,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,pixmap,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLabel,setAlignment,NULL,ZEND_ACC_PUBLIC)
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
	ZEND_ME(QLabel, __construct,NULL,ZEND_ACC_PUBLIC)
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
	ZEND_ME(QLatin1Char, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLatin1Char,toLatin1,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QLatin1Char(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLatin1Char",QLatin1Char_methods);
    QLatin1Char_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QLatin1String_methods[] = {
	ZEND_ME(QLatin1String, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLatin1String,latin1,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QLatin1String(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLatin1String",QLatin1String_methods);
    QLatin1String_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QLayout_methods[] = {
	ZEND_ME(QLayout,totalHeightForWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QLayout,isEmpty,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,setMargin,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,activate,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,setMenuBar,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,layout,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,totalMaximumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,sizeConstraint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,geometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,invalidate,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,setGeometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,setAlignment,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,removeWidget,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,setEnabled,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,addWidget,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,removeItem,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QLayout,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,totalMinimumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,minimumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,setSpacing,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,isEnabled,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,setSizeConstraint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,menuBar,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,totalSizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,closestAcceptableSize,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QLayout,parentWidget,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QLayout,maximumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,margin,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,expandingDirections,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,spacing,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,update,NULL,ZEND_ACC_PUBLIC)

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
	ZEND_ME(QLayoutItem,alignment,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayoutItem,setAlignment,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QLayoutItem(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLayoutItem",QLayoutItem_methods);
    QLayoutItem_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}
static zend_function_entry QLineEdit_methods[] = {
	ZEND_ME(QLineEdit,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QLineEdit,inputMask,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,insert,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,cursorPosition,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,clear,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,selectionStart,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,setMaxLength,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,setModified,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,setFrame,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,setReadOnly,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,setEchoMode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,cursorBackward,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,cursorWordBackward,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,setAlignment,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QLineEdit,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,inputMethodQuery,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,text,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,minimumSizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,home,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,del,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,cursorForward,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,setDragEnabled,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,echoMode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,setValidator,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,hasSelectedText,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,hasAcceptableInput,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,paste,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,redo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,copy,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,undo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,displayText,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,cursorWordForward,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,event,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,validator,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,end,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,isRedoAvailable,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,cursorPositionAt,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,deselect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,setSelection,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,selectedText,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,isUndoAvailable,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,hasFrame,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,setInputMask,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,dragEnabled,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,cut,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,setText,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,alignment,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,sizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,setCursorPosition,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,createStandardContextMenu,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,backspace,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,selectAll,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,maxLength,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,isModified,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLineEdit,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QLineEdit,isReadOnly,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QLineEdit(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLineEdit",QLineEdit_methods);
    QLineEdit_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QWidget_ce_ptr,NULL TSRMLS_CC);


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
static zend_function_entry QPaintDevice_methods[] = {
	ZEND_ME(QPaintDevice,width,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPaintDevice,physicalDpiX,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPaintDevice,logicalDpiY,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPaintDevice,heightMM,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPaintDevice,paintingActive,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPaintDevice,numColors,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPaintDevice,logicalDpiX,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPaintDevice,depth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPaintDevice,height,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPaintDevice,physicalDpiY,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPaintDevice,widthMM,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QPaintDevice(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QPaintDevice",QPaintDevice_methods);
    QPaintDevice_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

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
	ZEND_ME(QPainter, __construct,NULL,ZEND_ACC_PUBLIC)
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
static zend_function_entry QPushButton_methods[] = {
	ZEND_ME(QPushButton,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QPushButton,showMenu,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPushButton,setFlat,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPushButton,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QPushButton,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPushButton,isDefault,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPushButton,setAutoDefault,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPushButton,sizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPushButton,menu,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPushButton,setDefault,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPushButton, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPushButton,autoDefault,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPushButton,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QPushButton,isFlat,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QPushButton,setMenu,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QPushButton(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QPushButton",QPushButton_methods);
    QPushButton_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QAbstractButton_ce_ptr,NULL TSRMLS_CC);


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
static zend_function_entry QSlider_methods[] = {
	ZEND_ME(QSlider,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QSlider,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QSlider,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSlider, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSlider,minimumSizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSlider,sizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSlider,tickInterval,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSlider,setTickInterval,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSlider,tickPosition,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSlider,event,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSlider,setTickPosition,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSlider,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)

    {NULL,NULL,NULL}
};

void _register_QSlider(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QSlider",QSlider_methods);
    QSlider_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QAbstractSlider_ce_ptr,NULL TSRMLS_CC);


}
static zend_function_entry QSpacerItem_methods[] = {
	ZEND_ME(QSpacerItem,changeSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSpacerItem,isEmpty,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSpacerItem,setGeometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSpacerItem,spacerItem,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSpacerItem,minimumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSpacerItem,sizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSpacerItem,maximumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSpacerItem,geometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSpacerItem,expandingDirections,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QSpacerItem, __construct,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QSpacerItem(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QSpacerItem",QSpacerItem_methods);
    QSpacerItem_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QLayoutItem_ce_ptr,NULL TSRMLS_CC);


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
static zend_function_entry QString_methods[] = {
	ZEND_ME(QString,compare,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,utf16,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,constData,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,insert,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,clear,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,setUtf16,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,prepend,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,trimmed,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,chop,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,leftJustified,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,squeeze,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,count,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,fromAscii,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QString,toLongLong,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,toUpper,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,normalized,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,fromUtf16,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QString,isRightToLeft,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,setNum,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,endsWith,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,number,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QString,localeAwareCompare,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,section,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,isSimpleText,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,size,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,simplified,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,toUInt,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,toUShort,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,truncate,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,toAscii,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,length,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,right,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,push_front,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,toUtf8,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,toULongLong,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,indexOf,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,fromRawData,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QString,constEnd,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,left,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,fromLocal8Bit,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QString,startsWith,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,remove,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,isEmpty,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,arg,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,vsprintf,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,toFloat,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,isDetached,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,reserve,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,toULong,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,toShort,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,split,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,setUnicode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,fromLatin1,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QString,data,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,toLatin1,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,end,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,contains,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,resize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,replace,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,fromUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QString,toLong,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,detach,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,append,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,mid,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,toDouble,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,fill,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,rightJustified,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,toLower,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,lastIndexOf,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,unicode,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,at,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,begin,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,push_back,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,capacity,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,constBegin,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,toLocal8Bit,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,toInt,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QString,isNull,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QString(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QString",QString_methods);
    QString_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

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
	ZEND_ME(QTime, __construct,NULL,ZEND_ACC_PUBLIC)
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
	ZEND_ME(QTimer,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QTimer,setInterval,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,timerId,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,singleShot,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QTimer,stop,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,isActive,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,interval,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,setSingleShot,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QTimer,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
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
static zend_function_entry QTimerEvent_methods[] = {
	ZEND_ME(QTimerEvent,timerId,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QTimerEvent(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QTimerEvent",QTimerEvent_methods);
    QTimerEvent_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QEvent_ce_ptr,NULL TSRMLS_CC);


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
static zend_function_entry QVBoxLayout_methods[] = {
	ZEND_ME(QVBoxLayout,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QVBoxLayout,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QVBoxLayout,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QVBoxLayout,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QVBoxLayout, __construct,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QVBoxLayout(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QVBoxLayout",QVBoxLayout_methods);
    QVBoxLayout_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QBoxLayout_ce_ptr,NULL TSRMLS_CC);


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
static zend_function_entry QWidget_methods[] = {
	ZEND_ME(QWidget,nextInFocusChain,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,tr,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QWidget,focusPolicy,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,windowOpacity,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,y,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,clearFocus,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,fontInfo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isHidden,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setMaximumWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,contentsRect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setContextMenuPolicy,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,focusProxy,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,statusTip,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,visibleRegion,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isVisibleTo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,releaseMouse,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setTabOrder,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QWidget,setFocusProxy,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,topLevelWidget,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,mapToParent,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,overrideWindowFlags,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,hide,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,mapTo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,childrenRect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setStyle,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isRightToLeft,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setWindowModified,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setBackgroundRole,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setFixedSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,inputContext,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,palette,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setFixedHeight,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,repaint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,cursor,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setWindowIconText,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,fontMetrics,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,grabShortcut,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,releaseKeyboard,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setAccessibleDescription,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,qObject,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,maximumWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setWindowOpacity,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isTopLevel,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,mask,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isActiveWindow,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isEnabledTo,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,layoutDirection,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isAncestorOf,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,windowIcon,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,updatesEnabled,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isMinimized,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,height,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,normalGeometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setMask,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setForegroundRole,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,update,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,adjustSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,toolTip,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setCursor,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setMinimumWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isEnabledToTLW,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setWindowRole,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setPalette,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,acceptDrops,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setShortcutEnabled,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,geometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setShown,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,accessibleDescription,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setMaximumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setContentsMargins,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,backgroundRole,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,mapFromParent,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,updateGeometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setAttribute,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,windowType,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,focusWidget,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,ensurePolished,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,foregroundRole,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setEnabled,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,windowIconText,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,winId,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,close,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,childAt,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setFixedWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,windowRole,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setFont,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,hasMouseTracking,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,childrenRegion,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setInputContext,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,unsetLayoutDirection,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,sizeIncrement,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,mouseGrabber,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QWidget,trUtf8,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QWidget,isFullScreen,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,mapToGlobal,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,move,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,mapFromGlobal,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setUpdatesEnabled,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setSizeIncrement,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,grabMouse,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,layout,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,mapFrom,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,windowFlags,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isModal,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,unsetCursor,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setLayoutDirection,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,maximumHeight,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,frameGeometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,handle,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,lower,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setWindowTitle,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setWindowState,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,scroll,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,sizePolicy,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,width,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setHidden,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,find,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QWidget,staticMetaObject,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QWidget,size,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,activateWindow,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setToolTip,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setParent,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isWindowModified,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,testAttribute,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,pos,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isWindow,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setFocusPolicy,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,getContentsMargins,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,windowTitle,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,style,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,windowState,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,frameSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setAccessibleName,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setAcceptDrops,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,removeAction,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,hasFocus,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,showFullScreen,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setMouseTracking,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,clearMask,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,showMaximized,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,devType,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,font,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,stackUnder,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setMinimumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setDisabled,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,show,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,underMouse,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setWindowIcon,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,grabKeyboard,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,raise,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setWhatsThis,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setGeometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,contextMenuPolicy,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,resize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isLeftToRight,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setWindowFlags,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,baseSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setLayout,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setMaximumHeight,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,showNormal,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,insertAction,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,window,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,paintEngine,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,minimumHeight,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,x,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,releaseShortcut,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setStatusTip,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setBaseSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,rect,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,addAction,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,minimumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setFocus,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isVisible,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,accessibleName,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,minimumWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isEnabled,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,keyboardGrabber,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(QWidget,overrideWindowState,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,setMinimumHeight,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,isMaximized,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,parentWidget,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,whatsThis,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,maximumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidget,showMinimized,NULL,ZEND_ACC_PUBLIC)

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
	ZEND_ME(QWidgetItem,hasHeightForWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem,isEmpty,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem,setGeometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem, __construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem,minimumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem,sizeHint,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem,maximumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QWidgetItem,heightForWidth,NULL,ZEND_ACC_PUBLIC)
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
