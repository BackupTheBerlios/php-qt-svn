/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2004 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/
/*
 * Copyright (C) 2005 
 * Thomas Moenicke <tm@ippfp.org>, 
 * Jean-Luc Gyger <jean_luc.gyger@freesurf.ch>
 *
*/
/* $Id: header,v 1.15 2004/01/08 16:46:52 sniper Exp $ */

#include "php_qt.h"
#include <QObject>
#include <QApplication>
#include <QBoxLayout>

QOUT();

//static int objects_handle;

/* If you declare any globals in php_php_qt.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(php_qt)
*/

/* True global resources - no need for thread safety here */
static int le_php_qt;

zend_class_entry *QWidget_ce_ptr; //Gyger Jean-Luc change to non static
zend_class_entry *QString_ce_ptr;
zend_class_entry *QObject_ce_ptr;
zend_class_entry *QLatin1String_ce_ptr;
zend_class_entry *QPushButton_ce_ptr;
zend_class_entry *QAbstractButton_ce_ptr;
zend_class_entry *QApplication_ce_ptr;
zend_class_entry *QCoreApplication_ce_ptr;
zend_class_entry *QEvent_ce_ptr;
zend_class_entry *QLayoutItem_ce_ptr;
zend_class_entry *QLayout_ce_ptr;
zend_class_entry *QBoxLayout_ce_ptr;
zend_class_entry *QSpacerItem_ce_ptr;

/* {{{ php_qt_functions[]
 *
 * Every user visible function must have an entry in php_qt_functions[].
 */
function_entry php_qt_functions[] = {
	PHP_FE(confirm_php_qt_compiled,	NULL)		/* For testing, remove later. */
    PHP_FE(SIGNAL,	NULL)
    PHP_FE(SLOT,	NULL)	
	{NULL, NULL, NULL}	/* Must be the last line in php_qt_functions[] */
};
/* }}} */

/* {{{ php_qt_module_entry
 */
zend_module_entry php_qt_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"php_qt",
	php_qt_functions,
	PHP_MINIT(php_qt),
	PHP_MSHUTDOWN(php_qt),
	PHP_RINIT(php_qt),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(php_qt),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(php_qt),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PHP_QT
