#include <iostream>
using namespace std;

class MathOperations
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    int add(int a, int b, int c)
    {
        return a + b + c;
    }

    double add(double a, double b)
    {
        return a + b;
    }

    double add(double a, double b, double c)
    {
        return a + b + c;
    }

    int subtract(int a, int b)
    {
        return a - b;
    }

    double subtract(double a, double b)
    {
        return a - b;
    }

    int multiply(int a, int b)
    {
        return a * b;
    }

    double multiply(double a, double b)
    {
        return a * b;
    }

    int divide(int a, int b)
    {
        if (b == 0)
        {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return a / b;
    }

    double divide(double a, double b)
    {
        if (b == 0.0)
        {
            cout << "Error: Division by zero!" << endl;
            return 0.0;
        }
        return a / b;
    }
};

class IntegerAddThree : public MathOperations
{
public:
    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};

class DoubleAddThree : public MathOperations
{
public:
    double add(double a, double b, double c)
    {
        return a + b + c;
    }
};

int main()
{
    MathOperations baseOp;
    cout << "Base Integer addition of 2 parameters: " << baseOp.add(4, 5) << endl;
    cout << "Base Double addition of 2 parameters: " << baseOp.add(1.5, 2.5) << endl;

    IntegerAddThree intAddThree;
    cout << "Derived Integer addition of 3 parameters: " << intAddThree.add(1, 2, 3) << endl;

    DoubleAddThree doubleAddThree;
    cout << "Derived Double addition of 3 parameters: " << doubleAddThree.add(1.1, 2.2, 3.3) << endl;

    cout << "Base Integer division: " << baseOp.divide(10, 2) << endl;
    cout << "Base Integer division by zero: " << baseOp.divide(10, 0) << endl;

    return 0;
}
