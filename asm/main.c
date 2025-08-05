#include "c-impl.h"

main {
	print("Enter 3 numbers: ");
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
	println(" is greatest");
	exit(0);
}
