/***************************************************************************
    marshall_types.cpp - Derived from the QtRuby and PerlQt sources, see AUTHORS
                         for details
                             -------------------
    begin                : March 21 2007
    copyright            : (C) 2007 by Thomas Moenicke
    email                : tm@php-qt.org
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "marshall_types.h"

void
smokeStackToQtStack(Smoke::Stack stack, void ** o, int items, MocArgument* args)
{

	for (int i = 0; i < items; i++) {
		Smoke::StackItem *si = stack;
		switch(args[i].argType) {
		case xmoc_bool:
			o[i] = &si->s_bool;
			break;
		case xmoc_int:
			o[i] = &si->s_int;
			break;
		case xmoc_double:
			o[i] = &si->s_double;
			break;
		case xmoc_charstar:
			o[i] = &si->s_voidp;
			break;
		case xmoc_QString:
			o[i] = si->s_voidp;
			break;
		default:
		{
			const SmokeType &t = args[i].st;
			void *p;
			switch(t.elem()) {
			case Smoke::t_bool:
				p = &si->s_bool;
				break;
			case Smoke::t_char:
				p = &si->s_char;
				break;
			case Smoke::t_uchar:
				p = &si->s_uchar;
				break;
			case Smoke::t_short:
				p = &si->s_short;
				break;
			case Smoke::t_ushort:
				p = &si->s_ushort;
				break;
			case Smoke::t_int:
				p = &si->s_int;
				break;
			case Smoke::t_uint:
				p = &si->s_uint;
				break;
			case Smoke::t_long:
				p = &si->s_long;
				break;
			case Smoke::t_ulong:
				p = &si->s_ulong;
				break;
			case Smoke::t_float:
				p = &si->s_float;
				break;
			case Smoke::t_double:
				p = &si->s_double;
				break;
			case Smoke::t_enum:
			{
				// allocate a new enum value
				Smoke::EnumFn fn = SmokeClass(t).enumFn();
				if (!fn) {
					php_error(E_WARNING, "Unknown enumeration %s\n", t.name());
					p = new int((int)si->s_enum);
					break;
				}
				Smoke::Index id = t.typeId();
				(*fn)(Smoke::EnumNew, id, p, si->s_enum);
				(*fn)(Smoke::EnumFromLong, id, p, si->s_enum);
				// FIXME: MEMORY LEAK
				break;
			}
			case Smoke::t_class:
			case Smoke::t_voidp:
				if (strchr(t.name(), '*') != 0) {
					p = &si->s_voidp;
				} else {
					p = si->s_voidp;
				}
				break;
			default:
				p = 0;
				break;
			}
			o[i] = p;
		}
		}
	}
}

void
smokeStackFromQtStack(Smoke::Stack stack, void ** _o, int items, MocArgument* args)
{
	for (int i = 0; i < items; i++) {
		void *o = _o[i];
		switch(args[i].argType) {
		case xmoc_bool:
		stack[i].s_bool = *(bool*)o;
		break;
		case xmoc_int:
		stack[i].s_int = *(int*)o;
		break;
		case xmoc_double:
		stack[i].s_double = *(double*)o;
		break;
		case xmoc_charstar:
		stack[i].s_voidp = o;
		break;
		case xmoc_QString:
		stack[i].s_voidp = o;
		break;
		default:	// case xmoc_ptr:
		{
			const SmokeType &t = args[i].st;
			void *p = o;
			switch(t.elem()) {
			case Smoke::t_bool:
			stack[i].s_bool = **(bool**)o;
			break;
			case Smoke::t_char:
			stack[i].s_char = **(char**)o;
			break;
			case Smoke::t_uchar:
			stack[i].s_uchar = **(unsigned char**)o;
			break;
			case Smoke::t_short:
			stack[i].s_short = **(short**)p;
			break;
			case Smoke::t_ushort:
			stack[i].s_ushort = **(unsigned short**)p;
			break;
			case Smoke::t_int:
			stack[i].s_int = **(int**)p;
			break;
			case Smoke::t_uint:
			stack[i].s_uint = **(unsigned int**)p;
			break;
			case Smoke::t_long:
			stack[i].s_long = **(long**)p;
			break;
			case Smoke::t_ulong:
			stack[i].s_ulong = **(unsigned long**)p;
			break;
			case Smoke::t_float:
			stack[i].s_float = **(float**)p;
			break;
			case Smoke::t_double:
			stack[i].s_double = **(double**)p;
			break;
			case Smoke::t_enum:
			{
				Smoke::EnumFn fn = SmokeClass(t).enumFn();
				if (!fn) {
					php_error(E_WARNING, "Unknown enumeration %s\n", t.name());
					stack[i].s_enum = **(int**)p;
					break;
				}
				Smoke::Index id = t.typeId();
				(*fn)(Smoke::EnumToLong, id, p, stack[i].s_enum);
			}
			break;
			case Smoke::t_class:
			case Smoke::t_voidp:
				if (strchr(t.name(), '*') != 0) {
					stack[i].s_voidp = *(void **)p;
				} else {
					stack[i].s_voidp = p;
				}
			break;
			}
		}
		}
	}
}

/**
 *	MethodReturnValueBase
 */

