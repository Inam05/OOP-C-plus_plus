/*
Write a C++ program to make a car class with wheels, doors as private data members and
cur_speed as public data member while speed and break as public member functions. Use
constructor with default value of wheels=4,doors=2 and cur_speed=0 for initialization.
Make two objects in the name of ferrari and hino.
Ferrari is initialized through default values while hino has 10 wheels, 4 doors. Every time
when you call speed function cur_speed is increased by 5 while break function decrease it
by 5. Display current speed.
*/
#include<iostream>
using namespace std;
class Students {
public:
    string name;
    int age;

    Students() {
        name = "";
        age = 0;
    }

    Students(string Name, int Age) {
        name = Name;
        age = Age;
    }

    Students(Students& CS) {
        name = CS.name;
        age = CS.age;
    }

    void display_info() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    Students CS1;
    cout << "CS1: ";
    CS1.display_info();

    Students CS2("Inam",219);
    cout << "CS2: ";
    CS2.display_info();

    Students CS3 = CS2;
    cout << "CS3: ";
    CS3.display_info();

    return 0;
}