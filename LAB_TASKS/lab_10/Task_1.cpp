#include <iostream>
#include <string>
using namespace std;

class NumberConverter
{
public:
    string convert(int number, const string &toBase)
    {
        if (toBase == "Binary")
        {
            return toBinary(number);
        }
        else if (toBase == "Octal")
        {
            return toOctal(number);
        }
        else if (toBase == "Hexadecimal")
        {
            return toHexadecimal(number);
        }
        return to_string(number); 
    }

    int convert(const string &number, const string &fromBase)
    {
        if (fromBase == "Binary")
        {
            return fromBinary(number);
        }
        else if (fromBase == "Octal")
        {
            return fromOctal(number);
        }
        else if (fromBase == "Hexadecimal")
        {
            return fromHexadecimal(number);
        }
        return stoi(number); 
    }

private:
    string toBinary(int number)
    {
        string result = "";
        do
        {
            result = (char)((number % 2) + '0') + result;
            number /= 2;
        } 
        while (number > 0);
        return result;
    }

    string toOctal(int number)
    {
        string result = "";
        do
        {
            result = (char)((number % 8) + '0') + result;
            number /= 8;
        } while (number > 0);
        return result;
    }

    string toHexadecimal(int number)
    {
        string result = "";
        const char *hexChars = "0123456789ABCDEF";
        do
        {
            result = hexChars[number % 16] + result;
            number /= 16;
        } while (number > 0);
        return result;
    }

    int fromBinary(const string &number)
    {
        int result = 0;
        for (char c : number)
        {
            result = result * 2 + (c - '0');
        }
        return result;
    }

    int fromOctal(const string &number)
    {
        int result = 0;
        for (char c : number)
        {
            result = result * 8 + (c - '0');
        }
        return result;
    }

    int fromHexadecimal(const string &number)
    {
        int result = 0;
        for (char c : number)
        {
            if (c >= '0' && c <= '9')
            {
                result = result * 16 + (c - '0');
            }
            else if (c >= 'A' && c <= 'F')
            {
                result = result * 16 + (c - 'A' + 10);
            }
            else if (c >= 'a' && c <= 'f')
            {
                result = result * 16 + (c - 'a' + 10);
            }
        }
        return result;
    }
};

int main()
{
    NumberConverter converter;

    int decimalNumber = 255;
    string binaryNumber = "11111111";
    string octalNumber = "377";
    string hexNumber = "FF";

    cout << "Decimal to Binary: " << converter.convert(decimalNumber, "Binary") << endl;
    cout << "Decimal to Octal: " << converter.convert(decimalNumber, "Octal") << endl;
    cout << "Decimal to Hexadecimal: " << converter.convert(decimalNumber, "Hexadecimal") << endl;

    cout << "Binary to Decimal: " << converter.convert(binaryNumber, "Binary") << endl;
    cout << "Octal to Decimal: " << converter.convert(octalNumber, "Octal") << endl;
    cout << "Hexadecimal to Decimal: " << converter.convert(hexNumber, "Hexadecimal") << endl;

    return 0;
}
