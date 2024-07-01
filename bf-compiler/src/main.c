#include "interpreter.h"
#include "repl.h"
#include <stdio.h>
#include <string.h>

int main(int args, char **options) {
	FILE *fptr;
	fptr = fopen(options[1], "r");
	if (fptr == 0) {
		bfRepl();
		return 0;
	}
	interpreter(fptr);
	printf("\n");
	fclose(fptr);
	return 0;
}
