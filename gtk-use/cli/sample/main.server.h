#include "../models/$modelName.h"
#include "db/sqlite.h"

$modelName *out;

int str_to_int(char *str);

void create$modelNameTable(sqlite3 *db);
void insert$modelName(sqlite3 *db, int column_count, char **values,
					  char **errmsg);

int *callback(void *data, int col_count, char **values, char **column_names);