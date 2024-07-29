#include <iostream>
using namespace std;

class myClass
{
private:
    int value;

public:
    myClass(int value = 0) // Default constructor for convenience
    {
        this->value = value;
    }

    // Overloading the + operator to work with myClass and myClass
    myClass operator+(myClass &object2) const
    {
        // This example simply returns a new myClass object with the sum of values
        return this->value + object2.value;
    }

    // Function to display the value for demonstration purposes
    void display() const
    {
        cout << "Value: " << value << endl;
    }
};

int main()
{
    myClass object1(10); // Initialize with value 10
    myClass object2(20); // Initialize with value 20

    myClass result = object1 + object2; // Using the overloaded + operator
    result.display();                   // Display the result

    return 0;
}
