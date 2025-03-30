all:
	gcc -shared -o liblogging.so file-appender.c console-appender.c message.c level.c -fPIC -Wall -Wextra
	chmod -x liblogging.so
test:
	gcc demo.c ./liblogging.so
