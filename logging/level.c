#include "level.h"

char *level_to_string(LogLevel level) {
	switch (level) {
		case LOG_ERROR:
			return " ERROR ";
			break;
		case LOG_WARNING:
			return "WARNING";
			break;
		case LOG_SUCCESS:
			return "SUCCESS";
			break;
		case LOG_DEBUG:
			return " DEBUG ";
			break;
	}
	return " Error ";
}
