#include "file-appender.h"
#include "console-appender.h"
#include "level.h"
#include "message.h"
#include <stdio.h>
#include <time.h>

void __file_message(char *file_name, LogMessage msg) {
	FILE *fPtr = fopen(file_name, "a+");
	fprintf(fPtr, "%d-%d-%d %d:%d:%d [", msg.timestamp->tm_year, msg.timestamp->tm_mon, msg.timestamp->tm_mday,
		msg.timestamp->tm_hour, msg.timestamp->tm_min, msg.timestamp->tm_sec);
	fprintf(fPtr, "%s  ] ", level_to_string(msg.level));
	fprintf(fPtr, "%s\n", msg.message);
	fclose(fPtr);
	ConsoleAppender.log(GenerateLog.info("Log added to file success fully"));
}

struct _FileAppender FileAppender = { __file_message };
