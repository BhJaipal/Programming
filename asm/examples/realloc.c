#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *name = malloc(5);
	strcpy(name, "Jai");
	printf("%s ", name);
	void* ptr = name;

	name = realloc(name, 7);
	strcat(name, "pal");
	printf("%s\n%p %p\n", name, ptr, name);
}
