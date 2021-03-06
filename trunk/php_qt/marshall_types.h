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

#ifndef MARSHALL_TYPES_H
#define MARSHALL_TYPES_H

#include <QtCore/qstring.h>
#include <QtCore/qobject.h>
#include <QtCore/qmetaobject.h>

#include "marshall.h"
#include "php_qt.h"
#include "smokephp.h"
#include "smoke.h"


Marshall::HandlerFn getMarshallFn(const SmokeType &type);

extern void smokeStackToQtStack(Smoke::Stack stack, void ** o, int items, MocArgument* args);
extern void smokeStackFromQtStack(Smoke::Stack stack, void ** _o, int items, MocArgument* args);

/**
 *	MethodReturnValueBase
 */

class MethodReturnValueBase : public Marshall
{
public:
	MethodReturnValueBase(Smoke *smoke, Smoke::Index meth, Smoke::Stack stack, zval** return_value_ptr);
	const Smoke::Method &method();
	Smoke::StackItem &item();
	Smoke *smoke();
	SmokeType type();
	void next();
	bool cleanup();
	void unsupported();
	zval* var();
	zval* var(zval* zval_ptr);
	zval** return_value_ptr();

protected:
	Smoke *_smoke;
	Smoke::Index _method;
	Smoke::Stack _stack;
	SmokeType _st;
	zval* _retval;
	zval **_return_value_ptr;

	virtual const char *classname();
};

/**
 *	VirtualMethodReturnValue
 */

class VirtualMethodReturnValue : public MethodReturnValueBase {
public:
	VirtualMethodReturnValue(Smoke *smoke, Smoke::Index meth, Smoke::Stack stack, zval* retval);
	Marshall::Action action();

private:
// 	zval _retval2;
};

/**
 *	MethodReturnValue
 */

class MethodReturnValue : public MethodReturnValueBase {
public:
	MethodReturnValue(Smoke *smoke, Smoke::Index meth, Smoke::Stack stack, zval *retval, zval** return_value_ptr);
    Marshall::Action action();

private:
	const char *classname();
};

/**
 *	MethodCallBase
 */

class MethodCallBase : public Marshall
{
public:
	MethodCallBase(Smoke *smoke, Smoke::Index meth,zval** return_value_ptr);
	MethodCallBase(Smoke *smoke, Smoke::Index meth, Smoke::Stack stack, zval** return_value_ptr);
	Smoke *smoke();
	SmokeType type();
	Smoke::StackItem &item();
	const Smoke::Method &method();
	virtual int items() = 0;
	virtual void callMethod() = 0;
	void next();
	void unsupported();
	zval** return_value_ptr();

protected:
	Smoke *_smoke;
	Smoke::Index _method;
	Smoke::Stack _stack;
	int _cur;
	Smoke::Index *_args;
	bool _called;
	zval ***_sp;
	virtual const char* classname();
	zval** _return_value_ptr;

};

/**
 *	VirtualMethodCall
 */

class VirtualMethodCall : public MethodCallBase {
public:
	VirtualMethodCall(Smoke *smoke, Smoke::Index meth, Smoke::Stack stack, zval* obj, zval **sp, zval** return_value_ptr);
	~VirtualMethodCall();
	Marshall::Action action();
	zval* var();
	zval* var(zval* zval_ptr);
	int items();
	void callMethod();
	bool cleanup();
	bool doAlloc() { return true; }

	bool makeObject;

private:
	zval* _obj;
 	zval **__sp;

};

/**
 *	MethodCall
 */

class MethodCall : public MethodCallBase {
public:
	MethodCall(Smoke *smoke, Smoke::Index method, zval* target, zval ***sp, int items, zval *retval, zval** return_value_ptr);
	~MethodCall();
	Marshall::Action action();
	zval* var();
	zval* var(zval* zval_ptr);
	void callMethod();
	int items();
	bool cleanup();

private:
	zval* _target;
	void *_current_object;
	Smoke::Index _current_object_class;
	zval ***_sp;
	int _items;
	zval *_retval;

	const char *classname();
};

/**
 *	SigSlotBase
 */

class SigSlotBase : public Marshall {
public:
	SigSlotBase(zval*** sp);
	~SigSlotBase();
	const MocArgument &arg();
	SmokeType type();
	Smoke::StackItem &item();
	zval* var();
	Smoke *smoke();
	virtual const char *mytype() = 0;
	virtual void mainfunction() = 0;
	void unsupported();
	void next();

protected:
	MocArgument *_args;
	int _cur;
	bool _called;
	Smoke::Stack _stack;
	int _items;
	zval ***_sp;
};



class EmitSignal : public Marshall {
    QObject *_obj;
    int _id;
	zval * _result;
 public:
    EmitSignal(QObject *obj, int id, int items, MocArgument* mocStack, zval ***sp, zval * result);
    Marshall::Action action();
    Smoke::StackItem &item();
	const char *mytype();
	void emitSignal();
	void mainfunction();
	bool cleanup();
	void next();
	SmokeType type();
	zval* var();
	zval* var(zval* zval_ptr) { return var(); }
	void unsupported();
	Smoke* smoke();
	const MocArgument &arg();
	zval** return_value_ptr(){};

 protected:
	MocArgument *_args;
	int _cur;
	bool _called;
	Smoke::Stack _stack;
	int _items;
	zval ***_sp;
};

class InvokeNativeSlot : public SigSlotBase {
    QObject *_obj;
    int _id;
	zval * _result;
 public:
    InvokeNativeSlot(QObject *obj, int id, int items, zval* args, zval ***sp, zval * result);
    Marshall::Action action();
    Smoke::StackItem &item();
	const char *mytype();
	void invokeSlot();
	void mainfunction();
	bool cleanup();
};

class InvokeSlot : public SigSlotBase {
    zval* _obj;
    int _slotname;
    void **_o;
public:
    InvokeSlot(zval* obj, int slotname, zval*** args, void ** o);
	~InvokeSlot();
    Marshall::Action action();
	const char *mytype();
    bool cleanup();
	void copyArguments();
	void invokeSlot();
	void mainfunction();
};


/**
 *	SignalReturnValue
 *
 *	Converts a C++ value returned by a signal invocation to a PHP
 *	reply type
 */
class SignalReturnValue : public Marshall {
    MocArgument *	_replyType;
    Smoke::Stack _stack;
	zval * _result;
public:
	SignalReturnValue(void ** o, zval * result, MocArgument * replyType)
	{
		_result = result;
		_replyType = replyType;
		_stack = new Smoke::StackItem[1];
		smokeStackFromQtStack(_stack, o, 1, _replyType);
		Marshall::HandlerFn fn = getMarshallFn(type());
		(*fn)(this);
    }

    SmokeType type() {
		return _replyType[0].st;
	}
    Marshall::Action action() { return Marshall::ToZVAL; }
    Smoke::StackItem &item() { return _stack[0]; }
    zval* var() {
    	return _result;
    }

	void unsupported()
	{
		php_error(E_ERROR, "Cannot handle '%s' as signal reply-type", type().name());
    }
	Smoke *smoke() { return type().smoke(); }

	void next() {}

	bool cleanup() { return false; }

	~SignalReturnValue() {
		delete[] _stack;
	}
};


#endif
