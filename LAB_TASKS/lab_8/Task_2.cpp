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
