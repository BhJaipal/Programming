/**
 * @file sqlite.h
 * @author Jaipal001
 * @brief Contains utils to work with SQLite and aloo
 */
#ifndef ALOO_DB_SQLITE_H
#define ALOO_DB_SQLITE_H

#include <sqlite3.h>
/******************** Private Funcs ********************/

int __open(const char *filename, sqlite3 **db);
void __close(sqlite3 *db);
int __createTable(sqlite3 *db, char *table_name, char *body, char **errmsg);
int __insert(sqlite3 *db, char *table_name, int column_count,
			 char *column_names, char **values, char **errmsg);
int __select(sqlite3 *db, char *table_name, int column_count,
			 char **column_names, char *where_clause,
			 int (*callback)(void *data, int rows_count, char **values,
							 char **column_names),
			 char *errmsg);
int __delete(sqlite3 *db, char *table_name, char **column_names,
			 char *where_clause,
			 int (*callback)(void *data, int rows_count, char **values,
							 char **column_names),
			 char **errmsg);

int nothing(void *data, int rows_count, char **values, char **column_names);

int isString(char *str);

/******************** Private Types ********************/

struct _sqlite {
	int (*open)(const char *filename, sqlite3 **db);
	void (*close)(sqlite3 *db);
	int (*insert)(sqlite3 *, char *table_name, int column_count,
				  char *column_names, char **values, char **errmsg);
	int (*select)(sqlite3 *, char *table_name, int column_count,
				  char **column_names, char *where_clause,
				  int (*callback)(void *data, int rows_count, char **values,
								  char **column_names),
				  char *errmsg);
	int (*delete)(sqlite3 *, char *table_name, char **column_names,
				  char *where_clause,
				  int (*callback)(void *data, int rows_count, char **values,
								  char **column_names),
				  char **errmsg);
	int (*createTable)(sqlite3 *db, char *table_name, char *body,
					   char **errmsg);
};
extern struct _sqlite SQLite;

#endif // ALOO_DB_SQLITE_H
