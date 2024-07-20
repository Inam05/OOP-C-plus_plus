/*
Create a Rectangle class and a Square class. Implement a friend function that checks if a square can fit inside a rectangle. Also,
make one class a friend of the other and demonstrate the usage.
*/

#include <iostream>
using namespace std;

class Square;

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    friend bool canFit(const Rectangle &rect, const Square &sq);
};

class Square
{
private:
    double side;

public:
    Square(double s) : side(s) {}

    friend bool canFit(const Rectangle &rect, const Square &sq);
};

bool canFit(const Rectangle &rect, const Square &sq)
{
    return (sq.side <= rect.length && sq.side <= rect.width);
}

int main()
{
    Rectangle rect(10, 5);
    Square sq(4);

    if (canFit(rect, sq))
    {
        cout << "Square can fit inside the Rectangle" << endl;
    }
    else
    {
        cout << "Square cannot fit inside the Rectangle" << endl;
    }

    return 0;
}
