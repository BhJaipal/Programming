#include "c-impl.h"
void putchar(char c) {
	write(&c, 1);
}

int pow(int b, int e) {
	if (e == 0) return 1;
	if (e == 1) return b;
	for (int i= 1; i < e; i++) {
		b *= b;
	}
	return b;
}

void printd(unsigned int x) {
	if (x < 10) {
		// __asm__("movl -20(%rbp), %eax");
		// __asm__("addl $0x30, %eax");
		// __asm__("movl %eax, -4(%rbp)");
		putchar(x + 0x30);
		return;
	}
	int exp = 1;
	while (x/pow(10, exp))
		exp++;

	for (int i = exp - 1; i >= 0; i--) {
		int val = x%pow(10, i + 1);
		val /= pow(10, i);
		putchar(val + 0x30);
	}
}
