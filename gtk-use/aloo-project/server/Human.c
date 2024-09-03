#include "../models/Human.c"
#include "db/sqlite.h"

Human *out;

void createHumanTable(sqlite3 *db) {
	char *err;
	SQLite.createTable(db, "Human", "ID INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, isMale INTEGER", &err);
	if (err) printf("%s\n", err);
}
Human *selectHuman(sqlite3 *db, int col_count, char **cols,
							 char *where) {

	out = malloc(sizeof(Human) * 0);
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
	Human val;
	char **cols = {"id" "name", "age", "isMale"};
	for (int i = 0; i < col_count; i++) { val[cols[i]] = values[i]; }
	out = realloc(out, sizeof(out) + (sizeof(out[0])));
	return 0;
}