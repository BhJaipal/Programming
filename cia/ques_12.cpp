#include <iostream>
#include <cmath>
class Shape
{
public:
	virtual float area() = 0;
	virtual float perimeter() = 0;
};
class Circle : public Shape
{
	int radius;

public:
	Circle(int r)
	{
		radius = r;
	}
	float perimeter()
	{
		return 2 * 3.1415 * radius;
	}
	float area()
	{
		return radius * radius * 3.1415;
	}
	~Circle()
	{
		std::cout << "Circle Destructor called" << std::endl;
	}
};
class Rectangle : public Shape
{
	int length, breadth;

public:
	Rectangle(int l, int b)
	{
		length = l;
		breadth = b;
	}
	float perimeter()
	{
		return 2 * (length + breadth);
	}
	float area()
	{
		return length * breadth;
	}
	~Rectangle()
	{
		std::cout << "Rectangle Destructor called" << std::endl;
	}
};
int main(int argc, char const *argv[])
{
	Shape *s = new Circle(7);
	std::cout << s->area() << std::endl;
	std::cout << s->perimeter() << std::endl;
	delete s;
	s = new Rectangle(2, 3);
	std::cout << s->area() << std::endl;
	std::cout << s->perimeter() << std::endl;
	delete s;
	return 0;
}
