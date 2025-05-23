#ifndef LOGGING_CONSOLE_APPENDER_H
#define LOGGING_CONSOLE_APPENDER_H

#include "message.h"

extern struct _ConsoleAppender {
	void (*log)(LogMessage msg, char unref);
} ConsoleAppender;

#endif // LOGGING_CONSOLE_APPENDER_H
