#include <iostream>
using namespace std;

class myClass
{
private:
    int value;

public:
    myClass(int value = 0) : value(value) {} // Constructor with default value

    // Overloading the + operator to work with myClass and int
    myClass operator+(int b) const
    {
        // This example returns a new myClass object with the result of value + b
        return this->value + b;
    }

    // Function to display the value for demonstration purposes
    void display() const
    {
        cout << "Value: " << value << endl;
    }
};

int main()
{
    int a = 5;           // Value to add
    myClass object1(10); // Initialize object1 with value 10
    myClass object2;

    object2 = object1 + a; // Using the overloaded + operator

    object2.display(); // Display the result

    return 0;
}
