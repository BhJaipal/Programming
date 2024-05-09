#include <iostream>
using namespace std;

class Base {
public:
	Base() {
		cout << "Base constructor" << endl;
	}
	~Base() {
		cout << "Base destructor" << endl;
	}
};
int main() {
	Base b;
	return 0;
}
