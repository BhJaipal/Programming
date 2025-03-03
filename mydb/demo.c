#include "table-attr.h"
#include "table.h"
#include <stdio.h>

int main() {
	TableAttrArray *tattArr = table_attr_array_new();
	table_attr_array_push(tattArr, table_attr_new("name", STRING, 0));
	table_attr_array_push(tattArr, table_attr_new("age", INT, 1));
	Table *table = table_new("Human", tattArr);

	printf("by describe_table() => \n");
	describe_table(table);
	table_free(table);
	return 0;
}
