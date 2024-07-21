/*
Design a Student class with data members name, age, and grades.
Implement methods to read and write Student objects to and from a file. Ensure proper serialization and deserialization
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outFile("example.txt");
    if (outFile.is_open())
    {
        outFile << "Hello, world!" << endl;
        outFile << "This is a test file." << endl;
        outFile.close();
    }
    else
    {
        cout << "Unable to open file for writing" << endl;
    }

    ifstream inFile("example.txt");
    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
        inFile.close();
    }
    else
    {
        cout << "Unable to open file for reading" << endl;
    }

    return 0;
}
