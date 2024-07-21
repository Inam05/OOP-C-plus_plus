/*
Description: A system to manage bank accounts, including deposits, withdrawals, and balance inquiries.
Questions:
How will you manage multiple accounts?
How will you handle transactions and balance updates?
What security measures will you implement?
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

class Account
{
public:
    string accountNumber;
    double balance;

    Account(string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
        }
        else
        {
            cout << "Insufficient funds." << endl;
        }
    }

    void display() const
    {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }

    string toString() const
    {
        return accountNumber + "," + to_string(balance);
    }
};

class Bank
{
private:
    vector<Account> accounts;

    void loadAccounts()
    {
        ifstream file("accounts.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                size_t pos = line.find(',');
                string accountNumber = line.substr(0, pos);
                double balance = stod(line.substr(pos + 1));
                accounts.push_back(Account(accountNumber, balance));
            }
            file.close();
        }
    }

    void saveAccounts() const
    {
        ofstream file("accounts.txt");
        if (file.is_open())
        {
            for (const auto &account : accounts)
            {
                file << account.toString() << endl;
            }
            file.close();
        }
    }

public:
    Bank()
    {
        loadAccounts();
    }

    ~Bank()
    {
        saveAccounts();
    }

    void createAccount(const Account &account)
    {
        accounts.push_back(account);
    }

    void deposit(const string &accountNumber, double amount)
    {
        for (auto &account : accounts)
        {
            if (account.accountNumber == accountNumber)
            {
                account.deposit(amount);
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void withdraw(const string &accountNumber, double amount)
    {
        for (auto &account : accounts)
        {
            if (account.accountNumber == accountNumber)
            {
                account.withdraw(amount);
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void displayAccounts() const
    {
        for (const auto &account : accounts)
        {
            account.display();
        }
    }

    bool authenticateAdmin(const string &username, const string &password) const
    {
        return username == "admin" && password == "admin123";
    }
};

void adminMenu(Bank &bank)
{
    int choice;
    do
    {
        cout << "\nAdmin Menu:\n";
        cout << "1. Create Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string accountNumber;
            double initialBalance;
            cout << "Enter account number: ";
            getline(cin, accountNumber);
            cout << "Enter initial balance: ";
            cin >> initialBalance;
            cin.ignore();
            bank.createAccount(Account(accountNumber, initialBalance));
            cout << "Account created successfully.\n";
            break;
        }
        case 2:
            bank.displayAccounts();
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

void userMenu(Bank &bank)
{
    int choice;
    string accountNumber;
    do
    {
        cout << "\nUser Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account\n";
        cout << "4. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            double amount;
            cout << "Enter account number: ";
            getline(cin, accountNumber);
            cout << "Enter amount to deposit: ";
            cin >> amount;
            cin.ignore();
            bank.deposit(accountNumber, amount);
            break;
        }
        case 2:
        {
            double amount;
            cout << "Enter account number: ";
            getline(cin, accountNumber);
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            cin.ignore();
            bank.withdraw(accountNumber, amount);
            break;
        }
        case 3:
            bank.displayAccounts();
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
    Bank bank;

    string username, password;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    if (bank.authenticateAdmin(username, password))
    {
        cout << "Authentication successful.\n";
        adminMenu(bank);
    }
    else
    {
        cout << "Authentication failed. Enter account number for user menu: ";
        getline(cin, username); // Using username as account number for simplicity
        userMenu(bank);
    }

    return 0;
}
