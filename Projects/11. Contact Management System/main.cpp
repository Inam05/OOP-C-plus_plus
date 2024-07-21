/*
Description: A system for managing and organizing contact information.
Questions:
How will you store and organize contact details?
How will you handle searching and sorting contacts?
What features will you include for managing contact information?
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

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    virtual void display() const
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Patient : public Person
{
private:
    vector<string> medicalNotes;

public:
    Patient(string n, int a) : Person(n, a) {}

    void addMedicalNote(const string &note)
    {
        medicalNotes.push_back(note);
    }

    void viewMedicalNotes() const
    {
        cout << "Medical Notes for " << name << ":\n";
        for (const auto &note : medicalNotes)
        {
            cout << "- " << note << endl;
        }
    }

    void display() const override
    {
        Person::display();
        viewMedicalNotes();
    }
};

class Doctor : public Person
{
private:
    vector<string> patients;

public:
    Doctor(string n, int a) : Person(n, a) {}

    void addPatient(const string &patientName)
    {
        patients.push_back(patientName);
    }

    void viewPatients() const
    {
        cout << "Patients under Dr. " << name << ":\n";
        for (const auto &patient : patients)
        {
            cout << "- " << patient << endl;
        }
    }

    void display() const override
    {
        Person::display();
        viewPatients();
    }
};

class Admin : public User
{
private:
    vector<Doctor> doctors;
    vector<Patient> patients;

    void loadDoctors()
    {
        ifstream file("doctors.txt");
        if (file.is_open())
        {
            string name;
            int age;
            while (file >> name >> age)
            {
                doctors.push_back(Doctor(name, age));
            }
            file.close();
        }
    }

    void saveDoctors() const
    {
        ofstream file("doctors.txt");
        if (file.is_open())
        {
            for (const auto &doctor : doctors)
            {
                file << doctor.name << " " << doctor.age << endl;
            }
            file.close();
        }
    }

    void loadPatients()
    {
        ifstream file("patients.txt");
        if (file.is_open())
        {
            string name;
            int age;
            while (file >> name >> age)
            {
                patients.push_back(Patient(name, age));
            }
            file.close();
        }
    }

    void savePatients() const
    {
        ofstream file("patients.txt");
        if (file.is_open())
        {
            for (const auto &patient : patients)
            {
                file << patient.name << " " << patient.age << endl;
            }
            file.close();
        }
    }

public:
    Admin()
    {
        loadDoctors();
        loadPatients();
    }

    ~Admin()
    {
        saveDoctors();
        savePatients();
    }

    void addDoctor(const Doctor &doctor)
    {
        doctors.push_back(doctor);
        cout << "Doctor added successfully.\n";
    }

    void removeDoctor(const string &name)
    {
        auto it = remove_if(doctors.begin(), doctors.end(),
                            [name](const Doctor &d)
                            { return d.name == name; });
        if (it != doctors.end())
        {
            doctors.erase(it, doctors.end());
            cout << "Doctor removed successfully.\n";
        }
        else
        {
            cout << "Doctor not found.\n";
        }
    }

    void addPatient(const Patient &patient)
    {
        patients.push_back(patient);
        cout << "Patient added successfully.\n";
    }

    void removePatient(const string &name)
    {
        auto it = remove_if(patients.begin(), patients.end(),
                            [name](const Patient &p)
                            { return p.name == name; });
        if (it != patients.end())
        {
            patients.erase(it, patients.end());
            cout << "Patient removed successfully.\n";
        }
        else
        {
            cout << "Patient not found.\n";
        }
    }

    void displayDoctors() const
    {
        cout << "Doctor List:\n";
        for (const auto &doctor : doctors)
        {
            doctor.display();
        }
    }

    void displayPatients() const
    {
        cout << "Patient List:\n";
        for (const auto &patient : patients)
        {
            patient.display();
        }
    }

    void displayMenu() const override
    {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Doctor\n";
        cout << "2. Remove Doctor\n";
        cout << "3. Display Doctors\n";
        cout << "4. Add Patient\n";
        cout << "5. Remove Patient\n";
        cout << "6. Display Patients\n";
        cout << "7. Logout\n";
    }
};

class DoctorUser : public User
{
private:
    Doctor &doctor;

public:
    DoctorUser(Doctor &d) : doctor(d) {}

    void addPatientToDoctor(const string &patientName)
    {
        doctor.addPatient(patientName);
        cout << "Patient added to doctor.\n";
    }

    void displayMenu() const override
    {
        cout << "\nDoctor Menu:\n";
        cout << "1. Add Patient to Doctor\n";
        cout << "2. View Patients\n";
        cout << "3. Logout\n";
    }
};

class PatientUser : public User
{
private:
    Patient &patient;

public:
    PatientUser(Patient &p) : patient(p) {}

    void requestAppointment()
    {
        cout << "Appointment requested for " << patient.name << ".\n";
    }

    void addMedicalNoteToPatient(const string &note)
    {
        patient.addMedicalNote(note);
        cout << "Medical note added.\n";
    }

    void displayMenu() const override
    {
        cout << "\nPatient Menu:\n";
        cout << "1. Request Appointment\n";
        cout << "2. Add Medical Note\n";
        cout << "3. Logout\n";
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
            int age;
            cout << "Enter doctor name: ";
            getline(cin, name);
            cout << "Enter doctor age: ";
            cin >> age;
            cin.ignore();
            admin.addDoctor(Doctor(name, age));
            break;
        }
        case 2:
        {
            string name;
            cout << "Enter doctor name to remove: ";
            getline(cin, name);
            admin.removeDoctor(name);
            break;
        }
        case 3:
            admin.displayDoctors();
            break;
        case 4:
        {
            string name;
            int age;
            cout << "Enter patient name: ";
            getline(cin, name);
            cout << "Enter patient age: ";
            cin >> age;
            cin.ignore();
            admin.addPatient(Patient(name, age));
            break;
        }
        case 5:
        {
            string name;
            cout << "Enter patient name to remove: ";
            getline(cin, name);
            admin.removePatient(name);
            break;
        }
        case 6:
            admin.displayPatients();
            break;
        case 7:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 7);
}

void doctorMenu(DoctorUser &doctorUser)
{
    int choice;
    do
    {
        doctorUser.displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string patientName;
            cout << "Enter patient name to add: ";
            getline(cin, patientName);
            doctorUser.addPatientToDoctor(patientName);
            break;
        }
        case 2:
            doctorUser.doctor.viewPatients();
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

void patientMenu(PatientUser &patientUser)
{
    int choice;
    do
    {
        patientUser.displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            patientUser.requestAppointment();
            break;
        case 2:
        {
            string note;
            cout << "Enter medical note: ";
            getline(cin, note);
            patientUser.addMedicalNoteToPatient(note);
            break;
        }
        case 3:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 3);
}

int main()
{
    string role;
    cout << "Enter role (admin/doctor/patient): ";
    getline(cin, role);

    Admin admin;
    Doctor doctor("JohnDoe", 45);   // Example doctor
    Patient patient("JaneDoe", 30); // Example patient

    if (role == "admin")
    {
        adminMenu(admin);
    }
    else if (role == "doctor")
    {
        DoctorUser doctorUser(doctor);
        doctorMenu(doctorUser);
    }
    else if (role == "patient")
    {
        PatientUser patientUser(patient);
        patientMenu(patientUser);
    }
    else
    {
        cout << "Invalid role.\n";
    }

    return 0;
}
