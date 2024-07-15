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
