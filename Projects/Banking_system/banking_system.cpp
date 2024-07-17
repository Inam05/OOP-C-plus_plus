#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct BankAccount
{
    string accountHolder;
    double balance;
};

void createAccount(vector<BankAccount> &accounts);
void depositMoney(vector<BankAccount> &accounts);
void withdrawMoney(vector<BankAccount> &accounts);
void displayAccountInfo(const vector<BankAccount> &accounts);

int main()
{
    vector<BankAccount> accounts; // List to store bank accounts

    // Perform banking operations
    createAccount(accounts);
    depositMoney(accounts);
    withdrawMoney(accounts);
    displayAccountInfo(accounts);

    return 0;
}

// Function to create a new bank account
void createAccount(vector<BankAccount> &accounts)
{
    BankAccount newAccount;

    cout << "Enter the account holder's name: ";
    getline(cin, newAccount.accountHolder);

    newAccount.balance = 0.0;

    accounts.push_back(newAccount);

    cout << "Account created successfully!" << endl;
}

// Function to deposit money into an account
void depositMoney(vector<BankAccount> &accounts)
{
    cout << "Enter the account holder's name for deposit: ";
    string accountHolder;
    getline(cin, accountHolder);

    for (auto &account : accounts)
    {
        if (account.accountHolder == accountHolder)
        {
            double amount;
            cout << "Enter the amount to deposit: ";
            cin >> amount;
            cin.ignore(); // Consume the newline character

            account.balance += amount;

            cout << "Deposit successful! New balance: " << account.balance << endl;
            return;
        }
    }

    cout << "Account not found." << endl;
}

// Function to withdraw money from an account
void withdrawMoney(vector<BankAccount> &accounts)
{
    cout << "Enter the account holder's name for withdrawal: ";
    string accountHolder;
    getline(cin, accountHolder);

    for (auto &account : accounts)
    {
        if (account.accountHolder == accountHolder)
        {
            double amount;
            cout << "Enter the amount to withdraw: ";
            cin >> amount;
            cin.ignore(); // Consume the newline character

            if (amount > account.balance)
            {
                cout << "Insufficient funds. Withdrawal failed." << endl;
            }
            else
            {
                account.balance -= amount;
                cout << "Withdrawal successful! New balance: " << account.balance << endl;
            }
            return;
        }
    }

    cout << "Account not found." << endl;
}

// Function to display account information
void displayAccountInfo(const vector<BankAccount> &accounts)
{
    cout << "Account Information:" << endl;

    if (accounts.empty())
    {
        cout << "No accounts found." << endl;
    }
    else
    {
        for (const auto &account : accounts)
        {
            cout << "Account Holder: " << account.accountHolder << "\tBalance: " << account.balance << endl;
        }
    }
}
