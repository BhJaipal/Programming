#include "Human.h"
#include "db/sqlite.h"
#include <string.h>

Human *out;

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

void createHumanTable(sqlite3 *db) {
	char *err;
	SQLite.createTable(db, "Human",
					   "ID INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age "
					   "INTEGER, isMale INTEGER",
					   &err);
	if (err) printf("%s\n", err);
}

Human *selectHuman(sqlite3 *db, int col_count, char **cols, char *where) {
	out = malloc(sizeof(Human) * 0);
	char errmsg[1024];
	int result =
		SQLite.select(db, "Human", col_count, cols, where, callback, errmsg);
	if (result != SQLITE_OK) {
		fprintf(stderr, "Error: %s\n", errmsg);
		return NULL;
	}
	return out;
}
void insertHuman(sqlite3 *db, char **values, char **errmsg) {
	SQLite.insert(db, "Human", 3, "name, age, isMale", values, errmsg);
}

int callback(void *data, int col_count, char **values, char **column_names) {
	Human val;
	int i = 0;
	val.name = values[i++];
	val.age = str_to_int(values[i++]);
	val.isMale = str_to_int(values[i++]);

	out = realloc(out, sizeof(out) + (sizeof(out[0])));
	return 0;
}