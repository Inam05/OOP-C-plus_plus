/*
Project Description
A system to manage books, members, and transactions.
Questions
How will you structure the data for books and members?
How will you handle book borrowing and returning?
What features will you include for searching and managing books?
*/

// code :

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Book
{
public:
    string title;
    string author;
    bool isBorrowed;

    Book(string t, string a) : title(t), author(a), isBorrowed(false) {}

    void display() const
    {
        cout << "Title: " << title << ", Author: " << author;
        if (isBorrowed)
            cout << " (Borrowed)";
        cout << endl;
    }

    string toString() const
    {
        return title + "," + author + "," + (isBorrowed ? "1" : "0");
    }
};

class User
{
public:
    string username;
    string password;
    bool isAdmin;

    User(string u, string p, bool admin) : username(u), password(p), isAdmin(admin) {}

    bool authenticate(const string &pw) const
    {
        return password == pw;
    }
};

class Library
{
private:
    vector<Book> books;
    vector<User> users;

    void loadBooks()
    {
        ifstream file("books.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                size_t pos = line.find(',');
                string title = line.substr(0, pos);
                line.erase(0, pos + 1);
                pos = line.find(',');
                string author = line.substr(0, pos);
                bool isBorrowed = line.substr(pos + 1) == "1";
                books.push_back(Book(title, author));
                books.back().isBorrowed = isBorrowed;
            }
            file.close();
        }
    }

    void saveBooks() const
    {
        ofstream file("books.txt");
        if (file.is_open())
        {
            for (const auto &book : books)
            {
                file << book.toString() << endl;
            }
            file.close();
        }
    }

public:
    Library()
    {
        loadBooks();
    }

    ~Library()
    {
        saveBooks();
    }

    void addBook(const Book &book)
    {
        books.push_back(book);
    }

    void borrowBook(const string &title)
    {
        for (auto &book : books)
        {
            if (book.title == title && !book.isBorrowed)
            {
                book.isBorrowed = true;
                cout << "You borrowed \"" << title << "\"." << endl;
                return;
            }
        }
        cout << "Book not available or already borrowed." << endl;
    }

    void returnBook(const string &title)
    {
        for (auto &book : books)
        {
            if (book.title == title && book.isBorrowed)
            {
                book.isBorrowed = false;
                cout << "You returned \"" << title << "\"." << endl;
                return;
            }
        }
        cout << "This book was not borrowed or does not exist." << endl;
    }

    void displayBooks() const
    {
        for (const auto &book : books)
        {
            book.display();
        }
    }

    bool authenticateUser(const string &username, const string &password) const
    {
        for (const auto &user : users)
        {
            if (user.username == username && user.authenticate(password))
            {
                return true;
            }
        }
        return false;
    }

    void addUser(const User &user)
    {
        users.push_back(user);
    }
};

void adminMenu(Library &library)
{
    int choice;
    do
    {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string title, author;
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            library.addBook(Book(title, author));
            cout << "Book added successfully.\n";
            break;
        }
        case 2:
            library.displayBooks();
            break;
        case 3:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 3);
}

void userMenu(Library &library)
{
    int choice;
    do
    {
        cout << "\nUser Menu:\n";
        cout << "1. Borrow Book\n";
        cout << "2. Return Book\n";
        cout << "3. Display Books\n";
        cout << "4. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string title;
            cout << "Enter book title to borrow: ";
            getline(cin, title);
            library.borrowBook(title);
            break;
        }
        case 2:
        {
            string title;
            cout << "Enter book title to return: ";
            getline(cin, title);
            library.returnBook(title);
            break;
        }
        case 3:
            library.displayBooks();
            break;
        case 4:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 4);
}

int main()
{
    Library library;

    string username, password;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    if (library.authenticateUser(username, password))
    {
        cout << "Authentication successful.\n";
        if (username == "admin")
        {
            adminMenu(library);
        }
        else
        {
            userMenu(library);
        }
    }
    else
    {
        cout << "Authentication failed.\n";
    }

    return 0;
}
