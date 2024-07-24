/*
Design a class Media with attributes title and duration. Derive classes Audio and Video from Media. Implement a virtual method play()
in the base class and override it in the derived classes to handle playing audio and video files differently.
*/

// code

#include <iostream>
using namespace std;

class Media
{
protected:
    string title;
    int duration; // duration in seconds
public:
    Media(string t, int d) : title(t), duration(d) {}
    virtual void play() = 0; // Pure virtual function
};

class Audio : public Media
{
public:
    Audio(string t, int d) : Media(t, d) {}
    void play() override
    {
        cout << "Playing Audio: " << title << " for " << duration << " seconds" << endl;
    }
};

class Video : public Media
{
public:
    Video(string t, int d) : Media(t, d) {}
    void play() override
    {
        cout << "Playing Video: " << title << " for " << duration << " seconds" << endl;
    }
};

int main()
{
    Media *m1 = new Audio("Song.mp3", 180);
    Media *m2 = new Video("Movie.mp4", 7200);
    m1->play();
    m2->play();
    delete m1;
    delete m2;
    return 0;
}
