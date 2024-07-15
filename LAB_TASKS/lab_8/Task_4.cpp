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
