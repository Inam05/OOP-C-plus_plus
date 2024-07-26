/*
Design a class GameCharacter with attributes name and health. Derive classes Warrior and Mage from GameCharacter. Implement 
polymorphic behavior for a method attack() to simulate different attack styles for warriors and mages.
*/

#include <iostream>
using namespace std;

class GameCharacter {
protected:
    string name;
    int health;
public:
    GameCharacter(string n, int h) : name(n), health(h) {}
    virtual void attack() = 0; // Pure virtual function
};

class Warrior : public GameCharacter {
public:
    Warrior(string n, int h) : GameCharacter(n, h) {}
    void attack() override {
        cout << name << " attacks with a sword!" << endl;
    }
};

class Mage : public GameCharacter {
public:
    Mage(string n, int h) : GameCharacter(n, h) {}
    void attack() override {
        cout << name << " casts a spell!" << endl;
    }
};

int main() {
    GameCharacter* gc1 = new Warrior("Thor", 100);
    GameCharacter* gc2 = new Mage("Gandalf", 80);
    gc1->attack();
    gc2->attack();
    delete gc1;
    delete gc2;
    return 0;
}

