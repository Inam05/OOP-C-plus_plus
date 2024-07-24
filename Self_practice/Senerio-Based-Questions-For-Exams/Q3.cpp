/*
Create a base class Staff with attributes staffID and name. Derive classes Doctor and Nurse from Staff. Implement polymorphic behavior
for a method dutySchedule() that provides the duty schedules for doctors and nurses.
*/

// code

#include <iostream>
using namespace std;

class Staff
{
protected:
    int staffID;
    string name;

public:
    Staff(int id, string n) : staffID(id), name(n) {}
    virtual void dutySchedule()
    {
        cout << "Generic staff duty schedule" << endl;
    }
};

class Doctor : public Staff
{
private:
    string specialization;

public:
    Doctor(int id, string n, string s) : Staff(id, n), specialization(s) {}
    void dutySchedule() override
    {
        cout << "Doctor " << name << " specializes in " << specialization << " and works from 9 AM to 5 PM" << endl;
    }
};

class Nurse : public Staff
{
private:
    string department;

public:
    Nurse(int id, string n, string d) : Staff(id, n), department(d) {}
    void dutySchedule() override
    {
        cout << "Nurse " << name << " works in " << department << " department from 7 AM to 3 PM" << endl;
    }
};

int main()
{
    Staff *s1 = new Doctor(1, "Dr. John", "Cardiology");
    Staff *s2 = new Nurse(2, "Nurse Mary", "Pediatrics");
    s1->dutySchedule();
    s2->dutySchedule();
    delete s1;
    delete s2;
    return 0;
}
