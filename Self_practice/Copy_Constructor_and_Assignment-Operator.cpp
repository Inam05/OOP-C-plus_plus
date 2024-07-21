/*
Implement a String class with proper memory management. Provide a deep copy constructor and
an overloaded assignment operator to handle deep copying of string data.
*/

#include <iostream>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person() : Person("Unknown", 0)
    {
        cout << "Default constructor called" << endl;
    }

    Person(const string &n, int a) : name(n), age(a)
    {
        cout << "Parameterized constructor called" << endl;
    }

    void display() const
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    Person p1;
    Person p2("John", 30);

    p1.display();
    p2.display();

    return 0;
}
