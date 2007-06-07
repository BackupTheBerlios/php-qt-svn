/*!
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2006 - 2007
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

#include "phpqt_internals.h"

#include <QtCore/QMetaMethod>
#include <zend.h>
#include "smoke.h"
#include "php_qt.h"

extern zend_object_handlers php_qt_handler;
extern zend_class_entry* qstring_ce;

zend_class_entry* qobject_ce;
QHash<void*, smokephp_object*> SmokeQtObjects;
QHash<zend_object_handle, smokephp_object*> obj_x_smokephp;


/*!
 *	PHP-Qt internal functions
 */

int
PHPQt::metacall(smokephp_object* so, Smoke::StackItem* args, QMetaObject::Call _c, int _id, void **_a)
{
	QMetaObject* d = so->meta;
//	int offset = d->methodOffset();
	int offset = d->methodCount();

#if MOC_DEBUG
	cout << "qt_metacall " << so->ce_ptr->name << endl;
#endif

	// call the C++ one
	if(_id < offset){
		// find parent
		Smoke::Index parent = so->smoke->inheritanceList[so->smoke->classes[so->classId].parents];

		// methodId
		Smoke::Index nameId = so->smoke->idMethodName("qt_metacall$$?");
		Smoke::Index method = so->smoke->findMethod(so->classId, nameId);

		if(method > 0){
			Smoke::Method &m = so->smoke->methods[so->smoke->methodMaps[method].method];
			Smoke::ClassFn fn = so->smoke->classes[m.classId].classFn;
			Smoke::StackItem i[4];
			i[1].s_enum = _c;
			i[2].s_int = _id;
			i[3].s_voidp = (void*) args[3].s_voidp;
			(*fn)(m.method, so->ptr, i);

#if MOC_DEBUG
			cout << "\tcall Qt method " << so->ce_ptr->name << "::" << PQ::smoke()->methodNames[method] << endl;
#endif

			if((int)i[0].s_int < 0)
				return i[0].s_int;

		} else {
			// should never happen
			php_error(E_ERROR, "Cannot find %s::qt_metacall() method\n", d->className());
		}

	}

    if (_c != QMetaObject::InvokeMetaMethod) {
		return _id;
	}

	// try the PHP one
	// eg _q_buttonPressed(), breaking at the first bracket
	char* method_name = estrdup((d->method(_id)).signature());

    for(int i = 0; i < strlen(method_name); i++){
#define LEFT_PARENTHESIS 40
        if(method_name[i] == LEFT_PARENTHESIS){
            method_name[i] = 0;
            break;
        }
    }

    // is a Slot
    if(d->method(_id).methodType() == QMetaMethod::Slot){

        int j = 0;
        zval*** args = (zval***) safe_emalloc(2, sizeof(zval*), 0);
        QList<QByteArray> qargs = d->method(_id).parameterTypes();
        for(int i = 0; i < qargs.count(); i++){
            zval *arg;
            MAKE_STD_ZVAL(arg);

            // invoke to zend types
            if(!strncmp("int",(const char*) qargs[i],3)){

                ZVAL_LONG(arg, *reinterpret_cast< int*>(_a[i+1]));
            } else if(!strncmp("char*",(const char*) qargs[i],5)){
                ZVAL_STRING(arg, *reinterpret_cast< char**>(_a[i+1]), 1);
            } else if(!strncmp("bool",(const char*) qargs[i],4)){
                ZVAL_BOOL(arg, *reinterpret_cast< bool*>(_a[i+1]));
            } else if(!strncmp("double",(const char*) qargs[i],4)){
                ZVAL_DOUBLE(arg, *reinterpret_cast< double*>(_a[i+1]));
            } else {
                    // must be an object
                    void* ptr = *reinterpret_cast< QObject**>(_a[1]);

                    PHPQt::createObject(arg, ptr, qobject_ce);
            }

            args[j++] = &arg;

        }

#if MOC_DEBUG
    cout << "\tcall PHP method " << so->ce_ptr->name << "::" << method_name << endl;
#endif

         PHPQt::callPHPMethod(so->zval_ptr, method_name, j, *args);

    // is a signal
    } else {
        void *_b[] = { 0, _a[1] };
        QMetaObject::activate((QObject*) so->ptr, d, 0, _b);
    }

	efree(method_name);
    return _id;

}

void
PHPQt::destroyHashtable(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
#ifdef DEBUG
	php_error(E_ERROR,"Hashtable destroyed. Shutdown PHP-Qt now.");
#endif
}