ZEND_GET_MODULE(php_qt)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("php_qt.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_php_qt_globals, php_qt_globals)
    STD_PHP_INI_ENTRY("php_qt.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_php_qt_globals, php_qt_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_php_qt_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_php_qt_init_globals(zend_php_qt_globals *php_qt_globals)
{
	php_qt_globals->global_value = 0;
	php_qt_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */

PHP_MINIT_FUNCTION(php_qt)
{
	/* If you have INI entries, uncomment these lines 
	ZEND_INIT_MODULE_GLOBALS(php_qt, php_php_qt_init_globals, NULL);
	REGISTER_INI_ENTRIES();
	*/
	/*Qt constant */
	REGISTER_LONG_CONSTANT("QT_ALIGNMENT_ALIGNLEFT",Qt::AlignLeft ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QT_ALIGNMENT_ALIGNRIGHT",Qt::AlignRight ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QT_ALIGNMENT_ALIGNHCENTER",Qt::AlignHCenter ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QT_ALIGNMENT_ALIGNJUSTIFY",Qt::AlignJustify ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QT_ALIGNMENT_ALIGNTOP",Qt::AlignTop ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QT_ALIGNMENT_ALIGNBOTTOM",Qt::AlignBottom ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QT_ALIGNMENT_ALIGNVCENTER",Qt::AlignVCenter ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QT_ALIGNMENT_ALIGNCENTER",Qt::AlignCenter ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QT_ALIGNMENT_ALIGNABSOLUTE",Qt::AlignAbsolute ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QT_ALIGNMENT_ALIGNLEADING",Qt::AlignLeading ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QT_ALIGNMENT_ALIGNTRAILING",Qt::AlignTrailing ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QT_ALIGNMENT_ALIGNHORIZONTAL_MASK",Qt::AlignHorizontal_Mask ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QT_ALIGNMENT_ALIGNVERTICAL_MASK",Qt::AlignVertical_Mask ,CONST_CS | CONST_PERSISTENT);	
	
	
	
	_register_QCoreApplication(TSRMLS_C);
	REGISTER_LONG_CONSTANT("QCOREAPPLICATION_ENCODING_DEFAULTCODEC",QCoreApplication::DefaultCodec ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QCOREAPPLICATION_ENCODING_UNICODEUTF8",QCoreApplication::UnicodeUTF8 ,CONST_CS | CONST_PERSISTENT);	
	
    _register_QApplication(TSRMLS_C);
	//enum QApplication::ColorSpec
	REGISTER_LONG_CONSTANT("QAPPLICATION_COLORSPEC_NORMALCOLOR",QApplication::NormalColor ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QAPPLICATION_COLORSPEC_CUSTOMCOLOR",QApplication::CustomColor ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QAPPLICATION_COLORSPEC_MANYCOLOR",QApplication::ManyColor ,CONST_CS | CONST_PERSISTENT);	
	//enum QApplication::Type
	REGISTER_LONG_CONSTANT("QAPPLICATION_TYPE_TTY",QApplication::Tty ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QAPPLICATION_TYPE_GUICLIENT",QApplication::GuiClient ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QAPPLICATION_TYPE_GUISERVER",QApplication::GuiServer ,CONST_CS | CONST_PERSISTENT);	
	
	
    _register_QString(TSRMLS_C);
    _register_QLatin1String(TSRMLS_C);
    _register_QObject(TSRMLS_C);
    _register_QWidget(TSRMLS_C);
    _register_QAbstractButton(TSRMLS_C);
    _register_QPushButton(TSRMLS_C);
	
	_register_QEvent(TSRMLS_C);
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_NONE", QEvent::None,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_ACCESSIBILITYDESCRIPTION", QEvent::AccessibilityDescription,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_ACCESSIBILITYHELP", QEvent::AccessibilityHelp,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_ACCESSIBILITYPREPARE", QEvent::AccessibilityPrepare,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_ACTIONADDED", QEvent::ActionAdded,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_ACTIONCHANGED", QEvent::ActionChanged,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_ACTIONREMOVED", QEvent::ActionRemoved,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_ACTIVATIONCHANGED", QEvent::ActivationChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_APPLICATIONACTIVATED", QEvent::ApplicationActivated,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_APPLICATIONDEACTIVATED", QEvent::ApplicationDeactivated,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_APPLICATIONFONTCHANGE", QEvent::ApplicationFontChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_APPLICATIONLAYOUTDIRECTIONCHANGE", QEvent::ApplicationLayoutDirectionChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_APPLICATIONPALLETECHANGE", QEvent::ApplicationPaletteChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_APPLICATIONWINDOWICONCHANGE", QEvent::ApplicationWindowIconChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_CHILDADDED", QEvent::ChildAdded,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_CHILDPOLISHED", QEvent::ChildPolished,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_CHILDREMOVED", QEvent::ChildRemoved,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_CLIPBOARD", QEvent::Clipboard,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_CLOSE", QEvent::Close,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_CONTEXTMENU", QEvent::ContextMenu,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_DEFERREDDELETE", QEvent::DeferredDelete,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_DRAGENTER", QEvent::DragEnter,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_DRAGLEAVE", QEvent::DragLeave,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_DRAGMOVE", QEvent::DragMove,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_DROP", QEvent::Drop,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_ENABLEDCHANGE", QEvent::EnabledChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_ENTER", QEvent::Enter,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_ENTERWHATSTHISMODE", QEvent::EnterWhatsThisMode,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_FILEOPEN", QEvent::FileOpen,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_FOCUSIN", QEvent::FocusIn,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_FOCUSOUT", QEvent::FocusOut,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_FONTCHANGE", QEvent::FontChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_HIDE", QEvent::Hide,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_HIDETOPARENT", QEvent::HideToParent,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_HOVERENTER", QEvent::HoverEnter,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_HOVERLEAVE", QEvent::HoverLeave,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_HOVERMOVE", QEvent::HoverMove,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_ICONDRAG", QEvent::IconDrag,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_ICONTEXTCHANGE", QEvent::IconTextChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_INOUTMETHOD", QEvent::InputMethod,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_KEYPRESS", QEvent::KeyPress,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_KEYRELEASE", QEvent::KeyRelease,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_LANGUAGECHANGE", QEvent::LanguageChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_LAYOUTDIRECTIONCHANGE", QEvent::LayoutDirectionChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_LAYOUTREQUEST", QEvent::LayoutRequest,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_LEAVE", QEvent::Leave,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_LEAVEWHATSTHISMODE", QEvent::LeaveWhatsThisMode,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_LOCALECHANGE", QEvent::LocaleChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_METACALL", QEvent::MetaCall,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_MODIFIEDCHANGE", QEvent::ModifiedChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_MOUSEBUTTONDBCLICK", QEvent::MouseButtonDblClick,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_MOUSEBUTTONPRESS", QEvent::MouseButtonPress,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_MOUSEBUTTONRELEASE", QEvent::MouseButtonRelease,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_MOUSEMOUVE", QEvent::MouseMove,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_MOUSETRACKINGCHANGE", QEvent::MouseTrackingChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_MOVE", QEvent::Move,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_PAINT", QEvent::Paint,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_PALETTECHANGE", QEvent::PaletteChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_PARENTABOUTTOCHANGE", QEvent::ParentAboutToChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_PARENTCHANGE", QEvent::ParentChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_POLISH", QEvent::Polish,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_POLISHREQUEST", QEvent::PolishRequest,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_QUERYWHATSTHIS", QEvent::QueryWhatsThis,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_RESIZE", QEvent::Resize,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_SHORTCUT", QEvent::Shortcut,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_SHORTCUTOVERRIDE", QEvent::ShortcutOverride,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_SHOW", QEvent::Show,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_SHOWTOPARENT", QEvent::ShowToParent,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_SOCKACT", QEvent::SockAct,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_STATUSTIP", QEvent::StatusTip,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_STYLECHANGE", QEvent::StyleChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_TABLEMOVE", QEvent::TabletMove,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_TABLETPRESS", QEvent::TabletPress,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_TABLETRELEASE", QEvent::TabletRelease,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_TIMER", QEvent::Timer,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_TOOLBARCHANGE", QEvent::ToolBarChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_TOOLTIP", QEvent::ToolTip,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_UPDATEREQUEST", QEvent::UpdateRequest,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_WHATSTHIS", QEvent::WhatsThis,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_WHATSTHISCLICKED", QEvent::WhatsThisClicked,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_WHEEL", QEvent::Wheel,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_WINEVENTACT", QEvent::WinEventAct,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_WINDOWACTIVATED", QEvent::WindowActivate,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_WINDOWBLOCKED", QEvent::WindowBlocked,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_WINDOWDEACTIVATED", QEvent::WindowDeactivate,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_WINDOWICONCHANGE", QEvent::WindowIconChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_WINDOWSTATECHANGE", QEvent::WindowStateChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_WINDOWTITLECHANGE", QEvent::WindowTitleChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_WINDOWUNBLOCKED", QEvent::WindowUnblocked,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_ZORDERCHANGE", QEvent::ZOrderChange,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_USER", QEvent::User,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QEVENT_TYPE_MAXUSER", QEvent::MaxUser,CONST_CS | CONST_PERSISTENT);	
	
	
	_register_QLayoutItem(TSRMLS_C);
	
	_register_QLayout(TSRMLS_C);
	REGISTER_LONG_CONSTANT("QLAYOUT_SIZECONSTRAINT_SETDEFAULTCONSTRAINT",QLayout::SetDefaultConstraint ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QLAYOUT_SIZECONSTRAINT_SETFIXEDSIZE",QLayout::SetFixedSize ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QLAYOUT_SIZECONSTRAINT_SETMINIMUMSIZE",QLayout::SetMinimumSize ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QLAYOUT_SIZECONSTRAINT_SETMAXIMUMSIZE",QLayout::SetMaximumSize ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QLAYOUT_SIZECONSTRAINT_SETMINANDMAXSIZE",QLayout::SetMinAndMaxSize ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QLAYOUT_SIZECONSTRAINT_SETNOTCONSTRAINT",QLayout::SetNoConstraint ,CONST_CS | CONST_PERSISTENT);	
	
	_register_QBoxLayout(TSRMLS_C);
	REGISTER_LONG_CONSTANT("QBOXLAYOUT_DIRECTION_LEFT_TO_RIGHT",QBoxLayout::LeftToRight ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QBOXLAYOUT_DIRECTION_RIGHT_TO_LEFT",QBoxLayout::RightToLeft ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QBOXLAYOUT_DIRECTION_TOP_TO_BOTTOM",QBoxLayout::TopToBottom ,CONST_CS | CONST_PERSISTENT);	
	REGISTER_LONG_CONSTANT("QBOXLAYOUT_DIRECTION_BOTTOM_TO_TOP",QBoxLayout::BottomToTop ,CONST_CS | CONST_PERSISTENT);	
	
//    objects_handle = zend_register_list_destructors_ex(NULL,NULL,"Qt Wrapper",module_number);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(php_qt)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(php_qt)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(php_qt)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(php_qt)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "php_qt support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_php_qt_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_php_qt_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char string[256];

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

  	len = sprintf(string, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "php_qt", arg);
	RETURN_STRINGL(string, len, 1);

}

/*
 *  emulate the SIGNAL(), SLOT() macros in Qt
 */

PHP_FUNCTION(SIGNAL)
{
    const char* string;
    int* string_len;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s",&string,&string_len)) {
        return;
    }

    char* tmp = (char*) emalloc((int) string_len + 2);
    strcpy(tmp,"2");

    strncat(tmp, string, (int) string_len);

    ZVAL_STRING(return_value,tmp,1);

    efree(tmp);

    return;
}

PHP_FUNCTION(SLOT)
{
    const char* string;
    int* string_len;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s",&string,&string_len)) {
        return;
    }

    char* tmp = (char*) emalloc((int) string_len + 2);
    strcpy(tmp,"1");

    strncat(tmp, string, (int) string_len);

    ZVAL_STRING(return_value,tmp,1);

    efree(tmp);

    return;
}

/* }}} */
/* {{{ */

void php_qt_register(zval* this_ptr, zend_rsrc_list_entry le){

    if(PHP_QT_REGISTER_OBJECT(le) == FAILURE){
        php_error(E_ERROR,"PHP_QT: %s(): could not register qobject in hashtable.",get_active_function_name(TSRMLS_C));
        return;
    }

}

void* php_qt_fetch(zval* this_ptr){

    zend_rsrc_list_entry* le;  

    if(!zend_hash_exists(HASH_OF(this_ptr),PHP_QT_HASH_QOBJECT,strlen(PHP_QT_HASH_QOBJECT))){
        php_error(E_ERROR,"PHP_QT: %s(): hash not found.",get_active_function_name(TSRMLS_C));
    }

    if(PHP_QT_FETCH_OBJECT(le) == FAILURE){
        php_error(E_ERROR,"PHP_QT: %s(): could not fetch qobject from hashtable.",get_active_function_name(TSRMLS_C));
        return NULL;
    }

    return le->ptr;

}

///



static zend_function_entry QString_methods[] = { 
    ZEND_ME(QString,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QString,append,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QString,arg,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QString,at,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}

};

void _register_QString(TSRMLS_D)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QString",QString_methods);
    QString_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

    zend_declare_property_string(QString_ce_ptr,"QString",strlen("QString"),"",ZEND_ACC_PROTECTED TSRMLS_CC);

}

static zend_function_entry QLatin1String_methods[] = { 
    ZEND_ME(QLatin1String,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QLatin1String,latin1,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}

};

void _register_QLatin1String(TSRMLS_D){

    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce,"QLatin1String",QLatin1String_methods);
    QLatin1String_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

    zend_declare_property_string(QLatin1String_ce_ptr,"QLatin1String",strlen("QLatin1String"),"",ZEND_ACC_PROTECTED TSRMLS_CC);

}

