files = table.c table-attr.c table-rows.c table-data.c data-dict.c
deps = subprojects/logging/liblogging.so subprojects/dynamic-typed/libdynamic.so

all:
	gcc -Wall -Wextra -shared $(files) -fPIC -o libmydb.so $(deps)
	chmod -x libmydb.so
test:
	gcc demo.c ./libmydb.so $(deps)
