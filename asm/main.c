#include "c-impl.h"

int _start() {
	// write("Enter 3 numbers: ");
	int a = 43;
	int b = 34;
	int c = 73;
	int g;
	if (a > b) {
		if (a > c) g = a;
		else g = c;
	} else {
		if (b > c) g = b;
		else g = c;
	}
	printd(g);
	write(" is greatest\n", 14);
	exit(0);
}
