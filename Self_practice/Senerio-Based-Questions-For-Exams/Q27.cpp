/*
Create a class Property with attributes propertyID, address, and price. Derive classes House and Apartment from Property. Implement all
four types of constructors for Property. Add a method showDetails() to demonstrate polymorphism.
*/

#include <iostream>
using namespace std;

class Property
{
protected:
    int propertyID;
    string address;
    double price;

public:
    Property() : propertyID(0), address(""), price(0.0) {}                                                            // Default constructor
    Property(int id, string a, double p) : propertyID(id), address(a), price(p) {}                                    // Parameterized constructor
    Property(const Property &p) : propertyID(p.propertyID), address(p.address), price(p.price) {}                     // Copy constructor
    Property(Property &&p) : propertyID(p.propertyID), address(move(p.address)), price(p.price) { p.propertyID = 0; } // Move constructor

    virtual void showDetails() = 0; // Pure virtual function
};

class House : public Property
{
public:
    House() : Property() {}
    House(int id, string a, double p) : Property(id, a, p) {}
    House(const House &h) : Property(h) {}
    House(House &&h) : Property(move(h)) {}

    void showDetails() override
    {
        cout << "House ID: " << propertyID << ", Address: " << address << ", Price: $" << price << endl;
    }
};

class Apartment : public Property
{
public:
    Apartment() : Property() {}
    Apartment(int id, string a, double p) : Property(id, a, p) {}
    Apartment(const Apartment &a) : Property(a) {}
    Apartment(Apartment &&a) : Property(move(a)) {}

    void showDetails() override
    {
        cout << "Apartment ID: " << propertyID << ", Address: " << address << ", Price: $" << price << endl;
    }
};

int main()
{
    House h1(101, "123 Main St", 250000.0);
    Apartment a1(202, "456 Elm St", 150000.0);

    h1.showDetails();
    a1.showDetails();

    return 0;
}
