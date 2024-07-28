#include <iostream>
using namespace std;

class Shape
{
protected:
    int width, height;

public:
    Shape (int w , int h)
    {
        width = w ;
        height = h;
    }
    int getArea()
    {
        return width * height;
    }
};

class Rectangle : public Shape
{
public:
    Rectangle(int w, int h) : Shape(w, h) {}
    bool isSquare()
    {
        return width == height;
    }
};

int main()
{
    Rectangle r(5, 5);
    cout << "Area: " << r.getArea() << endl;
    cout << "Is Square? " << (r.isSquare() ? "Yes" : "No") << endl;
    return 0;
}
