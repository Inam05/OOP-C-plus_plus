/*
Create a base class Person with attributes name and age. Derive two classes Student and Teacher from Person. Implement polymorphic
behavior for a method displayInfo() to display information specific to Student and Teacher.
*/

// code
#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void displayInfo()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person
{
private:
    string studentID;

public:
    Student(string n, int a, string id) : Person(n, a), studentID(id) {}
    void displayInfo() override
    {
        cout << "Student Name: " << name << ", Age: " << age << ", ID: " << studentID << endl;
    }
};

class Teacher : public Person
{
private:
    string subject;

public:
    Teacher(string n, int a, string s) : Person(n, a), subject(s) {}
    void displayInfo() override
    {
        cout << "Teacher Name: " << name << ", Age: " << age << ", Subject: " << subject << endl;
    }
};

int main()
{
    Person *p1 = new Student("John Doe", 20, "S123");
    Person *p2 = new Teacher("Jane Smith", 40, "Mathematics");
    p1->displayInfo();
    p2->displayInfo();
    delete p1;
    delete p2;
    return 0;
}
