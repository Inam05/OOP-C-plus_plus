/*
Design a custom container class that integrates with the C++ Standard Template Library (STL). Implement iterators and necessary member functions
to make it compatible with STL algorithms.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverse(arr, arr + n);
    cout << "Reversed array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
