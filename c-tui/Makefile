all:
	gcc main.c ./libcti.so -o main.exe

build:
	gcc colors.c -c -fPIC
	gcc select.c -c -fPIC
	gcc option.c -c -fPIC
	gcc -shared colors.o select.o option.o -o libcti.so
	chmod -x libcti.so

-B: build
	gcc main.c ./libcti.so -o main.exe
