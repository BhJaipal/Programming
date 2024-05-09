#include <iostream>
using namespace std;

class draw {
	void shape() { cout << "Drawing Shape\n"; }

public:
	friend void drawShape(draw &);
};
void drawShape(draw &obj) {
	obj.shape();
}
int main() {
	draw obj;
	drawShape(obj);
	return 0;
}
/*
Output:
Drawing shape
*/
