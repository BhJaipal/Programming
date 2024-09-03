#include "db/sqlite.h"
#include <fmtmsg.h>
#include <stdio.h>
#include <string.h>
#include <tirpc/rpc/types.h>

int isString(char *str) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] < '0' || str[i] > '9') return TRUE;
	}
	return FALSE;
}

int nothing(void *data, int rows_count, char **values, char **column_names) {
	return 0;
}

int __open(const char *filename, sqlite3 **db) {
	return sqlite3_open(filename, db);
}
void __close(sqlite3 *db) { sqlite3_close(db); }

int __insert(sqlite3 *db, char *table_name, int column_count,
			 char *column_names, char **values, char **errmsg) {
	char *query = malloc(sizeof(char) * 1050);
	sprintf(query, "INSERT INTO %s", table_name);
	if (column_names != NULL) {
		sprintf(query + strlen(query), " (%s)", column_names);
	}

	sprintf(query + strlen(query), " VALUES (");
	for (int i = 0; i < column_count; i++) {
		sprintf(query + strlen(query),
				(isString(values[i])) ? "%s'%s'" : "%s%s", (i > 0) ? ", " : "",
				values[i]);
	}
	sprintf(query + strlen(query), ");");
	printf("%s\n", query);

	return sqlite3_exec(db, query, nothing, NULL, errmsg);
}
int __select(sqlite3 *db, char *table_name, int column_count,
			 char **column_names, char *where_clause,
			 int (*callback)(void *data, int rows_count, char **values,
							 char **column_names),
			 char *errmsg) {
	char query[1024] = "";
	if (column_names != NULL) {
		sprintf(query, "SELECT ");
		for (int i = 0; i < column_count; i++) {
			sprintf(query + strlen(query), "%s%s", (i > 0) ? ", " : "",
					column_names[i]);
		}
	} else {
		sprintf(query + strlen(query), "SELECT *");
	}
	sprintf(query + strlen(query), " FROM %s", table_name);
	if (where_clause && strlen(where_clause) > 0) {
		sprintf(query + strlen(query), " WHERE %s", where_clause);
	}
	sprintf(query + strlen(query), ";");
	return sqlite3_exec(db, query, callback, NULL, &errmsg);
}
int __delete(sqlite3 *db, char *table_name, char **column_names,
			 char *where_clause,
			 int (*callback)(void *data, int rows_count, char **values,
							 char **column_names),
			 char **errmsg) {

	char query[1024] = "";
	sprintf(query + strlen(query), "DELETE FROM %s", table_name);
	if (where_clause && strlen(where_clause) > 0) {
		sprintf(query + strlen(query), " WHERE %s;", where_clause);
		return sqlite3_exec(db, query, callback, NULL, errmsg);
	} else {
		printf("This action will delete all rows in table %s\n", table_name);
		printf("Are you sure you want to continue? (y/n) ");
		char c = getchar();
		sprintf(query + strlen(query), ";");
		if (c == 'y' || c == 'Y') {
			return sqlite3_exec(db, query, callback, NULL, errmsg);
		}
	}
	return 0;
}
int __createTable(sqlite3 *db, char *table_name, char *body, char **errmsg) {
	char query[1024];
	sprintf(query, "CREATE TABLE IF NOT EXISTS %s(%s);", table_name, body);
	return sqlite3_exec(db, query, nothing, NULL, errmsg);
}

struct _sqlite SQLite = {
	.close = __close,
	.delete = __delete,
	.insert = __insert,
	.open = __open,
	.select = __select,
	.createTable = __createTable,
};
