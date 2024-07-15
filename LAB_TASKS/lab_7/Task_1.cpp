#include <iostream>
#include <string>
using namespace std;
class Book
{
private:
    string title;
    bool available;
public:
    Book(string bookTitle)
    {
        title = bookTitle;
        available = true;
    }
    void borrow()
    {
        if (isAvailable())
        {
            cout << "You've borrowed the book: " << title << endl;
            available = false;
        }
        else
        {
            cout << "Sorry, the book: " << title << " is currently not available." << endl;
        }
    }
    bool isAvailable() const
    {
        return available;
    }
};
int main()
{
    Book myBook("object oriented Programming");
    if (myBook.isAvailable())
    {
        cout << "The book is available for borrowing." << endl;
    }
    else
    {
        cout << "The book is not available for borrowing." << endl;
    }
    return 0;
}