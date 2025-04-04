#!/bin/bash

printf "Enter your name: "
read name
mkdir $name
cd $name
mkdir subprojects
ln -s -r ../dynamic-typed subprojects/dynamic-typed
ln -s -r ../logging subprojects/logging
printf "Select a language [cpp|default= c]: "
read lang
if [[ $lang == 'cpp' || $lang == 'c++' ]]; then
	echo -e "project('$name-db', 'cpp')
src = [
  # your files
]
dynamic_dep = subproject('dynamic-typed').get_variable('dynamic_dep')
logging_dep = subproject('logging').get_variable('logging_dep')
deps = [dynamic_dep, logging_dep]
mydb = shared_library('$name-db', src, dependencies: deps, include_directories: include_directories('.'))
executable('demo', 'test.cpp', link_with: mydb, dependencies: deps)" >meson.build
	echo -e "#include /* \"your files\"*/" >mydb.h
	echo -e "#include \"mydb.h\"\n\nint main() {\n\treturn 0;\n}" >test.cpp
else
	echo -e "project('$name-db', 'c')
src = [
  # your files
]
dynamic_dep = subproject('dynamic-typed').get_variable('dynamic_dep')
logging_dep = subproject('logging').get_variable('logging_dep')
deps = [dynamic_dep, logging_dep]
mydb = shared_library('$name-db', src, dependencies: deps, include_directories: include_directories('.'))
executable('demo', 'test.c', link_with: mydb, dependencies: deps)" >meson.build
	echo -e "#include /*\"your files\"*/" >mydb.h
	echo -e "#include \"mydb.h\"\n\nint main() {\n\treturn 0;\n}" >test.cpp
fi
