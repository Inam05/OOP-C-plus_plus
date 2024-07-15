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