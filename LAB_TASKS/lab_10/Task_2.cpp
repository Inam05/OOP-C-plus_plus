#include <iostream>
#include <string>

using namespace std;

class BaseConverter
{
public:
    virtual string toBase(int number) = 0;
    virtual int fromBase(const string &number) = 0;
};

class BinaryConverter : public BaseConverter
{
public:
    string toBase(int number) override
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

    int fromBase(const string &number) override
    {
        int result = 0;
        for (char c : number)
        {
            result = result * 2 + (c - '0');
        }
        return result;
    }
};

class OctalConverter : public BaseConverter
{
public:
    string toBase(int number) override
    {
        string result = "";
        do
        {
            result = (char)((number % 8) + '0') + result;
            number /= 8;
        } while (number > 0);
        return result;
    }

    int fromBase(const string &number) override
    {
        int result = 0;
        for (char c : number)
        {
            result = result * 8 + (c - '0');
        }
        return result;
    }
};

class HexadecimalConverter : public BaseConverter
{
public:
    string toBase(int number) override
    {
        string result = "";
        const char *hexChars = "0123456789ABCDEF";
        do
        {
            result = hexChars[number % 16] + result;
            number /= 16;
        } 
        while (number > 0);
        return result;
    }

    int fromBase(const string &number) override
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

class NumberConverter
{
private:
    BinaryConverter binaryConverter;
    OctalConverter octalConverter;
    HexadecimalConverter hexadecimalConverter;
public:
    string convert(int number, const string &toBase)
    {
        if (toBase == "Binary")
        {
            return binaryConverter.toBase(number);
        }
        else if (toBase == "Octal")
        {
            return octalConverter.toBase(number);
        }
        else if (toBase == "Hexadecimal")
        {
            return hexadecimalConverter.toBase(number);
        }
        return to_string(number);
    }

    int convert(const string &number, const string &fromBase)
    {
        if (fromBase == "Binary")
        {
            return binaryConverter.fromBase(number);
        }
        else if (fromBase == "Octal")
        {
            return octalConverter.fromBase(number);
        }
        else if (fromBase == "Hexadecimal")
        {
            return hexadecimalConverter.fromBase(number);
        }
        return stoi(number);
    }


};

int main()
{
    NumberConverter converter;

    int decimalNumber = 255;
    string binaryNumber = "11111111";
    string octalNumber = "377";
    string hexNumber = "FF";
    cout << "Decimal to base systems" << endl;
    cout << "Decimal to Binary: " << converter.convert(decimalNumber, "Binary") << endl;
    cout << "Decimal to Octal: " << converter.convert(decimalNumber, "Octal") << endl;
    cout << "Decimal to Hexadecimal: " << converter.convert(decimalNumber, "Hexadecimal") << endl;
    cout << "Base to Decimal System" << endl;
    cout << "Binary to Decimal: " << converter.convert(binaryNumber, "Binary") << endl;
    cout << "Octal to Decimal: " << converter.convert(octalNumber, "Octal") << endl;
    cout << "Hexadecimal to Decimal: " << converter.convert(hexNumber, "Hexadecimal") << endl;

    return 0;
}
