#ifndef TABLE_H
#define TABLE_H
#include "table-attr.h"

typedef struct {
	char *name;
	TableAttrArray *Attributes;
} Table;

Table *table_new(char *table_name, TableAttrArray *attrs);

void describe_table(Table *table);

void table_free(Table *table);

#endif // TABLE_H
