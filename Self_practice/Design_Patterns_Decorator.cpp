/*
Create a Coffee class with a base Coffee type. Use the Decorator pattern to add different ingredients
like Milk, Sugar, and WhippedCream to the coffee. Demonstrate the usage with various combinations.
*/

#include <iostream>
#include <string>
using namespace std;

// Component
class Coffee
{
public:
    virtual ~Coffee() {}
    virtual string getDescription() const
    {
        return "Coffee";
    }
    virtual double cost() const
    {
        return 5.0; // Base cost of coffee
    }
};

// Decorator
class CoffeeDecorator : public Coffee
{
protected:
    Coffee *coffee;

public:
    CoffeeDecorator(Coffee *c) : coffee(c) {}
    virtual ~CoffeeDecorator()
    {
        delete coffee;
    }
};

// Concrete Decorators
class MilkDecorator : public CoffeeDecorator
{
public:
    MilkDecorator(Coffee *c) : CoffeeDecorator(c) {}

    string getDescription() const override
    {
        return coffee->getDescription() + ", Milk";
    }

    double cost() const override
    {
        return coffee->cost() + 1.5; // Adding cost for milk
    }
};

class SugarDecorator : public CoffeeDecorator
{
public:
    SugarDecorator(Coffee *c) : CoffeeDecorator(c) {}

    string getDescription() const override
    {
        return coffee->getDescription() + ", Sugar";
    }

    double cost() const override
    {
        return coffee->cost() + 0.5; // Adding cost for sugar
    }
};

// Main function to demonstrate the Decorator Pattern
int main()
{
    Coffee *myCoffee = new Coffee();
    cout << "Description: " << myCoffee->getDescription() << endl;
    cout << "Cost: $" << myCoffee->cost() << endl;

    Coffee *myMilkCoffee = new MilkDecorator(myCoffee);
    cout << "Description: " << myMilkCoffee->getDescription() << endl;
    cout << "Cost: $" << myMilkCoffee->cost() << endl;

    Coffee *mySugarMilkCoffee = new SugarDecorator(myMilkCoffee);
    cout << "Description: " << mySugarMilkCoffee->getDescription() << endl;
    cout << "Cost: $" << mySugarMilkCoffee->cost() << endl;

    delete mySugarMilkCoffee; // Deletes all the dynamically allocated objects

    return 0;
}
