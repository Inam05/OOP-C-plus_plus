/*
Create a class BankAccount with attributes accountNumber, holderName, and balance. Derive classes SavingsAccount and CheckingAccount
from BankAccount. Implement all four types of constructors for BankAccount. Add a method calculateInterest() to demonstrate polymorphism.
*/

#include <iostream>
using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    BankAccount() : accountNumber(0), holderName(""), balance(0.0) {}                                                                               // Default constructor
    BankAccount(int num, string name, double bal) : accountNumber(num), holderName(name), balance(bal) {}                                           // Parameterized constructor
    BankAccount(const BankAccount &ba) : accountNumber(ba.accountNumber), holderName(ba.holderName), balance(ba.balance) {}                         // Copy constructor
    BankAccount(BankAccount &&ba) : accountNumber(ba.accountNumber), holderName(move(ba.holderName)), balance(ba.balance) { ba.accountNumber = 0; } // Move constructor

    virtual void calculateInterest() = 0; // Pure virtual function
};

class SavingsAccount : public BankAccount
{
public:
    SavingsAccount() : BankAccount() {}
    SavingsAccount(int num, string name, double bal) : BankAccount(num, name, bal) {}
    SavingsAccount(const SavingsAccount &sa) : BankAccount(sa) {}
    SavingsAccount(SavingsAccount &&sa) : BankAccount(move(sa)) {}

    void calculateInterest() override
    {
        balance *= 1.05; // 5% interest
        cout << "Interest applied to Savings Account: " << holderName << ", New Balance: $" << balance << endl;
    }
};

class CheckingAccount : public BankAccount
{
public:
    CheckingAccount() : BankAccount() {}
    CheckingAccount(int num, string name, double bal) : BankAccount(num, name, bal) {}
    CheckingAccount(const CheckingAccount &ca) : BankAccount(ca) {}
    CheckingAccount(CheckingAccount &&ca) : BankAccount(move(ca)) {}

    void calculateInterest() override
    {
        balance *= 1.01; // 1% interest
        cout << "Interest applied to Checking Account: " << holderName << ", New Balance: $" << balance << endl;
    }
};

int main()
{
    SavingsAccount sa1(101, "John Doe", 1000.0);
    CheckingAccount ca1(202, "Jane Smith", 2000.0);

    sa1.calculateInterest();
    ca1.calculateInterest();

    return 0;
}
