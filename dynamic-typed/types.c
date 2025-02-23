#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DYNAMIC_TYPE_FN(EL_NAME, el_name, EL_TYPE, ASSIGNED, ENUM_TYPE) \
	EL_NAME##El *el_name##_el_new(EL_TYPE data) {		\
		EL_NAME##El *el = malloc(sizeof(EL_NAME##El));  \
		el->value = data;								\
		ASSIGNED;										\
		return el;										\
	}													\
	EL_TYPE el_name##_el_get_value(void *elem) {		\
		return ((EL_NAME##El *)elem)->value;			\
	}													\
	EL_TYPE el_name##_el_unref(void *elem) {			\
		EL_TYPE value = ((EL_NAME##El *)elem)->value;   \
		free (elem);									\
		return value;									\
	}													\
	Object el_name##_to_object (EL_TYPE value) {		\
		Object objt = {el_name##_el_new(value), ENUM_TYPE}; \
		return objt;										\
	}
	

/**
 * Generated Output for int:
	IntEl *int_el_new(EL_TYPE data) {
		IntEl *el = malloc(sizeof(IntEl));
		el->value = data;
		;
		return el;
	}
	int int_el_get_value(void *elem) {
		return ((IntEl *)elem)->value;
	}
	int int_el_unref(void *elem) {
		int value = ((IntEl *)elem)->value;
		free (elem);
		return value;
	}
*/
DYNAMIC_TYPE_FN(Int, int, int,,INT);
void int_print(void *elem) {
	printf("\x1b[38;5;156m%d\x1b[0m",
		((IntEl *)elem)->value);
}

/**
 * Generated Output for string:
	StringEl *string_el_new(char * data) {
		StringEl *el = malloc(sizeof(StringEl));
		el->value = data;
		//! Next 2 lines are by ASSIGNED parameter in DYNAMIC_TYPEEM_TYPE
		el->value = malloc(sizeof(char[strlen(data)]));
		strcpy(el->value, data);;
		return el;
	}
	char * int_el_get_value(void *elem) {
		return ((StringEl *)elem)->value;
	}
	char * int_el_unref(void *elem) {
		char * value = ((StringEl *)elem)->value;
		free (elem);
		return value;
	}
*/
DYNAMIC_TYPE_FN(String, string, char *,
		el->value = malloc(sizeof(char[strlen(data)]));
		strcpy(el->value, data);,
	STRING
);
void string_print(void *elem) {					\
	printf("\x1b[38;5;173m\"%s\"\x1b[0m",		\
		((StringEl *)elem)->value);				\
}

/**
 * Generated Output for float:
	FLoatEl *int_el_new(FloatEl data) {
		FloatEl *el = malloc(sizeof(FloatEl));
		el->value = data;
		;
		return el;
	}
	float int_el_get_value(void *elem) {
		return ((FloatEl *)elem)->value;
	}
	float int_el_unref(void *elem) {
		float value = ((FloatEl *)elem)->value;
		free (elem);
		return value;
	}
*/
DYNAMIC_TYPE_FN(Float, float, float,,FLOAT);
void float_print(void *elem) {
	printf("\x1b[38;5;156m%f\x1b[0m",
		((FloatEl *)elem)->value);
}
