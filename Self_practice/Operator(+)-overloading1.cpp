#include <iostream>
using namespace std;

class myClass
{
private:
    int value;

public:
    myClass(int value)
    {
        this->value = value;
    }
    // Overloading the + operator to work with myClass and int
    int operator+(int b)
    {
        // This example simply returns b + 5 for demonstration purposes
        return value + b;
    }
};

int main()
{
    int a, b = 10; // Assign a value to b for demonstration
    myClass object(10);
    a = object + b;                                       // Using the overloaded + operator
    cout << "The result of object + b is: " << a << endl; // Display the result
    return 0;
}
