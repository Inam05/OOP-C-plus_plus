/*
Write a C++ program to write following functions described below that use pointers
and dynamic memory allocation.
The Functions:
You will write these functions described below. Then you will call them from the
main function, to demonstrate their working:
1. maximum: takes an int array and the array's size as arguments. It should
return the maximum value of the array elements.
Do not use square brackets ANYWHERE in the function (use pointers
instead). Extra challenge: Do not use the loop variable in the body of the
loop.
*/
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
