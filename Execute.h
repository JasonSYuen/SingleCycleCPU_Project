#ifndef Execute_H_
#define Execute_H_
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "dec_bin_hex_conversion.h"
using namespace std;

string Execute(string alu_ctrl, string data_1, string data_2)
{
    // first part done still need to do Zero ouput and Branch target address
    // cout << alu_ctrl << " " << data_1 << " " << data_2 << endl;
    string to_return;
    if (alu_ctrl == "0010") // add
    {

        int sum = bin_to_dec(data_1) + bin_to_dec(data_2); // addition

        cout << "add" << bin_to_dec(data_1) << " " << bin_to_dec(data_2) << endl;
        cout << (sum) << endl;
        to_return = dec_to_bin(sum);
    }
    else if (alu_ctrl == "0110") // sub
    {
        int sum = bin_to_dec(data_1) - bin_to_dec(data_2); // sum
        cout << "sub" << bin_to_dec(data_1) << " " << bin_to_dec(data_2) << endl;
        to_return = dec_to_bin(sum);
    }
    else if (alu_ctrl == "0000") // and
    {
        while (data_1.length() < data_2.length()) // while loops to make strings equal size
        {
            data_1.insert(0, "0");
        }
        while (data_1.length() > data_2.length())
        {
            data_2.insert(0, "0");
        }

        for (int i = 0; i < data_1.length(); i++) // and operation
        {
            if (data_1[i] == '1' && data_2[i] == '1')
            {
                to_return.append("1");
            }
            else
            {
                to_return.append("0");
            }
        }
    }
    else if (alu_ctrl == "0001") // or
    {
        while (data_1.length() < data_2.length()) // while loops to make strings equal size
        {
            data_1.insert(0, "0");
        }
        while (data_1.length() > data_2.length())
        {
            data_2.insert(0, "0");
        }

        for (int i = 0; i < data_1.length(); i++) // or operation
        {
            if (data_1[i] == '1' || data_2[i] == '1')
            {
                to_return.append("1");
            }
            else
            {
                to_return.append("0");
            }
        }
    }

    // cout << to_return << endl;
    return to_return;
}

#endif