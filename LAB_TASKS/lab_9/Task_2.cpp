/*
Create a base class called Employee with virtual functions
calculateSalary() and displayInfo(). Derive subclasses FullTimeEmployee and
PartTimeEmployee from Employee. Implement the calculateSalary() function
differently in each subclass to calculate the salary based on hours worked or fixed
salary, and implement displayInfo() to show employee details.
*/
#include <iostream>
#include <string>

using namespace std;

class Employee
{
protected:
    string name;
    int id;

public:
    Employee(string name, int id)
    {
        this-> name = name;
        this-> id = id;
    }

    double calculateSalary()
    {
        return 0.0;
    }

    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

class FullTimeEmployee : public Employee
{
private:
    double salary;

public:
    FullTimeEmployee(string name, int id, double salary) : Employee(name, id)
    {
        this-> name = name;
        this-> id = id;
        this-> salary = salary;
    }

    double calculateSalary()
    {
        return salary;
    }
};

class PartTimeEmployee : public Employee
{
private:
    double hourlyRate;
    int hoursWorked;

public:
    PartTimeEmployee(string n, int i, double rate, int hours) : Employee(n, i), hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary()
    {
        return hourlyRate * hoursWorked;
    }
};

int main()
{
    FullTimeEmployee fullTimeEmp("John Doe", 101, 5000.0);
    PartTimeEmployee partTimeEmp("Jane Smith", 102, 15.0, 30);

    cout << "Full-Time Employee Details:" << endl;
    fullTimeEmp.displayInfo();
    cout << "Salary: $" << fullTimeEmp.calculateSalary() << endl;

    cout << endl;

    cout << "Part-Time Employee Details:" << endl;
    partTimeEmp.displayInfo();
    cout << "Salary: $" << partTimeEmp.calculateSalary() << endl;

    return 0;
}
