#include<iostream>
using namespace std;

class Animal
{
    string sound;
public:
    int age;
    void makeSound() {
        cout << "The animal makes a sound." << endl;
    }
    void eat() {
        cout << "The animal eats." << endl;
    }
    void sleep() {
        cout << "The animal sleeps." << endl;
    }
    void display() {
        cout << "Age: " << age << endl;
        cout << "Sound: " << sound << endl;
    }
};

class Mammal : public Animal
{
    string furColor;
public:
    int weight;
    void giveBirth() {
        cout << "The mammal gives birth." << endl;
    }
    void nurse() {
        cout << "The mammal nurses its young." << endl;
    }
    void walk() {
        cout << "The mammal walks." << endl;
    }
    void display() {
        cout << "Weight: " << weight << endl;
        cout << "Fur Color: " << furColor << endl;
        Animal::display();
    }
};

int main() {
    Mammal myMammal;
    myMammal.age = 5;
    myMammal.weight = 50;
    myMammal.makeSound();
    myMammal.eat();
    myMammal.sleep();
    myMammal.giveBirth();
    myMammal.nurse();
    myMammal.walk();
    myMammal.display();
    return 0;
}