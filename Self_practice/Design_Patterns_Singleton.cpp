/*
Implement the Singleton design pattern for a Logger class that logs messages to a file. Ensure thread safety and proper resource management.
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
