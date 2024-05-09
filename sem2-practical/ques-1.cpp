#include <iostream>
using namespace std;

class Base
{
public:
	void show();
};
void Base::show()
{
	cout << "Base class" << endl;
}
int main(int argc, char const *argv[])
{
	Base b;
	b.show();
	return 0;
}
/**
Output:
Base class
 */