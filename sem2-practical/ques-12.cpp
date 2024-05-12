#include <iostream>
using namespace std;

class B;
class A {
	int x;
public:
	A(int a = 0) : x(a) {}
	friend int sum(A &, B &);
};

class B {
	int y;
public:
	B(int b = 0) : y(b) {}
	friend int sum(A &, B &);
};
int sum(A &a, B &b) { return a.x + b.y; }

int main() {
	A a(10);
	B b(20);
	cout << "Sum: " << sum(a, b) << endl;
	return 0;
}
/*
Output:
Sum: 30
*/
