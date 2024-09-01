#ifndef ALOO_LOGGER_H
#define ALOO_LOGGER_H

struct _logger *newLogger();
void __aloo_log(struct _logger *self, const char *message);

struct _logger {
	int logCount;
	void (*err)(struct _logger *self, const char *message);
	void (*log)(struct _logger *self, const char *message);
	void (*warn)(struct _logger *self, const char *message);
	void (*info)(struct _logger *self, const char *message);
};
#endif // ALOO_LOGGER_H