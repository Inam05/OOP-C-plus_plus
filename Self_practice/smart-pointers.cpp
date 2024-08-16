/*
Smart pointers manage the lifecycle of dynamically allocated objects and help prevent memory leaks and dangling pointers.
They include std::unique_ptr, std::shared_ptr, and std::weak_ptr.
*/

#include <iostream>
#include <memory>

class MyClass
{
public:
    MyClass() { std::cout << "MyClass constructed" << std::endl; }
    ~MyClass() { std::cout << "MyClass destructed" << std::endl; }
    void greet() { std::cout << "Hello from MyClass!" << std::endl; }
};

int main()
{
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>();
    ptr1->greet();

    std::shared_ptr<MyClass> ptr2 = std::make_shared<MyClass>();
    ptr2->greet();

    std::weak_ptr<MyClass> weakPtr = ptr2;

    if (auto sharedPtr = weakPtr.lock())
    {
        sharedPtr->greet(); // Safe access
    }

    return 0;
}
