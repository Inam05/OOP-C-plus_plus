/*
Description: A system for managing and categorizing library books.
Questions:
How will you structure book categories and metadata?
How will you handle book searches and recommendations?
What features will you include for managing book catalogs?
*/

/*
    Created by Inam Ul Hassan
    Github : https://github.com/Inam05
*/

// code

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class User
{
public:
    virtual void displayMenu() const = 0; // Pure virtual function for polymorphism
    virtual ~User() {}
};

class Book
{
private:
    string title;
    string author;
    bool isAvailable;

public:
    Book(string t, string a, bool available = true)
        : title(t), author(a), isAvailable(available) {}

    string toString() const
    {
        return title + "|" + author + "|" + (isAvailable ? "Available" : "Not Available");
    }

    void display() const
    {
        cout << "Title: " << title << ", Author: " << author
             << ", Status: " << (isAvailable ? "Available" : "Not Available") << endl;
    }

    void setAvailability(bool availability)
    {
        isAvailable = availability;
    }

    bool getAvailability() const
    {
        return isAvailable;
    }

    string getTitle() const
    {
        return title;
    }
};

class Admin : public User
{
private:
    vector<Book> books;

    void loadBooks()
    {
        ifstream file("books.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                size_t pos1 = line.find('|');
                size_t pos2 = line.find('|', pos1 + 1);
                string title = line.substr(0, pos1);
                string author = line.substr(pos1 + 1, pos2 - pos1 - 1);
                bool isAvailable = line.substr(pos2 + 1) == "Available";
                books.push_back(Book(title, author, isAvailable));
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
    Admin()
    {
        loadBooks();
    }

    ~Admin()
    {
        saveBooks();
    }

    void addBook(const Book &book)
    {
        books.push_back(book);
        cout << "Book added successfully.\n";
    }

    void removeBook(const string &title)
    {
        auto it = remove_if(books.begin(), books.end(),
                            [title](const Book &b)
                            { return b.getTitle() == title; });
        if (it != books.end())
        {
            books.erase(it, books.end());
            cout << "Book removed successfully.\n";
        }
        else
        {
            cout << "Book not found.\n";
        }
    }

    void displayBooks() const
    {
        cout << "Book List:\n";
        for (const auto &book : books)
        {
            book.display();
        }
    }

    void displayMenu() const override
    {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Display Books\n";
        cout << "4. Logout\n";
    }
};

class Librarian : public User
{
private:
    vector<Book> &books;

public:
    Librarian(vector<Book> &b) : books(b) {}

    void issueBook(const string &title)
    {
        for (auto &book : books)
        {
            if (book.getTitle() == title && book.getAvailability())
            {
                book.setAvailability(false);
                cout << "Book issued successfully.\n";
                return;
            }
        }
        cout << "Book not available or not found.\n";
    }

    void returnBook(const string &title)
    {
        for (auto &book : books)
        {
            if (book.getTitle() == title && !book.getAvailability())
            {
                book.setAvailability(true);
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Book not found or was not issued.\n";
    }

    void displayMenu() const override
    {
        cout << "\nLibrarian Menu:\n";
        cout << "1. Issue Book\n";
        cout << "2. Return Book\n";
        cout << "3. Logout\n";
    }
};

class Member : public User
{
private:
    string name;

public:
    Member(string n) : name(n) {}

    void borrowBook(vector<Book> &books, const string &title)
    {
        for (auto &book : books)
        {
            if (book.getTitle() == title && book.getAvailability())
            {
                book.setAvailability(false);
                cout << "Book borrowed successfully.\n";
                return;
            }
        }
        cout << "Book not available or not found.\n";
    }

    void returnBook(vector<Book> &books, const string &title)
    {
        for (auto &book : books)
        {
            if (book.getTitle() == title && !book.getAvailability())
            {
                book.setAvailability(true);
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Book not found or was not borrowed.\n";
    }

    void displayMenu() const override
    {
        cout << "\nMember Menu:\n";
        cout << "1. Borrow Book\n";
        cout << "2. Return Book\n";
        cout << "3. Logout\n";
    }
};

void adminMenu(Admin &admin)
{
    int choice;
    do
    {
        admin.displayMenu();
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
            admin.addBook(Book(title, author));
            break;
        }
        case 2:
        {
            string title;
            cout << "Enter book title to remove: ";
            getline(cin, title);
            admin.removeBook(title);
            break;
        }
        case 3:
            admin.displayBooks();
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

void librarianMenu(Librarian &librarian)
{
    int choice;
    do
    {
        librarian.displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string title;
            cout << "Enter book title to issue: ";
            getline(cin, title);
            librarian.issueBook(title);
            break;
        }
        case 2:
        {
            string title;
            cout << "Enter book title to return: ";
            getline(cin, title);
            librarian.returnBook(title);
            break;
        }
        case 3:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 3);
}

void memberMenu(Member &member, vector<Book> &books)
{
    int choice;
    do
    {
        member.displayMenu();
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
            member.borrowBook(books, title);
            break;
        }
        case 2:
        {
            string title;
            cout << "Enter book title to return: ";
            getline(cin, title);
            member.returnBook(books, title);
            break;
        }
        case 3:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 3);
}

int main()
{
    string role;
    cout << "Enter role (admin/librarian/member): ";
    getline(cin, role);

    Admin admin;
    Librarian librarian(admin.books);
    Member member("Alice"); // Example member

    if (role == "admin")
    {
        adminMenu(admin);
    }
    else if (role == "librarian")
    {
        librarianMenu(librarian);
    }
    else if (role == "member")
    {
        memberMenu(member, admin.books);
    }
    else
    {
        cout << "Invalid role.\n";
    }

    return 0;
}
