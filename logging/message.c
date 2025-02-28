#include "message.h"
#include "level.h"

LogMessage log_message_new(char *message, LogLevel level) {
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	timeinfo->tm_year += 1900;
	timeinfo->tm_mon += 1;
	LogMessage msg = {timeinfo, level, message};
	return msg;
}

LogMessage __log_debug(char *message) {
	return log_message_new(message, LOG_DEBUG);
}
LogMessage __log_warn(char *message) {
	return log_message_new(message, LOG_WARNING);
}
LogMessage __log_info(char *message) {
	return log_message_new(message, LOG_INFO);
}
LogMessage __log_error(char *message) {
	return log_message_new(message, LOG_ERROR);
}

struct LogMessageGen GenerateLog = {log_message_new, __log_debug, __log_warn, __log_error, __log_info};
