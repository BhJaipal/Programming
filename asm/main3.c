#include "c-impl.h"

int main() {
	char *name = malloc(5);
	name[0] = 'J';
	name[1] = 'a';
	name[2] = 'i';
	name[3] = '\n';
	name[4] = 0;
	print(name);
	free(name);

	void *heap = heap_new(PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 10);
	name = heap_malloc(heap, 5);
	name[0] = 'H';
	name[1] = 'e';
	name[2] = 'm';
	name[3] = 'a';
	name[4] = 0;
	println(name);
	heap_free(heap, name);
	heap_destroy(heap);
}
