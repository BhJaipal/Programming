#include "dynamic-typed/dynamic-typed.h"
#include "logging/console-appender.h"
#include "table-rows.h"
#include <stdio.h>
#include <stdlib.h>

TableRows *table_row_new() {
	TableRows *row = malloc(sizeof(TableRows));
	row->len = 0;
	row->rows = malloc(0);
	return row;
}

void table_row_free(TableRows *arr) {
	for (unsigned i = 0; i < arr->len; i++) { array_free(arr->rows[i]); }
	free(arr);
}

void table_row_insert_at_index(TableRows *arr, Array *obj, int index) {
	if (index < 0) index = -index - 1;
	if ((unsigned)index >= arr->len) {
		warn("It will push elements to end of array\n");
		table_row_push(arr, obj);
		return;
	} else if ((unsigned)index == arr->len - 1) {
		table_row_push(arr, obj);
		return;
	}
	arr->len++;
	arr->rows = realloc(arr->rows, sizeof(Array[arr->len]));
	for (unsigned i = index; i < arr->len - 1; i++) {
		arr->rows[i + 1] = arr->rows[i];
	}
	arr->rows[index] = obj;
}

void table_row_push(TableRows *arr, Array *obj) {
	arr->rows = realloc(arr->rows, sizeof(Array[arr->len + 1]));
	arr->rows[arr->len] = obj;
	arr->len++;
}

/**
 * Gives error if index >= arr->len_ (also if table_row is empty)
 * else pops elem
 */
Array *table_row_pop_at_index(TableRows *arr, int index) {
	if (index < 0) index = -index - 1;
	if ((unsigned)index >= arr->len) {
		table_row_free(arr);
		ConsoleAppender.log(GenerateLog.error("Index out of range\n"), 1);
	}
	if (arr->len == 0) {
		table_row_free(arr);
		ConsoleAppender.log(GenerateLog.error("Array is empty\n"), 1);
	}
	if ((unsigned)index == arr->len - 1) return table_row_pop_last(arr);
	// 0 <= index <= arr->len_ - 2
	Array *elemAtI = arr->rows[index];
	for (unsigned i = index; i < arr->len - 1; i++) {
		arr->rows[i] = arr->rows[i + 1];
	}
	arr->rows = realloc(arr->rows, sizeof(Array[--arr->len]));
	return elemAtI;
}

/**
 * Gives error if table_row is empty
 */
Array *table_row_pop_last(TableRows *arr) {
	if (arr->len == 0) {
		printf("\x1b[1;31mError: \x1b[0mArray is empty\n");
		table_row_free(arr);
		exit(1);
	}
	arr->len--;
	Array *last = arr->rows[arr->len];
	arr->rows = realloc(arr->rows, sizeof(Array[arr->len]));
	return last;
}
