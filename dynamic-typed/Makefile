files = array.c types.c dict.c

build:
	gcc -shared $(files) -fPIC -o libdynamic.so
	chmod -x libdynamic.so

run:
	gcc $(filter-out $@,$(MAKECMDGOALS)) ./libdynamic.so -o run.exe
