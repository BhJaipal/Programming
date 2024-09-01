#include "utils/logger.h"
#include <gtk/gtk.h>

void __aloo_error(struct _logger *self, const char *message) {
	g_print("\033[1;31m[ALOO ERR]\033[0m: %s\n", message);
	self->logCount++;
}
void __aloo_log(struct _logger *self, const char *message) {
	g_print("\033[1;32m[ALOO LOG]\033[0m: %s\n", message);
	self->logCount++;
}
void __aloo_warn(struct _logger *self, const char *message) {
	g_print("\033[1;33m[ALOO WARN]\033[0m: %s\n", message);
	self->logCount++;
}
void __aloo_info(struct _logger *self, const char *message) {
	g_print("\033[1;34m[ALOO INFO]\033[0m: %s\n", message);
	self->logCount++;
}
struct _logger *newLogger() {
	struct _logger *self = malloc(sizeof(struct _logger));
	self->logCount = 0;
	self->err = __aloo_error;
	self->log = __aloo_log;
	self->warn = __aloo_warn;
	self->info = __aloo_info;
	return self;
}
