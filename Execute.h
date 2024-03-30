#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int bin_to_dec(string a) // binary to decimal
{
    int sum = 0;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        if (a[i] == '1')
        {
            sum += pow(2, i - 1);
        }
    }
    return sum;
}

string dec_to_bin(int a) // decimal to binary
{
    string bin = "";
    int count = 0;
    int temp = a;
    while (temp - pow(2, count) > 0)
    {
        count++;
    }
    cout << count << endl;
    while (a >= 0)
    {
        if (a - pow(2, count) >= 0)
        {
            bin.append("1");
            a = a - pow(2, count);
        }
        else
        {
            bin.append("0");
            if (a == 0)
            {
                break;
            }
        }
        count--;
    }
    return bin;
}

string Execute(string alu_ctrl, string data_1, string data_2)
{
    // first part done still need to do Zero ouput and Branch target address
    string to_return;
    if (alu_ctrl == "0010") // add
    {

        int sum = bin_to_dec(data_1) + bin_to_dec(data_2); // addition
        to_return = dec_to_bin(sum);
    }
    else if (alu_ctrl == "0110") // sub
    {
        int sum = bin_to_dec(data_1) - bin_to_dec(data_2); // sum
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

    cout << to_return << endl;
    return to_return;
}
