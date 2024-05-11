#include <iostream>
using namespace std;

class Complex {
	int real, imag;

public:
	Complex(int r, int i) : real(r), imag(i) {}
	Complex operator+(Complex &obj) { return Complex(real + obj.real, imag + obj.imag); }
	Complex operator-(Complex &obj) { return Complex(real - obj.real, imag - obj.imag); }
	void display() { cout << real << (imag < 0 ? "" : "+") << imag << "i\n"; }
};
int main() {
	Complex c1(4, 7), c2(3, 4);
	Complex c3 = c1 + c2;
	c3.display();
	Complex c4 = c1 - c2;
	c4.display();
	return 0;
}
/*
Output:
7+11i
1+3i
*/