bool
PHPQt::methodExists(zend_class_entry* ce_ptr, char* methodname)
{

	if(ce_ptr == NULL){
	  php_error(E_ERROR,"methodExists fatal error: no class entry");
	}

	char* lcname = zend_str_tolower_dup(methodname, strlen(methodname));

	if(zend_hash_exists(&ce_ptr->function_table, lcname, strlen(methodname)+1)){
		return true;
	}

	efree(lcname);
	return false;

}


zval*
PHPQt::callPHPMethod(zval* this_ptr, char* methodName, zend_uint param_count, zval** args)
{

	if(this_ptr == NULL){
	  php_error(E_ERROR,"callmethod fatal error: object does not exists");
	}

    zval *function_name;
    MAKE_STD_ZVAL(function_name);
    ZVAL_STRING(function_name,methodName,1);

    zval* retval;
    MAKE_STD_ZVAL(retval);

    if(call_user_function(EG(function_table),&this_ptr,function_name,retval,param_count,args) == FAILURE){
    	smokephp_object* o = PHPQt::getSmokePHPObjectFromZval(this_ptr);
    	php_error(E_ERROR, "PHP-Qt could not call method %s::%s", o->ce_ptr->name, methodName);
    }

    return retval;
}

/*!
 *	creates metaObject data
 *  example: "QWidget\0\0value\0test(int)\0"
 *	@param	zval*				this_ptr	pointer of the zval
 *	@param	char*				classname	name of the class
 *	@param	const QMetaObject*	superdata	superdata
 *	@return	QMetaObject*
 */

bool
PHPQt::getMocData(zval* this_ptr, char* classname, const QMetaObject* superdata, QMetaObject* meta, QString* meta_stringdata, uint* signature){

    /// readout the slots table
    zval **slotdata;

    zval *zslot;
    zslot = zend_read_property(Z_OBJCE_P(this_ptr),this_ptr,"slots",5,0);

    zval *zsignal;
    zsignal = zend_read_property(Z_OBJCE_P(this_ptr),this_ptr,"signals",7,0);

    if((zslot)->type==IS_ARRAY && (zsignal)->type==IS_ARRAY ) {


        HashTable* slots_hash = HASH_OF(zslot);
        HashTable* signals_hash = HASH_OF(zsignal);

        char* assocKey;
        ulong numKey;

        int signaturecount;
        signaturecount = 2 + strlen(classname);

#if MOC_DEBUG
	QString *qr = new QString();
	cout << "+== begin metaobject dump ==+\n";
	cout << "\t" << classname << "\n\t1 0 0 0 " << zend_hash_num_elements(slots_hash)+zend_hash_num_elements(signals_hash) << " 10 0 0 0 0" << endl << endl;
#endif

		/// write class signature
		signature[0] = 1;
		signature[1] = 0;
		signature[2] = 0;
		signature[3] = 0;
		signature[4] = zend_hash_num_elements(slots_hash)+zend_hash_num_elements(signals_hash);
		signature[5] = 10;
		signature[6] = 0;
		signature[7] = 0;
		signature[8] = 0;
		signature[9] = 0;

		/// write classname
		meta_stringdata->append(classname);
 		meta_stringdata->append(QChar::Null);
 		meta_stringdata->append(QChar::Null);

		int i;
		i = 10;

		zend_hash_internal_pointer_reset(signals_hash);

		while(zend_hash_has_more_elements(signals_hash) == SUCCESS){

			/// read slot from hashtable
			zend_hash_get_current_key(signals_hash,&assocKey,&numKey,0);
			zend_hash_get_current_data(signals_hash,(void**)&slotdata);

#if MOC_DEBUG
			qr->append(Z_STRVAL_PP(slotdata));
			qr->append(" ");
			cout << "\t" << signaturecount << "8 8 8 0x05 ::s" << endl;
#endif

			meta_stringdata->append(Z_STRVAL_PP(slotdata));
			meta_stringdata->append(QChar::Null);

			zend_hash_move_forward(signals_hash);

			/// write slot signature
			signature[i++] = signaturecount;
			signature[i++] = 8;
			signature[i++] = 8;
			signature[i++] = 8;
			signature[i++] = 0x05;

			signaturecount += strlen(Z_STRVAL_PP(slotdata)) + 1;

		}

    	zend_hash_internal_pointer_reset(slots_hash);

		while(zend_hash_has_more_elements(slots_hash) == SUCCESS){

			/// read slot from hashtable
			zend_hash_get_current_key(slots_hash,&assocKey,&numKey,0);
			zend_hash_get_current_data(slots_hash,(void**)&slotdata);

#if MOC_DEBUG
			qr->append(Z_STRVAL_PP(slotdata));
			qr->append(" ");
			cout << "\t" << signaturecount << "8 8 8 0x0a ::s" << endl;
#endif

			meta_stringdata->append(Z_STRVAL_PP(slotdata));
			meta_stringdata->append(QChar::Null);

			zend_hash_move_forward(slots_hash);

			/// write slot signature
			signature[i++] = signaturecount;
			signature[i++] = 8;
			signature[i++] = 8;
			signature[i++] = 8;
			signature[i++] = 0x0a;

			signaturecount += strlen(Z_STRVAL_PP(slotdata)) + 1;

		}
#if MOC_DEBUG
		cout << qr->toAscii().constData() << endl;
		cout << "+== end metaobject dump ==+" << endl;
#endif
		return true;
	} else {
		return false;
  	}
}

