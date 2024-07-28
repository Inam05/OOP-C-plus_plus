/*There's a base class Employee, and two derived classes Manager and Developer, which inherit from Employee.
Now, you need to create a class TeamLead which represents an employee who is both a manager and a developer*/

#include <iostream>
using namespace std;

class Employee
{
public:
    void work()
    {
        cout << "Employee is working." << endl;
    }
};

class Manager : public Employee
{
public:
    void manage()
    {
        cout << "Manager is managing." << endl;
    }
};

class Developer : public Employee
{
public:
    void code()
    {
        cout << "Developer is coding." << endl;
    }
};

class TeamLead : public Manager, public Developer
{
public:
    void coordinate()
    {
        cout << "TeamLead is coordinating." << endl;
    }

    void work()
    {
        Manager::work();
    }
};

int main()
{
    TeamLead lead;
    lead.work();
    lead.manage();
    lead.code();
    lead.coordinate();
    return 0;
}
