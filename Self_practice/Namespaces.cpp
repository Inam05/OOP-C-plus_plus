/*
Create a namespace Math that contains various mathematical functions like add, subtract, multiply,
and divide. Demonstrate the usage of these functions within and outside the namespace.
*/

#include <iostream>
using namespace std;

namespace Geometry
{
    class Point
    {
    private:
        int x, y;

    public:
        Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

        void display()
        {
            cout << "Point (" << x << ", " << y << ")" << endl;
        }
    };
}

int main()
{
    Geometry::Point p(3, 4);
    p.display();

    return 0;
}
