#ifndef TABLE_DATA_H
#define TABLE_DATA_H
#include "dynamic-typed/dynamic-typed.h"
#include "table-rows.h"
#include "table.h"

typedef struct {
	Table *table;
	TableRows *rows;
} TableData;

TableData *table_data_new(Table *table);

void table_data_add_row(TableData *table, Dict *new_row);

void table_data_select_all(TableData *data);

void table_data_free(TableData *data);

#endif // !TABLE_DATA_H
