#include <stdio.h>

int add(int a /* %edi */, int b /* %esi */) { return a + b; }

int main() {
	add(5, 3);
	int (*fn)(int) = (int (*)(int))add;
	// __asm__("movl $5, %edi");
	__asm__("movl $3, %esi");
	int sum = fn(5);
	printf("sum: %d\n", sum);
	return 0;
}