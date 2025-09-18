#include "test.h"

TEST({
	char *name = malloc(sizeof(char[5]));
	EXPECT(name, "Expected heap pointer, got nullptr instead");
	strncpy(name, "Jai\n", 5);
})
