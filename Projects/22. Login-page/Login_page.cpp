#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User
{
private:
    string username;
    string password;

public:
    User(const string &user, const string &pass) : username(user), password(pass) {}

    string getUsername() const { return username; }
    string getPassword() const { return password; }

    bool login(const string &user, const string &pass) const
    {
        return username == user && password == pass;
    }
};

class LoginSystem
{
private:
    void clearScreen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

public:
    void login()
    {
        string userId, password;
        clearScreen();
        cout << "\t\t\tPlease Enter the Username And the Password\n";
        cout << "\t\t\tEnter the Username: ";
        cin >> userId;
        cout << "\t\t\tEnter the Password: ";
        cin >> password;

        ifstream input("records.txt");
        string Id, pass;
        bool found = false;
        while (input >> Id >> pass)
        {
            if (User(Id, pass).login(userId, password))
            {
                found = true;
                break;
            }
        }
        input.close();

        clearScreen();
        if (found)
        {
            cout << "\t\t\t" << userId << "\n\t\t\tYou are logged in successfully.\n\t\t\tThanks for coming to our Page.\n\n";
        }
        else
        {
            cout << "\t\t\tLogin Error.\n\t\t\tPlease check your Username and the Password.\n\n";
        }
        displayMenu();
    }

    void registration()
    {
        string ruserId, rpassword;
        clearScreen();
        cout << "\t\t\tEnter Your Username And Password For the Registration\n";
        cout << "\t\t\tEnter the Username: ";
        cin >> ruserId;
        cout << "\t\t\tEnter the Password: ";
        cin >> rpassword;

        ofstream output("records.txt", ios::app);
        output << ruserId << ' ' << rpassword << endl;
        output.close();

        clearScreen();
        cout << "\t\t\tRegistration is Successful.\n\n";
        displayMenu();
    }

    void forgot()
    {
        clearScreen();
        cout << "\t\t\tYou forgot your password? No worries\n";
        cout << "Press 1 to search for your ID by your username.\n";
        cout << "Press 2 to go back to the main menu.\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string suserId, Id, spass;
            bool found = false;
            cout << "\n\t\t\tEnter the username that you remember: ";
            cin >> suserId;

            ifstream input("records.txt");
            while (input >> Id >> spass)
            {
                if (Id == suserId)
                {
                    found = true;
                    break;
                }
            }
            input.close();

            if (found)
            {
                cout << "\n\t\t\tYour Account Is Found\n";
                cout << "\t\t\tYour Password Is: " << spass << "\n";
            }
            else
            {
                cout << "\n\t\t\tYour Account Is not Found.\n";
            }
            break;
        }
        case 2:
            displayMenu();
            break;
        default:
            cout << "\t\t\tWrong Choice. Please Try Again.\n";
            forgot();
            break;
        }
    }

    void displayMenu()
    {
        int choice;
        cout << "\t\t\t______________________________________________________\n\n";
        cout << "\t\t\t             Welcome To The Login Page                  \n\n";
        cout << "\t\t\t_____________________MENU _____________________________\n\n";
        cout << "\t    |          Press 1 to Login\n";
        cout << "\t    |          Press 2 to Registration\n";
        cout << "\t    |          Press 3 to Forgot Password\n";
        cout << "\t    |          Press 4 to Exit\n\n";
        cout << "Enter your Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            clearScreen();
            cout << "\t\t\tThanks For Coming to Our Page!!!\n";
            break;
        default:
            clearScreen();
            cout << "\t\t\tPlease choose a valid option.\n";
            displayMenu();
            break;
        }
    }
};

int main()
{
    LoginSystem system;
    system.displayMenu();
    return 0;
}
