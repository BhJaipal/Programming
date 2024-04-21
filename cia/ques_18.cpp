#include <iostream>
#include <string>
class Shape
{
public:
	virtual void draw() = 0;
};
class Circle : public Shape
{
public:
	void draw() override
	{
		std::cout << "Drawing a Circle" << std::endl;
	}
};

class Square : public Shape
{
public:
	void draw() override
	{
		std::cout << "Drawing a Square" << std::endl;
	}
};
class ShapeFactory
{
public:
	virtual Shape *createShape() = 0;
};
class CircleFactory : public ShapeFactory
{
public:
	Shape *createShape() override { return new Circle(); }
};

class SquareFactory : public ShapeFactory
{
public:
	Shape *createShape() override { return new Square(); }
};
int main()
{
	std::cout << "Enter shape type (circle or square): ";
	std::string shapeType;
	std::cin >> shapeType;

	ShapeFactory *shapeFactory = nullptr;
	if (shapeType == "circle")
	{
		shapeFactory = new CircleFactory();
	}
	else if (shapeType == "square")
	{
		shapeFactory = new SquareFactory();
	}
	else
	{
		std::cout << "Invalid shape type entered." << std::endl;
		return 1;
	}
	Shape *shape = shapeFactory->createShape();
	shape->draw();
	delete shapeFactory;
	delete shape;
	return 0;
}
