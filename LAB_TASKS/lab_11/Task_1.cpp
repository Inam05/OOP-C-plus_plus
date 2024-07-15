#include <iostream>
#include <string>

using namespace std;

// Base class: LibraryItem
class LibraryItem
{
protected:
    string title;
    string author;
    int publication_Year;
    bool checked_Out;

public:
    LibraryItem(string title, string author, int publication_Year, bool checked_Out = false)
    {
        this->title = title;
        this->author = author;
        this->publication_Year = publication_Year;
        this->checked_Out = checked_Out;
    }

    virtual void displayInfo() const = 0;
    void checkout()
    {
        checked_Out = true;
    }
    void returnItem()
    {
        checked_Out = false;
    }
};

// Derived class: Book
class Book : public LibraryItem
{
private:
    string isbn;

public:
    Book(string title, string author, int publication_Year, string isbn) : LibraryItem(title, author, publication_Year)
    {
        this->isbn = isbn;
    }

    void displayInfo() const override
    {
        cout << "Book Info:" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publication_Year << endl;
        cout << "ISBN: " << isbn << endl;
    }
};

// Derived class: Magazine
class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string title, string author, int publication_Year, int issueNumber, bool checked_Out = false) : LibraryItem(title, author, publication_Year, checked_Out)
    {
        this->issueNumber = issueNumber;
    }

    void displayInfo() const override
    {
        cout << "Magazine Info:" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publication_Year << endl;
        cout << "Issue Number: " << issueNumber << endl;
    }
};

int main()
{
    Book b1("The Great Gatsby", "F. Scott Fitzgerald", 1925, "9780743273565");
    Magazine m1("National Geographic", "Various", 2024, 154);

    b1.displayInfo();
    b1.checkout();
    b1.returnItem();
    cout << endl;

    m1.displayInfo();
    m1.checkout();

    return 0;
}