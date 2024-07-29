#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout << "A:default" << endl;
    }
    ~A()
    {
        cout << "A:default" << endl;
    }
    A(int a)
    {
        cout << "A:parameter" << endl;
    }
};
class B : public A
{
public:
    B(int a)
    {
        cout << "B" << endl;
    }
};
int main()
{
    B test(1);
}