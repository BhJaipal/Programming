#include "table-data.h"
#include "table-attr.h"
#include "table-rows.h"
#include "table.h"
#include <stdio.h>
#include <string.h>

TableData *table_data_new(Table *table) {
	TableData *table_data = malloc(sizeof(TableData));
	table_data->table = table;
	table_data->rows = table_row_new();
	return table_data;
}

void table_data_add_row(TableData *table, Array *new_row) {
	for (unsigned i = 0; i < table->table->Attributes->len_; i++) {
		TableAttr attr = table->table->Attributes->arr[i];
		if (attr.type != new_row->elements_[i].type) {
			error("%s and %s has different types\n", attr.name, new_row->elements_[i].data);
		}
	}
	table_row_push(table->rows, new_row);
}

void table_data_select_all(TableData *data) {
	printf("+-------------------+-------------------+\n");
	for (unsigned i =0; i < data->table->Attributes->len_; i++) {
		TableAttr attr = data->table->Attributes->arr[i];
		printf("|%*s%*s ", 10 + (int)strlen(attr.name)/2, attr.name, 10 - (int)strlen(attr.name), "");
	}
	printf("|\n+-------------------+-------------------+\n");
	for (unsigned i = 0; i < data->rows->len; i++) {
		Array arr = data->rows->rows[i];
		printf("|  ");
		for (unsigned j =0; j < arr.len_; j++) {
			int lim = 9;
			switch (arr.elements_[j].type) {
				case STRING:
					{
						char out[10];
						strcpy(out, String.get_value(arr.elements_[j]));
						printf("%*s%*s", lim+(int)strlen(out)/2, out, lim-(int)strlen(out), "");
					}
					break;
				case FLOAT:
					{
						char out[10];
						sprintf(out, "%f", Float.get_value(arr.elements_[j]));
						printf("%*s%*s", lim+(int)strlen(out)/2, out, lim-(int)strlen(out), "");
					}
					break;
				default:
					{
						char out[5];
						sprintf(out, "%d", Int.get_value(arr.elements_[j]));
						printf("%*s%*s", lim+(int)strlen(out)/2, out, lim-(int)strlen(out), "");
					}
					break;
			}
			printf("  |");
		}
		printf("\n");
	}
	printf("+-------------------+-------------------+\n");
}

void table_data_free(TableData *data) {
	table_free(data->table);
	table_row_free(data->rows);
	free(data);
}
