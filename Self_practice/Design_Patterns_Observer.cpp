/*
Implement the Observer design pattern for a WeatherStation class that notifies multiple Display classes
about weather changes. Ensure proper observer registration and notification.

*/

#include <iostream>
#include <list>
using namespace std;

class Observer
{
public:
    virtual void update(float temperature) = 0;
    virtual ~Observer() {}
};

class Display : public Observer
{
private:
    string name;

public:
    Display(const string &n) : name(n) {}
    void update(float temperature) override
    {
        cout << name << " Display: Temperature updated to " << temperature << " degrees." << endl;
    }
};

class WeatherStation
{
private:
    list<Observer *> observers;
    float temperature;

public:
    void addObserver(Observer *observer)
    {
        observers.push_back(observer);
    }

    void removeObserver(Observer *observer)
    {
        observers.remove(observer);
    }

    void notifyObservers()
    {
        for (Observer *observer : observers)
        {
            observer->update(temperature);
        }
    }

    void setTemperature(float temp)
    {
        temperature = temp;
        notifyObservers();
    }
};

int main()
{
    WeatherStation station;

    Display display1("Living Room");
    Display display2("Bedroom");

    station.addObserver(&display1);
    station.addObserver(&display2);

    station.setTemperature(25.5);
    station.setTemperature(30.0);

    station.removeObserver(&display1);
    station.setTemperature(28.0);

    return 0;
}
