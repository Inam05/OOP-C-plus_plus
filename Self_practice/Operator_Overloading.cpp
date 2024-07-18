/*
Overload the +, -, *, and / operators for a custom ComplexNumber class. Ensure proper handling of
complex number arithmetic.
*/

#include <iostream>
using namespace std;

class ComplexNumber
{
private:
    double real;
    double imag;

public:
    ComplexNumber(double r = 0, double i = 0) : real(r), imag(i) {}

    ComplexNumber operator+(const ComplexNumber &other) const
    {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    ComplexNumber operator-(const ComplexNumber &other) const
    {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    ComplexNumber operator*(const ComplexNumber &other) const
    {
        return ComplexNumber(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    ComplexNumber operator/(const ComplexNumber &other) const
    {
        double denom = other.real * other.real + other.imag * other.imag;
        return ComplexNumber((real * other.real + imag * other.imag) / denom, (imag * other.real - real * other.imag) / denom);
    }

    friend ostream &operator<<(ostream &os, const ComplexNumber &cn);
};

ostream &operator<<(ostream &os, const ComplexNumber &cn)
{
    os << cn.real << " + " << cn.imag << "i";
    return os;
}

int main()
{
    ComplexNumber c1(3, 4);
    ComplexNumber c2(1, 2);

    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c1 - c2 = " << c1 - c2 << endl;
    cout << "c1 * c2 = " << c1 * c2 << endl;
    cout << "c1 / c2 = " << c1 / c2 << endl;

    return 0;
}
