/*
Create a base class Person with attributes name and age. Derive classes Student and Faculty from Person. Implement polymorphic 
behavior for a method displayDetails() to display details specific to students and faculty members.
*/

#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void displayDetails() = 0; // Pure virtual function
};

class Student : public Person {
private:
    string studentID;
public:
    Student(string n, int a, string id) : Person(n, a), studentID(id) {}
    void displayDetails() override {
        cout << "Student Name: " << name << ", Age: " << age << ", ID: " << studentID << endl;
    }
};

class Faculty : public Person {
private:
    string facultyID;
    string department;
public:
    Faculty(string n, int a, string id, string dept) : Person(n, a), facultyID(id), department(dept) {}
    void displayDetails() override {
        cout << "Faculty Name: " << name << ", Age: " << age << ", ID: " << facultyID << ", Department: " << department << endl;
    }
};

int main() {
    Person* p1 = new Student("Alice", 20, "S123");
    Person* p2 = new Faculty("Dr. Bob", 45, "F456", "Physics");
    p1->displayDetails();
    p2->displayDetails();
    delete p1;
    delete p2;
    return 0;
}

