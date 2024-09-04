#include "$modelName.h"
#include "db/sqlite.h"
#include <string.h>

$modelName *out;

int str_to_int(char *str) {
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ') { i++; }
	if (str[i] == '-' || str[i] == '+') {
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return result * sign;
}

void create$modelNameTable(sqlite3 *db) {
	char *err;
	SQLite.createTable(db, "$modelName", "$body", &err);
	if (err) printf("%s\n", err);
}

$modelName *select$modelName(sqlite3 *db, int col_count, char **cols,
							 char *where) {
	out = malloc(sizeof($modelName) * 0);
	char errmsg[1024];
	char cols = {"ID", $cols$};
	int result =
		__select(db, "Human", $col_count, cols, where, callback, &errmsg);
	if (result != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", errmsg);
		return NULL;
	}
	return out;
}
void insert$modelName(sqlite3 *db, int column_count, char **values,
					  char **errmsg) {
	SQLite.insert(db, "$modelName", column_count, "$cols", values, errmsg);
}

int *callback(void *data, int col_count, char **values, char **column_names) {
	$modelName val;
	int i = 0;
	val.$member = values[i++];
	out = realloc(out, sizeof(out) + (sizeof(out[0])));
	return 0;
}