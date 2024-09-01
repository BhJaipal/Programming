#ifndef ALOO_LOGGER_H
#define ALOO_LOGGER_H

struct _logger *newLogger();
void __aloo_log(struct _logger *self, const char *message);

struct _logger {
	int logCount;
	void (*log)(struct _logger *self, const char *message);
};
extern struct _logger Logger;

#endif // ALOO_LOGGER_H