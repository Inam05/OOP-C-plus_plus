/*
Design a class BankAccount that has a private member variable balance. Create a friend class BankManager that can access
and modify the balance of BankAccount. Show how the BankManager class can perform operations like deposit and withdrawal
on the BankAccount class using friend functions.
*/

#include <iostream>
using namespace std;

// Forward declaration of BankManager class
class BankManager;

// Class BankAccount
class BankAccount
{
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    // Friend class declaration
    friend class BankManager;

    // Function to display balance
    void displayBalance() const
    {
        cout << "Current balance: $" << balance << endl;
    }
};

// Class BankManager that is a friend of BankAccount
class BankManager
{
public:
    // Friend function to deposit money into the account
    void deposit(BankAccount &account, double amount)
    {
        if (amount > 0)
        {
            account.balance += amount;
            cout << "Deposited: $" << amount << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Friend function to withdraw money from the account
    void withdraw(BankAccount &account, double amount)
    {
        if (amount > 0 && amount <= account.balance)
        {
            account.balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        }
        else
        {
            cout << "Invalid or insufficient funds!" << endl;
        }
    }
};

// Main function to demonstrate friend class functionality
int main()
{
    BankAccount myAccount(1000.0); // Create a BankAccount with an initial balance of $1000
    BankManager manager;           // Create a BankManager instance

    myAccount.displayBalance(); // Display initial balance

    manager.deposit(myAccount, 500.0); // Deposit $500
    myAccount.displayBalance();        // Display balance after deposit

    manager.withdraw(myAccount, 200.0); // Withdraw $200
    myAccount.displayBalance();         // Display balance after withdrawal

    manager.withdraw(myAccount, 2000.0); // Attempt to withdraw more than the balance
    myAccount.displayBalance();          // Display balance after failed withdrawal

    return 0;
}
