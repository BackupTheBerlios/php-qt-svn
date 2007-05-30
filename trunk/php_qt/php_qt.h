/*!
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2006 
 * Thomas Moenicke <thomas.moenicke at kdemail.net>
 * Katrina Niolet <katrina at niolet.name>
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

#ifndef QTPHP_H
#define QTPHP_H

#define PHPQT_VERSION "0.0.4"

#define MONITOR

#define COMPILE_DL_PHP_QT
#define PHPQT_CLASS_COUNT 256
#define QSTRING_CLASSID -1

#include <iostream>
using namespace std;

#include <zend_interfaces.h>
#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"

#include "smoke.h"
#include "smokephp.h"
#include <QtCore/QMetaMethod>
#include <QtCore/QStack>
#include <QtCore/QHash>
#include <QtCore/QTextStream>
#include <QtCore/QVariant>
#include <QtCore/QString>
#include <QtCore/QCoreApplication>
#include <QtGui/QWidget>
#include <QtGui/QApplication>
#include <QtGui/QLayout>
#include <QtGui/QLCDNumber>
#include <QtGui/QFont>
#include <QtCore/QDebug>

// for older php versions
#ifndef ZEND_MN
#define ZEND_MN ZEND_FN
#endif

#define Qnil (zval *) NULL

#define PHP_QT_FETCH()  \
	phpqt_getQtObjectFromZval(getThis()) \

#define PHP_QT_FENTRY(zend_name, name_, arg_info_, flags_)	\
    t->fname = (char*) emalloc(strlen(#zend_name)+1); \
    t->fname = #zend_name; \
    t->handler = name_; \
    t->arg_info = arg_info_; \
    t->num_args = (zend_uint) (sizeof(arg_info_)/sizeof(struct _zend_arg_info)-1); \
    t->flags = flags_; \
    t++;

#define PHP_QT_ME(classname, name, arg_info, flags)	PHP_QT_FENTRY(name, ZEND_MN(classname##_##name), arg_info, flags)

// this is needed for override return_value, see qobject_cast
#if(PHP_MAJOR_VERSION > 5) || (PHP_MAJOR_VERSION == 5 && PHP_MINOR_VERSION > 0)
static
	ZEND_BEGIN_ARG_INFO_EX(phpqt_cast_arginfo, 0, 1, 0)
	ZEND_END_ARG_INFO();
#endif

PHP_MINIT_FUNCTION(php_qt);
PHP_MSHUTDOWN_FUNCTION(php_qt);
PHP_RINIT_FUNCTION(php_qt);
PHP_RSHUTDOWN_FUNCTION(php_qt);
PHP_MINFO_FUNCTION(php_qt);

PHP_FUNCTION(confirm_php_qt_compiled);	/* For testing, remove later. */
/* emulate SIGNAL(), SLOT() macros */
PHP_FUNCTION(SIGNAL);
PHP_FUNCTION(SLOT);
#undef emit
PHP_FUNCTION(emit);
PHP_FUNCTION(qDebug);
PHP_FUNCTION(qWarning);
PHP_FUNCTION(qCritical);
PHP_FUNCTION(qAbs);
PHP_FUNCTION(qRound);
PHP_FUNCTION(qRound64);
PHP_FUNCTION(qMin);
PHP_FUNCTION(qMax);
PHP_FUNCTION(qBound);
PHP_FUNCTION(qPrintable);
PHP_FUNCTION(qobject_cast);
PHP_FUNCTION(tr);
PHP_FUNCTION(check_qobject);
void check_qobject(zval* zobject);

void init_codec();
zval* zstringFromQString(QString * s);

struct smokephp_object {
    bool allocated;
    Smoke *smoke;
    int classId;
    void *ptr;
    zend_class_entry *ce_ptr;
    zend_class_entry *parent_ce_ptr;
    zval *zval_ptr;
    QMetaObject* meta;
};


static void 			phpqt_destroyHashtable(zend_rsrc_list_entry *rsrc);

// void 				phpqt_register(zval* this_ptr, zend_rsrc_list_entry le);
zval* 				phpqt_callPHPMethod(zval* zend_ptr, char* methodname, zend_uint param_count, zval** params[]);
bool 				phpqt_methodExists(zend_class_entry* ce_ptr, char* methodname);
bool 				phpqt_getMocData(zval* this_ptr, char* classname, const QMetaObject* superdata, QMetaObject* metachar, QString* meta_stringdata, uint* signature);
int					phpqt_metacall(smokephp_object* this_ptr, Smoke::StackItem* args, QMetaObject::Call _c, int _id, void **_a);
char*				phpqt_checkForOperator(const char* fname);

void* 				phpqt_getQtObjectFromZval(zval* this_ptr);
smokephp_object* 	phpqt_getSmokePHPObjectFromZval(zval* this_ptr);
smokephp_object*	phpqt_getSmokePHPObjectFromQt(void* QtPtr);
void				phpqt_setSmokePHPObject(smokephp_object* o);
bool 				phpqt_SmokePHPObjectExists(zval* this_ptr);
bool				phpqt_SmokePHPObjectExists(void* ptr);

bool				phpqt_unmapSmokePHPObject(zval* o);

smokephp_object*	phpqt_createObject(zval* zval_ptr, void* ptr, zend_class_entry* ce = NULL, Smoke::Index classId = 0);
smokephp_object*	phpqt_createOriginal(zval* zval_ptr, void* ptr);

const char* 		printType(int type);

extern Smoke* qt_Smoke;
class PQ
{
private:
    PQ();
    PQ(const PQ& cc){}

public:
    ~PQ();
    static inline Smoke* smoke() { return qt_Smoke; }
};

extern int le_php_qt_hashtype;
extern HashTable php_qt_objptr_hash;

bool 				smokephp_isQObject(Smoke::Index classId);
void				smokephp_prepareMethodName(zval*** args, int argc, QStack<QByteArray*> &methodNameStack);
QByteArray* 			smokephp_getSignature(int argc, zval ***argv, MocArgument* mocStack);
Smoke::Index			smokephp_getMethod(const char* c, const char* m, int argc, zval*** args);
void				smokephp_prepareConnect(zval*** args, int argc, Smoke::StackItem* qargs, const Smoke::Index method);
void				smokephp_callMethod(void *obj, Smoke::Index method, Smoke::Stack qargs);
void				smokephp_init();

void* 				transformArray(zval* args);

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

#endif
