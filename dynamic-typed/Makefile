files = array.c types.c dict.c singly-linked-list.c

build:
	gcc -shared $(files) -fPIC -o libdynamic.so -Wall -Wextra
	chmod -x libdynamic.so

run:
	gcc $(filter-out $@,$(MAKECMDGOALS)) ./libdynamic.so -o run.exe
