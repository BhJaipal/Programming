#include "console-appender.h"
#include "level.h"
#include "message.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void __log_message(LogMessage msg, char unref) {
	printf("[");
	switch (msg.level) {
		case LOG_ERROR:
			printf("\x1b[31m");
			break;
		case LOG_WARNING:
			printf("\x1b[33m");
			break;
		case LOG_DEBUG:
			printf("\x1b[94m");
			break;
		case LOG_SUCCESS:
			printf("\x1b[32m");
			break;
	}
	printf("  %s  \x1b[0m] ", level_to_string(msg.level));
	printf("\x1b[2m%d-%d-%d %d:%d:%d\x1b[0m ",
		msg.timestamp->tm_year, msg.timestamp->tm_mon, msg.timestamp->tm_mday,
		msg.timestamp->tm_hour, msg.timestamp->tm_min, msg.timestamp->tm_sec);
	printf("%s\n", msg.message);
	if (unref) {
		free(msg.message);
	}
}

struct _ConsoleAppender ConsoleAppender = { __log_message };
