#include <iostream>
using namespace std;

class Shape
{
public:
	virtual void draw() = 0;
};
class Circle : public Shape
{
public:
	void draw() { cout << "Drawing Circle\n"; }
};
class Rectangle : public Shape
{
public:
	void draw() { cout << "Drawing Rectangle\n"; }
};

int main()
{
	cout << "Choose 1 for Circle and 2 for Rectangle: ";
	int choice;
	cin >> choice;
	Shape *shape;
	if (choice == 1)
	{
		shape = new Circle();
	}
	else
	{
		shape = new Rectangle();
	}
	shape->draw();
	delete shape;
	return 0;
}
/*
Output:
Choose 1 for Circle and 2 for Rectangle: 1
Drawing Circle

Choose 1 for Circle and 2 for Rectangle: 2
Drawing Rectangle
*/