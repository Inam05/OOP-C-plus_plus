/*
Design a class SmartDevice with attributes deviceID and status. Derive classes SmartLight and SmartThermostat from SmartDevice. 
Implement a virtual method operate() to handle the operation of lights and thermostats.
*/

#include <iostream>
using namespace std;

class SmartDevice {
protected:
    int deviceID;
    string status;
public:
    SmartDevice(int id, string s) : deviceID(id), status(s) {}
    virtual void operate() = 0; // Pure virtual function
};

class SmartLight : public SmartDevice {
public:
    SmartLight(int id, string s) : SmartDevice(id, s) {}
    void operate() override {
        cout << "Smart Light " << deviceID << " is " << status << "." << endl;
    }
};

class SmartThermostat : public SmartDevice {
public:
    SmartThermostat(int id, string s) : SmartDevice(id, s) {}
    void operate() override {
        cout << "Smart Thermostat " << deviceID << " is " << status << "." << endl;
    }
};

int main() {
    SmartDevice* sd1 = new SmartLight(1, "ON");
    SmartDevice* sd2 = new SmartThermostat(2, "OFF");
    sd1->operate();
    sd2->operate();
    delete sd1;
    delete sd2;
    return 0;
}

