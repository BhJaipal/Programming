files = array.c types.c dict.c
cpp-src = object.cpp

build c:
	gcc -shared $(files) -fPIC -o libdynamic.so -Wall -Wextra
	gcc -shared $(cpp-src) -fPIC -o libdynamic++.so -Wall -Wextra
	chmod -x libdynamic.so
	chmod -x libdynamic++.so

run:
	gcc $(filter-out $@,$(MAKECMDGOALS)) ./libdynamic.so -o run.exe
