#ifndef Dec_Bin_Hex_Conversion_H_
#define Dec_Bin_Hex_Conversion_H_
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;

int bin_to_dec(string arr)
{
    int decimal = 0;

    int start = 1;

    int size = arr.length();
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] == '1')
            decimal += start;
        start = start * 2;
    }
    return decimal;
}

string dec_to_bin(int a) // decimal to binary
{
    string bin = "";
    if (a != 0)
    {
        int b = abs(a);
        int count = 0;
        int temp = b;
        while (temp - pow(2, count) >= 0)
        {
            count++;
        }
        // cout << count << endl;
        while (count > 0)
        {
            if (b - pow(2, count - 1) >= 0)
            {
                bin.append("1");
                b = b - pow(2, count - 1);
            }
            else
            {
                bin.append("0");
            }
            count--;
        }
        cout << "bin_1: " << bin << endl;
    }
    if (a == 0)
    {
        return "0";
    }

    if (a < 0)
    {
        for (int i = 0; i < bin.length(); i++)
        {
            if (bin[i] == '0')
            {
                bin[i] = '1';
            }
            else if (bin[i] == '1')
            {
                bin[i] = '0';
            }
        }
        bin.insert(0, "0");
        cout << "bin: " << bin << endl;
        int plus_one = bin_to_dec(bin) + 1;
    }

    return bin;
}

int twocomp_to_dec(string arr, int amt)
{
    int sign = 0;
    if (arr[0] == 48)
    {
        sign = 1;
    }
    else
    {
        sign = -1;
    }

    // char reverse[amt + 1];
    // char original[amt + 1];
    string reverse;
    string original;
    if (sign == -1)
    {
        for (int i = 0; i < amt; i++)
        {
            if (arr[i] == '0')
            {
                reverse[i] = '1';
            }
            else if (arr[i] == '1')
            {
                reverse[i] = '0';
            }
        }
        reverse[amt] = '\0';

        int carry = 1;
        for (int i = amt - 1; i >= 0; i--)
        {
            if (reverse[i] == '1' && carry == 1)
            {
                original[i] = '0';
            }
            else if (reverse[i] == '0' && carry == 1)
            {
                original[i] = '1';
                carry = 0;
            }
            else
            {
                original[i] = reverse[i];
            }
        }
        original[amt] = '\0';
    }
    else
    {
        // strncpy(original, arr + (0), amt);
        original = arr.substr(0, amt);
    }

    int dec = bin_to_dec(original);
    dec = dec * sign;

    return dec;
}

string dec_to_hex(int dec)
{
    stringstream convert;
    convert << hex << dec;
    string result(convert.str());
    return result;
}

int hex_to_dec(string address)
{
    int n = 0;
    int count = address.length();
    // cout << "count: " << count << endl;
    for (int i = 0; i < address.length(); i++)
    {
        // cout << address[i] << endl;
        // cout << int(address[i]) << endl;
        if (int(address[i]) > 64 && int(address[i] < 71))
        {
            int val_letter = int(address[i]) - 55;
            n = n + val_letter * pow(16, count - 1);
        }
        else if (int(address[i]) < 58 && int(address[i]) > 47)
        {

            n = n + (int(address[i]) - 48) * pow(16, count - 1);
        }
        count--;
        // cout << "count: " << count << endl;
        // cout << "N: " << n << endl;
    }

    return n;
}
#endif