#ifndef LOGGING_FILE_APPENDER_H
#define LOGGING_FILE_APPENDER_H

#include "message.h"

extern struct _FileAppender {
	void (*log)(char *file_name, LogMessage msg);
} FileAppender;

#endif // LOGGING_FILE_APPENDER_H
