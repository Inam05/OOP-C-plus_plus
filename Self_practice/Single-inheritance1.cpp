/*You have a base class called Animal with a protected member age. Now, you want to create a derived class called Dog
which inherits from Animal and adds a public method getAge() to retrieve the age of the dog.*/

#include <iostream>
using namespace std;
class Animal
{
protected:
    int age;

public:
    void setAge(int a)
    {
        age = a;
    }
};

class Dog : public Animal
{
public:
    int getAge()
    {
        return age;
    }
};
int main()
{
    Dog d;
    d.getAge();
    return 0;
}