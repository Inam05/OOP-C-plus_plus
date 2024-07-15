#include <iostream>
using namespace std;

int* concatenate(int *A, int size_a, int *B, int size_b) 
{
    int new_size = size_a + size_b;
    int *new_array = new int[new_size];
    for (int i = 0; i < size_a; ++i) 
    {
        *(new_array + i) = *(A + i);
    }

    for (int i = 0; i < size_b; ++i) 
    {
        *(new_array + size_a + i) = *(B + i);
    }

    return new_array;
}

int main() {
    int size_a, size_b;

    cout << "Enter the size of the first array: ";
    cin >> size_a;
    int *A = new int[size_a];
    for (int i = 0; i < size_a; ++i) 
    {
        cout << "Enter the element : ";
        cin >> *(A + i);
    }

    cout << "Enter the size of the second array: ";
    cin >> size_b;
    int *B = new int[size_b];
    for (int i = 0; i < size_b; ++i) 
    {
        cout << "Enter the element : ";
        cin >> *(B + i);
    }

    int *concantenated_array = concatenate(A, size_a, B, size_b);
    cout << "Concatenated array: ";
    for (int i = 0; i < size_a + size_b; ++i) {
        cout << *(concantenated_array + i) << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] concantenated_array;

    return 0;
}
