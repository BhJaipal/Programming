#include <malloc.h>

void main()
{
	char *n = malloc(0);
	n = realloc(n, 1);
	free(n);
}
