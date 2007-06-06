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


#include "zend_handlers.h"
#include "php_qt.h"
#include "ext/standard/php_string.h"

extern QStack<QByteArray*> methodNameStack;
extern zend_class_entry* activeCe;

zend_object_handlers php_qt_handler;
zend_object_handlers zend_orig_handler;
int (*originalConstantMethodHandler)(ZEND_OPCODE_HANDLER_ARGS);
opcode_handler_t *phpqt_original_opcode_handlers;
opcode_handler_t phpqt_opcode_handlers[PHPQT_OPHANDLER_COUNT];


/**
 *	proxy handler
 */

union _zend_function*
ZendHandlers::proxyHandler(zval **obj_ptr, char* methodName, int methodName_len TSRMLS_DC)
{
    union _zend_function *fbc;

    // overwritten protected Qt methods wont work until we cheat here
    int method_len = strlen(methodName);
    char* lc_method_name = (char*) do_alloca(method_len+1);
    zend_str_tolower_copy(lc_method_name, methodName, method_len);
    // get the zend object and the function pointer
    zend_object *zobj = zend_objects_get_address(*obj_ptr TSRMLS_CC);
    if (zend_hash_find(&zobj->ce->function_table, lc_method_name, method_len+1, (void **)&fbc) != FAILURE)
    {
		if(fbc->common.fn_flags & ZEND_ACC_PROTECTED)
		{
			if(PQ::smoke()->idMethodName(methodName) > 0)
			{
				fbc->common.fn_flags = ZEND_ACC_PUBLIC;
			}
		}
    }

    // a try for non-Qt objects
    fbc = zend_orig_handler.get_method(obj_ptr, methodName, methodName_len);
    if(!fbc) // maybe a Qt object
    {
        methodNameStack.push(new QByteArray(methodName));
	    // call proxy
	    fbc = zend_orig_handler.get_method(obj_ptr, "proxyMethod", 11);
    }

    return fbc;
}

/*!
 *	constants handler
 */

int
ZendHandlers::constantHandler(ZEND_OPCODE_HANDLER_ARGS) {

	zend_op *opline = EX__(opline);
	zend_class_entry *ce = NULL;
	zval **value;

	if (IS_CONST == IS_UNUSED) {
		if (!zend_get_constant(opline->op2.u.constant.value.str.val, opline->op2.u.constant.value.str.len, &EX_T(opline->result.u.var).tmp_var TSRMLS_CC)) {
			zend_error(E_NOTICE, "Use of undefined constant %s - assumed '%s'",
						opline->op2.u.constant.value.str.val,
						opline->op2.u.constant.value.str.val);
			EX_T(opline->result.u.var).tmp_var = opline->op2.u.constant;
			zval_copy_ctor(&EX_T(opline->result.u.var).tmp_var);
		}
		execute_data->opline++;
	}

	ce = EX_T(opline->op1.u.var).class_entry;

	if (zend_hash_find(&ce->constants_table, opline->op2.u.constant.value.str.val, opline->op2.u.constant.value.str.len+1, (void **) &value) == SUCCESS) {
		zval_update_constant(value, (void *) 1 TSRMLS_CC);
		EX_T(opline->result.u.var).tmp_var = **value;
		zval_copy_ctor(&EX_T(opline->result.u.var).tmp_var);
	} else {
		// enums are methods here
		Smoke::Index method = PQ::smoke()->findMethod(ce->name, opline->op2.u.constant.value.str.val);
		if(method <= 0) // smoke could not find one
		    php_error(E_ERROR, "undefined class constant '%s'", opline->op2.u.constant.value.str.val);

		method = PQ::smoke()->methodMaps[method].method;

		// get the Qt value
		Smoke::Stack args = (Smoke::Stack) safe_emalloc(1, sizeof(Smoke::Stack), 0);
		void* dummy; // dummy here
		smokephp_callMethod(dummy, method, args);

		// write the zend return value
		zval* return_value;
		MAKE_STD_ZVAL(return_value);
		ZVAL_LONG(return_value, args[0].s_enum);
		EX_T(opline->result.u.var).tmp_var = *return_value;
		zval_copy_ctor(&EX_T(opline->result.u.var).tmp_var);

		efree(args);

	}

	execute_data->opline++;
	return 0;

}

/*!
 *  here we'll try to find a static method defined in Qt and
 *  to assign the staticProxyMethod handler
 *  see ZEND_INIT_STATIC_METHOD_CALL_SPEC_CONST_HANDLER in zend_vm_execute.h
 */

int
ZendHandlers::constantMethodHandler(ZEND_OPCODE_HANDLER_ARGS)
{
	zend_op *opline = EX(opline);
	zend_class_entry *ce = EX_T(opline->op1.u.var).class_entry;
	union _zend_function *fbc;
	zval* function_name;
	char* function_name_strval;
	int function_name_strlen;

	function_name = &opline->op2.u.constant;
	// store the active ce
	activeCe = EX_T(opline->op1.u.var).class_entry;

	if (Z_TYPE_P(function_name) != IS_STRING) {
		zend_error_noreturn(E_ERROR, "Function name must be a string");
	}

	// get method name
  	function_name_strval = zend_str_tolower_dup(function_name->value.str.val, function_name->value.str.len);
 	function_name_strlen = function_name->value.str.len;

	// call proxyMethod if method is not defined in userspace
	if(zend_hash_find(&ce->function_table, function_name_strval, function_name_strlen+1, (void**) &fbc) == FAILURE)
	{
		zend_ptr_stack_3_push(&EG(arg_types_stack), EX(fbc), EX(object), NULL);
		zend_bool is_const = (IS_CONST == IS_CONST);

		if(zend_hash_find(&ce->function_table, "staticproxymethod", 18, (void**) &fbc) != FAILURE)
		{

			//! TODO	darn! we have a lowersized string here!
			const char* methodName = PQ::findRealMethodName( function_name->value.str.val );
			methodNameStack.push( new QByteArray( methodName ) );

			EX(fbc) = fbc;

			if(!is_const){ efree(function_name_strval); }
			EX(opline)++;
			ZEND_VM_CONTINUE();

		}

		if(!is_const){ efree(function_name_strval); }

	}  // end try call proxyMethod

  	return originalConstantMethodHandler(execute_data);

}

void
ZendHandlers::installZendHandlers()
{

	// overwrite method handler
	php_qt_handler = *zend_get_std_object_handlers();
	zend_orig_handler = php_qt_handler;
	php_qt_handler.get_method = proxyHandler;

	// overwrite :: operator, see zend_vm_execute.h
	memcpy(phpqt_opcode_handlers, zend_opcode_handlers, sizeof(phpqt_opcode_handlers));
	phpqt_original_opcode_handlers = zend_opcode_handlers;
	zend_opcode_handlers = phpqt_opcode_handlers;
	// ZEND_FETCH_CONSTANT = 99 => 2475
	phpqt_opcode_handlers[(ZEND_FETCH_CONSTANT*25) + 0] = constantHandler;
	// replace and store ZEND_INIT_STATIC_METHOD_CALL_SPEC_CONST_HANDLER
	originalConstantMethodHandler = phpqt_opcode_handlers[2825];
	phpqt_opcode_handlers[2825] = constantMethodHandler;
	phpqt_opcode_handlers[2830] = constantMethodHandler;
	phpqt_opcode_handlers[2835] = constantMethodHandler;
	phpqt_opcode_handlers[2840] = constantMethodHandler;
	phpqt_opcode_handlers[2845] = constantMethodHandler;

}
