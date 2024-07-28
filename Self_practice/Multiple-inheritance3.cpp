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
        cout << "enter name of the student;";
        cin >> name;
        cout << "enter roll number of the student=";
        cin >> rno;
    }
    void displaystudent()
    {
        cout << "name of the student=" << name << endl;
        cout << " roll number of the student=" << rno;
    }
};

class address
{
private:
    char city[20];

public:
    void getaddress()
    {
        cout << "enter city=";
        cin >> city;
    }
    void displayaddress()
    {
        cout << "city=" << city;
    }
};

class account : public student, public address
{
private:
    int tfee, submit, balance;

public:
    void getaccount()
    {
        getstudent();
        getaddress();
        cout << "enter total fee=";
        cin >> tfee;
        cout << "enter submit fee=";
        cin >> submit;
    }
    void displayaccount()
    {
        displaystudent();
        displayaddress();
        cout << "total fee=" << tfee;
        cout << "submit fee=" << submit;
        balance = tfee - submit;
        cout << "balance fee=" << balance;
    }
};

int main()
{
    account a1;
    a1.getaccount();
    a1.displayaccount();
}
