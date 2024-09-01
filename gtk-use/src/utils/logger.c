#include "utils/logger.h"
#include <gtk/gtk.h>

void __aloo_log(struct _logger *self, const char *message) {
	g_print("\033[1;32m[ALOO LOG]\033[0m: %s", message);
	self->logCount++;
}
struct _logger *newLogger() {
	struct _logger *self = malloc(sizeof(struct _logger));
	self->logCount = 0;
	self->log = __aloo_log;
	return self;
}

struct _logger Logger = {.logCount = 0, .log = __aloo_log};