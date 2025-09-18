#include "c-impl.h"

void format(const char *str, ...) {
	long v;
	char *s;
	asm("mov %%rdx, %0\n":"=r"(v));
	asm("mov %%rsi, %0\n":"=r"(s));
	println(str);
	write_uint(v);
	print(" ");
	println(s);
}

int main() {
	format("Hello {}", "World", 5);
}
