#include "../models/Human.h"
#include "db/sqlite.h"

int str_to_int(char *str);

void createHumanTable(sqlite3 *db);
void insertHuman(sqlite3 *db, char **values, char **errmsg);

int callback(void *data, int col_count, char **values, char **column_names);