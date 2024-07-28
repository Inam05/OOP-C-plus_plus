#include <iostream>
using namespace std;
class student
{
private:
    char name[20];
    int rno;

public:
    void getstudent()
    {
        cout << "enter name of the student=";
        cin >> name;
        cout << "enter roll number of the student=";
        cin >> rno;
    }
    void displaystudent()
    {
        cout << "name of the student=" << name;
        cout << "roll number of the student=" << rno;
    }
};

class test : public student
{
protected:
    int math, eng, sci;

public:
    void gettest()
    {
        getstudent();
        cout << "enter math marks=";
        cin >> math;
        cout << "enter english marks=";
        cin >> eng;
        cout << "enter science marks=";
        cin >> sci;
    }
    void displaytest()
    {
        displaystudent();
        cout << "math marks=" << math;
        cout << "english marks=" << eng;
        cout << "science marks=" << sci;
    }
};

class result : public test
{
private:
    int total, avg;

public:
    void getresult()
    {
        gettest();
        total = math + eng + sci;
        avg = total / 3;
    }
    void displayresult()
    {
        displaytest();
        cout << "Total Marks=" << total;
        cout << "Average marks=" << avg;
    }
};

int main()
{
    result r1;
    r1.getresult();
    r1.displayresult();
}
