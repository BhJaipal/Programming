#include <stdio.h>

int main(int argc, char const *argv[]) {
	int x = 5;
	int *ptr = &x;
	printf("%p\n\n", ptr);
	// on setting pointer to null (0)
	// on printing it, the pointer will be printed as
	// nil on %p, null on %ls and 0 on %d
	ptr = 0;
	printf("%ls\n", ptr); // null
	printf("%d\n", ptr);  // 0
	printf("%p\n", ptr);  // nil
	return 0;
}
