#include <iostream>
using namespace std;

int largest(int *A, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (*(A + i) < *(A + j)) 
            {
                int temp = *(A + i);
                *(A + i) = *(A + j);
                *(A + j) = temp;
            }
        }
    }
    return *A;
}

int main() 
{
    int x;
    cout << "Enter the size of an Array: ";
    cin >> x;

    int *A = new int[x];
    for (int i = 0; i < x; i++) 
    {
        cout << "Enter Number: ";
        cin >> *(A + i);
    }

    int Largest = largest(A, x);

    cout << "Largest Number in Array is: " << Largest << endl;

    delete[] A;

    return 0;
}