MethodReturnValueBase::MethodReturnValueBase(Smoke *smoke, Smoke::Index meth, Smoke::Stack stack, zval** return_value_ptr) :
	_smoke(smoke), _method(meth), _stack(stack), _return_value_ptr(return_value_ptr)
{
	identifier = "MethodReturnValueBase";
	_st.set(_smoke, method().ret);
}

const Smoke::Method&
MethodReturnValueBase::method()
{
	return _smoke->methods[_method];
}

Smoke::StackItem&
MethodReturnValueBase::item()
{
	return _stack[0];
}

Smoke *
MethodReturnValueBase::smoke()
{
	return _smoke;
}

SmokeType
MethodReturnValueBase::type()
{
	return _st;
}

void
MethodReturnValueBase::next() {}

bool
MethodReturnValueBase::cleanup()
{
	return false;
}

void
MethodReturnValueBase::unsupported()
{
	php_error(E_ERROR, "Cannot handle '%s' as return-type of %s::%s",
	type().name(),
	classname(),
	_smoke->methodNames[method().name]);
}

zval*
MethodReturnValueBase::var()
{
	return _retval;
}

void
MethodReturnValueBase::setVar(zval* zobj)
{
	_retval = zobj;
}

const char *
MethodReturnValueBase::classname()
{
	return _smoke->className(method().classId);
}

zval**
MethodReturnValueBase::return_value_ptr()
{
	return _return_value_ptr;
}

/**
 *	VirtualMethodReturnValue
 */

VirtualMethodReturnValue::VirtualMethodReturnValue(Smoke *smoke, Smoke::Index meth, Smoke::Stack stack, zval retval) :
	MethodReturnValueBase(smoke,meth,stack,NULL), _retval2(retval)
{
	identifier = "VirtualMethodReturnValue";
	_retval = &_retval2;
	Marshall::HandlerFn fn = getMarshallFn(type());
	(*fn)(this);
}

Marshall::Action
VirtualMethodReturnValue::action()
{
	return Marshall::FromZVAL;
}

/**
 *	MethodReturnValue
 */

MethodReturnValue::MethodReturnValue(Smoke *smoke, Smoke::Index meth, Smoke::Stack stack, zval* retval, zval** return_value_ptr) :
	MethodReturnValueBase(smoke,meth,stack,return_value_ptr)/*, _return_value_ptr(return_value_ptr)*/
{
	identifier = "MethodReturnValue";
	_retval = retval;
	Marshall::HandlerFn fn = getMarshallFn(type());
	(*fn)(this);
}

Marshall::Action
MethodReturnValue::action()
{
	return Marshall::ToZVAL;
}

