#include "include/db/sqlite.h"
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

int callback(void *data, int argc, char **val, char **col) {
	for (int i = 0; i < argc; i++) { printf("%s: %s\n", col[i], val[i]); }
	return 0;
}

int main() {
	sqlite3 *db;
	sqlite3_open("./sqlite.db", &db);

	char *query = "SELECT * FROM Human;";
	char *err;
	sqlite3_exec(db, query, callback, 0, &err);
	printf("\nMy:\n");
	char *cols[] = {"name", "age"};
	SQLite.select(db, "Human", 2, cols, "", callback, &err);
	// SQLite.delete(db, "Human", (void *)0, "name ='Hakuna'", (void *)0, &err);
	// char *data[] = {"'Hakari'", "35", "1"};
	// SQLite.insert(db, "Human", 3, (void *)0, data, &err);

	if (err) {
		printf("%s\n", err);
		sqlite3_free(err);
	}

	sqlite3_close(db);
	return 0;
}