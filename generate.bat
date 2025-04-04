@echo off

set /p name=Enter your name:
mkdir "%name%"
cd "%name%"
mkdir subprojects
mklink /D subprojects\dynamic-typed ..\dynamic-typed
mklink /D subprojects\logging ..\logging
set /p lang=Select a language [cpp|default= c]:
if /i "%lang%"=="cpp" (
    echo src = # your files>>Makefile
    echo deps = subprojects/dynamic-typed/libdynamic++.so, subprojects/logging/liblogging.so]>>Makefile
    echo.>>Makefile
    echo all:>>Makefile
    echo     g++ -Wall -Wextra $(src) $(deps) -shared -o lib%name%-db++.so>>Makefile
	echo test:>>Makefile
	echo.>>Makefile
    echo     g++ -o demo test.cpp lib%name%-db++.so $(deps)>>Makefile
    echo #include /* "your files" */>mydb.h
    echo #include "mydb.h" >>test.cpp
    echo. >>test.cpp
    echo int main() { >>test.cpp
    echo     return 0; >>test.cpp
    echo } >>test.cpp
) else (
    echo src = # your files>>Makefile
    echo deps = subprojects/dynamic-typed/libdynamic.so, subprojects/logging/liblogging.so]>>Makefile
    echo.>>Makefile
    echo all:>>Makefile
    echo     gcc -Wall -Wextra $(src) $(deps) -shared -o lib%name%-db.so>>Makefile
	echo test:>>Makefile
	echo.>>Makefile
    echo     gcc -o demo test.c lib%name%-db.so $(deps)>>Makefile
    echo #include /* "your files" */>mydb.h
    echo #include "mydb.h" >>test.c
    echo. >>test.c
    echo int main() { >>test.c
    echo     return 0; >>test.c
    echo } >>test.c
)
