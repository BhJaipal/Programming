FLAGS = -nostdlib -nostdinc -Wno-builtin-declaration-mismatch
SRC = asm-impl.s c-impl.c
MAIN ?= main.c

all:
	gcc $(FLAGS) $(SRC) $(MAIN)

asm:
	if [ ! -d build ]; then mkdir build; fi
	gcc $(FLAGS) $(MAIN) -S -o build/main.s 

half-asm:
	gcc $(FLAGS) ./c-asm-half.c -S

asm-std:
	as asm-impl.s -o build/asm-std.o

build-asm:
	as ./c-impl.s build/main.s -o build/main.o
	ld build/main.o build/asm-std.o

clean:
	rm -r build
	rm a.out
