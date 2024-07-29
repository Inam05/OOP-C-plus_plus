#include <iostream>
using namespace std;
class Complex
{
private:
    int real;
    int imag;

public:
    void Read()
    {
        cout << "Enter real and imaginary number respectively:" << endl;
        cin >> real >> imag;
    }
    void Add(Complex comp1, Complex comp2)
    {
        cout << "Checking" << endl;
        real = comp1.real + comp2.real;
        imag = comp1.imag + comp2.imag;
    }
    void Display()
    {
        cout << "Sum=" << real << "+" << imag << "i";
    }
};

int main()
{
    Complex cl, c2, c3, c4;
    cl.Read();
    c2.Read();
    c3.Add(cl, c2);
    c3.Display();
    return 0;
}
