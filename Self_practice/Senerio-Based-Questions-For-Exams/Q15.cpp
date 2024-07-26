/*
Create a base class Course with attributes courseID and title. Derive classes OnlineCourse and OfflineCourse from Course. 
Implement a virtual method displayCourseType() to indicate whether the course is online or offline.
*/

#include <iostream>
using namespace std;

class Course {
protected:
    int courseID;
    string title;
public:
    Course(int id, string t) : courseID(id), title(t) {}
    virtual void displayCourseType() = 0; // Pure virtual function
};

class OnlineCourse : public Course {
public:
    OnlineCourse(int id, string t) : Course(id, t) {}
    void displayCourseType() override {
        cout << "Course: " << title << " is an Online Course." << endl;
    }
};

class OfflineCourse : public Course {
public:
    OfflineCourse(int id, string t) : Course(id, t) {}
    void displayCourseType() override {
        cout << "Course: " << title << " is an Offline Course." << endl;
    }
};

int main() {
    Course* c1 = new OnlineCourse(101, "C++ Programming");
    Course* c2 = new OfflineCourse(202, "Data Structures");
    c1->displayCourseType();
    c2->displayCourseType();
    delete c1;
    delete c2;
    return 0;
}

