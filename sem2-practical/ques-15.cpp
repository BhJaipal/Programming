#include <iostream>
using namespace std;

class OpOverload {
	int num;

public:
	OpOverload(int _num) : num(_num) {}
	friend void operator-(OpOverload &);
	void display() { cout << num << endl; }
};
void operator-(OpOverload &obj) { obj.num = -obj.num; }
int main() {
	OpOverload obj(10);
	-obj;
	obj.display();
	return 0;
}
/*
Output:
-10
*/
