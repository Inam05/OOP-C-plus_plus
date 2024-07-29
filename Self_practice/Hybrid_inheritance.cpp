#include <iostream>
using namespace std;

class Student
{
private:
    char name[20];
    int mo;

public:
    void getStudent()
    {
        cout << "Enter your name : " << endl;
        cin >> name;
        cout << "Enter your roll number : " << endl;
        cin >> mo;
    }

    void displayStudent()
    {
        cout << "Name of the Student : " << name << endl;
        cout << "Roll Number of the Student : " << mo << endl;
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

class Address
{
private:
    string city;

public:
    void getAddress()
    {
        cout << "Enter city : ";
        cin >> city;
    }

    void displayAddress()
    {
        cout << "City : " << city << endl;
    }
};

class Result : public Test, public Address
{
private:
    int total, avg;

public:
    void getResult()
    {
        getTest();
        getAddress();
        total = math + eng + sci;
        avg = total / 3;
    }

    void displayResult()
    {
        displayTest(); 
        displayAddress();
        cout << "Total Marks : " << total << endl;
        cout << "Average Marks : " << avg << endl;
        displayAddress(); 
    }
};

int main()
{
    Result result;
    result.getResult();
    result.displayResult();
    return 0;
}
