/*
Define an abstract class Animal with pure virtual functions makeSound() and move(). Create derived classes Dog, Cat, and Bird that implement 
these functions. Use the abstract class to demonstrate polymorphism.
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
