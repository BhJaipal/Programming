#include "../models/$modelName.c"
#include "db/sqlite.h"

$modelName *out;

void create$modelNameTable(sqlite3 *db) {
	char *err;
	SQLite.createTable(db, "$modelName", "$body", &err);
	if (err) printf("%s\n", err);
}
$modelName *select$modelName(sqlite3 *db, int col_count, char **cols,
							 char *where) {

	out = malloc(sizeof($modelName) * 0);
	char errmsg[1024];
	int result =
		__select(db, "Human", col_count, cols, where, callback, &errmsg);

	if (result != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", errmsg);
		return NULL;
	}

	return out;
}

int *callback(void *data, int col_count, char **values, char **column_names) {
	$modelName val;
	char **cols = {"id" $cols};
	for (int i = 0; i < col_count; i++) { val[cols[i]] = values[i]; }
	out = realloc(out, sizeof(out) + (sizeof(out[0])));
	return 0;
}