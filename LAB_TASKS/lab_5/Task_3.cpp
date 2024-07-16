/*
expand: takes an int array and the array's size as arguments. It should
create a new array that is twice the size of the argument array. The function
Engr. Amna Bibi Lab 5 Page 7
should copy the contents of the argument array to the new array and
initialize the unused elements of the new array with -1. The function should
return a pointer to the new array.
*/
#include <iostream>
using namespace std;

int* expand(int *A, int size) {
    int new_size = size * 2;
    int *new_A = new int[new_size];
    
    for (int i = 0; i < size; i++) 
    {
        *(new_A + i) = *(A + i);
    }
    
    for (int i = size; i < new_size; i++) 
    {
        *(new_A + i) = -1;
    }
    
    return new_A;
}

int main() {
    int size;
    cout << "Enter the size of the Aay: ";
    cin >> size;
    
    int *A = new int[size];
    for (int i = 0; i < size; i++) 
    {
        cout << "Enter the element : ";
        cin >> *(A + i);
    }
    
    int *expanded_A = expand(A, size);
    
    cout << "Original Aay: ";
    for (int i = 0; i < size; i++) 
    {
        cout << *(A + i) << " ";
    }
    cout << endl;
    
    cout << "Expanded Aay: ";
    for (int i = 0; i < size * 2; i++) 
    {
        cout << *(expanded_A + i) << " ";
    }
    cout << endl;
    
    delete[] A;
    delete[] expanded_A;
    
    return 0;
}
