/*
Description: A system for managing and organizing contact information.
Questions:
How will you store and organize contact details?
How will you handle searching and sorting contacts?
What features will you include for managing contact information?
*/

/*
    Created by Inam Ul Hassan
    Github : https://github.com/Inam05
*/

// code

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Contact class
class Contact
{
private:
    string name;
    string phoneNumber;
    string email;

public:
    Contact(const string &name, const string &phoneNumber, const string &email)
        : name(name), phoneNumber(phoneNumber), email(email) {}

    string getName() const { return name; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }

    void setName(const string &newName) { name = newName; }
    void setPhoneNumber(const string &newPhoneNumber) { phoneNumber = newPhoneNumber; }
    void setEmail(const string &newEmail) { email = newEmail; }

    void display() const
    {
        cout << "Name: " << name << '\n';
        cout << "Phone Number: " << phoneNumber << '\n';
        cout << "Email: " << email << '\n';
    }
};

// ContactManager class
class ContactManager
{
private:
    vector<Contact> contacts;
    const string fileName = "contacts.txt";

    void loadContacts()
    {
        ifstream file(fileName);
        if (!file)
        {
            cerr << "Error opening file for reading.\n";
            return;
        }
        string name, phoneNumber, email;
        while (getline(file, name) && getline(file, phoneNumber) && getline(file, email))
        {
            contacts.emplace_back(name, phoneNumber, email);
        }
        file.close();
    }

    void saveContacts() const
    {
        ofstream file(fileName);
        if (!file)
        {
            cerr << "Error opening file for writing.\n";
            return;
        }
        for (const auto &contact : contacts)
        {
            file << contact.getName() << '\n';
            file << contact.getPhoneNumber() << '\n';
            file << contact.getEmail() << '\n';
        }
        file.close();
    }

public:
    ContactManager() { loadContacts(); }
    ~ContactManager() { saveContacts(); }

    void addContact(const Contact &contact)
    {
        contacts.push_back(contact);
    }

    void removeContact(const string &name)
    {
        auto it = remove_if(contacts.begin(), contacts.end(),
                            [&name](const Contact &contact)
                            { return contact.getName() == name; });
        if (it != contacts.end())
        {
            contacts.erase(it, contacts.end());
            cout << "Contact removed successfully.\n";
        }
        else
        {
            cout << "Contact not found.\n";
        }
    }

    void searchContact(const string &name) const
    {
        auto it = find_if(contacts.begin(), contacts.end(),
                          [&name](const Contact &contact)
                          { return contact.getName() == name; });
        if (it != contacts.end())
        {
            it->display();
        }
        else
        {
            cout << "Contact not found.\n";
        }
    }

    void displayAllContacts() const
    {
        if (contacts.empty())
        {
            cout << "No contacts available.\n";
        }
        else
        {
            for (const auto &contact : contacts)
            {
                contact.display();
                cout << "-------------------------\n";
            }
        }
    }
};

// Main function
int main()
{
    ContactManager manager;
    int choice;
    string name, phoneNumber, email;

    do
    {
        cout << "Contact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. Remove Contact\n";
        cout << "3. Search Contact\n";
        cout << "4. Display All Contacts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline

        switch (choice)
        {
        case 1:
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter phone number: ";
            getline(cin, phoneNumber);
            cout << "Enter email: ";
            getline(cin, email);
            manager.addContact(Contact(name, phoneNumber, email));
            break;
        case 2:
            cout << "Enter name of contact to remove: ";
            getline(cin, name);
            manager.removeContact(name);
            break;
        case 3:
            cout << "Enter name of contact to search: ";
            getline(cin, name);
            manager.searchContact(name);
            break;
        case 4:
            manager.displayAllContacts();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
