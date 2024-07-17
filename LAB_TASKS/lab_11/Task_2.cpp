/*
You are a software developer tasked with creating a basic inventory management system for a retail store. The store sells various 
types of products, including electronics, clothing, and food items. Each product type has specific attributes and details that need
to be managed.
You need to create a base class Product with common attributes and methods for all products. Then, derive three subclasses: Electronics, 
Clothing, and Food, each with additional attributes specific to their type. The system should be able to store and display details for each type of product.
*/
#include <iostream>
#include <string>

using namespace std;

// Base class Product
class Product
{
private:
    int productID;
    string name;
    double price;

public:
    Product(int id, const string &n, double p) : productID(id), name(n), price(p) {}

    void updatePrice(double newPrice)
    {
        price = newPrice;
    }

    double getPrice() const
    {
        return price;
    }

    virtual string getDetails() const
    {
        return "Product ID: " + to_string(productID) + "\nName: " + name + "\nPrice: $" + to_string(price);
    }

    virtual ~Product() {}
};

class Electronics : public Product
{
private:
    int warrantyPeriod; 

public:
    Electronics(int id, const string &n, double p, int wp) : Product(id, n, p), warrantyPeriod(wp) {}

    int getWarrantyPeriod() const
    {
        return warrantyPeriod;
    }

    string getDetails() const override
    {
        return Product::getDetails() + "\nWarranty Period: " + to_string(warrantyPeriod) + " months";
    }
};

class Clothing : public Product
{
private:
    string size;
    string fabricType;

public:
    Clothing(int id, const string &n, double p, const string &s, const string &f) : Product(id, n, p), size(s), fabricType(f) {}

    string getSize() const
    {
        return size;
    }

    string getFabricType() const
    {
        return fabricType;
    }

    string getDetails() const override
    {
        return Product::getDetails() + "\nSize: " + size + "\nFabric Type: " + fabricType;
    }
};

// Derived class Food
class Food : public Product
{
private:
    string expirationDate;

public:
    // Constructor
    Food(int id, const string &n, double p, const string &ed) : Product(id, n, p), expirationDate(ed) {}

    // Method to get expiration date
    string getExpirationDate() const
    {
        return expirationDate;
    }

    // Override getDetails to include expiration date
    string getDetails() const override
    {
        return Product::getDetails() + "\nExpiration Date: " + expirationDate;
    }
};

// Main function for demonstration
int main()
{
    // Creating objects of derived classes
    Electronics laptop(101, "Laptop", 999.99, 24);
    Clothing shirt(102, "Shirt", 49.99, "L", "Cotton");
    Food apple(103, "Apple", 0.99, "2024-12-31");

    // Display details of each product
    cout << laptop.getDetails() << endl << endl;
    cout << shirt.getDetails() << endl << endl;
    cout << apple.getDetails() << endl;

    return 0;
}
