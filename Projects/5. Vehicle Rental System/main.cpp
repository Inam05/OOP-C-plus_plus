/*
Description: A system to manage vehicle rentals, including availability and customer transactions.
Questions:
How will you track vehicle availability and rental status?
How will you handle rental agreements and transactions?
What features will you include for managing customer information?
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

class MenuItem
{
public:
    string name;
    double price;

    MenuItem(string n, double p) : name(n), price(p) {}

    void display() const
    {
        cout << "Item: " << name << ", Price: $" << price << endl;
    }

    string toString() const
    {
        return name + "," + to_string(price);
    }
};

class Order
{
public:
    vector<MenuItem> items;
    double totalAmount;

    Order() : totalAmount(0) {}

    void addItem(const MenuItem &item)
    {
        items.push_back(item);
        totalAmount += item.price;
    }

    void display() const
    {
        cout << "Order Details:\n";
        for (const auto &item : items)
        {
            item.display();
        }
        cout << "Total Amount: $" << totalAmount << endl;
    }
};

class Admin : public User
{
private:
    vector<MenuItem> menu;

    void loadMenu()
    {
        ifstream file("menu.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                size_t pos = line.find(',');
                string name = line.substr(0, pos);
                double price = stod(line.substr(pos + 1));
                menu.push_back(MenuItem(name, price));
            }
            file.close();
        }
    }

    void saveMenu() const
    {
        ofstream file("menu.txt");
        if (file.is_open())
        {
            for (const auto &item : menu)
            {
                file << item.toString() << endl;
            }
            file.close();
        }
    }

public:
    Admin()
    {
        loadMenu();
    }

    ~Admin()
    {
        saveMenu();
    }

    void addMenuItem(const MenuItem &item)
    {
        menu.push_back(item);
        cout << "Menu item added successfully.\n";
    }

    void removeMenuItem(const string &name)
    {
        auto it = remove_if(menu.begin(), menu.end(),
                            [name](const MenuItem &item)
                            { return item.name == name; });
        if (it != menu.end())
        {
            menu.erase(it, menu.end());
            cout << "Menu item removed successfully.\n";
        }
        else
        {
            cout << "Menu item not found.\n";
        }
    }

    void displayMenu() const override
    {
        cout << "Current Menu:\n";
        for (const auto &item : menu)
        {
            item.display();
        }
    }
};

class Chef : public User
{
public:
    void displayMenu() const override
    {
        Admin admin;
        admin.displayMenu();
    }
};

class Customer : public User
{
private:
    Order currentOrder;

public:
    void placeOrder(const MenuItem &item)
    {
        currentOrder.addItem(item);
        cout << "Item added to order.\n";
    }

    void viewOrder() const
    {
        currentOrder.display();
    }

    void displayMenu() const override
    {
        Admin admin;
        admin.displayMenu();
    }
};

void adminMenu(Admin &admin)
{
    int choice;
    do
    {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Menu Item\n";
        cout << "2. Remove Menu Item\n";
        cout << "3. Display Menu\n";
        cout << "4. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string name;
            double price;
            cout << "Enter item name: ";
            getline(cin, name);
            cout << "Enter price: ";
            cin >> price;
            cin.ignore();
            admin.addMenuItem(MenuItem(name, price));
            break;
        }
        case 2:
        {
            string name;
            cout << "Enter item name to remove: ";
            getline(cin, name);
            admin.removeMenuItem(name);
            break;
        }
        case 3:
            admin.displayMenu();
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

void customerMenu(Customer &customer)
{
    int choice;
    Admin admin;
    do
    {
        cout << "\nCustomer Menu:\n";
        cout << "1. View Menu\n";
        cout << "2. Place Order\n";
        cout << "3. View Order\n";
        cout << "4. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            customer.displayMenu();
            break;
        case 2:
        {
            string name;
            cout << "Enter item name to add to order: ";
            getline(cin, name);
            for (const auto &item : admin.menu)
            { // Admin object for menu access
                if (item.name == name)
                {
                    customer.placeOrder(item);
                    break;
                }
            }
            break;
        }
        case 3:
            customer.viewOrder();
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
    string role;
    cout << "Enter role (admin/customer): ";
    getline(cin, role);

    if (role == "admin")
    {
        Admin admin;
        adminMenu(admin);
    }
    else if (role == "customer")
    {
        Customer customer;
        customerMenu(customer);
    }
    else
    {
        cout << "Invalid role.\n";
    }

    return 0;
}
