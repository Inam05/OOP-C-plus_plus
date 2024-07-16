/*
: Multiple Inheritance
According to the following algorithm, write a C++ program:
Step 1: Take two classes teacher and student
Step 2: Within the teacher class Enter name and teacher Id with the help of getdata()
function and display this data using putdata() function.
Step 3: Within the student class Enter and display marks m1,m2,m3 with the help of
getdata(),putdata() functions.
Step 4: Within the student class extends teacher class and using data and their functions to
the student class. 
*/
#include <iostream>
#include <string>
using namespace std;

class Teacher
{
protected:
    string name;
    int teacherId;

public:
    void getdata()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter teacher ID: ";
        cin >> teacherId;
    }
    void putdata()
    {
        cout << "Name: " << name << ", Teacher ID: " << teacherId << endl;
    }
};

class Student : public Teacher
{
private:
    int m1, m2, m3;

public:
    void getdata()
    {
        Teacher::getdata();
        cout << "Enter marks for 3 subjects: ";
        cin >> m1 >> m2 >> m3;
    }
    void putdata()
    {
        Teacher::putdata();
        cout << "Marks: " << m1 << ", " << m2 << ", " << m3 << endl;
    }
};

int main()
{
    Student student;
    student.getdata();
    student.putdata();
    return 0;
}
