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

#define COMPILE_DL_PHP_QT
#define PHPQT_CLASS_COUNT 50

#include <iostream>
using namespace std;

#include <zend_interfaces.h>
#include "smoke.h"

#include <QtCore/QTextStream>
#include <QtCore/QVariant>
#include <QtCore/QStack>
#include <QtCore/QString>
#include <QtCore/QMetaMethod>
#include <QtCore/QHash>
#include <QtCore/QCoreApplication>

#include <QtGui/QWidget>
#include <QtGui/QApplication>
#include <QtGui/QLayout>
#include <QtGui/QLCDNumber>
#include <QtGui/QFont>

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

PHP_FUNCTION(check_qobject);

struct smokephp_object {
    Smoke *smoke;
    int classId;
    void *ptr;
    zend_class_entry *ce_ptr;
    zval *zval_ptr;
    QMetaObject* meta;
};

//zend_class_entry* php_qt_generic_class;

static void 		phpqt_destroyHashtable(zend_rsrc_list_entry *rsrc);
smokephp_object* 	phpqt_fetch(zval* this_ptr);
void 				phpqt_register(zval* this_ptr, zend_rsrc_list_entry le);
zval* 				phpqt_callMethod(zval* zend_ptr, char* methodname, zend_uint param_count, zval** params[]);
bool 				phpqt_methodExists(zend_class_entry* ce_ptr, char* methodname);
bool 				phpqt_getMocData(zval* this_ptr, char* classname, const QMetaObject* superdata, QMetaObject* metachar, QString* meta_stringdata, uint* signature);
zval* 				phpqt_fetchZendPtr(const QObject *o);
int					phpqt_metacall(smokephp_object* this_ptr, Smoke::StackItem* args, QMetaObject::Call _c, int _id, void **_a);
char*				phpqt_checkForOperator(const char* fname);
bool				phpqt_zval2qtIsEnd(void *o);
smokephp_object*	phpqt_getSmokePHPObject(void* ptr);
void				phpqt_setSmokePHPObject(smokephp_object* o);
bool				phpqt_SmokePHPObjectExists(smokephp_object* o);

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
bool				smokephp_isConnect(Smoke::Index method);


class SmokeType {
    Smoke::Type *_t;		// derived from _smoke and _id, but cached

    Smoke *_smoke;
    Smoke::Index _id;
public:
    SmokeType() : _t(0), _smoke(0), _id(0) {}
    SmokeType(Smoke *s, Smoke::Index i) : _smoke(s), _id(i) {
	if(_id < 0 || _id > _smoke->numTypes) _id = 0;
	_t = _smoke->types + _id;
    }
    // default copy constructors are fine, this is a constant structure

    // mutators
    void set(Smoke *s, Smoke::Index i) {
	_smoke = s;
	_id = i;
	_t = _smoke->types + _id;
    }

    // accessors
    Smoke *smoke() const { return _smoke; }
    Smoke::Index typeId() const { return _id; }
    const Smoke::Type &type() const { return *_t; }
    unsigned short flags() const { return _t->flags; }
    unsigned short elem() const { return _t->flags & Smoke::tf_elem; }
    const char *name() const { return _t->name; }
    Smoke::Index classId() const { return _t->classId; }

    // tests
    bool isStack() const { return ((flags() & Smoke::tf_ref) == Smoke::tf_stack); }
    bool isPtr() const { return ((flags() & Smoke::tf_ref) == Smoke::tf_ptr); }
    bool isRef() const { return ((flags() & Smoke::tf_ref) == Smoke::tf_ref); }
    bool isConst() const { return (flags() & Smoke::tf_const); }
    bool isClass() const {
	if(elem() == Smoke::t_class)
	    return classId() ? true : false;
	return false;
    }

