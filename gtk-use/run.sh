# mkdir bin
name="Aloo"
gcc $(pkg-config --cflags gtk4) -o bin/run.exe examples/main.c src/app.c src/box.c src/widget.c src/style.c src/grid.c $(pkg-config --libs gtk4)
./bin/run.exe
