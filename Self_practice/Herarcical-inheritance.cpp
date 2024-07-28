#include <iostream>
#include <string>

using namespace std;

// Base class
class Player
{
protected:
    string name;
    int playerID;
    int matchesPlayed;

public:
    Player(string n, int id, int matches) : name(n), playerID(id), matchesPlayed(matches) {}

    virtual void displayPlayerStats() const
    {
        cout << "Player Name: " << name << endl;
        cout << "Player ID: " << playerID << endl;
        cout << "Matches Played: " << matchesPlayed << endl;
    }
};

// Derived class for Batsman
class Batsman : virtual public Player
{
private:
    double battingAverage;
    int runsScored;

public:
    Batsman(string n, int id, int matches, double avg, int runs)
        : Player(n, id, matches), battingAverage(avg), runsScored(runs) {}

    void scoreRuns(int runs)
    {
        runsScored += runs;
    }

    void displayPlayerStats() const override
    {
        Player::displayPlayerStats();
        cout << "Batting Average: " << battingAverage << endl;
        cout << "Runs Scored: " << runsScored << endl;
    }
};

// Derived class for Bowler
class Bowler : virtual public Player
{
private:
    double bowlingStrikeRate;
    int wicketsTaken;

public:
    Bowler(string n, int id, int matches, double strikeRate, int wickets)
        : Player(n, id, matches), bowlingStrikeRate(strikeRate), wicketsTaken(wickets) {}

    void takeWickets(int wickets)
    {
        wicketsTaken += wickets;
    }

    void displayPlayerStats() const override
    {
        Player::displayPlayerStats();
        cout << "Bowling Strike Rate: " << bowlingStrikeRate << endl;
        cout << "Wickets Taken: " << wicketsTaken << endl;
    }
};

// Derived class for AllRounder
class AllRounder : public Batsman, public Bowler
{
public:
    AllRounder(string n, int id, int matches, double batAvg, int runs, double bowlSR, int wickets)
        : Player(n, id, matches), Batsman(n, id, matches, batAvg, runs), Bowler(n, id, matches, bowlSR, wickets) {}

    void displayPlayerStats() const override
    {
        Batsman::displayPlayerStats();
        Bowler::displayPlayerStats();
    }
};

int main()
{
    Batsman batsman("Virat Kohli", 18, 250, 50.0, 12000);
    Bowler bowler("Jasprit Bumrah", 93, 100, 18.0, 150);
    AllRounder allRounder("Ben Stokes", 55, 120, 40.0, 5000, 20.0, 200);

    cout << "Batsman Stats:" << endl;
    batsman.displayPlayerStats();
    cout << endl;

    cout << "Bowler Stats:" << endl;
    bowler.displayPlayerStats();
    cout << endl;

    cout << "AllRounder Stats:" << endl;
    allRounder.displayPlayerStats();
    cout << endl;

    return 0;
}
