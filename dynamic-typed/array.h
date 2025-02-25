#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <malloc.h>
#include <strings.h>
#include "types.h"

typedef struct {
	Object *elements_;
	unsigned int len_;
} Array;

Array *array_new();

void array_free(Array *arr);

void array_insert_at_index(Array *arr, Object obj, unsigned index);

void array_push(Array *arr, Object obj);

Object array_pop_at_index(Array *arr, unsigned index);

Object array_pop_last(Array *arr);

void array_print(Array *arr);

void array_print_all(Array *arr);

Object array_to_object(Array *arr);

#endif // DYNAMIC_ARRAY_H
