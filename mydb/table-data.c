#include "table-data.h"
#include "table-attr.h"
#include "table-rows.h"
#include "dynamic-typed/dict.h"
#include "logging/console-appender.h"
#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TableData *table_data_new(Table *table) {
	TableData *table_data = malloc(sizeof(TableData));
	table_data->table = table;
	table_data->rows = table_row_new();
	return table_data;
}

void table_data_add_row(TableData *table, Dict *new_row) {
	Array *result = array_new();
	for (unsigned i = 0; i < table->table->Attributes->len_; i++) {
		TableAttr attr = table->table->Attributes->arr[i];
		for (unsigned j = 0; j < new_row->len; j++) {
			DictElement obj = new_row->arr[j];
			if (!strcmp(attr.name, String.get_value(obj.key))) {
				if (obj.value.isNull) {
					if (attr.nullable)
						array_push(result, obj.value);
					else {
						array_free(result);
						table_data_free(table);
						ConsoleAppender.log(GenerateLog.error("%s is not nullable", (char *)(obj.key.data)));
						exit(1);
					}
					continue;
				}
				if (attr.type != obj.value.type) {
					array_free(result);
					table_data_free(table);
					ConsoleAppender.log(GenerateLog.error("%s.%s and Object.%s has different types\n", table->table->name, attr.name, String.get_value(obj.key)));
					exit(1);
				} else {
					array_push(result, obj.value);
				}
			}
		}
	}
	table_row_push(table->rows, result);
}

void table_data_select_all(TableData *data) {
	printf("+-------------------+-------------------+\n");
	for (unsigned i =0; i < data->table->Attributes->len_; i++) {
		TableAttr attr = data->table->Attributes->arr[i];
		printf("|%*s%*s ", 10 + (int)strlen(attr.name)/2, attr.name, 10 - (int)strlen(attr.name), "");
	}
	printf("|\n+-------------------+-------------------+\n");
	for (unsigned i = 0; i < data->rows->len; i++) {
		Array *arr = data->rows->rows[i];
		printf("|  ");
		for (unsigned j =0; j < arr->len_; j++) {
			int lim = 9;
			switch (arr->elements_[j].type) {
				case STRING:
					{
						char out[10];
						strcpy(out, String.get_value(arr->elements_[j]));
						printf("%*s%*s", lim+(int)strlen(out)/2-1, out, lim-(int)strlen(out)+1, "");
					}
					break;
				case FLOAT:
					{
						char out[10];
						sprintf(out, "%f", Float.get_value(arr->elements_[j]));
						printf("%*s%*s", lim+(int)strlen(out)/2, out, lim-(int)strlen(out), "");
					}
					break;
				default:
					{
						char out[10];
						if (arr->elements_[j].isNull)
							printf("%*s%*s", 11, "NULL", 6, "");
						else {
							sprintf(out, "%d", Int.get_value(arr->elements_[j]));
							printf("%*s%*s", lim+(int)strlen(out)/2, out, lim-(int)strlen(out), "");
						}
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