static zend_function_entry QObject_methods[] = { 
    ZEND_ME(QObject,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,test,NULL,ZEND_ACC_PUBLIC)    
    ZEND_ME(QObject,blockSignals,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,children,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,connect,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    ZEND_ME(QObject,disconnect,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    ZEND_ME(QObject,dumpObjectInfo,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,dumpObjectTree,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,event,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,eventFilter,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,findChild,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,findChildren,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,inherits,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,installEventFilter,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,isWidgetType,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,killTimer,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,metaObject,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,moveToThread,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,objectName,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,parent,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,property,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,removeEventFilter,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,setObjectName,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,setParent,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,setProperty,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,signalsBlocked,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,startTimer,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QObject,thread,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}
};

void _register_QObject(TSRMLS_D){

    zend_class_entry ce;
    TSRMLS_FETCH();

    INIT_CLASS_ENTRY(ce,"QObject",QObject_methods);
    QObject_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

    zend_declare_property_null(QObject_ce_ptr,"parent",strlen("parent"),ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_null(QObject_ce_ptr,"objectName",strlen("objectName"),ZEND_ACC_PROTECTED TSRMLS_CC);

}

static zend_function_entry QWidget_methods[] = {
 
    ZEND_ME(QWidget,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,show,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,hide,NULL,ZEND_ACC_PUBLIC)

    ZEND_ME(QWidget,acceptDrops,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,activateWindow,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,adjustSize,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,clearFocus,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,clearMask,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,grabKeyboard,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,grabMouse,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,hasFocus,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,hasMouseTracking,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,height,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,isActiveWindow,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,isEnabled,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,isFullScreen,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,isHidden,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,isMaximized,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,isMinimized,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,isModal,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,isVisible,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,isWindow,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,isWindowModified,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,maximumHeight,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,maximumWidth,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,minimumHeight,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,minimumWidth,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,releaseKeyboard,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,releaseMouse,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,underMouse,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,unsetCursor,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,unsetLayoutDirection,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,updateGeometry,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,updatesEnabled,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,width,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,x,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,y,NULL,ZEND_ACC_PUBLIC)

/*    ZEND_ME(QWidget,accessibleDescription,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,accessibleName,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,backgroundRole,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,baseSize,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,childrenRecr,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,childrenRegion,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,contentsRect,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,contextMenuPolicy,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,cursor,NULL,ZEND_ACC_PUBLIC)
*/    ZEND_ME(QWidget,ensurePolished,NULL,ZEND_ACC_PUBLIC)
/*    ZEND_ME(QWidget,focusPolicy,NULL,ZEND_ACC_PUBLIC)
*/    ZEND_ME(QWidget,focusProxy,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,focusWidget,NULL,ZEND_ACC_PUBLIC)
/*    ZEND_ME(QWidget,font,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,fontInfo,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,fontMetrics,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,foregroundRole,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,frameGeometry,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,frameSize,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,geometry,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,getDC,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,inputContext,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,inputMethodQuery,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,layout,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,layoutDirection,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,mask,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,maximumSize,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,minimumSize,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,minimumSizeHint,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,nextInFocusChain,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,normalGeometry,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,paintEngine,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,palette,NULL,ZEND_ACC_PUBLIC)
*/    ZEND_ME(QWidget,parentWidget,NULL,ZEND_ACC_PUBLIC)
/*    ZEND_ME(QWidget,pos,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,rect,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,releaseDC,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,size,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,sizeHint,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,sizeIncrement,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,sizePolicy,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,statusTip,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,style,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,toolTip,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,visibleRegion,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,whatsThis,NULL,ZEND_ACC_PUBLIC)
*/    ZEND_ME(QWidget,window,NULL,ZEND_ACC_PUBLIC)
/*    ZEND_ME(QWidget,windowFlags,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,windowIcon,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,windowIconText,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,windowOpacity,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,windowRole,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,windowState,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,windowTitle,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,windowType,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,x11Info,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QWidget,x11PictureHandle,NULL,ZEND_ACC_PUBLIC)
*/
    {NULL,NULL,NULL}
};

void _register_QWidget(TSRMLS_D)
{
    zend_class_entry ce;
    
    INIT_CLASS_ENTRY(ce,"QWidget",QWidget_methods);
    
    QWidget_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QObject_ce_ptr,NULL TSRMLS_CC);
    // call zend_do_inheritance directly to inherit from QPaintDevice

}

static zend_function_entry QPushButton_methods[] = {
 
    ZEND_ME(QPushButton,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,autoDefault,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,isDefault,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,isFlat,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,menu,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,setAutoDefault,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,setDefault,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,setFlat,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,setMenu,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QPushButton,paintEvent,NULL,ZEND_ACC_PROTECTED)
    {NULL,NULL,NULL}

};

void _register_QPushButton(TSRMLS_D)
{
    zend_class_entry ce;
    
    INIT_CLASS_ENTRY(ce,"QPushButton",QPushButton_methods);
    
    QPushButton_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QAbstractButton_ce_ptr,NULL TSRMLS_CC);
    zend_declare_property_null(QPushButton_ce_ptr,"menu",strlen("menu"),ZEND_ACC_PRIVATE TSRMLS_CC);

}

static zend_function_entry QAbstractButton_methods[] = {
 
    ZEND_ME(QAbstractButton,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,autoExclusive,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,autoRepeat,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,isCheckable,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,isChecked,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,isDown,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,setAutoExclusive,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,setAutoRepeat,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QAbstractButton,paintEvent,NULL,ZEND_ACC_PROTECTED|ZEND_ACC_ABSTRACT)
//    ZEND_ME(QAbstractButton,setCheckable,NULL,ZEND_ACC_PUBLIC)
//    ZEND_ME(QAbstractButton,setDown,NULL,ZEND_ACC_PUBLIC)

    {NULL,NULL,NULL}

};

void _register_QAbstractButton(TSRMLS_D)
{
    zend_class_entry ce;
    
    INIT_CLASS_ENTRY(ce,"QAbstractButton",QAbstractButton_methods);
    
    QAbstractButton_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QWidget_ce_ptr,NULL TSRMLS_CC);
    zend_declare_property_null(QAbstractButton_ce_ptr,"menu",strlen("menu"),ZEND_ACC_PRIVATE TSRMLS_CC);

    zend_declare_property_bool(QAbstractButton_ce_ptr,"autoExclusive",strlen("autoExclusive"),0,ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_bool(QAbstractButton_ce_ptr,"autoRepeat",strlen("autoRepeat"),0,ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_bool(QAbstractButton_ce_ptr,"checkable",strlen("checkable"),0,ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_bool(QAbstractButton_ce_ptr,"checked",strlen("checked"),0,ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_bool(QAbstractButton_ce_ptr,"down",strlen("down"),0,ZEND_ACC_PRIVATE TSRMLS_CC);

    zend_declare_property_null(QAbstractButton_ce_ptr,"icon",strlen("icon"),ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_null(QAbstractButton_ce_ptr,"iconSize",strlen("iconSize"),ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_null(QAbstractButton_ce_ptr,"shortcut",strlen("shortcut"),ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_null(QAbstractButton_ce_ptr,"text",strlen("text"),ZEND_ACC_PRIVATE TSRMLS_CC);

}

static zend_function_entry QCoreApplication_methods[] = {
	//public members 
    ZEND_ME(QCoreApplication,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QCoreApplication,filterEvent,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QCoreApplication,notify,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QCoreApplication,setEventFilter,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QCoreApplication,winEventFilter,NULL,ZEND_ACC_PUBLIC)
	//public slot
	ZEND_ME(QCoreApplication,quit,NULL,ZEND_ACC_PUBLIC)
	//public static members
    ZEND_ME(QCoreApplication,exec,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
	ZEND_ME(QCoreApplication,addLibraryPath,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,applicationDirPath,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,applicationFilePath,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,applicationName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,argc,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,argv,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,closingDown,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,exit,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,flush,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,hasPendingEvents,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,installTranslator,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,instance,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,libraryPaths,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,organizationDomain,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,organizationName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,postEvent,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,processEvents,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,removeLibraryPath,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,removePostedEvents,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,removeTranslator,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,sendEvent,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,sendPostedEvents,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,setApplicationName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,setLibraryPaths,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,setOrganizationDomain,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,setOrganizationName,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,startingUp,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QCoreApplication,translate,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
	{NULL,NULL,NULL}
};

void _register_QCoreApplication(TSRMLS_D)
{
    zend_class_entry ce;
    
    INIT_CLASS_ENTRY(ce,"QCoreApplication",QCoreApplication_methods);
    
    QCoreApplication_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QObject_ce_ptr,NULL TSRMLS_CC);

}

static zend_function_entry QApplication_methods[] = {

	//public members 
    ZEND_ME(QApplication,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(QApplication, commitData, NULL, ZEND_ACC_PUBLIC) 
    ZEND_ME(QApplication, inputContext, NULL, ZEND_ACC_PUBLIC) 
    ZEND_ME(QApplication, isSessionRestored, NULL, ZEND_ACC_PUBLIC) 
    ZEND_ME(QApplication, macEventFilter, NULL, ZEND_ACC_PUBLIC) 
    ZEND_ME(QApplication, qwsEventFilter, NULL, ZEND_ACC_PUBLIC) 
    ZEND_ME(QApplication, qwsSetCustomColors, NULL, ZEND_ACC_PUBLIC) 
    ZEND_ME(QApplication, saveState, NULL, ZEND_ACC_PUBLIC) 
    ZEND_ME(QApplication, sessionId, NULL, ZEND_ACC_PUBLIC) 
    ZEND_ME(QApplication, sessionKey, NULL, ZEND_ACC_PUBLIC) 
    ZEND_ME(QApplication, setInputContext, NULL, ZEND_ACC_PUBLIC) 
    ZEND_ME(QApplication, winFocus, NULL, ZEND_ACC_PUBLIC) 
    ZEND_ME(QApplication, x11EventFilter, NULL, ZEND_ACC_PUBLIC) 
    ZEND_ME(QApplication, x11ProcessEvent, NULL, ZEND_ACC_PUBLIC) 
	//public slots members
    ZEND_ME(QApplication, aboutQt, NULL, ZEND_ACC_PUBLIC) 
    ZEND_ME(QApplication, closeAllWindows, NULL, ZEND_ACC_PUBLIC) 
	//public static members
    //ZEND_ME(QApplication,exec,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QApplication, beep, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, colorSpec, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, cursorFlashTime, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, desktopSettingsAware, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, doubleClickInterval, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, isLeftToRight, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, isRightToLeft, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, keyboardInputInterval, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QApplication, quitOnLastWindowClosed, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QApplication, restoreOverrideCursor, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QApplication, setDesktopSettingsAware, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, setColorSpec, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, setCursorFlashTime, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, setDoubleClickInterval, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC) 
    ZEND_ME(QApplication, setKeyboardInputInterval, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, setQuitOnLastWindowClosed, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, setStartDragDistance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, setStartDragTime, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, setWheelScrollLines, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, startDragDistance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, startDragTime, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, syncX, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, wheelScrollLines, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, activeModalWidget, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, activePopupWidget, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, activeWindow, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, focusWidget, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
    ZEND_ME(QApplication, setActiveWindow, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, widgetAt, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, topLevelAt, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, type, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, allWidgets, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, changeOverrideCursor, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, clipboard, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, desktop, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, fontMetrics, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, globalStrut, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, isEffectEnabled, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, keyboardModifiers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, layoutDirection, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, mouseButton, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, overrideCursor, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, palette, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, qwsDecoration, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, qwsSetDecoration, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, setEffectEnabled, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, setFont, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, setGlobalStrut, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, setLayoutDirection, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, setOverrideCursor, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, setPalette, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, setStyle, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, setWindowIcon, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, style, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, topLevelWidgets, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	ZEND_ME(QApplication, windowIcon, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ALLOW_STATIC)
	{NULL,NULL,NULL}
};

void _register_QApplication(TSRMLS_D)
{
    zend_class_entry ce;
    
    INIT_CLASS_ENTRY(ce,"QApplication",QApplication_methods);
    
    QApplication_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QCoreApplication_ce_ptr,NULL TSRMLS_CC);

    // properties
    
    zend_declare_property_bool(QApplication_ce_ptr,"quitOnLastWindowClosed",strlen("quitOnLastWindowClosed"), QApplication::quitOnLastWindowClosed(),ZEND_ACC_PROTECTED TSRMLS_CC);

    zend_declare_property_long(QApplication_ce_ptr,"doubleClickInterval",strlen("doubleClickInterval"),QApplication::doubleClickInterval(),ZEND_ACC_PROTECTED TSRMLS_CC);
    zend_declare_property_long(QApplication_ce_ptr,"cursorFlashTime",strlen("cursorFlashTime"),QApplication::cursorFlashTime(),ZEND_ACC_PROTECTED TSRMLS_CC);

    zend_declare_property_long(QApplication_ce_ptr,"keyboardInputInterval",strlen("keyboardInputInterval"),QApplication::keyboardInputInterval(),ZEND_ACC_PROTECTED TSRMLS_CC);


    zend_declare_property_long(QApplication_ce_ptr,"startDragDistance",strlen("startDragDistance"),QApplication::startDragDistance(),ZEND_ACC_PROTECTED TSRMLS_CC);
    zend_declare_property_long(QApplication_ce_ptr,"startDragTime",strlen("startDragTime"),QApplication::startDragTime(),ZEND_ACC_PROTECTED TSRMLS_CC);
    zend_declare_property_long(QApplication_ce_ptr,"wheelScrollLines",strlen("wheelScrollLines"),QApplication::wheelScrollLines(),ZEND_ACC_PROTECTED TSRMLS_CC);

}

static zend_function_entry QEvent_methods[] = {
	ZEND_ME(QEvent,__construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QEvent,accept,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QEvent,ignore,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QEvent,isAccepted,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QEvent,setAccepted,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QEvent,spontaneous,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QEvent,type,NULL,ZEND_ACC_PUBLIC)
	{NULL,NULL,NULL}
};

void _register_QEvent(TSRMLS_D)
{
    zend_class_entry ce;
    TSRMLS_FETCH();

    INIT_CLASS_ENTRY(ce,"QEvent",QEvent_methods);
    QEvent_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);

}

static zend_function_entry QLayoutItem_methods[] = {
	ZEND_ME(QLayoutItem,__construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayoutItem,alignment,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayoutItem,hasHeightForWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayoutItem,heightForWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayoutItem,invalidate,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayoutItem,layout,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayoutItem,minimumHeightForWidth,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayoutItem,setAlignment,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayoutItem,spacerItem,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayoutItem,widget,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayoutItem, expandingDirections,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ME(QLayoutItem,geometry,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ME(QLayoutItem,isEmpty,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ME(QLayoutItem,maximumSize,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ME(QLayoutItem,minimumSize,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ME(QLayoutItem,setGeometry,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ME(QLayoutItem,sizeHint,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	{NULL,NULL,NULL}
};


void _register_QLayoutItem(TSRMLS_C)
{
    zend_class_entry ce;
    TSRMLS_FETCH();

    INIT_CLASS_ENTRY(ce,"QLayoutItem",QLayoutItem_methods);
    QLayoutItem_ce_ptr = zend_register_internal_class(&ce TSRMLS_CC);
}

static zend_function_entry QLayout_methods[] = {
	ZEND_ME(QLayout,__construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,expandingDirections,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,geometry,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,isEmpty,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,maximumSize,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QLayout,minimumSize,NULL,ZEND_ACC_PUBLIC)
	//abstract class
	ZEND_ME(QLayout,addItem,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ME(QLayout,count,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	ZEND_ME(QLayout,takeAt,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)

	{NULL,NULL,NULL}
};


void _register_QLayout(TSRMLS_C)
{
   zend_class_entry ce;
   
   //QLayout inherits QLayoutItem and QObject 
   INIT_CLASS_ENTRY(ce,"QLayout",QLayout_methods);
   //Register class and inherits QLayoutItem
   QLayout_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QLayoutItem_ce_ptr,NULL TSRMLS_CC);
   //Inherits QObject
   zend_do_inheritance(QLayout_ce_ptr, QObject_ce_ptr TSRMLS_CC);
}

static zend_function_entry QBoxLayout_methods[] = {
	ZEND_ME(QBoxLayout,__construct,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,sizeHint,NULL,ZEND_ACC_PUBLIC)
	//abstract class
	ZEND_ME(QBoxLayout,addItem,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,count,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,takeAt,NULL,ZEND_ACC_PUBLIC)
	ZEND_ME(QBoxLayout,setGeometry,NULL,ZEND_ACC_PUBLIC)	

	ZEND_ME(QBoxLayout,addLayout,NULL,ZEND_ACC_PUBLIC)	
	ZEND_ME(QBoxLayout,addSpacing,NULL,ZEND_ACC_PUBLIC)	
	ZEND_ME(QBoxLayout,addStretch,NULL,ZEND_ACC_PUBLIC)	
	ZEND_ME(QBoxLayout,addStrut,NULL,ZEND_ACC_PUBLIC)	
	ZEND_ME(QBoxLayout,addWidget,NULL,ZEND_ACC_PUBLIC)	
	ZEND_ME(QBoxLayout,direction,NULL,ZEND_ACC_PUBLIC)	
	ZEND_ME(QBoxLayout,insertLayout,NULL,ZEND_ACC_PUBLIC)	
	ZEND_ME(QBoxLayout,insertSpacing,NULL,ZEND_ACC_PUBLIC)	
	ZEND_ME(QBoxLayout,insertStretch,NULL,ZEND_ACC_PUBLIC)	
	ZEND_ME(QBoxLayout,insertWidget,NULL,ZEND_ACC_PUBLIC)	
	ZEND_ME(QBoxLayout,invalidate,NULL,ZEND_ACC_PUBLIC)	
	ZEND_ME(QBoxLayout,setDirection,NULL,ZEND_ACC_PUBLIC)	
	ZEND_ME(QBoxLayout,setStretchFactor,NULL,ZEND_ACC_PUBLIC)	
	ZEND_ME(QBoxLayout,insertItem,NULL,ZEND_ACC_PROTECTED)	
		
	{NULL,NULL,NULL}
};

void _register_QBoxLayout(TSRMLS_C)
{
   zend_class_entry ce;
    
   INIT_CLASS_ENTRY(ce,"QBoxLayout",QBoxLayout_methods);
   QBoxLayout_ce_ptr = zend_register_internal_class_ex(&ce TSRMLS_CC, QLayout_ce_ptr,NULL TSRMLS_CC);
}

/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

