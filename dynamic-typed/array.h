#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <malloc.h>
#include <strings.h>
#include "types.h"

typedef struct {
	Object *elements_;
	unsigned int len_;
} Array;

// using __THROW means it won't cause any exception and I am sure about it

Array *array_new() __THROW;

void array_free(Array *arr) __THROW;

void array_insert_at_index(Array *arr, void *data, ObjectType type, unsigned index);

void array_push_object(Array *arr, Object obj) __THROW;

void array_push(Array *arr, void *data, ObjectType type) __THROW;

Object array_pop_at_index(Array *arr, unsigned index);

Object array_pop_last(Array *arr);

void array_print(Array *arr) __THROW;

void array_print_all(Array *arr) __THROW;

Object array_to_object(Array *arr) __THROW;

#endif // DYNAMIC_ARRAY_H
