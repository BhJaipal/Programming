#include "table-attr.h"
#include "table-data.h"
#include "table.h"
#include <stdio.h>

int main() {
	TableAttrArray *tattArr = table_attr_array_new();
	table_attr_array_push(tattArr, table_attr_new("name", STRING, 0));
	table_attr_array_push(tattArr, table_attr_new("age", INT, 1));
	Table *table = table_new("Human", tattArr);

	printf("by describe_table() => \n");
	describe_table(table);
	printf("\nBy table_data_select_all():\n");

	TableData *data = table_data_new(table);
	Array *arr = array_new();
	array_push(arr, string_to_object("Jaipal"));
	array_push(arr, int_to_object(21));
	table_data_add_row(data, arr);
	table_data_select_all(data);
	table_free(table);
	return 0;
}
