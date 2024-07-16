/*
Hierarchical Inheritance
Create a base class called `Shape` with a function called `draw()` that displays the shape's
information. Derive two subclasses, `Circle` and `Square`, from the `Shape` class. Use
the `draw()` function in each subclass to display specific information about the circle and
square.
*/
#include <iostream>
#include <string>
using namespace std;

class Shape
{
public:
    void draw()
    {
        cout << "Drawing Shape" << endl;
    }
};

class Circle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing Circle" << endl;
    }
};

class Square : public Shape
{
public:
    void draw()
    {
        cout << "Drawing Square" << endl;
    }
};

int main()
{
    Circle circle;
    Square square;
    circle.draw();
    square.draw();
    return 0;
}
