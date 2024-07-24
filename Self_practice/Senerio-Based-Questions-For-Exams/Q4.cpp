/*
Design a base class Shape with a pure virtual method draw(). Derive classes Circle, Rectangle, and Triangle from Shape. Implement
the draw() method in each derived class to draw the specific shape.
*/

// code

#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing a Circle" << endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing a Rectangle" << endl;
    }
};

class Triangle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing a Triangle" << endl;
    }
};

int main()
{
    Shape *s1 = new Circle();
    Shape *s2 = new Rectangle();
    Shape *s3 = new Triangle();
    s1->draw();
    s2->draw();
    s3->draw();
    delete s1;
    delete s2;
    delete s3;
    return 0;
}
