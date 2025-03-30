#include "mydb.h"
#include <stdio.h>

int main() {
	TableAttrArray *tattArr = table_attr_array_new();
	table_attr_array_push(tattArr, table_attr_new("name", STRING, 0));
	table_attr_array_push(tattArr, table_attr_new("age", INT, 0));
	Table *table = table_new("Human", tattArr);

	printf("by describe_table() => \n");
	describe_table(table);
	printf("\nBy table_data_select_all():\n");

	TableData *data = table_data_new(table);
	Dict *arr = dict_new();
	dict_add_element(arr, String.to_object("age"), Int.to_object(21));
	dict_add_element(arr, String.to_object("name"), String.to_object("Jaipal"));
	table_data_add_row(data, arr);
	table_data_select_all(data);
	table_data_free(data);
	return 0;
}
