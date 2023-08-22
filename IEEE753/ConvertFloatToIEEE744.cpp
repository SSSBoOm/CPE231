#include "iostream"

using namespace std;

string intToBin(int integer)
{
    string abc;
    while (integer > 1)
    {
        abc += to_string(integer % 2);
        integer = integer / 2;
    }
    abc += to_string(integer);
    reverse(abc.begin(), abc.end());

    return abc;
}

string decToBin(double integer)
{
    string abc;
    while (1)
    {
        if (integer == 1.0 || integer == 0.0 || abc.size() >= 55)
        {
            break;
        }
        integer = integer * 2;
        abc += to_string(int(integer));
        if (integer > 1)
        {
            integer--;
        }
    }

    return abc;
}

int floatingPointToIEEE743(double input, string &sign, string &exponent, string &mantissa)
{
    string str11Bit = "00000000000";
    string str52Bit = "0000000000000000000000000000000000000000000000000000";
    int exp = 1023;
    sign = ((input >= 0) ? "0" : "1");
    if (input == 0)
    {
        exponent = str11Bit;
        mantissa = str52Bit;
        return 1;
    }
    input = ((sign == "0") ? input : -1 * input);
    int beforePoint = input;
    double afterPoint = input - beforePoint;

    string binary1 = intToBin(beforePoint);
    string binary2 = decToBin(afterPoint);

    string binaryAll = binary1 + binary2;
    int i = 0;
    while (1)
    {
        if (binaryAll.front() == '0')
        {
            binaryAll = binaryAll.substr(1, binaryAll.length());
            i++;
        }
        else
        {
            break;
        }
    }

    int twoPow = binary1.length() - 1 - i;

    exponent = intToBin(exp + twoPow);
    exponent = str11Bit.substr(0, 11 - exponent.length()) + exponent;

    mantissa = binaryAll.substr(1, 52);
    mantissa = mantissa + str52Bit.substr(0, 52 - mantissa.length());

    return 1;
}

int main()
{
    double input;
    cin >> input;

    string sign, exponent, mantissa;

    floatingPointToIEEE743(input, sign, exponent, mantissa);

    cout << "Sign : " << sign << endl;
    cout << "Exponent : " << exponent << endl;
    cout << "Mantissa : " << mantissa << endl;

    cout << "IEEE754 : " << endl
         << sign << " " << exponent << " " << mantissa << endl;
}