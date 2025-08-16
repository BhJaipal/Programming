FLAGS = -nostdlib -nostdinc -Wno-builtin-declaration-mismatch
SRC = asm-impl.s c-impl.c
MAIN ?= main.c

all:
	gcc $(FLAGS) $(SRC) $(MAIN)

c-impl:
	gcc $(FLAGS) c-impl.c -S -o build/c-impl.s

asm:
	if [ ! -d build ]; then mkdir build; fi
	gcc $(FLAGS) $(MAIN) -S -o build/main.s 

asm-main: asm-std
	as $(AMAIN) -o build/elf.o
	ld build/elf.o build/asm-std.o
	./a.out

asm-std:
	if [ ! -d build ]; then mkdir build; fi
	as asm-impl.s -o build/asm-std.o

build-asm:
	as ./c-impl.s build/main.s -o build/main.o
	ld build/main.o build/asm-std.o

clean:
	rm -r build
	rm a.out
