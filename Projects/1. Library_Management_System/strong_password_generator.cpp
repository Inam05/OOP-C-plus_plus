#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

string generateStrongPassword(int length)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-=_+";
    srand(static_cast<unsigned int>(time(0)));
    string password;
    for (int i = 0; i < length; ++i)
    {
        password += charset[rand() % (sizeof(charset) - 1)];
    }
    return password;
}

int main()
{
    int passwordLength;
    cout << "Enter the length of the strong password: ";
    cin >> passwordLength;
    if (passwordLength <= 0)
    {
        cout << "Password length should be greater than 0." << endl;
        return 1;
    }
    string strongPassword = generateStrongPassword(passwordLength);
    cout << "Generated Strong Password: " << strongPassword << endl;
    return 0;
}
