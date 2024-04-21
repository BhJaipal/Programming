#include <iostream>
#include <cmath>

class Circle
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
class Rectangle
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
class Triangle
{
	int a, b, c;

public:
	Triangle(int s1, int s2, int s3) : a(s1), b(s2), c(s3)
	{
	}
	float perimeter()
	{
		return a + b + c;
	}
	float area()
	{
		float s = perimeter() / 2;
		return std::sqrt(s * (s - a) * (s - b) * (s - c));
	}
	~Triangle()
	{
		std::cout << "Triangle Destructor called" << std::endl;
	}
};
int main()
{
	Rectangle r(10, 5);
	std::cout << "Rectangle Area: " << r.area() << "\n";
	std::cout << "Rectangle perimeter: " << r.perimeter() << "\n\n";
	Circle c(7);
	std::cout << "Circle Area: " << c.area() << "\n";
	std::cout << "Circle perimeter: " << c.perimeter() << "\n\n";
	Triangle tri(3, 4, 5);
	std::cout << "Triangle Area: " << tri.area() << "\n";
	std::cout << "Triangle perimeter: " << tri.perimeter() << "\n\n";
	return 0;
}