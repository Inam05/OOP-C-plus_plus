/*
Design a class LibraryItem with attributes title, author, and publicationYear. Derive classes Book and Journal from LibraryItem.
Implement all four types of constructors for LibraryItem. Add a method borrow() to demonstrate polymorphism.
*/

#include <iostream>
using namespace std;

class LibraryItem
{
protected:
    string title;
    string author;
    int publicationYear;

public:
    LibraryItem() : title(""), author(""), publicationYear(0) {}                                                                                    // Default constructor
    LibraryItem(string t, string a, int y) : title(t), author(a), publicationYear(y) {}                                                             // Parameterized constructor
    LibraryItem(const LibraryItem &li) : title(li.title), author(li.author), publicationYear(li.publicationYear) {}                                 // Copy constructor
    LibraryItem(LibraryItem &&li) : title(move(li.title)), author(move(li.author)), publicationYear(li.publicationYear) { li.publicationYear = 0; } // Move constructor

    virtual void borrow() = 0; // Pure virtual function
};

class Book : public LibraryItem
{
public:
    Book() : LibraryItem() {}
    Book(string t, string a, int y) : LibraryItem(t, a, y) {}
    Book(const Book &b) : LibraryItem(b) {}
    Book(Book &&b) : LibraryItem(move(b)) {}

    void borrow() override
    {
        cout << "Borrowing Book: " << title << " by " << author << " (" << publicationYear << ")" << endl;
    }
};

class Journal : public LibraryItem
{
public:
    Journal() : LibraryItem() {}
    Journal(string t, string a, int y) : LibraryItem(t, a, y) {}
    Journal(const Journal &j) : LibraryItem(j) {}
    Journal(Journal &&j) : LibraryItem(move(j)) {}

    void borrow() override
    {
        cout << "Borrowing Journal: " << title << " by " << author << " (" << publicationYear << ")" << endl;
    }
};

int main()
{
    Book b1("1984", "George Orwell", 1949);
    Journal j1("Science Journal", "Various", 2023);

    b1.borrow();
    j1.borrow();

    return 0;
}
