/*
Design a class MusicTrack with attributes title, artist, and duration. Derive classes MP3Track and CDTrack from MusicTrack. Implement
all four types of constructors for MusicTrack. Add a method play() to demonstrate polymorphism.
*/

#include <iostream>
using namespace std;

class MusicTrack
{
protected:
    string title;
    string artist;
    int duration;

public:
    MusicTrack() : title(""), artist(""), duration(0) {}                                                                // Default constructor
    MusicTrack(string t, string a, int d) : title(t), artist(a), duration(d) {}                                         // Parameterized constructor
    MusicTrack(const MusicTrack &m) : title(m.title), artist(m.artist), duration(m.duration) {}                         // Copy constructor
    MusicTrack(MusicTrack &&m) : title(move(m.title)), artist(move(m.artist)), duration(m.duration) { m.duration = 0; } // Move constructor

    virtual void play() = 0; // Pure virtual function
};

class MP3Track : public MusicTrack
{
public:
    MP3Track() : MusicTrack() {}
    MP3Track(string t, string a, int d) : MusicTrack(t, a, d) {}
    MP3Track(const MP3Track &m) : MusicTrack(m) {}
    MP3Track(MP3Track &&m) : MusicTrack(move(m)) {}

    void play() override
    {
        cout << "Playing MP3 track: " << title << " by " << artist << endl;
    }
};

class CDTrack : public MusicTrack
{
public:
    CDTrack() : MusicTrack() {}
    CDTrack(string t, string a, int d) : MusicTrack(t, a, d) {}
    CDTrack(const CDTrack &m) : MusicTrack(m) {}
    CDTrack(CDTrack &&m) : MusicTrack(move(m)) {}

    void play() override
    {
        cout << "Playing CD track: " << title << " by " << artist << endl;
    }
};

int main()
{
    MP3Track mp3("Song A", "Artist A", 300);
    CDTrack cd("Song B", "Artist B", 350);

    mp3.play();
    cd.play();

    return 0;
}
