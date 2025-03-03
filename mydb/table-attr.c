#include "table-attr.h"
#include "typed-array.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TableAttr table_attr_new(char *name, ObjectType attr_type, char isNullable) {
	TableAttr attr;
	attr.name = malloc(sizeof(char[strlen(name)]));
	strcpy(attr.name, name);
	attr.type = attr_type;
	attr.nullable = isNullable;
	return attr;
}

void table_attr_print(TableAttr attr) {
	printf("\x1b[38;5;123m    %*s:%*s \x1b[38;5;079m  ", (int)(4 + strlen(attr.name)/2), attr.name, (int)(4 - strlen(attr.name)/2), "");
	switch (attr.type) {
		case STRING:
			printf("String ");
			break;
		case FLOAT:
			printf(" Float ");
			break;
		case ARRAY:
			printf(" Array ");
			break;
		case DICT:
			printf(" Dict  ");
			break;
		default:
			printf("Integer");
			break;
	}
	printf("\x1b[0m\x1b[2m | ");
	if (!attr.nullable) {
		printf("\x1b[38;5;192mNOT NULL\x1b[0m;");
	} else {
		printf("\x1b[38;5;192m  NULL\x1b[0m;  ");
	}
	printf("\n");
}

void table_attr_free(TableAttr attr) {
	free(attr.name);
}
TYPED_ARRAY_NEW(TableAttr, table_attr);

TYPED_ARRAY_FREE(TableAttr, table_attr);

TYPED_ARRAY_ADD(TableAttr, table_attr);

TYPED_ARRAY_REMOVE(TableAttr, table_attr);
