/*
Implement a Counter class with a static member variable to keep track of the number of Counter objects created.
Provide static member functions to access and manipulate this count.
*/

#include <iostream>
using namespace std;

class Counter
{
private:
    static int count;

public:
    Counter()
    {
        ++count;
    }

    static int getCount()
    {
        return count;
    }
};

int Counter::count = 0;

int main()
{
    Counter c1;
    Counter c2;
    Counter c3;

    cout << "Number of Counter objects: " << Counter::getCount() << endl;

    return 0;
}
