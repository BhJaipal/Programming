#ifndef TABLE_DATA_H
#define TABLE_DATA_H
#include "table.h"
#include "table-rows.h"

typedef struct {
	Table *table;
	TableRows *rows;
} TableData;

TableData *table_data_new(Table *table);

void table_data_add_row(TableData *table, Array *new_row);

void table_data_select_all(TableData *data);

#endif // !TABLE_DATA_H
