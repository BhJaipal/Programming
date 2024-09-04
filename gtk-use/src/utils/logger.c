#include "utils/logger.h"
#include <gtk/gtk.h>
#include <stdarg.h>
#include <stdio.h>

void __aloo_error(struct _logger *self, const char *message, ...) {
	va_list arg;
	va_start(arg, message);
	fprintf(stdout, "\033[1;31m[ALOO ERR]\033[0m: ");
	vfprintf(stdout, message, arg);
	fprintf(stdout, "\n");
	va_end(arg);
	self->logCount++;
}
void __aloo_log(struct _logger *self, const char *message, ...) {
	va_list arg;
	va_start(arg, message);
	fprintf(stdout, "\033[1;32m[ALOO LOG]\033[0m: ");
	vfprintf(stdout, message, arg);
	fprintf(stdout, "\n");
	va_end(arg);
	self->logCount++;
}
void __aloo_warn(struct _logger *self, const char *message, ...) {
	va_list arg;
	va_start(arg, message);
	fprintf(stdout, "\033[1;33m[ALOO WARN]\033[0m: ");
	vfprintf(stdout, message, arg);
	fprintf(stdout, "\n");
	va_end(arg);
	self->logCount++;
}
void __aloo_info(struct _logger *self, const char *message, ...) {
	va_list arg;
	va_start(arg, message);
	fprintf(stdout, "\033[1;34m[ALOO INFO]\033[0m: ");
	vfprintf(stdout, message, arg);
	fprintf(stdout, "\n");
	va_end(arg);
	self->logCount++;
}
struct _logger *newLogger() {
	struct _logger *self = malloc(sizeof(struct _logger));
	self->logCount = 0;
	self->err = __aloo_error;
	self->log = __aloo_log;
	self->warn = __aloo_warn;
	self->info = __aloo_info;
	fprintf(stdout, "\r       \n");
	return self;
}
