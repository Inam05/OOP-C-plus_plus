/*
Create a class PaymentMethod with a virtual method processPayment(). Derive classes CreditCard and PayPal from PaymentMethod.
Implement processPayment() in both derived classes to process payments differently based on the payment method.
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