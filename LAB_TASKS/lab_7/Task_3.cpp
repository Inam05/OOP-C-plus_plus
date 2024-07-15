#include <iostream>
#include <string>
using namespace std;
class Course
{
private:
    string courseName, instructor, schedule;
    int courseID;

public:
    Course()
    {
        courseName = " ";
        courseID = 0;
        instructor = " ";
        schedule = " ";
    }
    Course(string name, int id, string instr, string sched)
    {
        courseName = name;
        courseID = id;
        instructor = instr;
        schedule = sched;
    }
    void displayCourseInfo() const
    {
        cout << "Course Name: " << courseName << endl;
        cout << "Course ID: " << courseID << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Schedule: " << schedule << endl;
    }
};
int main()
{
    Course course1;
    course1.displayCourseInfo();
    Course course2("Object-Oriented Programming", 101, "Mam Amna", "10:40AM to 1:20PM");
    course2.displayCourseInfo();
    return 0;
}