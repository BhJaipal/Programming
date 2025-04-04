#include "dynamic-typed.h"

typedef struct {
	char *name;
	Object value;
} DataPair;

DataPair data_pair_new(char *name, Object val);
void data_pair_free(DataPair pair);

typedef struct {
	DataPair *arr;
	unsigned len_;
} DataDict;

DataDict *data_dict_new();
void data_dict_free(DataDict *arr);
void data_dict_insert_at_index(DataDict *arr, char* name, Object value, int index);
void data_dict_push(DataDict *arr, char* name, Object value);
DataPair data_dict_pop_at_index(DataDict *arr, int index);
DataPair data_dict_pop_last(DataDict *arr);
