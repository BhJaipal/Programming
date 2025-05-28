#include <iostream>

/**
 * Function Overloading:
 *		Function name same
 *		Order or arguments different
 *		Types of arguments different
 *		Number of arguments different
 */

/* 3 arguments */
float add(int a, int b, int c) { return a+b; }
/* 2 arguments, int & int */
float add(int a, int b) { return a+b; }
/* 2 arguments, float & int */
float add(float a, int b) { return a+b; }
/* 2 arguments, int & float */
float add(int a, float b) { return a+b; }

int main() {
	std::cout << add(5, 3) << " "
		<< add(4.2f, 8) << " "
		<< add(3, 7.6f) << " "
		<< add(6, 2, 7) << "\n";
	return 0;
}
