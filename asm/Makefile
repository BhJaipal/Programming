FLAGS = -nostdlib -nostdinc -Wno-builtin-declaration-mismatch
SRC = ./asm-impl.s ./c-impl.c ./main.c

asm:
	gcc $(FLAGS) $(SRC) -S
build:
	gcc $(FLAGS) $(SRC)