const char *
MethodReturnValue::classname()
{
	return qstrcmp(MethodReturnValueBase::classname(), "QGlobalSpace") == 0 ? "" : MethodReturnValueBase::classname();
}

/**
 *	MethodCallBase
 */

MethodCallBase::MethodCallBase(Smoke *smoke, Smoke::Index meth,zval** return_value_ptr) :
	_smoke(smoke), _method(meth), _cur(-1), _called(false), _sp(0), _return_value_ptr(return_value_ptr)
{
}

MethodCallBase::MethodCallBase(Smoke *smoke, Smoke::Index meth, Smoke::Stack stack,zval** return_value_ptr) :
	_smoke(smoke), _method(meth), _stack(stack), _cur(-1), _called(false), _sp(0), _return_value_ptr(return_value_ptr)
{
}

Smoke *
MethodCallBase::smoke()
{
	return _smoke;
}

SmokeType
MethodCallBase::type()
{
	return SmokeType(_smoke, _args[_cur]);
}

Smoke::StackItem &
MethodCallBase::item()
{
	return _stack[_cur + 1];
}

const Smoke::Method &
MethodCallBase::method()
{
	return _smoke->methods[_method];
}

void
MethodCallBase::next()
{
	int oldcur = _cur;
	_cur++;
	while(!_called && _cur < items() ) {
		Marshall::HandlerFn fn = getMarshallFn(type());
		(*fn)(this);
		_cur++;
	}

	callMethod();
	_cur = oldcur;
}

void
MethodCallBase::unsupported()
{
	php_error(E_ERROR, "Cannot handle '%s' as argument of %s::%s",
		type().name(),
		classname(),
		_smoke->methodNames[method().name]);
}

const char*
MethodCallBase::classname()
{
	return _smoke->className(method().classId);
}

zval**
MethodCallBase::return_value_ptr()
{
	return _return_value_ptr;
}

/**
 *	VirtualMethodCall
 */

VirtualMethodCall::VirtualMethodCall(Smoke *smoke, Smoke::Index meth, Smoke::Stack stack, zval* obj, zval **sp, zval** return_value_ptr) :
	MethodCallBase( smoke, meth, stack, return_value_ptr), _obj(obj)/*, _sp(sp)*/
{
	__sp = sp;
	identifier = "VirtualMethodCall";
  	_args = _smoke->argumentList + method().args;
}

VirtualMethodCall::~VirtualMethodCall()
{
    delete[] _stack;
}

Marshall::Action
VirtualMethodCall::action()
{
	return Marshall::ToZVAL;
}

zval*
VirtualMethodCall::var()
{
// 	*_sp[_cur] = (zval*) emalloc(sizeof(zval));
	ZVAL_NULL(__sp[_cur]);
    return __sp[_cur];
}

int
VirtualMethodCall::items()
{
	return method().numArgs;
}

void
VirtualMethodCall::callMethod()
{
	if (_called) return;
	_called = true;

	phpqt_callPHPMethod(_obj, (char*) _smoke->methodNames[method().name], items(), __sp);

	zval _retval;
 	VirtualMethodReturnValue r(_smoke, _method, _stack, _retval);
}

bool
VirtualMethodCall::cleanup()
{
	return false;
}

/**
 *	MethodCall
 */

MethodCall::MethodCall(Smoke *smoke, Smoke::Index method, zval* target, zval ***sp, int items, zval *retval, zval** return_value_ptr) :
 	MethodCallBase(smoke,method,return_value_ptr), _target(target), _current_object(0), _sp(sp), _items(items), _retval(retval)
{

	identifier = "MethodCall";
    if(target != NULL)
    {
		if (phpqt_SmokePHPObjectExists(_target))
		{
			smokephp_object *o = phpqt_getSmokePHPObjectFromZval(_target);
			if (o && o->ptr)
			{
				_current_object = o->ptr;
				_current_object_class = o->classId;
			}
		}
	} else {_target = (zval*) emalloc(sizeof(zval));}

    _args = _smoke->argumentList + _smoke->methods[_method].args;
    _items = _smoke->methods[_method].numArgs;

    _stack = new Smoke::StackItem[items + 1];
// 	_retval = retval;
}

