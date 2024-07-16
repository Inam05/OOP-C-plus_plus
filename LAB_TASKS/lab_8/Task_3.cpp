/*
Multilevel Inheritance
Define a base class called `Animal` with member variables representing the animal's
species and age. Derive a subclass called `Mammal` from the `Animal` class, and then
derive another subclass called `Dog` from the `Mammal` class. Implement methods to
display information about each type of animal.
*/
#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
    string species;
    int age;

public:
    Animal(string sp, int ag)
    {
        species = sp;
        age = ag;
    }
    void display()
    {
        cout << "Species: " << species << ", Age: " << age << endl;
    }
};

class Mammal : public Animal
{
public:
    Mammal(string sp, int ag) : Animal(sp, ag) {}
};

class Dog : public Mammal
{
public:
    Dog(string sp, int ag) : Mammal(sp, ag) {}
};

int main()
{
    Dog dog("Canine", 5);
    dog.display();
    return 0;
}
