FLAGS = -nostdlib -nostdinc -Wno-builtin-declaration-mismatch
SRC = ./asm-impl.s ./c-impl.c ./main.c

build:
	gcc $(FLAGS) $(SRC)

asm:
	gcc $(FLAGS) $(SRC) -S

asm-std:
	as ./asm-impl.s -o asm-std.o

build-asm: asm asm-std
	as ./c-impl.s ./main.s -o main.o
	ld main.o asm-std.o
