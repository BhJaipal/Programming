#include <iostream>
using namespace std;

class Complex {
	int real, imag;

public:
	Complex(int r, int i) : real(r), imag(i) {}

	Complex operator+(Complex &obj) { return Complex(real + obj.real, imag + obj.imag); }
	void display() { cout << real << (imag < 0 ? "" : "+") << imag << "i" << endl; }
};
int main() {
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2;
	c3.display();
	return 0;
}
/*
Output:
12+9i
*/