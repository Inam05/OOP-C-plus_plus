/*You have a base class Animal, and then you have two derived classes, Mammal and Bird, which inherit from Animal.
Now, you want to create a class Bat which represents a mammal that can fly.*/

#include <iostream>
using namespace std;

class Animal
{
public:
    void eat()
    {
        cout << "Animal is eating." << endl;
    }
};

class Mammal : public Animal
{
public:
    void breathe()
    {
        cout << "Mammal is breathing." << endl;
    }
};

class Bird : public Animal
{
public:
    void fly()
    {
        cout << "Bird is flying." << endl;
    }
};

class Bat : public Mammal, public Bird
{
public:
    void eat()
    {
        Mammal::eat();
    }

    void nocturnal()
    {
        cout << "Bat is nocturnal." << endl;
    }
};

int main()
{
    Bat bat;
    bat.eat();
    bat.breathe();
    bat.fly();
    bat.nocturnal();
    return 0;
}