/*
Create a base class Animal with attributes name and species. Derive classes Bird and Mammal from Animal. Implement a virtual method
makeSound() in the base class and override it in the derived classes to simulate different sounds made by birds and mammals.
*/

// code

#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
    string species;

public:
    Animal(string n, string s) : name(n), species(s) {}
    virtual void makeSound() = 0; // Pure virtual function
};

class Bird : public Animal
{
public:
    Bird(string n) : Animal(n, "Bird") {}
    void makeSound() override
    {
        cout << "Bird " << name << " chirps" << endl;
    }
};

class Mammal : public Animal
{
public:
    Mammal(string n) : Animal(n, "Mammal") {}
    void makeSound() override
    {
        cout << "Mammal " << name << " roars" << endl;
    }
};

int main()
{
    Animal *a1 = new Bird("Parrot");
    Animal *a2 = new Mammal("Lion");
    a1->makeSound();
    a2->makeSound();
    delete a1;
    delete a2;
    return 0;
}
