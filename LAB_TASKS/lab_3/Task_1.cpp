/*
Write a program to create an employee class using parameterized constructor with two
parameters id and name and along with method displayinfo() to display the data.
While creating the objects obj1 and obj2 passed two arguments so that this
constructor gets invoked after creation of obj1 and obj2.
*/
#include <iostream>
using namespace std;
class Employee {
private:
    int id;
    const char* name;

public:
    Employee(int Id, const char* Name) {
        id = Id;
        name = Name;
    }

    void display_info() {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
    }
};

int main() {
    Employee obj1(219, "Inam");
    Employee obj2(100, "Taimoor");

    cout << "Employee 1 Information:" << endl;
    obj1.display_info();
    cout << endl;

    cout << "Employee 2 Information:" << endl;
    obj2.display_info();
    
    return 0;
}