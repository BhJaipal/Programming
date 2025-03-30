#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include "types.h"

typedef struct {
	Object *elements_;
	unsigned int len_;
} Array;

Array *array_new();

void array_free(Array *arr);

/**
 * if index >= arr->len_, it pushes obj to end and gives you warning about it too
 * else inserts it to that index
 */
void array_insert_at_index(Array *arr, Object obj, int index);

void array_push(Array *arr, Object obj);

/**
 * Gives error if index >= arr->len_ (also if array is empty)
 * else pops elem
 */
Object array_pop_at_index(Array *arr, int index);

/**
 * Gives error if array is empty
 */
Object array_pop_last(Array *arr);

void array_print(Array *arr);

void array_print_all(Array *arr);

Object array_to_object(Array *arr);

#endif // DYNAMIC_ARRAY_H
