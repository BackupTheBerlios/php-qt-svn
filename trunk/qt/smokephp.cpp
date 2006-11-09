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
#include "smoke.h"
#include <QMetaMethod>
#include <QHash>
#include <QCoreApplication>
#include <QApplication>

extern Smoke *qt_Smoke;
extern void init_qt_Smoke();

Smoke::Index connect1;
Smoke::Index connect2;
Smoke::Index connect3;
Smoke::Index connect4;
Smoke::Index connect5;

class PHPQtSmokeBinding : public SmokeBinding {

public:
    PHPQtSmokeBinding(Smoke *s) : SmokeBinding(s) {}

    virtual void deleted(Smoke::Index, void*) {
            // ignore object deletion
    }
    virtual bool callMethod(Smoke::Index method, void* ptr, Smoke::Stack args, bool /*isAbstract*/) {

		smokephp_object *o = (smokephp_object*) phpqt_getSmokePHPObject(ptr);

		if(!o){
			// no related smokephp_object
			return false;
		}

		const char *methodName = qt_Smoke->methodNames[smoke->methods[method].name];

		// metaobjects
		if(!strcmp(methodName, "metaObject")){
			args[0].s_class = o->meta;
			return true;
		}

		if(!strcmp(methodName, "qt_metacall")){
			phpqt_metacall(o, args, (QMetaObject::Call) args[1].s_enum, args[2].s_int, (void**) args[3].s_voidp);
			return true;
		}
		return false;

    }

    virtual char *className(Smoke::Index classId) {
	// return a new[] copy of the language-specific name of this Smoke class
	// poorly designed function, but oh well. Sorry.

	const char *className = smoke->className(classId);
	char *buf = new char[strlen(className) + 1];
	strcpy(buf, className);
	return buf;
    }
    virtual ~PHPQtSmokeBinding() {}
};

/**
 * 	call init function
 *
 *	@param	-
 *	@return	-
 */

void 
smokephp_init() {

    if (qt_Smoke != 0L) {
	php_error(E_ERROR,"could not initialize smoke");
    }

    init_qt_Smoke();

    if(qt_Smoke->numClasses <= 0){
		php_error(E_ERROR,"could not initialize smoke");
    }

    qt_Smoke->binding = new PHPQtSmokeBinding(qt_Smoke);

}

/*!
 *  @param  const char*     c   class-name 
 *  @param  const char*     m   mangled function-name
 *  @return Smoke::Index        unambiguous method ID
 */
Smoke::Index 
smokephp_getMethod(Smoke *smoke, const char* c, const char* m, Smoke::StackItem** qargs, int argc, zval*** args) {

    Smoke::Index method = smoke->findMethod(c, m);	// qt_Smoke->methods
    Smoke::Index i = smoke->methodMaps[method].method;

    if(i <= 0) {
	    i = -i;		// turn into ambiguousMethodList index
	    while(qt_Smoke->ambiguousMethodList[i]) {

	    	Smoke::Method &methodRef = qt_Smoke->methods[qt_Smoke->ambiguousMethodList[i]];

			if ((methodRef.flags & Smoke::mf_internal) == 0) {
				// try to compare smoke types with the php ones
				bool right = false;
				for(int k=0;k < argc;k++){
					uint type = ((int) ((zval) **args[k]).type);
					switch((qt_Smoke->types[qt_Smoke->argumentList[qt_Smoke->methods[qt_Smoke->ambiguousMethodList[i]].args+k]].flags & Smoke::tf_elem)){
						case Smoke::t_voidp:
							if(type == IS_ARRAY)
								right = true;
							if(type == IS_STRING)
								right = true;
							break;
						case Smoke::t_bool:
							if(type == IS_BOOL)
								right = true;
							break;
						case Smoke::t_char:
						case Smoke::t_uchar:
						case Smoke::t_short:
						case Smoke::t_ushort:
						case Smoke::t_int:
						case Smoke::t_uint:
						case Smoke::t_long:
						case Smoke::t_ulong:
							if(type == IS_LONG)
								right = true;
							break;
						case Smoke::t_float:
						case Smoke::t_double: 
							if(type == IS_DOUBLE)
								right = true;
							break;
						case Smoke::t_enum:
							php_error(E_WARNING,"type enum not yet implemented\n");
							break;
						case Smoke::t_class:
							if(type == IS_OBJECT)
								right = true;
							break;
						default:
							php_error(E_ERROR, "unknown argument type");
							break;
					}
				}
				if(right){
#ifdef DEBUG
					php_error(E_NOTICE, "Ambiguous Method %s::%s => %d, %d", c, m, qt_Smoke->ambiguousMethodList[i], i);
#endif
					return qt_Smoke->ambiguousMethodList[i];
				}
			}
			
			i++;
    	}
    }

    return i;
}

