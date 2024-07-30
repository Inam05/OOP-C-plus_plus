#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Expense
{
private:
    string category;
    double amount;
    string date;

public:
    // Constructor
    Expense(const string &cat, double amt, const string &d) : category(cat), amount(amt), date(d) {}

    // Getters
    string getCategory() const { return category; }
    double getAmount() const { return amount; }
    string getDate() const { return date; }

    // Display expense details
    void display() const
    {
        cout << setw(15) << category << setw(15) << amount << setw(15) << date << endl;
    }
};

class ExpenseTracker
{
private:
    vector<Expense> expenses;

public:
    void addExpense(const Expense &expense)
    {
        expenses.push_back(expense);
        cout << "Expense added successfully." << endl;
    }

    void viewExpenses() const
    {
        if (expenses.empty())
        {
            cout << "No expenses recorded yet." << endl;
            return;
        }

        cout << setw(15) << "Category" << setw(15) << "Amount" << setw(15) << "Date" << endl;
        cout << setfill('-') << setw(45) << "" << setfill(' ') << endl;

        for (const Expense &exp : expenses)
        {
            exp.display();
        }
    }

    double calculateTotalExpense() const
    {
        double total = 0.0;
        for (const Expense &exp : expenses)
        {
            total += exp.getAmount();
        }
        return total;
    }
};

int main()
{
    ExpenseTracker expenseTracker;

    while (true)
    {
        cout << "Expense Tracker" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. View Expenses" << endl;
        cout << "3. Total Expenses" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string category, date;
            double amount;

            cout << "Enter expense category: ";
            cin >> category;
            cout << "Enter expense amount: ";
            cin >> amount;
            cout << "Enter expense date: ";
            cin >> date;

            Expense newExpense(category, amount, date);
            expenseTracker.addExpense(newExpense);
            break;
        }
        case 2:
            expenseTracker.viewExpenses();
            break;
        case 3:
            cout << "Total Expenses: $" << expenseTracker.calculateTotalExpense() << endl;
            break;
        case 4:
            cout << "Exiting Expense Tracker. Have a great day!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
