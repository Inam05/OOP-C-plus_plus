/*
Create a base class Booking with attributes bookingID and customerName. Derive classes FlightBooking and HotelBooking from Booking. 
Implement a virtual method confirmBooking() to confirm bookings for flights and hotels.
*/

#include <iostream>
using namespace std;

class Booking {
protected:
    int bookingID;
    string customerName;
public:
    Booking(int id, string cn) : bookingID(id), customerName(cn) {}
    virtual void confirmBooking() = 0; // Pure virtual function
};

class FlightBooking : public Booking {
public:
    FlightBooking(int id, string cn) : Booking(id, cn) {}
    void confirmBooking() override {
        cout << "Flight booking for " << customerName << " is confirmed." << endl;
    }
};

class HotelBooking : public Booking {
public:
    HotelBooking(int id, string cn) : Booking(id, cn) {}
    void confirmBooking() override {
        cout << "Hotel booking for " << customerName << " is confirmed." << endl;
    }
};

int main() {
    Booking* b1 = new FlightBooking(1, "Alice");
    Booking* b2 = new HotelBooking(2, "Bob");
    b1->confirmBooking();
    b2->confirmBooking();
    delete b1;
    delete b2;
    return 0;
}

