#include "table.h"
#include "table-attr.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

Table *table_new(char *table_name, TableAttrArray *attr) {
	Table *table = malloc(sizeof(Table));
	table->name = malloc(sizeof(strlen(table_name)));
	strcpy(table->name, table_name);
	table->Attributes = attr;
	return table;
}

void describe_table(Table *table) {
	printf("\x1b[38;5;079mTable \x1b[38;5;123m%s\x1b[0m {\n", table->name);
	for (unsigned i = 0; i < table->Attributes->len_; i++) {
		printf("\t");
		table_attr_print(table->Attributes->arr[i]);
	}
	printf("}\n");
}

void table_free(Table *table) {
	free(table->name);
	table_attr_array_free(table->Attributes);
	free(table);
}
