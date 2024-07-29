#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Structure to represent an employee
struct Employee
{
    string name;
    int employeeId;
    bool present;
};

class AttendanceManagementSystem
{
private:
    vector<Employee> employees;
    int nextEmployeeId; // To automatically generate employee IDs

public:
    // Constructor to initialize the nextEmployeeId
    AttendanceManagementSystem() : nextEmployeeId(1001) {}

    // Add a new employee to the system
    void addEmployee()
    {
        cout << "Enter the name of the employee: ";
        string name;
        cin.ignore(); // Clear input buffer
        getline(cin, name);

        employees.push_back({name, nextEmployeeId, false});
        cout << "Employee added successfully. Employee ID: " << nextEmployeeId << endl;
        nextEmployeeId++;
    }

    // Mark employee attendance
    void markAttendance()
    {
        cout << "Enter the Employee ID to mark attendance: ";
        int employeeId;
        cin >> employeeId;

        bool found = false;

        for (auto &employee : employees)
        {
            if (employee.employeeId == employeeId)
            {
                if (!employee.present)
                {
                    employee.present = true;
                    cout << "Attendance marked successfully for " << employee.name << "." << endl;
                }
                else
                {
                    cout << "Attendance already marked for " << employee.name << "." << endl;
                }
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Employee not found." << endl;
        }
    }

    // Display attendance report
    void displayAttendanceReport() const
    {
        cout << setw(20) << "Employee Name" << setw(15) << "Employee ID" << setw(15) << "Status" << endl;
        cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;

        for (const Employee &employee : employees)
        {
            cout << setw(20) << employee.name << setw(15) << employee.employeeId << setw(15)
                 << (employee.present ? "Present" : "Absent") << endl;
        }
    }
};

int main()
{
    AttendanceManagementSystem attendanceSystem;

    int choice;
    do
    {
        cout << "\nMenu:\n1. Add Employee\n2. Mark Attendance\n3. Display Attendance Report\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            attendanceSystem.addEmployee();
            break;
        case 2:
            attendanceSystem.markAttendance();
            break;
        case 3:
            attendanceSystem.displayAttendanceReport();
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
