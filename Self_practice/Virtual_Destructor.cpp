/*
Explain and demonstrate the importance of virtual destructors in a class hierarchy involving base and derived classes.
Provide code examples to show the proper use of virtual destructors.
*/

#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show() { cout << "Base class" << endl; }
    virtual ~Base() { cout << "Base class destructor" << endl; } // Virtual destructor
};

class Derived : public Base
{
public:
    void show() override { cout << "Derived class" << endl; }
    void derivedOnly() { cout << "Derived only function" << endl; }
    ~Derived() { cout << "Derived class destructor" << endl; } // Virtual destructor
};

int main()
{
    Base *basePtr = new Derived();

    // Safe downcasting
    Derived *derivedPtr = dynamic_cast<Derived *>(basePtr);
    if (derivedPtr)
    {
        derivedPtr->show();        // Output: Derived class
        derivedPtr->derivedOnly(); // Output: Derived only function
    }
    else
    {
        cout << "Cast failed" << endl;
    }

    delete basePtr; // Correctly calls Derived destructor then Base destructor
    return 0;
}
