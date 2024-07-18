/*
Create a base class Shape with derived classes Circle, Rectangle, and Triangle. Implement a
virtual function draw() in the base class and override it in the derived classes.
Use polymorphism to draw different shapes.
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

int main()
{
    Circle c;
    Rectangle r;
    Triangle t;

    Shape *shapes[] = {&c, &r, &t};

    for (int i = 0; i < 3; ++i)
    {
        shapes[i]->draw();
    }

    return 0;
}
