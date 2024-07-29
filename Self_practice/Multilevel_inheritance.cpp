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

class Test : public Student
{
protected:
    int math, eng, sci;

public:
    void getTest()
    {
        getStudent();
        cout << "Enter math marks : ";
        cin >> math;
        cout << "Enter english marks : ";
        cin >> eng;
        cout << "Enter science marks : ";
        cin >> sci;
    }

    void displayTest()
    {
        displayStudent();
        cout << "Math Marks : " << math << endl;
        cout << "English Marks : " << eng << endl;
        cout << "Science Marks : " << sci << endl;
    }
};

class Result : public Test
{
private:
    int total, avg;

public:
    void getResult()
    {
        getTest();
        total = math + eng + sci;
        avg = total / 3;
    }

    void displayResult()
    {
        displayResult();
        cout << "Total Marks : " << total << endl;
        cout << "Average Marks : " << avg << endl;
    }
};

int main()
{
    Result student;
    student.getResult();
    student.displayResult();

    return 0;
}