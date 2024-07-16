/*
Single Inheritance
Create a base class called `Vehicle` with a constructor that initializes a member variable
representing the vehicle's year. Derive a subclass called `Car` from the `Vehicle` class with
its own constructor that initializes additional member variables such as make and model.
*/
#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    int year;

public:
    Vehicle(int y)
    {
        year = y;
    }
};

class Car : public Vehicle
{
private:
    string make;
    string model;
public:
    Car(int y, string mk, string mdl) : Vehicle(y)
    {
        year = y;
        make = mk ;
        model = mdl;
    }
    void display()
    {
        cout << "Year: " << year << ", Make: " << make << ", Model: " << model << endl;
    }
};

int main()
{
    Car car(2022, "Toyota", "Camry");
    car.display();
    return 0;
}