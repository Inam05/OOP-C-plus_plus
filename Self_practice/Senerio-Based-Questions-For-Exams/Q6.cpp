/*
Design a class Media with attributes title and duration. Derive classes Audio and Video from Media. Implement a virtual method play()
in the base class and override it in the derived classes to handle playing audio and video files differently.
*/

// code

#include <iostream>
using namespace std;

class PaymentMethod
{
public:
    virtual void processPayment() = 0; // Pure virtual function
};

class CreditCard : public PaymentMethod
{
public:
    void processPayment() override
    {
        cout << "Processing Credit Card Payment" << endl;
    }
};

class PayPal : public PaymentMethod
{
public:
    void processPayment() override
    {
        cout << "Processing PayPal Payment" << endl;
    }
};

int main()
{
    PaymentMethod *pm1 = new CreditCard();
    PaymentMethod *pm2 = new PayPal();
    pm1->processPayment();
    pm2->processPayment();
    delete pm1;
    delete pm2;
    return 0;
}
