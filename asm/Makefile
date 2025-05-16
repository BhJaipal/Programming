FLAGS = -nostdlib -nostdinc -Wno-builtin-declaration-mismatch
SRC = ./asm-impl.s ./c-impl.c ./main.c

build:
	gcc $(FLAGS) $(SRC)

asm:
	gcc $(FLAGS) $(SRC) -S
	mv ./main.s asm-out
	mv ./c-impl.s asm-out

asm-std:
	as ./asm-impl.s -o asm-std.o

build-asm: asm asm-std
	as ./c-impl.s ./main.s -o main.o
	ld main.o asm-std.o

clean:
	rm asm-out/c-impl.s
	rm asm-out/main.s
	rm a.out
