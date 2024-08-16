/*
Move semantics optimize resource management by transferring ownership of resources instead of copying them. It helps
avoid unnecessary copies and improves performance.
*/

#include <iostream>
#include <utility> // For std::move

class Resource
{
public:
    Resource() : data(new int[100]) { std::cout << "Resource acquired" << std::endl; }
    ~Resource()
    {
        delete[] data;
        std::cout << "Resource released" << std::endl;
    }

    // Move constructor
    Resource(Resource &&other) noexcept : data(other.data)
    {
        other.data = nullptr;
        std::cout << "Resource moved" << std::endl;
    }

    // Move assignment operator
    Resource &operator=(Resource &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            other.data = nullptr;
            std::cout << "Resource move-assigned" << std::endl;
        }
        return *this;
    }

private:
    int *data;
};

int main()
{
    Resource res1;
    Resource res2 = std::move(res1); // Move constructor

    Resource res3;
    res3 = std::move(res2); // Move assignment operator

    return 0;
}
