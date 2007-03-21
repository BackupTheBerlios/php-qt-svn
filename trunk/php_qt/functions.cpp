/*!
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2006 
 * Thomas Moenicke <thomas.moenicke at kdemail.net>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#include "php_qt.h"

extern Smoke *qt_Smoke;
extern Smoke::Index qstring;
extern zend_class_entry* qstring_ce;
extern Smoke::Index qobject;
extern zend_class_entry* qobject_ce;

/* Every user-visible function in PHP should document itself in the source */
/* proto string confirm_php_qt_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_php_qt_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char string[256];

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

  	len = sprintf(string, "Congratulations! Module PHP-Qt is now compiled into PHP.", arg);
	RETURN_STRINGL(string, len, 1);

}

/*!
 *	PHP userspace functions
 */

/*!
 *  emulates the Qt SIGNAL() macro
 */

PHP_FUNCTION(SIGNAL)
{
    const char* string;
    int string_len;
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

/*!
 *  emulates the Qt SLOT() macro
 */

PHP_FUNCTION(SLOT)
{
    const char* string;
    int string_len;
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

/*!
 *  emits a signal
 */

PHP_FUNCTION(emit)
{
    const char* string;
    int string_len;
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


/**
 *	simply returns the first parameter because objects are casted automatically in smokephp_convertReturn(...)
 *
 */

PHP_FUNCTION(qobject_cast){

    zval *obj;
    zval *cast_type;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"zz|", &obj, &cast_type) == FAILURE) {
        php_error(E_WARNING,"error while casting object, wrong parameters");
        return; 
    }

	ZVAL_ZVAL(return_value, obj, 0, 0);
    return;

}

/*!
 *	tr() returns QObject::tr()
 *
 */

PHP_FUNCTION(tr)
{
    const char* string;
    int string_len;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"s",&string,&string_len)) {
        return;
    }

	smokephp_object* o = (smokephp_object*) emalloc(sizeof(smokephp_object));
	o->ptr = new QString(QObject::tr(string));
	o->smoke = qt_Smoke;
	o->classId = 0;		// QString is not in smoke
	o->ce_ptr = qstring_ce;
	o->zval_ptr = return_value;

	object_init_ex(return_value, qstring_ce);
	zend_rsrc_list_entry le;
	le.ptr = o;
	phpqt_register(return_value, le);
	phpqt_setSmokePHPObject(o);
	phpqt_setZvalPtr(o, o->zval_ptr);
    return;
}

/*!
 *	check_qobject()
 *
 */


void check_object(zval* zobject)
{

	if(!phpqt_SmokePHPObjectExists(zobject)) {
	    php_error(E_ERROR,"Object is not registered.");
	}

	smokephp_object* o = phpqt_getSmokePHPObjectFromZval(zobject);

	cout << "PHP-Qt object \n(" << endl;

	cout << "\t       zval => " << zobject << endl;
	cout << "\tclass entry => " << Z_OBJCE_P(zobject)->name << endl;
	cout << "\t  ref count => " << zobject->refcount << endl;
	cout << "\t     is_ref => " << zobject->is_ref << endl;
	cout << "\t       type => " << Z_TYPE_P(zobject) << endl;

	cout << endl;

	cout << "\t      smokeobj => " << o << endl;
	cout << "\t         Smoke => " << o->smoke << endl;
	cout << "\t       classId => " << o->classId << endl;
	cout << "\t        Qt ptr => " << o->ptr << endl;
	cout << "\t        ce_ptr => " << o->ce_ptr << endl;
	cout << "\t      zval_ptr => " << o->zval_ptr << endl;
	cout << "\t  QMetaObject* => " << o->meta << endl;

	cout << ")" << endl;

}

PHP_FUNCTION(check_qobject)
{

    zval* zobject;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,"o",&zobject)) {
        return;
    }

    check_object(zobject);
}
