/*
Create a base class called Geometry with virtual functions
calculateArea() and calculatePerimeter(). Derive subclasses Circle, Rectangle,
and Triangle from Geometry. Implement the calculateArea() and
calculatePerimeter() functions differently in each subclass to calculate the area
and perimeter of the respective shapes.
*/
#include <iostream>
#include <cmath>

using namespace std;

class Geometry
{
public:
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual ~Geometry() = default;
};

class Circle : public Geometry
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override
    {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() const override
    {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Geometry
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() const override
    {
        return length * width;
    }

    double calculatePerimeter() const override
    {
        return 2 * (length + width);
    }
};

class Triangle : public Geometry
{
private:
    double a, b, c; // sides of the triangle
public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}

    double calculateArea() const override
    {
        double s = (a + b + c) / 2; // semi-perimeter
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double calculatePerimeter() const override
    {
        return a + b + c;
    }
};

int main()
{
    Geometry *circle = new Circle(5);
    cout << "Circle Area: " << circle->calculateArea() << endl;
    cout << "Circle Perimeter: " << circle->calculatePerimeter() << endl;

    Geometry *rectangle = new Rectangle(4, 6);
    cout << "Rectangle Area: " << rectangle->calculateArea() << endl;
    cout << "Rectangle Perimeter: " << rectangle->calculatePerimeter() << endl;

    Geometry *triangle = new Triangle(3, 4, 5);
    cout << "Triangle Area: " << triangle->calculateArea() << endl;
    cout << "Triangle Perimeter: " << triangle->calculatePerimeter() << endl;

    delete circle;
    delete rectangle;
    delete triangle;

    return 0;
}
