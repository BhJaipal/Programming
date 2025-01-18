all:
	gcc main.c ./libcti.so -o main.exe

build:
	gcc colors.c -c -fPIC
	gcc -shared colors.o -o libcti.so
	chmod -x libcti.so

