/*
Design a class Artwork with attributes title, artist, and year. Derive classes Painting and Sculpture from Artwork. Implement all four
types of constructors for Artwork. Add a method display() to demonstrate polymorphism.
*/

#include <iostream>
using namespace std;

class Artwork
{
protected:
    string title;
    string artist;
    int year;

public:
    Artwork() : title(""), artist(""), year(0) {}                                                     // Default constructor
    Artwork(string t, string a, int y) : title(t), artist(a), year(y) {}                              // Parameterized constructor
    Artwork(const Artwork &a) : title(a.title), artist(a.artist), year(a.year) {}                     // Copy constructor
    Artwork(Artwork &&a) : title(move(a.title)), artist(move(a.artist)), year(a.year) { a.year = 0; } // Move constructor

    virtual void display() = 0; // Pure virtual function
};

class Painting : public Artwork
{
public:
    Painting() : Artwork() {}
    Painting(string t, string a, int y) : Artwork(t, a, y) {}
    Painting(const Painting &p) : Artwork(p) {}
    Painting(Painting &&p) : Artwork(move(p)) {}

    void display() override
    {
        cout << "Painting: " << title << " by " << artist << " (" << year << ")" << endl;
    }
};

class Sculpture : public Artwork
{
public:
    Sculpture() : Artwork() {}
    Sculpture(string t, string a, int y) : Artwork(t, a, y) {}
    Sculpture(const Sculpture &s) : Artwork(s) {}
    Sculpture(Sculpture &&s) : Artwork(move(s)) {}

    void display() override
    {
        cout << "Sculpture: " << title << " by " << artist << " (" << year << ")" << endl;
    }
};

int main()
{
    Painting p1("Starry Night", "Van Gogh", 1889);
    Sculpture s1("David", "Michelangelo", 1504);

    p1.display();
    s1.display();

    return 0;
}
