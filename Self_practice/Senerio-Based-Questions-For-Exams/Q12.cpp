/*
Design a class InventoryItem with attributes itemID, name, and quantity. Derive classes PerishableItem and NonPerishableItem from 
InventoryItem. Implement a virtual method checkExpiration() in the base class and override it in the derived class PerishableItem to 
handle expiration checks.
*/

#include <iostream>
using namespace std;

class InventoryItem {
protected:
    int itemID;
    string name;
    int quantity;
public:
    InventoryItem(int id, string n, int q) : itemID(id), name(n), quantity(q) {}
    virtual void checkExpiration() {
        cout << "Non-perishable item: " << name << " does not expire." << endl;
    }
    void display() {
        cout << "Item ID: " << itemID << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};

class PerishableItem : public InventoryItem {
private:
    string expirationDate;
public:
    PerishableItem(int id, string n, int q, string ed) : InventoryItem(id, n, q), expirationDate(ed) {}
    void checkExpiration() override {
        cout << "Perishable item: " << name << " expires on " << expirationDate << endl;
    }
};

int main() {
    InventoryItem* i1 = new InventoryItem(101, "Canned Beans", 50);
    InventoryItem* i2 = new PerishableItem(202, "Milk", 20, "2024-08-01");
    i1->checkExpiration();
    i2->checkExpiration();
    i1->display();
    i2->display();
    delete i1;
    delete i2;
    return 0;
}

