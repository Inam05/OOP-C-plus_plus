/*
Design a class GameObject with a virtual method update(). Derive classes Player and Enemy from GameObject. Implement the update()
method in each derived class to handle updates specific to player and enemy objects in the game.
*/

// code


#include <iostream>
using namespace std;

class GameObject
{
public:
    virtual void update() = 0; // Pure virtual function
};

class Player : public GameObject
{
public:
    void update() override
    {
        cout << "Updating Player's position" << endl;
    }
};

class Enemy : public GameObject
{
public:
    void update() override
    {
        cout << "Updating Enemy's position" << endl;
    }
};

int main()
{
    GameObject *g1 = new Player();
    GameObject *g2 = new Enemy();
    g1->update();
    g2->update();
    delete g1;
    delete g2;
    return 0;
}