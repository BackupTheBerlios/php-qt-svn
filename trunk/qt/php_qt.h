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

#define debug
#define MONITOR

#include <iostream>
using namespace std;

#include <zend_interfaces.h>
#include "smoke.h"

#include <QTextStream>
#include <QVariant>
#include <QWidget>
#include <QStack>
#include <QString>
#include <QMetaMethod>
#include <QHash>
#include <QCoreApplication>
#include <QApplication>

// for older php versions
#ifndef ZEND_MN
#define ZEND_MN ZEND_FN
#endif

#define QOUT()                                              \
    extern QTextStream qout(stdout, QIODevice::WriteOnly);  \

#ifndef NOT_YET_IMPLEMENTED
#define NOT_YET_IMPLEMENTED { php_printf("%s(): functionality not yet implemented\n",get_active_function_name(TSRMLS_C));} 
#endif

#define PHP_QT_REGISTER(object)     \
    zend_rsrc_list_entry le;        \
    le.ptr = object;                \
    phpqt_register(getThis(),le);  \

#define PHP_QT_FETCH()  \
	phpqt_fetch(getThis()) \

#define PHP_QT_FENTRY(zend_name, name_, arg_info_, flags_)	\
    t->fname = (char*) emalloc(strlen(#zend_name)+1); \
    t->fname = #zend_name; \
    t->handler = name_; \
    t->arg_info = arg_info_; \
    t->num_args = (zend_uint) (sizeof(arg_info_)/sizeof(struct _zend_arg_info)-1); \
    t->flags = flags_; \
    t++;

#define PHP_QT_ME(classname, name, arg_info, flags)	PHP_QT_FENTRY(name, ZEND_MN(classname##_##name), arg_info, flags)


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"

PHP_MINIT_FUNCTION(php_qt);
PHP_MSHUTDOWN_FUNCTION(php_qt);
PHP_RINIT_FUNCTION(php_qt);
PHP_RSHUTDOWN_FUNCTION(php_qt);
PHP_MINFO_FUNCTION(php_qt);

PHP_FUNCTION(confirm_php_qt_compiled);	/* For testing, remove later. */

/* emulate SIGNAL(), SLOT() macros */
PHP_FUNCTION(SIGNAL);
PHP_FUNCTION(SLOT);
PHP_FUNCTION(qobject_cast);
PHP_FUNCTION(tr);

struct smokephp_object {
    bool allocated;
    Smoke *smoke;
    int classId;
    void *ptr;
    zend_class_entry *ce_ptr;
    zval *zval_ptr;
    QMetaObject* meta;
};

//zend_class_entry* php_qt_generic_class;

static void 		phpqt_destroy_hashtable(zend_rsrc_list_entry *rsrc);
smokephp_object* 	phpqt_fetch(zval* this_ptr);
void 				phpqt_register(zval* this_ptr, zend_rsrc_list_entry le);
zval* 				phpqt_callmethod(zval* zend_ptr, char* methodname, zend_uint param_count, zval** params[]);
bool 				phpqt_methodExists(zend_class_entry* ce_ptr, char* methodname);
bool 				phpqt_getMocData(zval* this_ptr, char* classname, const QMetaObject* superdata, QMetaObject* metachar, QString* meta_stringdata, uint* signature);
zval* 				phpqt_fetch_zend_ptr(const QObject *o);
int					phpqt_metacall(smokephp_object* this_ptr, Smoke::StackItem* args, QMetaObject::Call _c, int _id, void **_a);
char*				phpqt_checkForOperator(const char* fname);
bool				phpqt_zval2qtIsEnd(void *o);
smokephp_object*	phpqt_getSmokePHPObject(void* ptr);

extern int le_php_qt_hashtype;
extern HashTable php_qt_objptr_hash;

void 				smokephp_convertArgsCxxToZend(zval*** args, int argc, Smoke::StackItem* qargs);
bool 				smokephp_isQObject(Smoke *smoke, Smoke::Index classId);
Smoke::Index 		smokephp_getClassId(const char* classname);
void				smokephp_convertArgsZendToCxx(zval*** args, int argc, Smoke::StackItem* qargs, QStack<QString*> &methodNameStack);
Smoke::Index		smokephp_getMethod(Smoke *smoke, const char* c, const char* m, Smoke::StackItem** qargs, int argc, zval*** args);
void				smokephp_prepareConnect(zval*** args, int argc, Smoke::StackItem* qargs, const Smoke::Index method);
void				smokephp_callMethod(Smoke *smoke, void *obj, Smoke::Index method, Smoke::Stack qargs);
void				smokephp_convertReturn(Smoke::StackItem *ret_val, const Smoke::Type type, const Smoke::Index ret, zval* return_value);
void				smokephp_init();
Smoke::Index		smokephp_findConnect();
smokephp_object*	smokephp_getSmokePHPObject(void* ptr);
bool				smokephp_isConnect(Smoke::Index method);

