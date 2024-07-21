/*
Description: A system for managing employee records, payroll, and departments.
Questions:
How will you handle employee information and payroll details?
How will you manage department assignments and reports?
What features will you include for managing employee data?
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

class Employee
{
public:
    string name;
    double salary;

    Employee(string n, double s) : name(n), salary(s) {}

    void display() const
    {
        cout << "Name: " << name << ", Salary: $" << salary << endl;
    }

    string toString() const
    {
        return name + "," + to_string(salary);
    }
};

class Admin : public User
{
private:
    vector<Employee> employees;

    void loadEmployees()
    {
        ifstream file("employees.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                size_t pos = line.find(',');
                string name = line.substr(0, pos);
                double salary = stod(line.substr(pos + 1));
                employees.push_back(Employee(name, salary));
            }
            file.close();
        }
    }

    void saveEmployees() const
    {
        ofstream file("employees.txt");
        if (file.is_open())
        {
            for (const auto &employee : employees)
            {
                file << employee.toString() << endl;
            }
            file.close();
        }
    }

public:
    Admin()
    {
        loadEmployees();
    }

    ~Admin()
    {
        saveEmployees();
    }

    void addEmployee(const Employee &employee)
    {
        employees.push_back(employee);
        cout << "Employee added successfully.\n";
    }

    void removeEmployee(const string &name)
    {
        auto it = remove_if(employees.begin(), employees.end(),
                            [name](const Employee &e)
                            { return e.name == name; });
        if (it != employees.end())
        {
            employees.erase(it, employees.end());
            cout << "Employee removed successfully.\n";
        }
        else
        {
            cout << "Employee not found.\n";
        }
    }

    void displayEmployees() const
    {
        cout << "Employee Records:\n";
        for (const auto &employee : employees)
        {
            employee.display();
        }
    }

    void displayMenu() const override
    {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Remove Employee\n";
        cout << "3. Display Employees\n";
        cout << "4. Logout\n";
    }
};

class HR : public User
{
private:
    vector<Employee> payroll;

public:
    void addToPayroll(const Employee &employee)
    {
        payroll.push_back(employee);
        cout << "Employee added to payroll.\n";
    }

    void displayPayroll() const
    {
        cout << "Payroll Records:\n";
        for (const auto &employee : payroll)
        {
            employee.display();
        }
    }

    void displayMenu() const override
    {
        cout << "\nHR Menu:\n";
        cout << "1. Add Employee to Payroll\n";
        cout << "2. Display Payroll\n";
        cout << "3. Logout\n";
    }
};

class EmployeeUser : public User
{
private:
    string name;

public:
    EmployeeUser(string n) : name(n) {}

    void viewRecord(const vector<Employee> &employees) const
    {
        for (const auto &employee : employees)
        {
            if (employee.name == name)
            {
                employee.display();
                return;
            }
        }
        cout << "Employee record not found.\n";
    }

    void displayMenu() const override
    {
        cout << "\nEmployee Menu:\n";
        cout << "1. View Record\n";
        cout << "2. Logout\n";
    }
};

void adminMenu(Admin &admin)
{
    int choice;
    do
    {
        admin.displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string name;
            double salary;
            cout << "Enter employee name: ";
            getline(cin, name);
            cout << "Enter salary: ";
            cin >> salary;
            cin.ignore();
            admin.addEmployee(Employee(name, salary));
            break;
        }
        case 2:
        {
            string name;
            cout << "Enter employee name to remove: ";
            getline(cin, name);
            admin.removeEmployee(name);
            break;
        }
        case 3:
            admin.displayEmployees();
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

void hrMenu(HR &hr, Admin &admin)
{
    int choice;
    do
    {
        hr.displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string name;
            cout << "Enter employee name to add to payroll: ";
            getline(cin, name);
            for (const auto &employee : admin.employees)
            {
                if (employee.name == name)
                {
                    hr.addToPayroll(employee);
                    break;
                }
            }
            break;
        }
        case 2:
            hr.displayPayroll();
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

void employeeMenu(EmployeeUser &employee, const vector<Employee> &employees)
{
    int choice;
    do
    {
        employee.displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            employee.viewRecord(employees);
            break;
        case 2:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 2);
}

int main()
{
    string role;
    cout << "Enter role (admin/hr/employee): ";
    getline(cin, role);

    Admin admin;
    HR hr;
    EmployeeUser employee("John Doe"); // Example employee name

    if (role == "admin")
    {
        adminMenu(admin);
    }
    else if (role == "hr")
    {
        hrMenu(hr, admin);
    }
    else if (role == "employee")
    {
        employeeMenu(employee, admin.employees);
    }
    else
    {
        cout << "Invalid role.\n";
    }

    return 0;
}
