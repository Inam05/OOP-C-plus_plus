#include <iostream>
using namespace std;
class Profit
{
private:
    int value;

public:
    Profit(int value) 
    {
        this->value = value;
    }

    bool operator>(const Profit &other) const
    {
        return value > other.value;
    }

    bool operator<(const Profit &other) const
    {
        return value < other.value;
    }

    Profit operator-(int val) const
    {
        return Profit(value - val);
    }

    Profit operator+(int val) const
    {
        return Profit(value + val);
    }

    int getValue() const
    {
        return value;
    }
};

int main()
{
    Profit profit(600); 

    if (profit > Profit(500))
    {
        profit = profit - 200; 
    }
    else if (profit < Profit(500))
    {
        profit = profit + 100;
    }

    cout << "Final profit: " << profit.getValue() << endl;

    return 0;
}
