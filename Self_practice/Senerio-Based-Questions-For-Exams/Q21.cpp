/*
Create a base class Animal with attributes name and age, and derive classes Dog and Cat. Implement default, parameterized, copy,
and move constructors for Animal. Add a method makeSound() to demonstrate polymorphism.
*/

#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
    int age;

public:
    Animal() : name(""), age(0) {}                                     // Default constructor
    Animal(string n, int a) : name(n), age(a) {}                       // Parameterized constructor
    Animal(const Animal &a) : name(a.name), age(a.age) {}              // Copy constructor
    Animal(Animal &&a) : name(move(a.name)), age(a.age) { a.age = 0; } // Move constructor

    virtual void makeSound() = 0; // Pure virtual function
};

class Dog : public Animal
{
public:
    Dog() : Animal() {}
    Dog(string n, int a) : Animal(n, a) {}
    Dog(const Dog &d) : Animal(d) {}
    Dog(Dog &&d) : Animal(move(d)) {}

    void makeSound() override
    {
        cout << name << " says Woof!" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat() : Animal() {}
    Cat(string n, int a) : Animal(n, a) {}
    Cat(const Cat &c) : Animal(c) {}
    Cat(Cat &&c) : Animal(move(c)) {}

    void makeSound() override
    {
        cout << name << " says Meow!" << endl;
    }
};

int main()
{
    Dog dog1("Buddy", 3);
    Dog dog2 = dog1;       // Using copy constructor
    Dog dog3 = move(dog1); // Using move constructor

    Cat cat1("Whiskers", 2);
    Cat cat2 = cat1;       // Using copy constructor
    Cat cat3 = move(cat1); // Using move constructor

    dog2.makeSound();
    dog3.makeSound();
    cat2.makeSound();
    cat3.makeSound();

    return 0;
}
