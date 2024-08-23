# mkdir build
# mkdir bin
# gcc -o build/app.o src/app.c
gcc $(pkg-config --cflags gtk4) -o bin/run.exe examples/main.c src/app.c $(pkg-config --libs gtk4)
./bin/run.exe
