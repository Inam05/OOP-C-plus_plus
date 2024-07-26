/*
Create a class Product with attributes productID, name, and price. Derive classes FoodProduct and ElectronicsProduct from Product. 
Implement polymorphic behavior for a method applyDiscount() to apply different discount rates for food and electronics products.
*/

#include <iostream>
using namespace std;

class Product {
protected:
    int productID;
    string name;
    double price;
public:
    Product(int id, string n, double p) : productID(id), name(n), price(p) {}
    virtual void applyDiscount() = 0; // Pure virtual function
    void display() {
        cout << "Product ID: " << productID << ", Name: " << name << ", Price: $" << price << endl;
    }
};

class FoodProduct : public Product {
public:
    FoodProduct(int id, string n, double p) : Product(id, n, p) {}
    void applyDiscount() override {
        price *= 0.9; // 10% discount
        cout << "Discount applied to Food Product: " << name << ", New Price: $" << price << endl;
    }
};

class ElectronicsProduct : public Product {
public:
    ElectronicsProduct(int id, string n, double p) : Product(id, n, p) {}
    void applyDiscount() override {
        price *= 0.8; // 20% discount
        cout << "Discount applied to Electronics Product: " << name << ", New Price: $" << price << endl;
    }
};

int main() {
    Product* p1 = new FoodProduct(101, "Apple", 1.0);
    Product* p2 = new ElectronicsProduct(202, "Laptop", 1000.0);
    p1->applyDiscount();
    p2->applyDiscount();
    p1->display();
    p2->display();
    delete p1;
    delete p2;
    return 0;
}
