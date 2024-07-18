/*
Design a class hierarchy for a company with Employee, Manager, Engineer, and Intern classes.
Implement common methods and unique functionalities for each class. Ensure proper use of access
specifiers, constructors, and destructors.
*/
#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    string name;
    int id;
    virtual void display() const = 0;
    virtual ~Employee() {}
};

class Manager : public Employee
{
public:
    void display() const override
    {
        cout << "Manager: " << name << ", ID: " << id << endl;
    }
};

class Engineer : public Employee
{
public:
    void display() const override
    {
        cout << "Engineer: " << name << ", ID: " << id << endl;
    }
};

class Intern : public Employee
{
public:
    void display() const override
    {
        cout << "Intern: " << name << ", ID: " << id << endl;
    }
};

int main()
{
    Manager m;
    m.name = "Alice";
    m.id = 1;

    Engineer e;
    e.name = "Bob";
    e.id = 2;

    Intern i;
    i.name = "Charlie";
    i.id = 3;

    Employee *employees[] = {&m, &e, &i};

    for (int j = 0; j < 3; ++j)
    {
        employees[j]->display();
    }

    return 0;
}
