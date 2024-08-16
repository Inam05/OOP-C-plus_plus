/*
Create a class hierarchy to demonstrate the diamond problem in C++ using multiple inheritance. For instance, create a base
class A, and two classes B and C that both inherit from A. Then create a class D that inherits from both B and C. Resolve
the diamond problem using virtual inheritance. Illustrate the use of virtual base classes to avoid ambiguity and ensure
proper object construction.
*/

#include <iostream>
using namespace std;

// Base class A
class A
{
public:
    A() { cout << "Constructor A" << endl; }
    void display() { cout << "Class A" << endl; }
};

// Derived class B inheriting virtually from A
class B : virtual public A
{
public:
    B() { cout << "Constructor B" << endl; }
    void display() { cout << "Class B" << endl; }
};

// Derived class C inheriting virtually from A
class C : virtual public A
{
public:
    C() { cout << "Constructor C" << endl; }
    void display() { cout << "Class C" << endl; }
};

// Derived class D inheriting from B and C
class D : public B, public C
{
public:
    D() { cout << "Constructor D" << endl; }
    void display() { cout << "Class D" << endl; }
};

// Main function to demonstrate the diamond problem and virtual inheritance
int main()
{
    D d; // Create an instance of D

    // Call display methods
    d.display();    // Calls display() of D
    d.B::display(); // Calls display() of B
    d.C::display(); // Calls display() of C
    d.A::display(); // Calls display() of A, showing correct base class instance

    return 0;
}
