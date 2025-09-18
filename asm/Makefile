FLAGS = -nostdlib -nostdinc -Wno-builtin-declaration-mismatch -g -fPIC
SRC := syscall.c c-impl.c malloc.c libc-start.c string.c
ASM := ./asm-impl.s
LIB = ./mylibc.so

define MAIN_FN
$(filter-out $1,$(MAKECMDGOALS))
endef

define TO_OBJ
$(subst .c,.o,$1)
endef

%.o: %.c
	gcc $(FLAGS) $(subst .o,,$@).c -c -o build/$@

OBJ := $(foreach src, $(SRC), $(call TO_OBJ, $(src)))

test:
	gcc $(FLAGS) ./tests/test.c tests/$(TEST).c $(LIB) $(ASM) -o $(TEST)-test.exe
	./$(TEST)-test.exe $(TEST)

all:
	gcc $(FLAGS) $(call MAIN_FN, $@) $(LIB) $(ASM)

build: $(OBJ)
	echo "Building done"

shared:
	gcc $(FLAGS) $(foreach o, $(OBJ),$(call TO_OBJ,build/$(o))) -shared -o $(LIB)

asm:
	if [ ! -d build ]; then mkdir build; fi
	gcc $(FLAGS) c-impl.c -S -o build/c-impl.s 

asm-std:
	if [ ! -d build ]; then mkdir build; fi
	as asm-impl.s -o build/asm-std.o

clean:
	rm -r build
	rm a.out
	rm *-test.exe
