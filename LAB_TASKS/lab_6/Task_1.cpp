/*
Create a class representing a Point in 2D space with x and y coordinates. Declare a
constant pointer to an object of this class and call both constant and non-constant
member functions through this pointer.
Implement constant member functions to calculate distance from another point
without modifying the point's coordinates.
*/
#include <iostream>
using namespace std;

class Point
{
private:
    double x, y;

    double sqrt(double value) const
    {
        double approx = value / 2.0;
        double better_approx = 0.5 * (approx + value / approx);
        while (approx != better_approx)
        {
            approx = better_approx;
            better_approx = 0.5 * (approx + value / approx);
        }
        return approx;
    }

public:
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }

    void setX(double x_coord)
    {
        x = x_coord;
    }
    void setY(double y_coord)
    {
        y = y_coord;
    }

    double distance(const Point &other) const
    {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};
int main()
{
    Point p1(3.0, 4.0);
    Point p2(0.0, 0.0);

    const Point *const ptr = &p1;

    cout << "Distance from point 2 to point 1: " << ptr->distance(p2) << endl;

    return 0;
}
