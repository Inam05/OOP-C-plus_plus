#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
    char name[20];
    char direction;
    double positionX;
    double positionY;

public:
    Car(const char *carName, char initialDirection, double initialX, double initialY)
        : direction(initialDirection), positionX(initialX), positionY(initialY)
    {
        int i;
        for (i = 0; i < 19 && carName[i] != '\0'; ++i)
        {
            name[i] = carName[i];
        }
        name[i] = '\0';
    }

    void Turn()
    {
        switch (direction)
        {
        case 'E':
            direction = 'S';
            break;
        case 'S':
            direction = 'W';
            break;
        case 'W':
            direction = 'N';
            break;
        case 'N':
            direction = 'E';
            break;
        }
    }

    void Turn(char newDirection)
    {
        direction = newDirection;
    }

    void Move(double distance)
    {
        switch (direction)
        {
        case 'E':
            positionX += distance;
            break;
        case 'W':
            positionX -= distance;
            break;
        case 'N':
            positionY += distance;
            break;
        case 'S':
            positionY -= distance;
            break;
        }
    }

    double GetX() const
    {
        return positionX;
    }
    double GetY() const
    {
        return positionY;
    }
};

int main()
{
    Car mycar("MyCar", 'E', 0.0, 0.0);
    mycar.Turn();
    mycar.Move(5.0);
    cout << "Car position: (" << mycar.GetX() << ", " << mycar.GetY() << ")" << endl;
    return 0;
}
