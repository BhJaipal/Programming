#include <iostream>
class Shape
{
public:
	virtual void draw() = 0;
};
class Rectangle : public Shape
{
	void draw()
	{
		std::cout << "drawing rectangle\nEnter length and breadth: ";
		int a, b;
		std::cin >> a >> b;
		float area = a * b;
		std::cout << "rectangle drawn of area: " << area << std::endl;
	}
};
class Circle : public Shape
{
public:
	void draw()
	{
		std::cout << "drawing circle\nEnter radius: ";
		int r;
		std::cin >> r;
		float area = 3.1415 * r * r;
		std::cout << "circle drawn of area: " << area << std::endl;
	}
};
int main()
{
	Shape *s;
	Rectangle r;
	Circle c;
	s = &r;
	s->draw();
	std::cout << std::endl;
	s = &c;
	s->draw();
	return 0;
}