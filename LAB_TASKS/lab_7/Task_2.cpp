#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    string department;
    double salary;

public:
    Employee() {}
    string getName() const
    {
        return name;
    }
    string getDepartment() const
    {
        return department;
    }
    double getSalary() const
    {
        return salary;
    }
    void setName(const string &n)
    {
        name = n;
    }

    void setDepartment(const string &d)
    {
        department = d;
    }
    void setSalary(double s)
    {
        salary = s;
    }
    void getData()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter department: ";
        cin >> department;
        cout << "Enter salary: ";
        cin >> salary;
    }

    void displayData() const
    {
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main()
{
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    Employee *employees = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; i++)
    {
        cout << "Enter data for employee " << (i + 1) << ":" << endl;
        employees[i].getData();
    }

    int choice;
    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Search by name" << endl;
        cout << "2. Search by department" << endl;
        cout << "3. Search by salary" << endl;
        cout << "4. Add new employee" << endl;
        cout << "5. Display all employees" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            cout << "Enter name to search: ";
            cin >> name;
            bool found = false;
            for (int i = 0; i < numEmployees; i++)
            {
                if (employees[i].getName() == name)
                {
                    employees[i].displayData();
                    found = true;
                }
            }
            if (!found)
            {
                cout << "Employee not found." << endl;
            }
            break;
        }
        case 2:
        {
            string department;
            cout << "Enter department to search: ";
            cin >> department;
            bool found = false;
            for (int i = 0; i < numEmployees; i++)
            {
                if (employees[i].getDepartment() == department)
                {
                    employees[i].displayData();
                    found = true;
                }
            }
            if (!found)
            {
                cout << "Employee not found." << endl;
            }
            break;
        }
        case 3:
        {
            double salary;
            cout << "Enter salary to search: ";
            cin >> salary;
            bool found = false;
            for (int i = 0; i < numEmployees; i++)
            {
                if (employees[i].getSalary() == salary)
                {
                    employees[i].displayData();
                    found = true;
                }
            }
            if (!found)
            {
                cout << "Employee not found." << endl;
            }
            break;
        }
        case 4:
        {
            Employee newEmployee;
            newEmployee.getData();
            Employee *temp = new Employee[numEmployees + 1];
            for (int i = 0; i < numEmployees; i++)
            {
                temp[i] = employees[i];
            }
            temp[numEmployees] = newEmployee;
            delete[] employees;
            employees = temp;
            numEmployees++;
            break;
        }
        case 5:
        {
            for (int i = 0; i < numEmployees; i++)
            {
                employees[i].displayData();
                cout << endl;
            }
            break;
        }
        case 6:
        {
            delete[] employees;
            return 0;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        }
    }
    return 0;
}