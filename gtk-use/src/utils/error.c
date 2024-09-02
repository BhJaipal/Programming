#include "utils/error.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void throw_error(const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	char buffer[1024];
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);
	fprintf(stderr, "\033[1;31mError:\033[0m %s\n", buffer);
}