char*
PHPQt::checkForOperator(const char* fname){
	return (char*) fname;
}

bool
PHPQt::SmokePHPObjectExists(zval* this_ptr)
{
	return obj_x_smokephp.contains(this_ptr->value.obj.handle);
}

smokephp_object*
PHPQt::getSmokePHPObjectFromZval(zval* this_ptr)
{

	if(this_ptr == NULL){
	  php_error(E_ERROR,"fatal: object does not exists and could not be fetched, %s",Z_OBJCE_P(this_ptr)->name);
	}

	// value.obj.handle
 	return (smokephp_object*) obj_x_smokephp.value(this_ptr->value.obj.handle);

}

void*
PHPQt::getQtObjectFromZval(zval* this_ptr){
	smokephp_object* o = getSmokePHPObjectFromZval(this_ptr);
	return o->ptr;
}

smokephp_object*
PHPQt::getSmokePHPObjectFromQt(void* QtPtr){
	return (smokephp_object*) SmokeQtObjects.value(QtPtr);
}

void
PHPQt::setSmokePHPObject(smokephp_object* o){
	SmokeQtObjects.insert(o->ptr, o);
}

bool
PHPQt::SmokePHPObjectExists(void* ptr){
	return (SmokeQtObjects.find(ptr) != SmokeQtObjects.end());
}

bool
PHPQt::unmapSmokePHPObject(zval* o)
{
	return (bool) obj_x_smokephp.remove(o->value.obj.handle);
}

/**
 *	marshall_basetypes.h marshall_to_php<SmokeClassWrapper>(Marshall *m)
 */

smokephp_object*
PHPQt::createObject(zval* zval_ptr, void* ptr, zend_class_entry* ce, Smoke::Index classId){

	Q_ASSERT (zval_ptr);
	Q_ASSERT (ptr);

 	if(!ce) {
 		qFatal("no class entry!");
 	}

	if(classId == QSTRING_CLASSID)
	{
		ce = qstring_ce;
	} else if (classId == 0)
	{
		qDebug("\nno class id");
		check_qobject(zval_ptr);
		qFatal("php object creation failed");
	}

	Z_TYPE_P(zval_ptr) = IS_OBJECT;
	object_init_ex(zval_ptr, ce);

	smokephp_object* o = (smokephp_object*) emalloc(sizeof(smokephp_object));
	o->allocated = true;
	o->ptr = ptr;
	o->zval_ptr = zval_ptr;
	o->ce_ptr = ce;
	o->parent_ce_ptr = ce;
 	o->classId = classId;
	o->smoke = PQ::smoke();

	Z_OBJ_HT_P(zval_ptr) = &php_qt_handler;
	setSmokePHPObject(o);
	zval_add_ref(&zval_ptr);

	obj_x_smokephp.insert(zval_ptr->value.obj.handle, o);

	return o;

}

smokephp_object*
PHPQt::createOriginal(zval* zval_ptr, void* ptr)
{
	smokephp_object* o = getSmokePHPObjectFromQt(ptr);
/* 		ZVAL_ZVAL(zval_ptr, o->zval_ptr, 1, 0);
// 		zval_ptr->is_ref = 1;
		Z_OBJ_HT_P(zval_ptr) = &php_qt_handler;
		zval_x_smokephp.insert(zval_ptr, o);*/
	Z_OBJ_HT_P(zval_ptr) = &php_qt_handler;
	zval_ptr = o->zval_ptr;
	zval_add_ref(&zval_ptr);

	return o;
}

