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
