#ifndef Mem_H_
#define Mem_H_
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
    d_mem[28] = 5;
    d_mem[29] = 16;
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
#endif