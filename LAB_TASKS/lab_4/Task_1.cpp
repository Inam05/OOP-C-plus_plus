#include <iostream>
using namespace std;

class Car {
private:
    int wheels;
    int doors;
public:
    int cur_speed;
    Car (int w = 4, int d = 2)
    {
        wheels = w;
        doors = d;
        cur_speed = 0;
    }

    void speed() {
        cur_speed += 5;
    }

    void brake() {
        if (cur_speed >= 5) {
            cur_speed -= 5;
        } else {
            cur_speed = 0;
        }
    }

    int get_speed() {
        return cur_speed;
    }
};

int main() {
    Car ferrari;
    Car hino(10, 4);

    ferrari.speed();
    cout << "Current speed of Ferrari: " << ferrari.get_speed() << " km/h" << endl;

    hino.brake();
    cout << "Current speed of Hino: " << hino.get_speed() << " km/h" << endl;

    return 0;
}