/*!
 *  @param  void*           obj
 *  @param  Smoke::Index    method
 *  @param  Smoke::Stack    qargs
 *  @return void
 */
void
smokephp_callMethod(Smoke *smoke, void *obj, Smoke::Index method, Smoke::Stack qargs) {
    Smoke::Method *m = smoke->methods + method;
    Smoke::ClassFn fn = smoke->classes[m->classId].classFn;
    fn(m->method, obj, qargs);
}

/*!
 * cast argument pointer to the correct type for the specified method argument
 * args[i].s_class = (void*)(typeof(args[i]))(className*)obj
 *
 *  @param  Smoke::Index        method
 *  @param  Smoke::Stack        qargs
 *  @param  Smoke::Index        i
 *  @param  void*               obj
 *  @param  const char*         className
 */
void 
smokephp_smokeCast(Smoke *smoke, Smoke::Index method, Smoke::Stack qargs, Smoke::Index i, void *obj, const char *className) {
    // cast obj from className to the desired type of args[i]
    Smoke::Index arg = smoke->argumentList[
        smoke->methods[method].args + i - 1
    ];
    // cast(obj, from_type, to_type)
    qargs[i].s_class = smoke->cast(obj, smoke->idClass(className), smoke->types[arg].classId);
}

/*!
 *  cast obj to the required type of this, which, dur to multiple-inheritance, could change the pointer-address
 *  from the one returned by new. Puts the pointer in args[0].s_class, even though smoke doesn't do it that way
 *
 *  @param  Smoke::Index        method
 *  @param  Smoke::Stack        qargs
 *  @param  const char*         className
 */
void 
smokephp_smokeCastThis(Smoke *smoke, Smoke::Index method, Smoke::Stack qargs, void *obj, const char *className) {
    qargs[0].s_class = smoke->cast(obj, smoke->idClass(className), smoke->methods[method].classId);
}

/*!
 *  The munging works this way:
 *  $ is a plain scalar
 *  # is an object
 *  ? is a non-scalar (reference to array or hash, undef)
 *
 * data types
 * #define IS_NULL		0
 * #define IS_LONG		1
 * #define IS_DOUBLE	2
 * #define IS_BOOL		3
 * #define IS_ARRAY		4
 * #define IS_OBJECT	5
 * #define IS_STRING	6
 * #define IS_RESOURCE	7
 * #define IS_CONSTANT	8
 * #define IS_CONSTANT_ARRAY	9
 * 
 *  @param  zval***                 args
 *	@param	int						argc
 *  @param  Smoke::StackItem*       qargs
 */

