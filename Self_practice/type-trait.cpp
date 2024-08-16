/*
Type traits provide compile-time information about types and enable type-based programming. They are useful for
template metaprogramming.
*/

#include <iostream>
#include <type_traits>

template <typename T>
void printType()
{
    if (std::is_integral<T>::value)
    {
        std::cout << "Integral type" << std::endl;
    }
    else
    {
        std::cout << "Non-integral type" << std::endl;
    }
}

int main()
{
    printType<int>();    // Integral type
    printType<double>(); // Non-integral type

    return 0;
}
