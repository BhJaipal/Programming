#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_EL_FN(EL_NAME, el_name, EL_TYPE, ASSIGNED) \
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
ARRAY_EL_FN(Int, int, int,);

/**
 * Generated Output for string:
	StringEl *string_el_new(char * data) {
		StringEl *el = malloc(sizeof(StringEl));
		el->value = data;
		//! Next 2 lines are by ASSIGNED parameter in ARRAY_ELEM_TYPE
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
ARRAY_EL_FN(String, string, char *,
		el->value = malloc(sizeof(char[strlen(data)]));
		strcpy(el->value, data);
);

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
ARRAY_EL_FN(Float, float, float, );

Array *array_new() {
	Array *a = malloc(sizeof(Array));
	a->len_ = 0;
	a->elements_ = malloc(0);
	return a;
}

void array_free(Array *arr) {
	for (int i = 0; i < arr->len_; i++) {
		if (arr->elements_[i].type == String) {
			free(((StringEl *)arr->elements_[i].data)->value);
		}
		free(arr->elements_[i].data);
	}
	arr->len_ = 0;
	free(arr);
}

void array_insert_at_index(Array *arr, void *data, ArrayElemTypes type, unsigned index) {
	if (index < 0) index = -index - 1;
	if (index >= arr->len_) {
		printf("\x1b[1;33mWarning: \x1b[0mIt will push elements to end of array\n");
		array_push(arr, data, type);
		return;
	}
	else if (index == arr->len_ - 1) {
		array_push(arr, data, type);
		return;
	}
	arr->len_++;
	arr->elements_ = realloc(arr->elements_, sizeof(ArrayElement[arr->len_]));
	for (unsigned i = index; i < arr->len_ - 1; i++) {
		arr->elements_[i + 1] = arr->elements_[i];
	}
	ArrayElement el = {data, type};
	arr->elements_[index] = el;
}

void array_push(Array *arr, void *data, ArrayElemTypes type) {
	arr->elements_ = realloc(arr->elements_, sizeof(ArrayElement[arr->len_ + 1]));
	ArrayElement el = {data, type};
	arr->elements_[arr->len_] = el;
	arr->len_++;
}

ArrayElement array_pop_at_index(Array *arr, unsigned index) {
	if (index < 0) index = -index - 1;
	if (index >= arr->len_) {
		printf("\x1b[1;31mError: \x1b[0mIndex out of range\n");
		array_free(arr);
		exit(1);
	}
	if (arr->len_ == 0) {
		printf("\x1b[1;31mError: \x1b[0mArray is empty\n");
		array_free(arr);
		exit(1);
	}
	if (index == arr->len_ - 1)
		return array_pop_last(arr);
	// 0 <= index <= arr->len_ - 2
	ArrayElement elemAtI = arr->elements_[index];
	for (int i = index; i < arr->len_ - 1; i++) {
		arr->elements_[i] = arr->elements_[i + 1];
	}
	arr->elements_[arr->len_ - 1].data = NULL;
	arr->elements_[arr->len_ - 1].type = Int;
	arr->elements_ = realloc(arr->elements_, sizeof(ArrayElement[--arr->len_]));
	return elemAtI;
}

ArrayElement array_pop_last(Array *arr) {
	if (arr->len_ == 0) {
		printf("\x1b[1;31mError: \x1b[0mArray is empty\n");
		array_free(arr);
		exit(1);
	}
	arr->len_--;
	ArrayElement last = arr->elements_[arr->len_];
	arr->elements_ = realloc(arr->elements_, sizeof(ArrayElement[arr->len_]));
	return last;
}

void arrar_print(Array *arr) {
	printf("[ ");
	for (unsigned i = 0; i < arr->len_; i++) {
		if (arr->elements_[i].type == String)
			printf("\e[38;5;173m\"%s\"\e[0m", string_el_get_value(arr->elements_[i].data));
		else if (arr->elements_[i].type == Float)
			printf("\e[38;5;156m%f\e[0m", float_el_get_value(arr->elements_[i].data));
		else
			printf("\e[38;5;156m%d\e[0m", int_el_get_value(arr->elements_[i].data));
		if (i != arr->len_ - 1) printf(", ");
	}
	printf(" ]\n");
}
