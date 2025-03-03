#ifndef LOGGING_LEVEL_H
#define LOGGING_LEVEL_H

typedef enum {
	LOG_DEBUG,
	LOG_ERROR,
	LOG_WARNING,
	LOG_SUCCESS
} LogLevel;

char *level_to_string(LogLevel level);

#endif // LOGGING_LEVEL_H
