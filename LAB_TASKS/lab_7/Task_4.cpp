#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
    string name;
    int id;
    float gpa;
    Student()
    {
        name = " ";
        id = 0;
        gpa = 0.0;
    }
    void display()
    {
        cout << "Name: " << name << ", ID: " << id << ", GPA: " << gpa << endl;
    }
};
const int max_students = 100;
Student studentDatabase[max_students];
int studentCount = 0;
void addStudent(const string &name, int id, float gpa)
{
    if (studentCount < max_students)
    {
        studentDatabase[studentCount].name = name;
        studentDatabase[studentCount].id = id;
        studentDatabase[studentCount].gpa = gpa;
        studentCount++;
    }
    else
    {
        cout << "Database is full. Cannot add more students." << endl;
    }
}
Student *searchByName(const string &name)
{
    for (int i = 0; i < studentCount; i++)
    {
        if (studentDatabase[i].name == name)
        {
            return &studentDatabase[i];
        }
    }
    return nullptr;
}
Student *searchById(int id)
{
    for (int i = 0; i < studentCount; i++)
    {
        if (studentDatabase[i].id == id)
        {
            return &studentDatabase[i];
        }
    }
    return nullptr;
}
void displayAllStudents()
{
    for (int i = 0; i < studentCount; i++)
    {
        studentDatabase[i].display();
    }
}
int main()
{
    string Name;
    int Id;
    float Gpa;
    char n;
    do
    {
        cout << "Enter student's name: ";
        cin >> Name;
        cout << "Enter student's ID: ";
        cin >> Id;
        cout << "Enter student's GPA: ";
        cin >> Gpa;
        addStudent(Name, Id, Gpa);
        cout << "Do you want to add another student? (y/n): ";
        cin >> n;
    } while (n == 'y' || n == 'Y');
    cout << "Search by name or ID? (n/i): ";
    cin >> n;
    if (n == 'n' || n == 'N')
    {
        cout << "Enter student's name: ";
        cin >> Name;
        Student *foundStudent = searchByName(Name);
        if (foundStudent)
        {
            foundStudent->display();
        }
        else
        {
            cout << "Student not found." << endl;
        }
    }
    else if (n == 'i' || n == 'I')
    {
        cout << "Enter student's ID: ";
        cin >> Id;
        Student *foundStudent = searchById(Id);
        if (foundStudent)
        {
            foundStudent->display();
        }
        else
        {
            cout << "Student not found." << endl;
        }
    }
    cout << "\nAll students:" << endl;
    displayAllStudents();
    return 0;
}