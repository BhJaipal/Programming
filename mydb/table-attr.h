#ifndef TABLE_ATTR_H
#define TABLE_ATTR_H
#include "typed-array.h"
#include "types.h"

typedef struct {
	char *name;
	ObjectType type;
	char nullable;
} TableAttr;

TableAttr table_attr_new(char *name, ObjectType attr_type, char isNullable);

void table_attr_print(TableAttr attr);

void table_attr_free(TableAttr attr);

TYPED_ARRAY(TableAttr, table_attr, TableAttr);

#endif //!TABLE_ATTR_H
