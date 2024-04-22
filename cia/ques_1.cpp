//Design a class hierarchy to represent different shapes such as Circle, Rectangle, and 
//Triangle. Include methods to calculate the area and perimeter of each shape. Implement 
//appropriate constructors and destructor. 

#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
    public:
    virtual void area() = 0;
    virtual void perimeter() = 0;
    ~Shape()
    {
        cout<<"Destructor of Shape"<<endl;
    }
};

class Circle: public Shape
{
    float radius;
    public:
    Circle(float r)
    {
        radius = r;
    }
    void area()
    {
        cout<<"Area of Circle: "<<3.14*radius*radius<<endl;
    }
    void perimeter()
    {
        cout<<"Perimeter of Circle: "<<2*3.14*radius<<endl;
    }
    ~Circle()
    {
        cout<<"Circle Destroyed"<<endl;
    }
};

class Rectangle: public Shape
{
    float length, breadth;
    public:
    Rectangle(float l, float b)
    {
        length = l;
        breadth = b;
    }
    void area()
    {
        cout<<"Area of Rectangle: "<<length*breadth<<endl;
    }
    void perimeter()
    {
        cout<<"Perimeter of Rectangle: "<<2*(length+breadth)<<endl;
    }
    ~Rectangle()
    {
        cout<<"Rectangle Destroyed"<<endl;
    }
};

class Triangle: public Shape
{
    float a, b, c;
    public:
    Triangle(float x, float y, float z)
    {
        a = x;
        b = y;
        c = z;
    }
    void area()
    {
        float s = (a+b+c)/2;
        cout<<"Area of Triangle: "<<sqrt(s*(s-a)*(s-b)*(s-c))<<endl;
    }
    void perimeter()
    {
        cout<<"Perimeter of Triangle: "<<a+b+c<<endl;
    }
    ~Triangle()
    {
        cout<<"Triangle Destroyed"<<endl;
    }
};

int main()
{
    Circle c(5);
    c.area();
    c.perimeter();
    Rectangle r(5, 10);
    r.area();
    r.perimeter();
    Triangle t(3, 4, 5);
    t.area();
    t.perimeter();
    return 0;
}
