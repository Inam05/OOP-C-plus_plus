/*
Design a class LibraryItem with attributes title and itemID. Derive classes Book and Magazine from LibraryItem. Implement a virtual
method borrowItem() in the base class and override it in the derived classes to handle borrowing books and magazines differently.
*/

// code

#include <iostream>
using namespace std;

class LibraryItem
{
protected:
    string title;
    int itemID;

public:
    LibraryItem(string t, int id) : title(t), itemID(id) {}
    virtual void borrowItem() = 0; // Pure virtual function
};

class Book : public LibraryItem
{
public:
    Book(string t, int id) : LibraryItem(t, id) {}
    void borrowItem() override
    {
        cout << "Borrowing Book: " << title << endl;
    }
};

class Magazine : public LibraryItem
{
public:
    Magazine(string t, int id) : LibraryItem(t, id) {}
    void borrowItem() override
    {
        cout << "Borrowing Magazine: " << title << endl;
    }
};

int main()
{
    LibraryItem *li1 = new Book("C++ Programming", 101);
    LibraryItem *li2 = new Magazine("Tech Monthly", 202);
    li1->borrowItem();
    li2->borrowItem();
    delete li1;
    delete li2;
    return 0;
}