MethodCall::~MethodCall()
{
	delete[] _stack;
}

Marshall::Action
MethodCall::action()
{
	return Marshall::FromZVAL;
}

zval*
MethodCall::var()
{
	if (_cur < 0) return _retval;
	return (zval*) *_sp[_cur];
}

void
MethodCall::callMethod() {
	if(_called) return;
	_called = true;

	QString className(_smoke->className(method().classId));

	if (! className.endsWith(_smoke->methodNames[method().name])
		&& Z_TYPE_P(_target) == IS_NULL
		&& !(method().flags & Smoke::mf_static) )
	{
		php_error(E_ERROR, "Instance is not initialized, cannot call %s",
					_smoke->methodNames[method().name]);
	}

	if (Z_TYPE_P(_target) == IS_NULL && !(method().flags & Smoke::mf_static)) {
		php_error(E_ERROR, "%s is not a class method\n", _smoke->methodNames[method().name]);
	}

	Smoke::ClassFn fn = _smoke->classes[method().classId].classFn;
	void *ptr = _smoke->cast(_current_object, _current_object_class, method().classId);
	_items = -1;

	(*fn)(method().method, ptr, _stack);
	MethodReturnValue r(_smoke, _method, _stack, _retval, _return_value_ptr);
}


int
MethodCall::items()
{
	return _items;
}

bool
MethodCall::cleanup()
{
	return true;
}

const char *
MethodCall::classname()
{
	return qstrcmp(MethodCallBase::classname(), "QGlobalSpace") == 0 ? "" : MethodCallBase::classname();
}

/**
 *	SigSlotBase
 */

SigSlotBase::SigSlotBase(zval*** sp) : _cur(-1), _called(false), _sp(sp)
{
	identifier = "SigSlotBase";
	_stack = new Smoke::StackItem[_items -1];
}

SigSlotBase::~SigSlotBase()
{
	delete[] _stack;
}

const MocArgument &
SigSlotBase::arg()
{
	return _args[_cur + 1];
}

SmokeType
SigSlotBase::type()
{
	return arg().st;
}

Smoke::StackItem &
SigSlotBase::item()
{
	return _stack[_cur];
}

zval*
SigSlotBase::var()
{
	return (zval*) *_sp[_cur];
}

Smoke *
SigSlotBase::smoke()
{
	return type().smoke();
}

void
SigSlotBase::unsupported()
{
	php_error(E_ERROR, "Cannot handle '%s' as %s argument\n", type().name(), mytype() );
}

void
SigSlotBase::next()
{
	int oldcur = _cur;
	_cur++;

	while(!_called && _cur < _items - 1) {
		Marshall::HandlerFn fn = getMarshallFn(type());
		(*fn)(this);
		_cur++;
	}
	mainfunction();
	_cur = oldcur;
}

/**
 *	SlotReturnValue
 *
 *	Converts a zval* returned by a slot invocation to a Qt slot
 *	reply type
 */

class SlotReturnValue : public Marshall {
    MocArgument *	_replyType;
    Smoke::Stack _stack;
	zval* _result;
public:
	SlotReturnValue(void ** o, zval* result, MocArgument * replyType)
	{
		_result = result;
		_replyType = replyType;
		_stack = new Smoke::StackItem[1];
		Marshall::HandlerFn fn = getMarshallFn(type());
		(*fn)(this);
		// Save any address in zeroth element of the arrary of 'void*'s passed to
		// qt_metacall()
		void * ptr = o[0];
		smokeStackToQtStack(_stack, o, 1, _replyType);
		// Only if the zeroth element of the array of 'void*'s passed to qt_metacall()
		// contains an address, is the return value of the slot needed.
		if (ptr != 0) {
			*(void**)ptr = *(void**)(o[0]);
		}
    }

