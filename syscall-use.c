#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void Syscall(int rax, ...) {
	va_list args;
	va_start(args, rax);
	if (rax == 0) {
		read(va_arg(args, int), va_arg(args, char *), va_arg(args, int));
	} else if (rax == 1) {
		int fd = va_arg(args, int);
		char *str = va_arg(args, char*);
		write(fd, str, strlen(str));
	}
	int val = va_arg(args, int);
	va_end(args);
	if (rax == 60) {
		exit(val);
	}
}

int main() {
	Syscall(1, 1, "Hello World");
	Syscall(60, 1);
	return 0;
}
