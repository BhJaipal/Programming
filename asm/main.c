#include "c-impl.h"

int _start() {
	write("Enter 3 numbers: ", 18);
	int a = read_int();
	int b = read_int();
	int c = read_int();
	int g;
	if (a > b) {
		if (a > c) g = a;
		else g = c;
	} else {
		if (b > c) g = b;
		else g = c;
	}
	write_int(g);
	write(" is greatest\n", 14);
	exit(0);
}
