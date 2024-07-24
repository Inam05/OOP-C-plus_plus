/*
Design a class Product with attributes productID, name, and price. Derive classes Electronics and Clothing from Product. Implement a
virtual method calculateDiscount() in the base class and override it in the derived classes to apply category-specific discounts.
*/

// code

#include <iostream>
using namespace std;

class Product
{
protected:
    int productID;
    string name;
    float price;

public:
    Product(int id, string n, float p) : productID(id), name(n), price(p) {}
    virtual float calculateDiscount()
    {
        return 0.0; // Base class default discount
    }
    void display()
    {
        cout << "Product ID: " << productID << ", Name: " << name << ", Price: " << price << ", Discounted Price: " << price - calculateDiscount() << endl;
    }
};

class Electronics : public Product
{
public:
    Electronics(int id, string n, float p) : Product(id, n, p) {}
    float calculateDiscount() override
    {
        return price * 0.10; // 10% discount for electronics
    }
};

class Clothing : public Product
{
public:
    Clothing(int id, string n, float p) : Product(id, n, p) {}
    float calculateDiscount() override
    {
        return price * 0.20; // 20% discount for clothing
    }
};

int main()
{
    Product *p1 = new Electronics(101, "Laptop", 1500);
    Product *p2 = new Clothing(202, "T-Shirt", 30);
    p1->display();
    p2->display();
    delete p1;
    delete p2;
    return 0;
}
