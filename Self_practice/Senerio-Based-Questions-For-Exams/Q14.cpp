/*
Design a base class Vehicle with attributes licensePlate and model. Derive classes Bus and Taxi from Vehicle. Implement a virtual 
method calculateFare() in the base class and override it in the derived classes to calculate fares based on the vehicle type.
*/

#include <iostream>
using namespace std;

class Vehicle {
protected:
    string licensePlate;
    string model;
public:
    Vehicle(string lp, string m) : licensePlate(lp), model(m) {}
    virtual double calculateFare(double distance) = 0; // Pure virtual function
};

class Bus : public Vehicle {
public:
    Bus(string lp, string m) : Vehicle(lp, m) {}
    double calculateFare(double distance) override {
        return distance * 1.0; // $1 per km
    }
};

class Taxi : public Vehicle {
public:
    Taxi(string lp, string m) : Vehicle(lp, m) {}
    double calculateFare(double distance) override {
        return distance * 2.5; // $2.5 per km
    }
};

int main() {
    Vehicle* v1 = new Bus("BUS123", "Volvo");
    Vehicle* v2 = new Taxi("TAXI456", "Toyota");
    cout << "Bus Fare for 10 km: $" << v1->calculateFare(10) << endl;
    cout << "Taxi Fare for 10 km: $" << v2->calculateFare(10) << endl;
    delete v1;
    delete v2;
    return 0;
}