void 
smokephp_convertArgsZendToCxx(zval*** args, int argc, Smoke::StackItem* qargs, QStack<QString*> &methodNameStack) {

    for(int i=0;i<argc;i++){
	    uint type = ((int) ((zval) **args[i]).type);
	    if (type == IS_RESOURCE){
	    } else if (type == IS_ARRAY){
	        // convert array
      	    char** c = new char*[1];
      	    c[0] = "";
      	    qargs[i+1].s_voidp = (void*) c;
			methodNameStack.top()->append("?");
	    } else if (type == IS_BOOL){
    	    qargs[i+1].s_bool = Z_BVAL_PP(args[i]);
            methodNameStack.top()->append("$");
	    } else if (type == IS_LONG){
    	    qargs[i+1].s_short = Z_LVAL_PP(args[i]);
    	    qargs[i+1].s_ushort = Z_LVAL_PP(args[i]);
    	    qargs[i+1].s_int = Z_LVAL_PP(args[i]);
    	    qargs[i+1].s_uint = Z_LVAL_PP(args[i]);
    	    qargs[i+1].s_long = Z_LVAL_PP(args[i]);
    	    qargs[i+1].s_ulong = Z_LVAL_PP(args[i]);
    	    methodNameStack.top()->append("$");
	    } else if (type == IS_DOUBLE){
    	    qargs[i+1].s_double = Z_DVAL_PP(args[i]);
            methodNameStack.top()->append("$");
	    } else if (type == IS_STRING){
    	    qargs[i+1].s_class = emalloc(sizeof(QString)+strlen(Z_STRVAL_PP(args[i]))); // important
    	    qargs[i+1].s_class = new QString(Z_STRVAL_PP(args[i]));
            methodNameStack.top()->append("$");
	    } else if (type == IS_OBJECT){
			smokephp_object *o = phpqt_fetch(((zval*) *args[i]));
            qargs[i+1].s_class = o->ptr;
            // as default QString is not supported in Smoke
            if(!strcmp(Z_OBJCE_P(((zval*) *args[i]))->name, "QString")){
            	qargs[i+1].s_class = new QString(((QString*) o->ptr)->toAscii().constData());
            	methodNameStack.top()->append("$");
            } else {
            	methodNameStack.top()->append("#");
            }
	    } else {
	        php_error(E_ERROR,"Unknown argument or unsupported argument type %d, type %d, exit\n", i, type);
	        exit(FAILURE);
	    }
    }

}

void 
smokephp_convertReturn(Smoke::StackItem *ret_val, const Smoke::Type type, const Smoke::Index ret, zval* return_value){

    smokephp_object* o = (smokephp_object*) emalloc(sizeof(smokephp_object));

    switch((type.flags & Smoke::tf_elem)){
        case Smoke::t_voidp:
            RETVAL_NULL();
            break;
        case Smoke::t_bool:
            RETVAL_BOOL(ret_val->s_bool);
            break;
        case Smoke::t_char:
            RETVAL_STRING((char*)ret_val->s_char, 1);
            break;
        case Smoke::t_uchar:
            RETVAL_STRING((char*)ret_val->s_char, 1);
            break;
        case Smoke::t_short:
            RETVAL_LONG(ret_val->s_short);
            break;
        case Smoke::t_ushort:
            RETVAL_LONG(ret_val->s_ushort);
            break;
        case Smoke::t_int:
            RETVAL_LONG(ret_val->s_int);
            break;
        case Smoke::t_uint:
            RETVAL_LONG(ret_val->s_uint);
            break;
        case Smoke::t_long:
            RETVAL_LONG(ret_val->s_long);
            break;
        case Smoke::t_ulong:
            RETVAL_LONG(ret_val->s_ulong);
            break;
        case Smoke::t_float:
            RETVAL_DOUBLE(ret_val->s_float);
            break;
        case Smoke::t_double:
            RETVAL_DOUBLE(ret_val->s_double);
            break;
        case Smoke::t_enum:
            php_error(E_WARNING,"type enum not implemented\n");
            break;
        case Smoke::t_class:

			// zval already exists
//			if(zval_x_qt.find(o) != zval_x_qt.end()){
			if(phpqt_zval2qtIsEnd(o)){
				return_value = phpqt_fetch_zend_ptr((QObject*) o->ptr);
			// create a new one
			} else {
				
				o->ptr = ret_val->s_class;
				o->smoke = qt_Smoke;

				if(!strcmp((char*) qt_Smoke->classes[qt_Smoke->types[ret].classId].className, "QObject")){
					// cast from, to
					o->ptr = o->smoke->cast(o->ptr, qt_Smoke->idClass("QObject"), qt_Smoke->types[ret].classId);
					object_init_ex(return_value, 
									zend_fetch_class((char*)((QObject*) o->ptr)->metaObject()->className(),
									strlen(((QObject*) o->ptr)->metaObject()->className()), 
									ZEND_FETCH_CLASS_AUTO TSRMLS_DC));
				//
				} else if (!strcmp((char*) qt_Smoke->classes[qt_Smoke->types[ret].classId].className, "QBool")) {
            		RETVAL_BOOL(*((QBool*) ret_val->s_class));
            		return;
				// fallback, already with correct type
				} else {
					object_init_ex(return_value, 
									zend_fetch_class((char*) qt_Smoke->classes[qt_Smoke->types[ret].classId].className,
									strlen(qt_Smoke->classes[qt_Smoke->types[ret].classId].className), 
									ZEND_FETCH_CLASS_AUTO TSRMLS_DC));
				}

				o->zval_ptr = return_value;
				o->ce_ptr = Z_OBJCE_P(return_value);
				o->classId = qt_Smoke->types[ret].classId;
// FIXME:	segfaults here:
//				SmokeToPtr.insert(o->ptr, (long int) o);

				zend_rsrc_list_entry le;
				le.ptr = o;
				phpqt_register(return_value, le);

			}

            return;
        default:
            php_error(E_ERROR,"unknown return type\n");
            return;
    }
    return;
}

