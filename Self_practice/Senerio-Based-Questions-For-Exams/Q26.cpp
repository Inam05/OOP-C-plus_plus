/*
Design a class Person with attributes name and age. Derive classes Teacher and Student from Person. Implement all four types of
constructors for Person. Add a method displayRole() to demonstrate polymorphism.
*/

#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person() : name(""), age(0) {}                                     // Default constructor
    Person(string n, int a) : name(n), age(a) {}                       // Parameterized constructor
    Person(const Person &p) : name(p.name), age(p.age) {}              // Copy constructor
    Person(Person &&p) : name(move(p.name)), age(p.age) { p.age = 0; } // Move constructor

    virtual void displayRole() = 0; // Pure virtual function
};

class Teacher : public Person
{
public:
    Teacher() : Person() {}
    Teacher(string n, int a) : Person(n, a) {}
    Teacher(const Teacher &t) : Person(t) {}
    Teacher(Teacher &&t) : Person(move(t)) {}

    void displayRole() override
    {
        cout << "Teacher: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person
{
public:
    Student() : Person() {}
    Student(string n, int a) : Person(n, a) {}
    Student(const Student &s) : Person(s) {}
    Student(Student &&s) : Person(move(s)) {}

    void displayRole() override
    {
        cout << "Student: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    Teacher t1("Mr. Smith", 40);
    Student s1("Alice", 20);

    t1.displayRole();
    s1.displayRole();

    return 0;
}
