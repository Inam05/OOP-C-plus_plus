/*
Create a base class Employee with attributes employeeID and name. Derive classes Chef, Waiter, and Manager from Employee. Implement 
polymorphic behavior for a method getRoleDescription() to describe the role of each type of employee.
*/

#include <iostream>
using namespace std;

class Employee {
protected:
    int employeeID;
    string name;
public:
    Employee(int id, string n) : employeeID(id), name(n) {}
    virtual void getRoleDescription() = 0; // Pure virtual function
};

class Chef : public Employee {
public:
    Chef(int id, string n) : Employee(id, n) {}
    void getRoleDescription() override {
        cout << "Chef " << name << " is responsible for preparing food." << endl;
    }
};

class Waiter : public Employee {
public:
    Waiter(int id, string n) : Employee(id, n) {}
    void getRoleDescription() override {
        cout << "Waiter " << name << " is responsible for serving customers." << endl;
    }
};

class Manager : public Employee {
public:
    Manager(int id, string n) : Employee(id, n) {}
    void getRoleDescription() override {
        cout << "Manager " << name << " is responsible for managing the restaurant." << endl;
    }
};

int main() {
    Employee* e1 = new Chef(1, "Gordon Ramsay");
    Employee* e2 = new Waiter(2, "John Doe");
    Employee* e3 = new Manager(3, "Jane Smith");
    e1->getRoleDescription();
    e2->getRoleDescription();
    e3->getRoleDescription();
    delete e1;
    delete e2;
    delete e3;
    return 0;
}

