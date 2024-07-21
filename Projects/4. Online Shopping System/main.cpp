/*
Description: A system for managing products, customer accounts, and orders.
Questions:
How will you handle product listings and inventory?
How will you process and manage orders?
What features will you include for managing customer accounts?
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

class Item
{
public:
    string itemName;
    int quantity;
    double price;

    Item(string name, int qty, double pr) : itemName(name), quantity(qty), price(pr) {}

    void display() const
    {
        cout << "Item: " << itemName << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }

    string toString() const
    {
        return itemName + "," + to_string(quantity) + "," + to_string(price);
    }
};

class InventoryManager
{
private:
    vector<Item> items;

    void loadItems()
    {
        ifstream file("items.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);
                string itemName = line.substr(0, pos1);
                int quantity = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
                double price = stod(line.substr(pos2 + 1));
                items.push_back(Item(itemName, quantity, price));
            }
            file.close();
        }
    }

    void saveItems() const
    {
        ofstream file("items.txt");
        if (file.is_open())
        {
            for (const auto &item : items)
            {
                file << item.toString() << endl;
            }
            file.close();
        }
    }

public:
    InventoryManager()
    {
        loadItems();
    }

    ~InventoryManager()
    {
        saveItems();
    }

    void addItem(const Item &item)
    {
        items.push_back(item);
        cout << "Item added successfully.\n";
    }

    void updateItem(const string &name, const Item &updatedItem)
    {
        for (auto &item : items)
        {
            if (item.itemName == name)
            {
                item = updatedItem;
                cout << "Item updated successfully.\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

    void removeItem(const string &name)
    {
        auto it = remove_if(items.begin(), items.end(),
                            [name](const Item &i)
                            { return i.itemName == name; });
        if (it != items.end())
        {
            items.erase(it, items.end());
            cout << "Item removed successfully.\n";
        }
        else
        {
            cout << "Item not found.\n";
        }
    }

    void displayItems() const
    {
        for (const auto &item : items)
        {
            item.display();
        }
    }

    bool authenticateAdmin(const string &username, const string &password) const
    {
        return username == "admin" && password == "admin123";
    }
};

void adminMenu(InventoryManager &manager)
{
    int choice;
    do
    {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Item\n";
        cout << "2. Update Item\n";
        cout << "3. Remove Item\n";
        cout << "4. Display Items\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string name;
            int quantity;
            double price;
            cout << "Enter item name: ";
            getline(cin, name);
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;
            cin.ignore();
            manager.addItem(Item(name, quantity, price));
            break;
        }
        case 2:
        {
            string name;
            int quantity;
            double price;
            cout << "Enter item name to update: ";
            getline(cin, name);
            cout << "Enter new quantity: ";
            cin >> quantity;
            cout << "Enter new price: ";
            cin >> price;
            cin.ignore();
            manager.updateItem(name, Item(name, quantity, price));
            break;
        }
        case 3:
        {
            string name;
            cout << "Enter item name to remove: ";
            getline(cin, name);
            manager.removeItem(name);
            break;
        }
        case 4:
            manager.displayItems();
            break;
        case 5:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 5);
}

int main()
{
    InventoryManager manager;

    string username, password;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    if (manager.authenticateAdmin(username, password))
    {
        cout << "Authentication successful.\n";
        adminMenu(manager);
    }
    else
    {
        cout << "Authentication failed.\n";
    }

    return 0;
}
