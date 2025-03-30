#include "array.h"
#include "dict.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Array *array_new() {
	Array *a = malloc(sizeof(Array));
	a->len_ = 0;
	a->elements_ = malloc(0);
	return a;
}

void array_free(Array *arr) {
	for (unsigned i = 0; i < arr->len_; i++) {
		SWITCH_ON_OBJ(arr->elements_[i], String.unref, Float.unref, dict_free, array_free, Int.unref);
	}
	free(arr->elements_);
	arr->len_ = 0;
	free(arr);
}

void array_insert_at_index(Array *arr, Object data, int index) {
	if (index < 0) index = -index - 1;
	if ((unsigned)index >= arr->len_) {
		warn("It will push elements to end of array\n");
		array_push(arr, data);
		return;
	}
	else if ((unsigned)index == arr->len_ - 1) {
		array_push(arr, data);
		return;
	}
	arr->len_++;
	arr->elements_ = realloc(arr->elements_, sizeof(Object[arr->len_]));
	for (unsigned i = index; i < arr->len_ - 1; i++) {
		arr->elements_[i + 1] = arr->elements_[i];
	}
	arr->elements_[index] = data;
}

void array_push(Array *arr, Object obj) {
	arr->elements_ = realloc(arr->elements_, sizeof(Object[arr->len_ + 1]));
	arr->elements_[arr->len_] = obj;
	arr->len_++;
}

Object array_pop_at_index(Array *arr, int index) {
	if (index < 0) index = -index - 1;
	if ((unsigned)index >= arr->len_) {
		array_free(arr);
		error("Index out of range\n");
	}
	if (arr->len_ == 0) {
		array_free(arr);
		error("Array is empty\n");
	}
	if ((unsigned)index == arr->len_ - 1)
		return array_pop_last(arr);
	// 0 <= index <= arr->len_ - 2
	Object elemAtI = arr->elements_[index];
	for (unsigned i = index; i < arr->len_ - 1; i++) {
		arr->elements_[i] = arr->elements_[i + 1];
	}
	arr->elements_[arr->len_ - 1].data = NULL;
	arr->elements_[arr->len_ - 1].type = INT;
	arr->elements_ = realloc(arr->elements_, sizeof(Object[--arr->len_]));
	return elemAtI;
}

Object array_pop_last(Array *arr) {
	if (arr->len_ == 0) {
		printf("\x1b[1;31mError: \x1b[0mArray is empty\n");
		array_free(arr);
		exit(1);
	}
	arr->len_--;
	Object last = arr->elements_[arr->len_];
	arr->elements_ = realloc(arr->elements_, sizeof(Object[arr->len_]));
	return last;
}

void array_print(Array *arr) {
	printf("[ ");
	for (unsigned i = 0; i < arr->len_; i++) {
		SWITCH_ON_OBJ(arr->elements_[i], String.print, Float.print, dict_print, array_print, Int.print);
		if (i != arr->len_ - 1) printf(", ");
	}
	printf(" ]");
}

void array_print_all(Array *arr) {
	array_print(arr);
	printf("\nLength: %u\n", arr->len_);
}

Object array_to_object(Array *arr) {
	Object obj = {arr, ARRAY, 0};
	return obj;
}