    SmokeType type() {
		return _replyType[0].st;
	}
    Marshall::Action action() { return Marshall::FromZVAL; }
    Smoke::StackItem &item() { return _stack[0]; }
    zval* var() {
    	return _result;
    }

	void unsupported()
	{
		php_error(E_ERROR, "Cannot handle '%s' as slot reply-type", type().name());
    }
	Smoke *smoke() { return type().smoke(); }

	void next() {}

	bool cleanup() { return false; }

	~SlotReturnValue() {
		delete[] _stack;
	}

	zval** return_value_ptr(){};

};

/**
 *	InvokeSlot
 *	TODO
 */

InvokeSlot::InvokeSlot(zval* obj, int slotname, zval*** args, void ** o) : SigSlotBase(args),
    _obj(obj), _slotname(slotname), _o(o)
{
	identifier = "InvokeSlot";
	_sp = (zval ***) safe_emalloc(sizeof(zval), _items - 1, 0);
	_sp = args;
	copyArguments();
}

InvokeSlot::~InvokeSlot()
{
	free(_sp);
}

Marshall::Action
InvokeSlot::action()
{
	return Marshall::ToZVAL;
}

const char *
InvokeSlot::mytype()
{
	return "slot";
}

bool
InvokeSlot::cleanup()
{
	return false;
}

void
InvokeSlot::copyArguments()
{
	smokeStackFromQtStack(_stack, _o + 1, _items - 1, _args + 1);
}

void
InvokeSlot::invokeSlot()
{
	if (_called) return;
	_called = true;
 	zval* result = phpqt_callPHPMethod(_obj, (char*) PQ::smoke()->methodNames[PQ::smoke()->methods[_slotname].name], _items - 1, *_sp);
	if (_args[0].argType != xmoc_void) {
		SlotReturnValue r(_o, result, _args);
	}
}

void
InvokeSlot::mainfunction()
{
	invokeSlot();
}

/**
 *	EmitSignal
 */

EmitSignal::EmitSignal(QObject *obj, int id, int items, MocArgument *mocStack, zval ***sp, zval * result) :
    _obj(obj), _id(id)
{
	identifier = "EmitSignal";
	_items = items + 1;
	_args = mocStack;
	_id = id;
	_sp = sp;
	_result = result;
}

Marshall::Action
EmitSignal::action()
{
	return Marshall::FromZVAL;
}

Smoke::StackItem &
EmitSignal::item()
{
	return _stack[_cur];
}

const char *
EmitSignal::mytype()
{
	return "signal";
}

void
EmitSignal::emitSignal()
{

	if (_called) return;
	_called = true;

	void ** o = new void*[_items];
	smokeStackToQtStack(_stack, o + 1, _items - 1, _args + 1);
	_obj->metaObject()->activate(_obj, _id, o);

	if (_args[0].argType != xmoc_void) {
//		SignalReturnValue r(o, _result, _args);
	}

	delete[] o;
}

void
EmitSignal::mainfunction()
{
	emitSignal();
}

bool
EmitSignal::cleanup()
{
	return true;
}

SmokeType
EmitSignal::type()
{
	return arg().st;
}

zval*
EmitSignal::var()
{
	return (zval*) *_sp[_cur];
}

Smoke *
EmitSignal::smoke()
{
	return type().smoke();
}

void
EmitSignal::unsupported()
{
	php_error(E_ERROR, "Cannot handle '%s' as %s argument\n", type().name(), mytype() );
}

const MocArgument &
EmitSignal::arg()
{
	return _args[_cur + 1];
}

void
EmitSignal::next()
{
	int oldcur = _cur;
	_cur++;

	while(!_called && _cur < _items - 1) {
		Marshall::HandlerFn fn = getMarshallFn(type());
		(*fn)(this);
		_cur++;
	}
	mainfunction();
	_cur = oldcur;
}

