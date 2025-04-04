#include "mydb.h"
#include <stdio.h>

int main() {
	TableAttrArray *tattArr = table_attr_array_new();
	table_attr_array_push(tattArr, table_attr_new("name", STRING, 0));
	table_attr_array_push(tattArr, table_attr_new("age", INT, 0));

	// Describe Human
	printf("by describe_table() => \n");
	Table *table = table_new("Human", tattArr);
	describe_table(table);

	TableData *data = table_data_new(table);
	// Add data to table
	DataDict *arr = data_dict_new();
	data_dict_push(arr, "age", Int.to_object(21));
	data_dict_push(arr, "name", String.to_object("Jaipal"));
	table_data_add_row(data, arr);

	// Select * from Human
	printf("\nBy table_data_select_all():\n");
	table_data_select_all(data);

	table_data_free(data);
	return 0;
}
