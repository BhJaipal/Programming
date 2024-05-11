#include <iostream>
using namespace std;

class Base {
public:
	int x, y;
	void input() {
		cout << "Enter 2 numbers: ";
		cin >> x >> y;
	}
};
class Derived : public Base {
public:
	void add() { cout << "Sum = " << x + y << endl; }
};
int main() {
	Derived d;
	d.input();
	d.add();
	return 0;
}
/*
Output:
Enter 2 numbers: 7 5
Sum = 12
*/
