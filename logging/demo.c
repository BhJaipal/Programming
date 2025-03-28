#include "console-appender.h"
#include "file-appender.h"
#include <stdio.h>

int main() {
	LogMessage msg1 = GenerateLog.debug("Hello World"),
	msg2 = GenerateLog.warn("Please allocate memory carefully"),
	msg3 = GenerateLog.error("Unexpected token: %s", "Hello");

	ConsoleAppender.log(msg1);
	ConsoleAppender.log(msg2);
	ConsoleAppender.log(msg3);

	printf("\n");
	FileAppender.log("out.log", msg1);
	FileAppender.log("out.log", msg2);
	FileAppender.log("out.log", msg3);
	return 0;
}
