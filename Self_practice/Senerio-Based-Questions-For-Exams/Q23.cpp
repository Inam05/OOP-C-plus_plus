/*
Create a class Player with attributes playerID, name, and team. Derive classes FootballPlayer and BasketballPlayer from Player.
Implement all four types of constructors for Player. Add a method displayInfo() to demonstrate polymorphism.
*/

#include <iostream>
using namespace std;

class Player
{
protected:
    int playerID;
    string name;
    string team;

public:
    Player() : playerID(0), name(""), team("") {}                                                         // Default constructor
    Player(int id, string n, string t) : playerID(id), name(n), team(t) {}                                // Parameterized constructor
    Player(const Player &p) : playerID(p.playerID), name(p.name), team(p.team) {}                         // Copy constructor
    Player(Player &&p) : playerID(p.playerID), name(move(p.name)), team(move(p.team)) { p.playerID = 0; } // Move constructor

    virtual void displayInfo() = 0; // Pure virtual function
};

class FootballPlayer : public Player
{
public:
    FootballPlayer() : Player() {}
    FootballPlayer(int id, string n, string t) : Player(id, n, t) {}
    FootballPlayer(const FootballPlayer &fp) : Player(fp) {}
    FootballPlayer(FootballPlayer &&fp) : Player(move(fp)) {}

    void displayInfo() override
    {
        cout << "Football Player: " << name << ", Team: " << team << endl;
    }
};

class BasketballPlayer : public Player
{
public:
    BasketballPlayer() : Player() {}
    BasketballPlayer(int id, string n, string t) : Player(id, n, t) {}
    BasketballPlayer(const BasketballPlayer &bp) : Player(bp) {}
    BasketballPlayer(BasketballPlayer &&bp) : Player(move(bp)) {}

    void displayInfo() override
    {
        cout << "Basketball Player: " << name << ", Team: " << team << endl;
    }
};

int main()
{
    FootballPlayer fp1(1, "John", "Team A");
    BasketballPlayer bp1(2, "Mike", "Team B");

    fp1.displayInfo();
    bp1.displayInfo();

    return 0;
}
