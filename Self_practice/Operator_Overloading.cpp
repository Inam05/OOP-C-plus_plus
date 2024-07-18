/*
Overload the +, -, *, and / operators for a custom ComplexNumber class. Ensure proper handling of
complex number arithmetic.
*/

#include <iostream>
#include <stdexcept>
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double initial_balance) : balance(initial_balance) {}

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            throw invalid_argument("Deposit amount must be positive");
        }
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            throw runtime_error("Insufficient funds");
        }
        balance -= amount;
    }

    void transfer(BankAccount &to, double amount)
    {
        withdraw(amount);
        to.deposit(amount);
    }

    double getBalance() const
    {
        return balance;
    }
};

int main()
{
    try
    {
        BankAccount account1(100);
        BankAccount account2(50);

        account1.transfer(account2, 30);

        cout << "Account 1 balance: " << account1.getBalance() << endl;
        cout << "Account 2 balance: " << account2.getBalance() << endl;

        account1.withdraw(200); // This will throw an exception
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
