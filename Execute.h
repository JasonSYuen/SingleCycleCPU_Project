#ifndef Execute_H_
#define Execute_H_
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "dec_bin_hex_conversion.h"
using namespace std;

extern string aluZero;
extern int immediate;
extern bool branchbecauseiwantto;

string Execute(string alu_ctrl, int data_1, int data_2)
{
    // first part done still need to do Zero ouput and Branch target address
    // cout << alu_ctrl << " " << data_1 << " " << data_2 << endl;
    string to_return;
    if (alu_ctrl == "0010") // add
    {

        int sum = data_1 + data_2; // addition

        // cout << "add " << bin_to_dec(data_1) << " " << bin_to_dec(data_2) << endl;
        // cout << "sum: " << (sum) << endl;
        to_return = dec_to_bin(sum);
    }
    else if (alu_ctrl == "0110") // sub
    {
        int sum = data_1 - data_2; // sum
        // cout << "sub: " << bin_to_dec(data_1) << " " << bin_to_dec(data_2) << endl;
        to_return = dec_to_bin(sum);
    }
    else if (alu_ctrl == "0000") // and
    {
        cout << data_1 << " " << data_2 << endl;
        string data_1_bin = dec_to_bin(data_1);
        string data_2_bin = dec_to_bin(data_2);

        while (data_1_bin.length() < data_2_bin.length()) // while loops to make strings equal size
        {
            data_1_bin.insert(0, "0");
        }
        while (data_1_bin.length() > data_2_bin.length())
        {
            data_2_bin.insert(0, "0");
        }

        for (int i = 0; i < data_1_bin.length(); i++) // and operation
        {
            if (data_1_bin[i] == '1' && data_2_bin[i] == '1')
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
        string data_1_bin = dec_to_bin(data_1);
        string data_2_bin = dec_to_bin(data_2);
        while (data_1_bin.length() < data_2_bin.length()) // while loops to make strings equal size
        {
            data_1_bin.insert(0, "0");
        }
        while (data_1_bin.length() > data_2_bin.length())
        {
            data_2_bin.insert(0, "0");
        }

        for (int i = 0; i < data_1_bin.length(); i++) // or operation
        {
            if (data_1_bin[i] == '1' || data_2_bin[i] == '1')
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

    // Reset ALUzero
    //|| branchbecauseiwantto == true
    if (bin_to_dec(to_return) == 0)
    {
        aluZero = "1";
        cout << "immediate " << immediate << endl;
        branchTarget = immediate * 4;

        cout << "branchTarget " << branchTarget << endl;
    }
    else
    {
        aluZero = "0";
    }
    return to_return;
}

#endif