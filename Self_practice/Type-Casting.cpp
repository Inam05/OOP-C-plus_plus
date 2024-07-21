/*
Demonstrate the use of different type casting operators (static_cast, dynamic_cast, const_cast, and reinterpret_cast) in various scenarios. Provide
code examples for each type cast and explain their use cases.
*/

#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show()
    {
        cout << "Base class show function" << endl;
    }
};

class Derived : public Base
{
public:
    void show() override
    {
        cout << "Derived class show function" << endl;
    }

    void exclusive()
    {
        cout << "Derived class exclusive function" << endl;
    }
};

int main()
{
    Base *b = new Derived();
    b->show();

    Derived *d = dynamic_cast<Derived *>(b);
    if (d)
    {
        d->exclusive();
    }
    else
    {
        cout << "Type casting failed" << endl;
    }

    delete b;

    return 0;
}
