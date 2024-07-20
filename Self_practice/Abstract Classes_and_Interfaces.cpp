/*
Define an abstract class Animal with pure virtual functions makeSound() and move(). Create derived classes Dog, Cat, and Bird that implement
these functions. Use the abstract class to demonstrate polymorphism.
*/

#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void makeSound() const = 0;
    virtual void move() const = 0;
    virtual ~Animal() {}
};

class Dog : public Animal
{
public:
    void makeSound() const override
    {
        cout << "Woof!" << endl;
    }

    void move() const override
    {
        cout << "Dog runs" << endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() const override
    {
        cout << "Meow!" << endl;
    }

    void move() const override
    {
        cout << "Cat jumps" << endl;
    }
};

class Bird : public Animal
{
public:
    void makeSound() const override
    {
        cout << "Chirp!" << endl;
    }

    void move() const override
    {
        cout << "Bird flies" << endl;
    }
};

int main()
{
    Dog d;
    Cat c;
    Bird b;

    Animal *animals[] = {&d, &c, &b};
    for (Animal *animal : animals)
    {
        animal->makeSound();
        animal->move();
    }

    return 0;
}
