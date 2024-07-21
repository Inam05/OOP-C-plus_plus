/*
Use lambda expressions to implement a custom sorting function for a std::vector of Person objects based
on their age and name. Demonstrate the usage of the lambda function in std::sort.
*/

#include <iostream>
using namespace std;

int main()
{
    auto add = [](int a, int b) -> int
    {
        return a + b;
    };

    auto multiply = [](int a, int b) -> int
    {
        return a * b;
    };

    cout << "Addition: " << add(5, 3) << endl;
    cout << "Multiplication: " << multiply(5, 3) << endl;

    return 0;
}
