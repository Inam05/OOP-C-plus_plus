/*
Write a function template for a sort() function that can sort an array of any data type. Implement specialized versions
for int and std::string types.
*/

#include <iostream>
using namespace std;

template <typename T>
void sort(T arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <>
void sort<int>(int arr[], int n)
{
    // Custom sort for int if needed
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <>
void sort<string>(string arr[], int n)
{
    // Custom sort for string if needed
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr1[] = {5, 3, 8, 4, 2};
    string arr2[] = {"banana", "apple", "cherry", "date"};

    sort(arr1, 5);
    sort(arr2, 4);

    for (int i = 0; i < 5; ++i)
        cout << arr1[i] << " ";
    cout << endl;

    for (int i = 0; i < 4; ++i)
        cout << arr2[i] << " ";
    cout << endl;

    return 0;
}
