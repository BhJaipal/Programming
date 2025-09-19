#include "../c-impl.h"

int main() {
	char *name = malloc(5);
	strcpy(name, "Jai");
	print(name);
	print(" ");
	name = realloc(name, 7);
	strcat(name, "pal");
	println(name);
	free(name);

	void *heap = heap_new(PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1);
	name = heap_malloc(heap, 5);
	strcpy(name, "Hema");
	println(name);
	name = heap_realloc(heap, name, 9);
	strcat(name, " bha");
	println(name);
	heap_free(heap, name);
	heap_destroy(heap);
}
