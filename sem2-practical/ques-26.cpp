#include <iostream>
using namespace std;

class Shape {
protected:
	Shape() = default;
public:
	friend Shape createShape();
	virtual float area() { return 0; }
	virtual ~Shape() { cout << "Shape Destructor\n"; }
	virtual void findArea(int sides);
};

class Rectangle : public Shape {
	float l, b;
public:
	Rectangle(float _l, float _b) : l(_l), b(_b) {}
	float area() { return l * b; }
	~Rectangle() { cout << "Rectangle Destructor\n"; }
	void findArea(int sides) {}
};
class Circle : public Shape {
	float r;
public:
	Circle(float _r) : r(_r) {}
	float area() { return 3.14 * r * r; }
	~Circle() { cout << "Circle Destructor\n"; }
	void findArea(int sides) {}
};

void Shape::findArea(int sides) {
	Shape *shape;
	if (sides == 4) {
		cout << "Rectangle\nEnter length and breadth: ";
		int l, b; cin >> l >> b;
		shape = new Rectangle(l, b);
	}
	else if (sides == 1) {
		cout << "Circle\nEnter Radius: ";
		int r; cin >> r;
		shape = new Circle(r);
	}
	if (sides != 4 && sides != 1) { cout << "Invalid Input\n"; }
	else {
		float a = shape->area();
		cout << "Area: " << a << endl;
		delete shape;
	}
}
Shape createShape() { return Shape(); }
int main() {
	Shape s = createShape();
	s.findArea(0);
	cout << endl;
	s.findArea(1);
	cout << endl;
	return 0;
}
/*
Output:
Invalid Input

Circle
Enter Radius: 7
Area: 153.86
Circle Destructor
Shape Destructor

Shape Destructor
*/
