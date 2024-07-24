/*
Create a base class Employee with attributes employeeID and name. Derive classes Manager and Engineer from Employee. Implement a
virtual method calculateSalary() in the base class and override it in the derived classes to calculate salaries based on the employee type.
*/

#include <iostream>
using namespace std;

class Employee
{
protected:
    int employeeID;
    string name;

public:
    Employee(int id, string n) : employeeID(id), name(n) {}
    virtual float calculateSalary() = 0; // Pure virtual function
};

class Manager : public Employee
{
private:
    float baseSalary;

public:
    Manager(int id, string n, float salary) : Employee(id, n), baseSalary(salary) {}
    float calculateSalary() override
    {
        return baseSalary + (baseSalary * 0.1); // 10% bonus
    }
};

class Engineer : public Employee
{
private:
    float hourlyRate;
    int hoursWorked;

public:
    Engineer(int id, string n, float rate, int hours) : Employee(id, n), hourlyRate(rate), hoursWorked(hours) {}
    float calculateSalary() override
    {
        return hourlyRate * hoursWorked;
    }
};

int main()
{
    Employee *e1 = new Manager(1, "Alice", 5000);
    Employee *e2 = new Engineer(2, "Bob", 50, 160);
    cout << "Manager's Salary: $" << e1->calculateSalary() << endl;
    cout << "Engineer's Salary: $" << e2->calculateSalary() << endl;
    delete e1;
    delete e2;
    return 0;
}
