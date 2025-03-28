#ifndef DYNAMIC_TYPES_H
#define DYNAMIC_TYPES_H

#define DYNAMIC_ELEM_TYPE(Name, EL_TYPE)		\
	typedef struct {							\
		EL_TYPE *(*new)(EL_TYPE data);			\
		EL_TYPE (*get_value)(Object elem);		\
		void (*unref)(Object elem);				\
		Object (*to_object)(EL_TYPE value);		\
		void (*print)(Object elem);				\
	} _##Name##_s;								\
	extern _##Name##_s Name;

#define DYNAMIC_ELEM_INIT(Name, name)	\
	_##Name##_s Name= {			\
		name##_new,						\
		name##_get_value,				\
		name##_unref,					\
		name##_to_object,				\
		name##_print					\
	};

typedef enum {
	STRING,
	INT,
	FLOAT,
	ARRAY,
	DICT
} ObjectType;

typedef struct {
	void *data;
	ObjectType type;
	char isNull;
} Object;

DYNAMIC_ELEM_TYPE(Int, int);

typedef struct {
	char *(*new)(char *data);
	char *(*get_value)(Object elem);
	void (*unref)(Object elem);
	Object (*to_object)(char *value);
	void (*print)(Object elem);
} _String_s;
extern _String_s String;

DYNAMIC_ELEM_TYPE(Float, float);

#define NullObject (Object){Int.new(0), INT, 1}

void warn(char *message, ...);

void error(char *message, ...);

/** params: Object, StrFn, FloatFn, DictFn, ArrayFn, DefFn */
#define SWITCH_ON_OBJ(OBJ, STR_FN, FLOAT_FN, DICT_FN, ARR_FN, DEFAULT_INT_FN) { \
	Object obj = (Object)OBJ;												\
	switch (obj.type){														\
		case STRING:														\
			STR_FN(obj);													\
			break;															\
		case FLOAT:															\
			FLOAT_FN(obj);													\
			break;															\
		case DICT:															\
			DICT_FN(obj.data);												\
			break;															\
		case ARRAY:															\
			ARR_FN(obj.data);												\
			break;															\
		default:															\
			DEFAULT_INT_FN(obj);											\
			break;															\
	}																		\
}

#endif
