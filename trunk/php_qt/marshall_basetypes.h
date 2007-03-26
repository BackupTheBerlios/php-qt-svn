/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

template <class T> T* smoke_ptr(Marshall *m) { return (T*) m->item().s_voidp; }

template<> bool* smoke_ptr<bool>(Marshall *m) { return &m->item().s_bool; }
template<> signed char* smoke_ptr<signed char>(Marshall *m) { return &m->item().s_char; }
template<> unsigned char* smoke_ptr<unsigned char>(Marshall *m) { return &m->item().s_uchar; }
template<> short* smoke_ptr<short>(Marshall *m) { return &m->item().s_short; }
template<> unsigned short* smoke_ptr<unsigned short>(Marshall *m) { return &m->item().s_ushort; }
template<> int* smoke_ptr<int>(Marshall *m) { return &m->item().s_int; }
template<> unsigned int* smoke_ptr<unsigned int>(Marshall *m) { return &m->item().s_uint; }
template<> long* smoke_ptr<long>(Marshall *m) { 	return &m->item().s_long; }
template<> unsigned long* smoke_ptr<unsigned long>(Marshall *m) { return &m->item().s_ulong; }
template<> float* smoke_ptr<float>(Marshall *m) { return &m->item().s_float; }
template<> double* smoke_ptr<double>(Marshall *m) { return &m->item().s_double; }
template<> void* smoke_ptr<void>(Marshall *m) { return m->item().s_voidp; }

template <class T> T php_to_primitive(zval*);
template <class T> zval* primitive_to_php(T, zval* return_value);

template <class T> 
static void marshall_from_php(Marshall *m) 
{
	zval* obj = m->var();
	(*smoke_ptr<T>(m)) = php_to_primitive<T>(obj);
}

template <class T>
static void marshall_to_php(Marshall *m)
{
	m->setRetval(primitive_to_php<T>( *smoke_ptr<T>(m) , m->retval()));
}

#include "marshall_primitives.h"
//#include "marshall_complex.h"

// Special case marshallers

template <> 
static void marshall_from_php<char *>(Marshall *m) 
{
	zval* obj = m->var();
	m->item().s_voidp = php_to_primitive<char*>(obj);
}

template <>
static void marshall_from_php<SmokeEnumWrapper>(Marshall *m)
{
	zval* v = m->var();

	if (Z_TYPE_P(v) == IS_OBJECT) {
		// A Qt::Enum is a subclass of Qt::Integer, so 'get_qinteger()' can be called ok
	} else {
		m->item().s_enum = (long) Z_LVAL_P(v);
	}

}

template <>
static void marshall_to_php<SmokeEnumWrapper>(Marshall *m)
{
	long val = m->item().s_enum;
}

template <>
static void marshall_from_php<SmokeClassWrapper>(Marshall *m)
{
	zval* v = m->var();

	if(v == NULL) {
		m->item().s_class = 0;
		return;
	}

	if(!phpqt_SmokePHPObjectExists(v)) {
		php_error(E_ERROR, "Invalid type, expecting %s, %s given\n", m->type().name(), zend_zval_type_name(v));
		return;
	}

	smokephp_object *o = phpqt_getSmokePHPObjectFromZval(v);
	if(!o || !o->ptr) {
		if(m->type().isRef()) {
			php_error(E_WARNING, "References can't be nil\n");
			m->unsupported();
		}
					
		m->item().s_class = 0;
		return;
	}

	void *ptr = o->ptr;

//	if((!m->cleanup() && m->type().isStack())) {
	if(m->type().isRef()){
		ptr = construct_copy(o);
#ifdef DEBUG
			php_error(E_WARNING, "copying %s %p to %p\n", resolve_classname(o->smoke, o->classId, o->ptr), o->ptr, ptr);
#endif
	}

	const Smoke::Class &cl = m->smoke()->classes[m->type().classId()];

	ptr = o->smoke->cast(
		ptr,				// pointer
		o->classId,			// from
		o->smoke->idClass(cl.className)	// to
		);

	m->item().s_class = ptr;
	return;
}

template <>
static void marshall_to_php<SmokeClassWrapper>(Marshall *m)
{

	if(m->item().s_voidp == 0) {
		m->setRetval(Qnil);
		return;
	}
	void *p = m->item().s_voidp;

	smokephp_object* o = (smokephp_object*) emalloc(sizeof(smokephp_object));
	zval* obj = m->var();

	if(phpqt_SmokePHPObjectExists(p)) {
	    smokephp_object* o = phpqt_getSmokePHPObjectFromQt(p);
	    ZVAL_ZVAL(obj, o->zval_ptr,0,0);
	    zend_rsrc_list_entry le;
	    le.ptr = o;
	    phpqt_register(obj, le);
	// create a new object
	} else {
	    o->ptr = m->item().s_class;
	    o->smoke = m->smoke();

	    if (Z_TYPE_P(m->var()) == IS_OBJECT) {
		// do nothing
	    } else if(!strcmp((char*) m->smoke()->classes[m->type().classId()].className, "QObject")){
		// cast from, to
		o->ptr = o->smoke->cast(o->ptr, m->smoke()->idClass("QObject"), m->type().classId());
		object_init_ex(obj, 
			    zend_fetch_class((char*)((QObject*) o->ptr)->metaObject()->className(),
			    strlen(((QObject*) o->ptr)->metaObject()->className()), 
			    ZEND_FETCH_CLASS_AUTO TSRMLS_DC));
	    // fallback, already with correct type
	    } else {
		object_init_ex(obj, 
		zend_fetch_class((char*) m->smoke()->classes[m->type().classId()].className,
				strlen(m->smoke()->classes[m->type().classId()].className), 
				ZEND_FETCH_CLASS_AUTO TSRMLS_DC));
	    }

	    Z_TYPE_P(m->var()) = IS_OBJECT;
	    o->zval_ptr = obj;
	    o->ce_ptr = Z_OBJCE_P(obj);
	    o->parent_ce_ptr = o->ce_ptr;
	    o->classId = m->type().classId();

	    if(!phpqt_SmokePHPObjectExists(o->ptr))
		phpqt_setSmokePHPObject(o);

	    zend_rsrc_list_entry le;
	    le.ptr = o;
	    phpqt_register(obj, le);

//	    if(m->type().isConst() && m->type().isRef()) {
	    if(m->type().isRef()) {
		p = construct_copy( o );
#ifdef DEBUG
			const char * classname = o->ce_ptr->name;
			php_error(E_WARNING, "copying %s %p to %p\n", classname, o->ptr, p);
#endif

		if(p) {
			o->ptr = p;
			o->allocated = true;
		}
	}

#ifdef DEBUG
		php_error(E_WARNING, "allocating %s %p -> %p\n", classname, o->ptr, (void*)obj);
#endif

	if(m->type().isStack()) {
		o->allocated = true;
	}

	}
}

template <>
static void marshall_to_php<char *>(Marshall *m)
{
	char *sv = (char*)m->item().s_voidp;
	zval* obj;
	if(sv) {
	    ZVAL_STRING(obj,sv,/*duplicate*/ 1);
	} else {
	    obj = Qnil;
	}
	if(m->cleanup())
		delete[] sv;

	m->setRetval(obj);
}

template <>
static void marshall_to_php<unsigned char *>(Marshall *m)
{
	m->unsupported();
}
