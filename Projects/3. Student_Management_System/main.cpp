/*
Description: A system for managing student records, including enrollment, grades, and courses.
Questions:
How will you handle student data and course information?
How will you calculate and store grades?
How will you generate student reports and transcripts?
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

class Student
{
public:
    string name;
    int rollNumber;
    double GPA;

    Student(string n, int r, double g) : name(n), rollNumber(r), GPA(g) {}

    void display() const
    {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << ", GPA: " << GPA << endl;
    }

    string toString() const
    {
        return name + "," + to_string(rollNumber) + "," + to_string(GPA);
    }
};

class StudentManager
{
private:
    vector<Student> students;

    void loadStudents()
    {
        ifstream file("students.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);
                string name = line.substr(0, pos1);
                int rollNumber = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
                double GPA = stod(line.substr(pos2 + 1));
                students.push_back(Student(name, rollNumber, GPA));
            }
            file.close();
        }
    }

    void saveStudents() const
    {
        ofstream file("students.txt");
        if (file.is_open())
        {
            for (const auto &student : students)
            {
                file << student.toString() << endl;
            }
            file.close();
        }
    }

public:
    StudentManager()
    {
        loadStudents();
    }

    ~StudentManager()
    {
        saveStudents();
    }

    void addStudent(const Student &student)
    {
        students.push_back(student);
        cout << "Student added successfully.\n";
    }

    void updateStudent(int rollNumber, const Student &updatedStudent)
    {
        for (auto &student : students)
        {
            if (student.rollNumber == rollNumber)
            {
                student = updatedStudent;
                cout << "Student updated successfully.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void deleteStudent(int rollNumber)
    {
        auto it = remove_if(students.begin(), students.end(),
                            [rollNumber](const Student &s)
                            { return s.rollNumber == rollNumber; });
        if (it != students.end())
        {
            students.erase(it, students.end());
            cout << "Student deleted successfully.\n";
        }
        else
        {
            cout << "Student not found.\n";
        }
    }

    void displayStudents() const
    {
        for (const auto &student : students)
        {
            student.display();
        }
    }

    bool authenticateAdmin(const string &username, const string &password) const
    {
        return username == "admin" && password == "admin123";
    }
};

void adminMenu(StudentManager &manager)
{
    int choice;
    do
    {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Update Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display Students\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string name;
            int rollNumber;
            double GPA;
            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Enter roll number: ";
            cin >> rollNumber;
            cout << "Enter GPA: ";
            cin >> GPA;
            cin.ignore();
            manager.addStudent(Student(name, rollNumber, GPA));
            break;
        }
        case 2:
        {
            int rollNumber;
            string name;
            double GPA;
            cout << "Enter roll number of student to update: ";
            cin >> rollNumber;
            cin.ignore();
            cout << "Enter new name: ";
            getline(cin, name);
            cout << "Enter new GPA: ";
            cin >> GPA;
            cin.ignore();
            manager.updateStudent(rollNumber, Student(name, rollNumber, GPA));
            break;
        }
        case 3:
        {
            int rollNumber;
            cout << "Enter roll number of student to delete: ";
            cin >> rollNumber;
            cin.ignore();
            manager.deleteStudent(rollNumber);
            break;
        }
        case 4:
            manager.displayStudents();
            break;
        case 5:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 5);
}

int main()
{
    StudentManager manager;

    string username, password;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    if (manager.authenticateAdmin(username, password))
    {
        cout << "Authentication successful.\n";
        adminMenu(manager);
    }
    else
    {
        cout << "Authentication failed.\n";
    }

    return 0;
}
