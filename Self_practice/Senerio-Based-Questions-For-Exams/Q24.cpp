/*
Design a class RentalVehicle with attributes vehicleID, brand, and ratePerDay. Derive classes Car and Bike from RentalVehicle.
Implement all four types of constructors for RentalVehicle. Add a method rent() to demonstrate polymorphism.
*/

#include <iostream>
using namespace std;

class RentalVehicle
{
protected:
    int vehicleID;
    string brand;
    double ratePerDay;

public:
    RentalVehicle() : vehicleID(0), brand(""), ratePerDay(0.0) {}                                                                       // Default constructor
    RentalVehicle(int id, string b, double rate) : vehicleID(id), brand(b), ratePerDay(rate) {}                                         // Parameterized constructor
    RentalVehicle(const RentalVehicle &rv) : vehicleID(rv.vehicleID), brand(rv.brand), ratePerDay(rv.ratePerDay) {}                     // Copy constructor
    RentalVehicle(RentalVehicle &&rv) : vehicleID(rv.vehicleID), brand(move(rv.brand)), ratePerDay(rv.ratePerDay) { rv.vehicleID = 0; } // Move constructor

    virtual void rent() = 0; // Pure virtual function
};

class Car : public RentalVehicle
{
public:
    Car() : RentalVehicle() {}
    Car(int id, string b, double rate) : RentalVehicle(id, b, rate) {}
    Car(const Car &c) : RentalVehicle(c) {}
    Car(Car &&c) : RentalVehicle(move(c)) {}

    void rent() override
    {
        cout << "Car rented: " << brand << " for $" << ratePerDay << " per day." << endl;
    }
};

class Bike : public RentalVehicle
{
public:
    Bike() : RentalVehicle() {}
    Bike(int id, string b, double rate) : RentalVehicle(id, b, rate) {}
    Bike(const Bike &b) : RentalVehicle(b) {}
    Bike(Bike &&b) : RentalVehicle(move(b)) {}

    void rent() override
    {
        cout << "Bike rented: " << brand << " for $" << ratePerDay << " per day." << endl;
    }
};

int main()
{
    Car car1(101, "Toyota", 50.0);
    Bike bike1(202, "Yamaha", 20.0);

    car1.rent();
    bike1.rent();

    return 0;
}
