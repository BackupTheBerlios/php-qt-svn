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

#ifndef PHPQT_INTERNALS_H
#define PHPQT_INTERNALS_H

class QMetaObject;
class QString;

#include "php_qt.h"

namespace PHPQt {

void 				destroyHashtable(zend_rsrc_list_entry *rsrc);

zval* 				callPHPMethod(zval* zend_ptr, char* methodname, zend_uint param_count, zval** params);
bool 				methodExists(zend_class_entry* ce_ptr, char* methodname);
bool 				getMocData(zval* this_ptr, char* classname, const QMetaObject* superdata, QMetaObject* metachar, QString* meta_stringdata, uint* signature);
int					metacall(smokephp_object* this_ptr, Smoke::StackItem* args, QMetaObject::Call _c, int _id, void **_a);
char*				checkForOperator(const char* fname);

void* 				getQtObjectFromZval(zval* this_ptr);
smokephp_object* 	getSmokePHPObjectFromZval(zval* this_ptr);
smokephp_object*	getSmokePHPObjectFromQt(void* QtPtr);
void				setSmokePHPObject(smokephp_object* o);
bool 				SmokePHPObjectExists(zval* this_ptr);
bool				SmokePHPObjectExists(void* ptr);

bool				unmapSmokePHPObject(zval* o);

smokephp_object*	createObject(zval* zval_ptr, void* ptr, zend_class_entry* ce = NULL, Smoke::Index classId = 0);
smokephp_object*	createOriginal(zval* zval_ptr, void* ptr);

} // namespace PHPQt

#endif
