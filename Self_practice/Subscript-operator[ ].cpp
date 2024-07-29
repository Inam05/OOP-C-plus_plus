#include <iostream>
using namespace std;
class Student
{
private:
    double gpa[8];

public:
    Student()
    {
        gpa[0] = 3.5;
        gpa[1] = 3.2;
        gpa[2] = 4;
        gpa[3] = 3.3;
        gpa[4] = 3.8;
        gpa[5] = 3.6;
        gpa[6] = 3.5;
        gpa[7] = 3.8;
    }
    double &operator[](int Index)
    {
        return gpa[Index];
    }
    void print()
    {
        for (int i = 0; i < 8; i++)
        {
            cout << gpa[i] << endl;
        }
    }
};

int main()
{
    Student semesterGPA;
    semesterGPA[5] = 10.9;
    double gpa = semesterGPA[5];
    cout << gpa << endl;
    semesterGPA.print();
}
