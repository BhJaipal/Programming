files = table.c table-attr.c table-rows.c table-data.c

all:
	gcc -Wall -Wextra -shared $(files) -fPIC -o libmydb.so dynamic-typed/libdynamic.so logging/liblogging.so
	chmod -x libmydb.so
test:
	gcc demo.c ./libmydb.so dynamic-typed/libdynamic.so logging/liblogging.so
