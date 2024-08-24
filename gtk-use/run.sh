# mkdir bin
name="Aloo"
gcc $(pkg-config --cflags gtk4) -o bin/run.exe examples/main.c src/app.c $(pkg-config --libs gtk4)
./bin/run.exe
