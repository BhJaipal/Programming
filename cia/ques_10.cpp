#include <iostream>

class Base
{
public:
	virtual ~Base()
	{
		std::cout << "Base destructor" << std::endl;
	}
};
class Derived1 : public Base
{
	~Derived1()
	{
		std::cout << "Derived 1 destructor" << std::endl;
	}
};
class Derived2 : public Base
{
	~Derived2()
	{
		std::cout << "Derived 2 destructor" << std::endl;
	}
};
int main()
{
	Base *b = new Derived1();
	Base *c = new Derived2();
	delete b;
	delete c;
	return 0;
}
