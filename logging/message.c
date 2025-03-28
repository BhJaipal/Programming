#include "message.h"
#include "level.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

LogMessage log_message_new(LogLevel level, char *message, ...) {
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	timeinfo->tm_year += 1900;
	timeinfo->tm_mon += 1;
	char *out = malloc(sizeof(char[100]));
	va_list args;
	va_start(args, message);
	vsprintf(out, message, args);
	va_end(args);
	LogMessage msg = {timeinfo, level, message};
	return msg;
}

LogMessage __log_debug(char *message, ...) {
	char *out = malloc(sizeof(char[100]));
	va_list args;
	va_start(args, message);
	vsprintf(out, message, args);
	va_end(args);
	return log_message_new(LOG_DEBUG, out);
}
LogMessage __log_warn(char *message, ...) {
	char *out = malloc(sizeof(char[100]));
	va_list args;
	va_start(args, message);
	vsprintf(out, message, args);
	va_end(args);
	return log_message_new(LOG_WARNING, out);;
}
LogMessage __log_info(char *message, ...) {
	char *out = malloc(sizeof(char[100]));
	va_list args;
	va_start(args, message);
	vsprintf(out, message, args);
	va_end(args);
	return log_message_new(LOG_SUCCESS, out);;
}
LogMessage __log_error(char *message, ...) {
	char *out = malloc(sizeof(char[100]));
	va_list args;
	va_start(args, message);
	vsprintf(out, message, args);
	va_end(args);
	return log_message_new(LOG_ERROR, out);;
}

struct LogMessageGen GenerateLog = {log_message_new, __log_debug, __log_warn, __log_error, __log_info};
