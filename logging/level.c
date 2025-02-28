#include "level.h"

char *level_to_string(LogLevel level) {
	switch (level) {
		case LOG_ERROR:
			return "Error  ";
			break;
		case LOG_WARNING:
			return "Warning";
			break;
		case LOG_INFO:
			return "Info   ";
			break;
		case LOG_DEBUG:
			return "Debug  ";
			break;
	}
	return "Error";
}
