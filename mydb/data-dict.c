#include "data-dict.h"
#include <stdio.h>
#include <stdlib.h>

DataPair data_pair_new(char *name, Object val) {
	return (DataPair){name, val};
}
DataDict *data_dict_new() {
	DataDict *a = malloc(sizeof(DataDict));
	a->len_ = 0;
	a->arr = malloc(0);
	return a;
}

void data_dict_free(DataDict *arr) {
	free (arr->arr);
	arr->len_ = 0;
	free(arr);
}

void data_dict_insert_at_index(DataDict *arr, char* name, Object value, int index) {\
	if (index < 0) index = -index - 1;
	if ((unsigned)index >= arr->len_) {
		warn("It will push elements to end of array\n");\
		data_dict_push(arr, name, value);
		return;
	}
	else if ((unsigned)index == arr->len_ - 1) {
		data_dict_push(arr, name, value);
		return;
	}
	arr->len_++;
	arr->arr = realloc(arr->arr, sizeof(DataPair[arr->len_]));
	for (unsigned i = index; i < arr->len_ - 1; i++) {
		arr->arr[i + 1] = arr->arr[i];
	}
	arr->arr[index] = data_pair_new(name, value);
}

void data_dict_push(DataDict *arr, char* name, Object value) {
	arr->arr = realloc(arr->arr,
		sizeof(DataPair[arr->len_ + 1]));
	arr->arr[arr->len_] = data_pair_new(name, value);
	arr->len_++;
}

DataPair data_pair_pop_at_index(DataDict *arr, int index) {
	if (index < 0) index = -index - 1;
	if ((unsigned)index >= arr->len_) {
		data_dict_free (arr);
		error("Index out of range\n");
	}
	if (arr->len_ == 0) {
		data_dict_free (arr);
		error("Array is empty\n");
	}
	if ((unsigned)index == arr->len_ - 1)
		return data_dict_pop_last (arr);
	/* 0 <= index <= arr->len_ - 2*/
	DataPair elemAtI = arr->arr[index];
	for (unsigned i = index; i < arr->len_ - 1; i++) {
		arr->arr[i] = arr->arr[i + 1];
	}
	arr->arr = realloc(arr->arr,
			sizeof (DataPair[--arr->len_]));
	return elemAtI;
}
DataPair data_dict_pop_last(DataDict *arr) {
	if (arr->len_ == 0) {
		printf("\x1b[1;31mError:x1b[0mArray is empty\n");
		data_dict_free(arr);
		exit(1);
	}
	arr->len_--;
	DataPair last = arr->arr[arr->len_];
	arr->arr = realloc(arr->arr,
		sizeof(DataPair[arr->len_]));
	return last;
}
