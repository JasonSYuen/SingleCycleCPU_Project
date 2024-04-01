#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int d_mem[33];

int hex_to_dec(string address)
{
    int n = 0;
    int count = address.length();
    cout << "count: " << count << endl;
    for (int i = 0; i < address.length(); i++)
    {
        cout << address[i] << endl;
        cout << int(address[i]) << endl;
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
        cout << "count: " << count << endl;
        cout << "N: " << n << endl;
    }

    return n;
}

int Mem(string address)
{
    // for testing purposes

    for (int i = 0; i < 32; i++)
    {

        d_mem[i] = i;
    }
    int place_in_array = 0;

    place_in_array = hex_to_dec(address) / 4;
    cout << place_in_array << endl;
    cout << " test " << endl;

    return d_mem[place_in_array];
}