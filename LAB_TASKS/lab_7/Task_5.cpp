#include <iostream>
#include <string>
using namespace std;
class Car
{
private:
    string model;

public:
    Car(string model)
    {
        this->model = model;
    }
    string getModel() const
    {
        return model;
    }
};
int main()
{
    Car car("Honda Civic RS_Turbo");
    cout << "The model of the car is: " << car.getModel() << endl;
    return 0;
}