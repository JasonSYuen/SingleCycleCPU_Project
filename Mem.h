#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "dec_bin_hex_conversion.h"
using namespace std;

int d_mem[33];

int Mem(string address, string lw_sw, string to_store)
{
    // for testing purposes
    // cout << "////" << endl;
    for (int i = 0; i < 32; i++)
    {

        d_mem[i] = i;
    }
    int place_in_array = 0;

    place_in_array = hex_to_dec(address) / 4;
    // << place_in_array << endl;
    // cout << " test " << endl;

    if (lw_sw == "sw")
    {
        d_mem[place_in_array] = stoi(to_store);
        // cout << d_mem[place_in_array] << endl;
    }

    return d_mem[place_in_array];
}

string dec_to_bin(int a) // decimal to binary
{
    string bin = "";
    if (a > 0)
    {
        int count = 0;
        int temp = a;
        while (temp - pow(2, count) >= 0)
        {
            count++;
        }
        // cout << count << endl;
        while (count > 0)
        {
            if (a - pow(2, count - 1) >= 0)
            {
                bin.append("1");
                a = a - pow(2, count - 1);
            }
            else
            {
                bin.append("0");
            }
            count--;
        }
        cout << bin << endl;
    }
    return bin;
}