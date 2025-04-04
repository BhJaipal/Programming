#include "table-attr.h"
#include "typed-array.h"
#include "console-appender.h"
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
TYPED_ARRAY_NEW(TableAttr, table_attr, TableAttr);

TYPED_ARRAY_FREE(TableAttr, table_attr);

void table_attr_array_insert_at_index(TableAttrArray *arr, TableAttr data, int index) {
	if (data.type == ARRAY) {
		ConsoleAppender.log(GenerateLog.error("Attribute cannot contain an array\n"), 1);
		table_attr_free(data);
		table_attr_array_free(arr);
		exit(1);
	}
	if (data.type == DICT) {
		ConsoleAppender.log(GenerateLog.error("Attribute cannot contain an dict\n"), 1);
		table_attr_free(data);
		table_attr_array_free(arr);
		exit(1);
	}
	if (index < 0) index = -index - 1;
	if ((unsigned)index >= arr->len_) {
		warn("It will push elements to end of array\n");
		table_attr_array_push(arr, data);
		return;
	}
	else if ((unsigned)index == arr->len_ - 1) {
		table_attr_array_push(arr, data);
		return;
	}
	arr->len_++;
	arr->arr = realloc(arr->arr, sizeof(TableAttr[arr->len_]));
	for (unsigned i = index; i < arr->len_ - 1; i++) {
		arr->arr[i + 1] = arr->arr[i];
	}
	arr->arr[index] = data;
}

void table_attr_array_push(TableAttrArray *arr, TableAttr obj) {
	if (obj.type == ARRAY) error("Attribute cannot contain an array\n");
	if (obj.type == DICT) error("Attribute cannot contain an dict\n");
	arr->arr = realloc(arr->arr,
		sizeof(TableAttr[arr->len_ + 1]));
	arr->arr[arr->len_] = obj;
	arr->len_++;
}

TYPED_ARRAY_REMOVE(TableAttr, table_attr, TableAttr);
