/*
Implement a custom smart pointer class similar to std::shared_ptr or std::unique_ptr.
Demonstrate its usage with a sample class and ensure proper memory management.
*/

#include <iostream>
using namespace std;

template <typename T>
class SmartPointer
{
private:
    T *ptr;

public:
    explicit SmartPointer(T *p = nullptr) : ptr(p) {}
    ~SmartPointer() { delete ptr; }

    T &operator*()
    {
        return *ptr;
    }
    T *operator->()
    {
        return ptr;
    }
};

class Resource
{
public:
    void sayHello()
    {
        cout << "Hello from Resource" << endl;
    }
};

int main()
{
    SmartPointer<Resource> res(new Resource());
    res->sayHello();

    return 0;
}
