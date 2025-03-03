#include "typed-array.h"
#include <malloc.h>

#define TYPED_ARRAY_NEW(Name, name)			\
Name##Array *name##_array_new() {					\
	Name##Array *a = malloc(sizeof(Name##Array)); \
	a->len_ = 0;							\
	a->arr = malloc(0);						\
	return a;								\
}

#define TYPED_ARRAY_FREE(Name, name)		\
void name##_array_free(Name##Array *arr) {	\
	for (int i = 0; i < arr->len_; i++) {	\
		name##_free(arr->arr[i]);			\
	}										\
	free (arr->arr);						\
	arr->len_ = 0;							\
	free(arr);								\
}

#define TYPED_ARRAY_ADD(Name, name)			\
void name##_array_insert_at_index(Name##Array *arr, Name data, unsigned index) {\
	if (index < 0) index = -index - 1;					\
	if (index >= arr->len_) {							\
		warn("It will push elements to end of array\n");\
		name##_array_push(arr, data);		\
		return;								\
	}										\
	else if (index == arr->len_ - 1) {		\
		name##_array_push(arr, data);		\
		return;								\
	}										\
	arr->len_++;							\
	arr->arr = realloc(arr->arr, sizeof(Name[arr->len_]));	\
	for (unsigned i = index; i < arr->len_ - 1; i++) {		\
		arr->arr[i + 1] = arr->arr[i];						\
	}														\
	arr->arr[index] = data;									\
}															\
															\
void name##_array_push(Name##Array *arr, Name obj) {		\
	arr->arr = realloc(arr->arr,							\
		sizeof(Name[arr->len_ + 1]));						\
	arr->arr[arr->len_] = obj;								\
	arr->len_++;											\
}															\

#define TYPED_ARRAY_REMOVE(Name, name)								\
Name name##array_pop_at_index(Name##Array *arr, unsigned index) {	\
	if (index < 0) index = -index - 1;					\
	if (index >= arr->len_) {							\
		name##_array_free (arr);						\
		error("Index out of range\n");					\
	}													\
	if (arr->len_ == 0) {								\
		name##_array_free (arr);						\
		error("Array is empty\n");						\
	}													\
	if (index == arr->len_ - 1)							\
		return name##_array_pop_last (arr);				\
	/* 0 <= index <= arr->len_ - 2*/					\
	Name elemAtI = arr->arr[index];						\
	for (int i = index; i < arr->len_ - 1; i++) {		\
		arr->arr[i] = arr->arr[i + 1];					\
	}													\
	arr->arr = realloc(arr->arr, sizeof(Name[--arr->len_]));\
	return elemAtI;									\
}													\
Name name##_array_pop_last(Name##Array *arr) {				\
	if (arr->len_ == 0) {							\
		printf("\x1b[1;31mError: \x1b[0mArray is empty\n");\
		name##_array_free(arr);				\
		exit(1);							\
	}										\
	arr->len_--;							\
	Name last = arr->arr[arr->len_];		\
	arr->arr = realloc(arr->arr,			\
		sizeof(Name[arr->len_]));			\
	return last;							\
}
