/*
Create a class Product with attributes productID, name, and price. Derive classes Clothing and Electronics from Product. Implement all
four types of constructors for Product. Add a method applyDiscount() to demonstrate polymorphism.
*/

#include <iostream>
using namespace std;

class Product
{
protected:
    int productID;
    string name;
    double price;

public:
    Product() : productID(0), name(""), price(0.0) {}                                                      // Default constructor
    Product(int id, string n, double p) : productID(id), name(n), price(p) {}                              // Parameterized constructor
    Product(const Product &p) : productID(p.productID), name(p.name), price(p.price) {}                    // Copy constructor
    Product(Product &&p) : productID(p.productID), name(move(p.name)), price(p.price) { p.productID = 0; } // Move constructor

    virtual void applyDiscount() = 0; // Pure virtual function
};

class Clothing : public Product
{
public:
    Clothing() : Product() {}
    Clothing(int id, string n, double p) : Product(id, n, p) {}
    Clothing(const Clothing &c) : Product(c) {}
    Clothing(Clothing &&c) : Product(move(c)) {}

    void applyDiscount() override
    {
        price *= 0.9; // 10% discount
        cout << "Discount applied to Clothing: " << name << ", New Price: $" << price << endl;
    }
};

class Electronics : public Product
{
public:
    Electronics() : Product() {}
    Electronics(int id, string n, double p) : Product(id, n, p) {}
    Electronics(const Electronics &e) : Product(e) {}
    Electronics(Electronics &&e) : Product(move(e)) {}

    void applyDiscount() override
    {
        price *= 0.8; // 20% discount
        cout << "Discount applied to Electronics: " << name << ", New Price: $" << price << endl;
    }
};

int main()
{
    Clothing c1(101, "T-Shirt", 20.0);
    Electronics e1(202, "Smartphone", 500.0);

    c1.applyDiscount();
    e1.applyDiscount();

    return 0;
}
