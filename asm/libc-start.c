#include "syscall.h"

void* heap_init(size_t heap_size);

void set_global_heap(void *_heap);
void global_heap_destroy();
extern int main(int argc, char **argv);

void _libc_main() {
	long argc;
	char **argv;
	asm("mov %%rsi, %0\n":"=r"(argc));
	asm("mov %%rdx, %0\n":"=r"(argv));
	set_global_heap(heap_init(1096));
	int status = main(argc, argv);
	global_heap_destroy();
	exit(status);
}
