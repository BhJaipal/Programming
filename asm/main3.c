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
}
