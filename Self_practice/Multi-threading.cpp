/*
Implement a ThreadSafeQueue class that allows multiple threads to safely add and remove elements.
Use mutexes and condition variables to ensure thread safety.
*/

#include <iostream>
#include <thread>
using namespace std;

void printMessage(const string &message, int count)
{
    for (int i = 0; i < count; ++i)
    {
        cout << message << endl;
    }
}

int main()
{
    thread t1(printMessage, "Hello from thread 1", 5);
    thread t2(printMessage, "Hello from thread 2", 5);

    t1.join();
    t2.join();

    return 0;
}
