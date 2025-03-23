files = table.c table-attr.c typed-array.c table-rows.c table-data.c

all:
	gcc -shared $(files) -fPIC -o libmydb.so dynamic-typed/libdynamic.so
	chmod -x libmydb.so
