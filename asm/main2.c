#include "c-impl.h"

main {
	int *name = mmap(0, 4);
	if (name == null) {
		exit(1);
	}
	name[0] = 0x4a;
	name[1] = 0x61;
	name[2] = 0x69;
	name[3] = 0x0a;
	write((char *)name, 4);
	free(name);
end
