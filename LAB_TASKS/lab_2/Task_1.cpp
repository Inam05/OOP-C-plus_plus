#include <iostream>
using namespace std;
class Student
{
public:
    string name;
    int number;
    float percentage;

    void inputData()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Registration Number: ";
        cin >> number;
        cout << "Enter Percentage: ";
        cin >> percentage;
    }

    void displayData()
    {
        cout << "Name: " << name << endl;
        cout << "Registration Number: " << number << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main()
{
    Student student;
    student.inputData();
    cout << "\nStudent Information:\n";
    student.displayData();
    return 0;
}