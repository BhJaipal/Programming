#include <iostream>
using namespace std;

class A {
public:
	int x;
	A(int a) : x(a) {}
};

class B {
public:
	int y;
	B() : y(0) {}
	B(A &obj) { y = obj.x; }
};
int main() {
	A a(7);
	B b;
	b = a;
	cout << b.y << endl;
	return 0;
}
/*
Output:
7
*/
