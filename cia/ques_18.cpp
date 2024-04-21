// Abstract product class
#include <iostream>
#include <string>
class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape()
	{
	} // Virtual destructor for polymorphism
};
// Concrete product class - Circle
class Circle : public Shape
{
public:
	void draw() override
	{
		std::cout << "Drawing a Circle" << std::endl;
	}
};

// Concrete product class - Square
class Square : public Shape
{
public:
	void draw() override
	{
		std::cout << "Drawing a Square" << std::endl;
	}
};
// Abstract creator class
class ShapeFactory
{
public:
	virtual Shape *createShape() = 0;
	virtual ~ShapeFactory()
	{
	} // Virtual destructor for polymorphism
};
// Concrete creator class - CircleFactory
class CircleFactory : public ShapeFactory
{
public:
	Shape *createShape() override { return new Circle(); }
};

// Concrete creator class - SquareFactory
class SquareFactory : public ShapeFactory
{
public:
	Shape *createShape() override { return new Square(); }
};
int main()
{

	// Client code based on user-input

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
