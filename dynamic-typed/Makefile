all:
	gcc array.c types.c dict.c -c
	rm *.o
	gcc -shared -o libdynamic.so array.c dict.c types.c
	chmod -x libdynamic.so
