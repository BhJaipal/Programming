# mkdir bin
name="Aloo"
# gcc $(pkg-config --cflags gtk4) -o bin/run.exe main.c ../lib/libaloo.a $(pkg-config --libs gtk4)
# ./bin/run.exe

if [ -f "main.c" ]; then
	cmake -S . -B build
	cd build && make all
	cd ../ && ./bin/run.exe
else
	cd examples
	cmake -S . -B build
	cd build && make all
	cd ../ && ./bin/run.exe
fi
