/*
Create a scenario with multiple inheritance where a class Hybrid inherits from two base classes Base1 and Base2.
Implement a method in Hybrid that resolves ambiguity arising from multiple inheritance.
*/

#include <iostream>
using namespace std;

class Base1
{
public:
    void greet()
    {
        cout << "Hello from Base1" << endl;
    }
};

class Base2
{
public:
    void greet()
    {
        cout << "Hello from Base2" << endl;
    }
};

class Hybrid : public Base1, public Base2
{
public:
    void greet()
    {
        Base1::greet(); // Resolving ambiguity
        Base2::greet();
    }
};

int main()
{
    Hybrid h;
    h.greet();

    return 0;
}
