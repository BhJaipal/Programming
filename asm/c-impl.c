#include "c-impl.h"
inline void putchar(char c) {
	write(&c, 1);
}

int pow(int b, int e) {
	int out = 1;
	for (unsigned i = 0; i < e; i++) {
		out *= b;
	}
	return out;
}

void write_uint(unsigned int x) {
	if (x < 10) {
		putchar(x + 0x30);
		return;
	}
	int exp = 1;
	while (x/pow(10, exp))
		exp++;

	for (int i = exp - 1; i >= 0; i--) {
		int val = x % pow(10, i + 1);
		val /= pow(10, i);
		putchar(val + 0x30);
	}
}

unsigned int read_uint() {
	unsigned int x = 0;
	char num[11];
	for (int i = 0; i < 11;i++) {
		read(num + i, 1);
		if (num[i] == 0 || num[i] == ' ' || num[i] == '\n')
			break;
		if (num[i] <= '0' || num[i] >= '9') {
			write("\e[91mERROR: \e[0m", 17);
			write("Only integers allowed\n", 23);
			exit(1);
		}
	}
	for (int i = 0; i < 11; i++) {
		if (num[i] == 0 || num[i] == ' ' || num[i] == '\n')
			break;
		x *= 10;
		x += num[i] - 0x30;
	}
	return x;
}
void write_int(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) {
		putchar(x + 0x30);
		return;
	}

	int exp = 1;
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	while (x / pow(10, exp))
		exp++;
	for (int i = exp - 1; i >= 0; i--) {
		int val = x % pow(10, i + 1);
		val /= pow(10, i);
		putchar(val + 0x30);
	}
}

int read_int() {
	int x = 0;
	char num[11];
	for (int i = 0; i < 11; i++) {
		read(num + i, 1);
		if (num[i] == 0 || num[i] == ' ' || num[i] == '\n')
			break;
		else if (i == 0 && num[i] == '-')
			continue;
		else if (num[i] <= '0' || num[i] >= '9') {
			write("\e[91mERROR: \e[0m", 17);
			write("Only integers allowed\n", 23);
			exit(1);
		}
	}
	for (int i = 0; i < 11; i++) {
		if (num[i] == 0 || num[i] == ' ' || num[i] == '\n')
			break;
		if (i == 0 && num[0] == '-')
			continue;
		x *= 10;
		x += num[i] - 0x30;
	}
	if (num[0] == '-')
		x = -x;
	return x;
}


unsigned strlen(const char *str) {
	unsigned i = 0;
	while (str[i]) { i++; }
	return i;
}

void print(const char *str) {
	unsigned i = strlen(str);
	write(str, i);
}

void println(const char *str) {
	write(str, strlen(str));
	putchar(10);
}

void free(void *ptr) {
	asm("mov %0, %%rdi" :: "r"(ptr));
	munmap();
}
// void *malloc() {}
