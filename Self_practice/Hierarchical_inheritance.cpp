#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int rollNumber;

public:
    void getStudent()
    {
        cout << "Enter your name : ";
        cin >> name;
        cout << "Enter your roll number : ";
        cin >> rollNumber;
    }

    void displayStudent()
    {
        cout << "Name of the Student : " << name << endl;
        cout << "Roll Number of the Student : " << rollNumber << endl;
    }
};

class BA : public Student
{
private:
    int urdu, punjabi;

public:
    void getBA()
    {
        getStudent();
        cout << "Enter Urdu marks : ";
        cin >> urdu;
        cout << "Enter Punjabi marks : ";
        cin >> punjabi;
    }

    void displayBA()
    {
        displayStudent();
        cout << "Urdu marks : " << urdu << endl;
        cout << "Punjabi marks : " << punjabi << endl;
    }
};

class BSc : public Student
{
private:
    int phys, chem, math;

public:
    void getBSc()
    {
        getStudent();
        cout << "Enter Physics marks : ";
        cin >> phys;
        cout << "Enter Chemistry marks : ";
        cin >> chem;
        cout << "Enter Maths marks : ";
        cin >> math;
    }

    void displayBSc()
    {
        displayStudent();
        cout << "Physics marks : " << phys << endl;
        cout << "Chemistry marks : " << chem << endl;
        cout << "Maths marks : " << math << endl;
    }
};

int main()
{
    BA baStudent;
    BSc bscStudent;
    int choice;
    cout << "Enter 1 for BA and 2 for BSc : ";
    cin >> choice;
    if (choice == 1)
    {
        baStudent.getBA();
        baStudent.displayBA();
    }
    else
    {
        bscStudent.getBSc();
        bscStudent.displayBSc();
    }
    return 0;
}