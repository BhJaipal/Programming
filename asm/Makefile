FLAGS = -nostdlib -nostdinc -Wno-builtin-declaration-mismatch -g
SRC = asm-impl.s c-impl.c

define MAIN
	$(filter-out $1,$(MAKECMDGOALS))
endef

all:
	gcc $(FLAGS) $(SRC) $(call MAIN, $@)

shared:
	gcc $(FLAGS) $(SRC) -shared ./tinyalloc.c -o libasm.so

asm:
	if [ ! -d build ]; then mkdir build; fi
	gcc $(FLAGS) c-impl.c -S -o build/c-impl.s 

asm-std:
	if [ ! -d build ]; then mkdir build; fi
	as asm-impl.s -o build/asm-std.o

clean:
	rm -r build
	rm a.out
