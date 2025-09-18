#include "../c-impl.h"

int main(int argc, char **argv) {
	print("[");
	for (int  i = 0; i < argc; i++) {
		print("'");
		print(argv[i]);
		print("'");
		if (i != argc-1) {
			print(", ");
		}
	}
	println("]");

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
	exit(1);
}
