#ifndef TABLE_ROWS_H
#define TABLE_ROWS_H
#include "dynamic-typed/array.h"

typedef struct {
	Array *rows;
	unsigned len;
} TableRows;

TableRows *table_row_new();

void table_row_free(TableRows *arr);

/**
 * if index >= arr->len_, it pushes obj to end and gives you warning about it too
 * else inserts it to that index
 */
void table_row_insert_at_index(TableRows *arr, Array *obj, unsigned index);

void table_row_push(TableRows *arr, Array *obj);

/**
 * Gives error if index >= arr->len_ (also if table_row is empty)
 * else pops elem
 */
Array table_row_pop_at_index(TableRows *arr, unsigned index);

/**
 * Gives error if table_row is empty
 */
Array table_row_pop_last(TableRows *arr);

#endif // !TABLE_ROWS_H
