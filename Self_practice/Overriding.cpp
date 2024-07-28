#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string name;
    int age;

public:
    Student()
    {
    }
    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    virtual void get()
    {
        cout << "Enter name:";
        cin >> name;
        cout << "Enter age:";
        cin >> age;
    }
    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Adress
{
protected:
    string adress;
    string city;

public:
    Adress()
    {
    }
    Adress(string adress, string city)
    {
        this->adress = adress;
        this->city = city;
    }
    void get()
    {
        cout << "Enter Adress:";
        cin >> adress;
        cout << "Enter City:";
        cin >> city;
    }
    void display()
    {
        cout << "Adress: " << adress << endl;
        cout << "City: " << city << endl;
    }
};

class Information : public Student, public Adress
{
protected:
    string phone;
    string id;

public:
    Information()
    {
    }
    Information(string name, int age, string adress, string city, string phone, string id)
        : Student(name, age), Adress(adress, city)
    {
        this->phone = phone;
        this->id = id;
    }
    void get()
    {
        cout << "Enter phone number : ";
        cin >> phone;
        cout << "Enter ID : ";
        cin >> id;
    }
    void display()
    {
        cout << "Phone number is : " << phone << endl;
        cout << "ID is : " << id << endl;
    }
};

int main()
{
    Student *pbr1;
    Adress *pbr2;
    Information pbr3;
    pbr1 = &pbr3;
    pbr2 = &pbr3;
    pbr1->get();
    pbr2->get();
    pbr1->display();
    pbr2->display();
    return 0;
}