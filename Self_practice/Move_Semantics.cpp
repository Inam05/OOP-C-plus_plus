/*
Implement a Vector class with move semantics. Provide move constructor and move assignment
operator to efficiently transfer resources without deep copying.
*/

#include <iostream>
using namespace std;

class Moveable
{
private:
    int *data;

public:
    Moveable(int value)
    {
        data = new int(value);
        cout << "Constructed " << *data << endl;
    }

    ~Moveable()
    {
        delete data;
        cout << "Destructed" << endl;
    }

    Moveable(const Moveable &other)
    {
        data = new int(*other.data);
        cout << "Copy constructed " << *data << endl;
    }

    Moveable(Moveable &&other) noexcept
    {
        data = other.data;
        other.data = nullptr;
        cout << "Move constructed" << endl;
    }

    Moveable &operator=(Moveable &&other) noexcept
    {
        if (this != &other)
        {
            delete data;
            data = other.data;
            other.data = nullptr;
            cout << "Move assigned" << endl;
        }
        return *this;
    }

    void display() const
    {
        if (data)
        {
            cout << "Data: " << *data << endl;
        }
        else
        {
            cout << "Data: nullptr" << endl;
        }
    }
};

int main()
{
    Moveable m1(10);
    Moveable m2(move(m1));

    m2.display();
    m1.display();

    Moveable m3(20);
    m3 = move(m2);

    m3.display();
    m2.display();

    return 0;
}
