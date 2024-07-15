#include <iostream>
using namespace std;
int odd_swap(int *x, int *y) 
{
    int temp = *x;
    *x = *y * 5;
    *y = temp * 5;
    return *x + *y;
}

int main() 
{
    int a = 13, b = 17;
    cout << "Before swapping: a = " << a << " & b = " << b << endl;
    int sum = odd_swap(&a, &b);
    cout << "After swapping: a = " << a << " & b = " << b << endl;
    cout << "Sum after manipulation: " << sum << std::endl;
    return 0;
}