    bool operator ==(const SmokeType &b) const {
	const SmokeType &a = *this;
	if(a.name() == b.name()) return true;
	if(a.name() && b.name() && qstrcmp(a.name(), b.name()) == 0)
	    return true;
	return false;
    }
    bool operator !=(const SmokeType &b) const {
	const SmokeType &a = *this;
	return !(a == b);
    }

};

ZEND_METHOD(QString, __toString);
ZEND_METHOD(QString, compare);
ZEND_METHOD(QString, utf16);
ZEND_METHOD(QString, constData);
ZEND_METHOD(QString, insert);
ZEND_METHOD(QString, clear);
ZEND_METHOD(QString, setUtf16);
ZEND_METHOD(QString, prepend);
ZEND_METHOD(QString, trimmed);
ZEND_METHOD(QString, chop);
ZEND_METHOD(QString, leftJustified);
ZEND_METHOD(QString, squeeze);
ZEND_METHOD(QString, count);
ZEND_METHOD(QString, fromAscii);
ZEND_METHOD(QString, toLongLong);
ZEND_METHOD(QString, toUpper);
ZEND_METHOD(QString, __construct);
ZEND_METHOD(QString, normalized);
ZEND_METHOD(QString, fromUtf16);
ZEND_METHOD(QString, isRightToLeft);
ZEND_METHOD(QString, setNum);
ZEND_METHOD(QString, endsWith);
ZEND_METHOD(QString, number);
ZEND_METHOD(QString, localeAwareCompare);
ZEND_METHOD(QString, section);
ZEND_METHOD(QString, isSimpleText);
ZEND_METHOD(QString, size);
ZEND_METHOD(QString, simplified);
ZEND_METHOD(QString, toUInt);
ZEND_METHOD(QString, toUShort);
ZEND_METHOD(QString, truncate);
ZEND_METHOD(QString, toAscii);
ZEND_METHOD(QString, length);
ZEND_METHOD(QString, right);
ZEND_METHOD(QString, push_front);
ZEND_METHOD(QString, toUtf8);
ZEND_METHOD(QString, toULongLong);
ZEND_METHOD(QString, indexOf);
ZEND_METHOD(QString, fromRawData);
ZEND_METHOD(QString, constEnd);
ZEND_METHOD(QString, left);
ZEND_METHOD(QString, fromLocal8Bit);
ZEND_METHOD(QString, startsWith);
ZEND_METHOD(QString, remove);
ZEND_METHOD(QString, isEmpty);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, vsprintf);
ZEND_METHOD(QString, toFloat);
ZEND_METHOD(QString, isDetached);
ZEND_METHOD(QString, reserve);
ZEND_METHOD(QString, toULong);
ZEND_METHOD(QString, toShort);
ZEND_METHOD(QString, split);
ZEND_METHOD(QString, setUnicode);
ZEND_METHOD(QString, fromLatin1);
ZEND_METHOD(QString, data);
ZEND_METHOD(QString, toLatin1);
ZEND_METHOD(QString, end);
ZEND_METHOD(QString, contains);
ZEND_METHOD(QString, resize);
ZEND_METHOD(QString, replace);
ZEND_METHOD(QString, fromUtf8);
ZEND_METHOD(QString, toLong);
ZEND_METHOD(QString, detach);
ZEND_METHOD(QString, append);
ZEND_METHOD(QString, mid);
ZEND_METHOD(QString, toDouble);
ZEND_METHOD(QString, fill);
ZEND_METHOD(QString, rightJustified);
ZEND_METHOD(QString, toLower);
ZEND_METHOD(QString, lastIndexOf);
ZEND_METHOD(QString, unicode);
ZEND_METHOD(QString, at);
ZEND_METHOD(QString, begin);
ZEND_METHOD(QString, push_back);
ZEND_METHOD(QString, capacity);
ZEND_METHOD(QString, constBegin);
ZEND_METHOD(QString, toLocal8Bit);
ZEND_METHOD(QString, toInt);
ZEND_METHOD(QString, isNull);