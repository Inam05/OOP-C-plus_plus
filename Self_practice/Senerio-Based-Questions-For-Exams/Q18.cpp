/*
Design a class LibraryItem with attributes title and itemID. Derive classes EBook and PhysicalBook from LibraryItem. Implement a 
virtual method read() to handle reading an eBook and a physical book differently.
*/

#include <iostream>
using namespace std;

class LibraryItem {
protected:
    string title;
    int itemID;
public:
    LibraryItem(string t, int id) : title(t), itemID(id) {}
    virtual void read() = 0; // Pure virtual function
};

class EBook : public LibraryItem {
public:
    EBook(string t, int id) : LibraryItem(t, id) {}
    void read() override {
        cout << "Reading eBook: " << title << " on a device." << endl;
    }
};

class PhysicalBook : public LibraryItem {
public:
    PhysicalBook(string t, int id) : LibraryItem(t, id) {}
    void read() override {
        cout << "Reading physical book: " << title << " by turning pages." << endl;
    }
};

int main() {
    LibraryItem* l1 = new EBook("C++ Programming", 101);
    LibraryItem* l2 = new PhysicalBook("Data Structures", 202);
    l1->read();
    l2->read();
    delete l1;
    delete l2;
    return 0;
}

