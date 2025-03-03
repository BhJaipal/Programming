#include "utility.h"
#include <stdio.h>

char validate_db(FILE *file) {
	char type[6];
	fgets(type, 6, file);
	if (type[0] != 0) return 0;
	if ((type[1] == 'M') && (type[2] == 'Y') && (type[3] == 'D') && (type[4] == 'B'))
		return 1;
	return 0;
}
