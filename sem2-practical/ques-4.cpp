#include <iostream>
using namespace std;

class Employee {
public:
	static int count;
	Employee() { count++; }
	~Employee() { count--; }
};

int Employee::count = 0;
int main() {
	Employee e1, e2;
	cout << "Count: " << Employee::count << endl;
	Employee e3;
	cout << "Count: " << Employee::count << endl;
	return 0;
}
/*
Count: 2
Count: 3
*/
