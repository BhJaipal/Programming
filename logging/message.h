#ifndef LOGGING_MESSAGE_H
#define LOGGING_MESSAGE_H
#include "level.h"
#include <time.h>

typedef struct {
	struct tm *timestamp;
	LogLevel level;
	char *message;
} LogMessage;

extern struct LogMessageGen {
	LogMessage (*new)(LogLevel level, char *message, ...),
			   (*debug)(char *message, ...),
			   (*warn)(char *message, ...),
			   (*error)(char *message, ...),
			   (*info)(char *message, ...);
} GenerateLog;
LogMessage log_message_new(LogLevel level, char *message, ...);

#endif // LOGGING_MESSAGE_H