void 
smokephp_prepareConnect(zval*** args, int argc, Smoke::StackItem* qargs, const Smoke::Index method){

    int j;

    // second loop: we dont have the method-Id before the first call
    for(j = 0; j < argc; j++){
 	    uint type = ((int) ((zval) **args[j]).type);    // als Macro!
        if (type == IS_STRING) {
        	qargs[j+1].s_voidp = args[j][0]->value.str.val;
        }
    }

}

Smoke::Index
smokephp_findConnect(){

	for(int i=0;i<10000;i++){
		if(qt_Smoke->methodMaps[i].name == qt_Smoke->idMethodName("connect#$#$")){
			connect1 = qt_Smoke->methodMaps[i].method;
		}
		if(qt_Smoke->methodMaps[i].name == qt_Smoke->idMethodName("connect#$#$$")){
			connect2 = qt_Smoke->methodMaps[i].method;
		}
		if(qt_Smoke->methodMaps[i].name == qt_Smoke->idMethodName("connect")){
			connect3 = qt_Smoke->methodMaps[i].method;
		}
		// these are ambiguous methods
		if(qt_Smoke->methodMaps[i].name == qt_Smoke->idMethodName("connect#$$")){
			connect4 = qt_Smoke->methodMaps[i].method;
		}
		if(qt_Smoke->methodMaps[i].name == qt_Smoke->idMethodName("connect#$$$")){
			connect5 = qt_Smoke->methodMaps[i].method;
		}
	}
}

/**
 *	returns the related classId
 *	@todo	caching, SmokeType
 *	@param	char*	classname
 *	@return Smoke::Index
 */

Smoke::Index 
smokephp_getClassId(const char* classname){

	Smoke::Index classId = 0;
	Smoke::Class *p = qt_Smoke->classes;
	while(p++ != qt_Smoke->classes+qt_Smoke->numClasses){
		classId++;
		if(!strcmp(p->className,classname)){
			return classId;
		}
	}
	// should never happen
	php_error(E_ERROR,"fatal: QObject not found\n");
	return 0;

}

bool 
smokephp_isQObject(Smoke *smoke, Smoke::Index classId) {
	if(strcmp(smoke->classes[classId].className, "QObject") == 0)
		return true;
	
	for(Smoke::Index *p = smoke->inheritanceList + smoke->classes[classId].parents;	*p;	p++) {
		if(smokephp_isQObject(smoke, *p))
			return true;
    }
    return false;
}

bool
smokephp_isConnect(Smoke::Index method){

	if(
		method == connect1
		|| method == connect2
		|| method == connect3
		|| method == connect4
		|| method == connect5
	) return true; else return false;

}
