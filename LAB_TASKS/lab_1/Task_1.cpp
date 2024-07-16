// Write a C++ Program to sort two numbers
#include <iostream>
using namespace std;
double perimeter(double length, double width)
{
    return 2 * (length + width);
}

double area(double length, double width)
{
    return length * width;
}

int main()
{
    double length, width;
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;
    if (length <= 0 || width <= 0)
    {
        cout << "Invalid input. Length and width must be positive numbers." << endl;
        return 1; 
    }
    cout << "Perimeter of the rectangle: " << perimeter(length, width) << endl;
    cout << "Area of the rectangle: " << area(length, width) << endl;
    return 0; 
}