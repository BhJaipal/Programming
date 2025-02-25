#include "types.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define DYNAMIC_TYPE_FN(el_name, EL_TYPE, ENUM_TYPE)	\
	EL_TYPE *el_name##_new(EL_TYPE data) {				\
		EL_TYPE *el = malloc(sizeof(EL_TYPE));			\
		*el = data;										\
		return el;										\
	}													\
	EL_TYPE el_name##_get_value(Object elem) {			\
		return *(EL_TYPE *)elem.data;					\
	}													\
	void el_name##_unref (Object elem) {				\
		free(elem.data);								\
	}													\
	Object el_name##_to_object (EL_TYPE value) {		\
		Object objt = {el_name##_new(value), ENUM_TYPE};\
		return objt;									\
	}

DYNAMIC_TYPE_FN(int, int,INT);
void int_print(Object elem) {
	printf("\x1b[38;5;156m%d\x1b[0m",
		int_get_value(elem));
}

char *string_new(char *data) {
	char *el = malloc(sizeof(char[strlen(data)]));
	strcpy(el, data);
	return el;
}
char *string_get_value(Object elem) {
	return (elem.data);
}
void string_unref(Object elem) {
	free(elem.data);
}
Object string_to_object(char *value) {
	Object objt = {string_new(value), STRING};
	return objt;
}

void string_print(Object elem) {
	printf("\x1b[38;5;173m\"%s\"\x1b[0m",
		((char *)elem.data));
}

DYNAMIC_TYPE_FN(float, float,FLOAT);
void float_print(Object elem) {
	printf("\x1b[38;5;156m%f\x1b[0m",
		float_get_value(elem));
}
