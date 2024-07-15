#include <iostream>
using namespace std;
const int max_leng = 50;
class Account
{
public:
    void enter_data(int &number, char name[max_leng], double &balance)
    {
        cout << "Enter Account Number: ";
        cin >> number;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Balance: ";
        cin >> balance;
    }

    void display_data(int number, const char name[max_leng], double balance)
    {
        cout << "Account Number: " << number << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: $" << balance << endl;
    }

    void deposit(double &balance, double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful. Updated Balance: $" << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount. Please enter a positive value." << endl;
        }
    }

    void withdraw(double &balance, double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful. Updated Balance: $" << balance << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient funds. Withdrawal unsuccessful." << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount. Please enter a positive value." << endl;
        }
    }
};

int main()
{
    Account account; 
    int number;
    char name[max_leng];
    double balance;

    account.enter_data(number, name, balance);

    cout << "\nAccount Details:\n";
    account.display_data(number, name, balance);

    double depositAmount;
    cout << "\nEnter deposit amount: $";
    cin >> depositAmount;
    account.deposit(balance, depositAmount);

    double withdrawAmount;
    cout << "\nEnter withdrawal amount: $";
    cin >> withdrawAmount;
    account.withdraw(balance, withdrawAmount);

    cout << "\nUpdated Account Details:\n";
    account.display_data(number, name, balance);

    return 0;
}
