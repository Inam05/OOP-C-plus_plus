/*
Design a ShapeFactory class that creates objects of different shape classes (Circle, Rectangle, Triangle).
Use the Factory design pattern to demonstrate object creation.
*/

#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
    void draw() const override
    {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw() const override
    {
        cout << "Drawing Rectangle" << endl;
    }
};

class Triangle : public Shape
{
public:
    void draw() const override
    {
        cout << "Drawing Triangle" << endl;
    }
};

class ShapeFactory
{
public:
    static Shape *createShape(const string &type)
    {
        if (type == "Circle")
            return new Circle();
        else if (type == "Rectangle")
            return new Rectangle();
        else if (type == "Triangle")
            return new Triangle();
        else
            return nullptr;
    }
};

int main()
{
    Shape *shape1 = ShapeFactory::createShape("Circle");
    Shape *shape2 = ShapeFactory::createShape("Rectangle");
    Shape *shape3 = ShapeFactory::createShape("Triangle");

    shape1->draw();
    shape2->draw();
    shape3->draw();

    delete shape1;
    delete shape2;
    delete shape3;

    return 0;
}
