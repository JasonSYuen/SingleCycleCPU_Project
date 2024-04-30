#ifndef Mem_H_
#define Mem_H_
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "dec_bin_hex_conversion.h"
using namespace std;

int d_mem[33];

extern string memWrite;
extern string memToReg;
extern string memRead;

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
        d_mem[place_in_array] = (bin_to_dec(to_store));
        //cout << " in d-mem [" << place_in_array << "]" << d_mem[place_in_array] << endl;
    }

    return d_mem[place_in_array];
}

int Mem2(string address, int to_store)
{
    // for testing purposes
    // cout << "////" << endl;
    d_mem[28] = 5;
    d_mem[29] = 16;
    int place_in_array = 0;

    place_in_array = hex_to_dec(address) / 4;
    // << place_in_array << endl;
    // cout << " test " << endl;

    if (memWrite == "1")
    {
        d_mem[place_in_array] = (to_store);
        cout << "memory 0x" << address << " is modified to 0x" << dec_to_hex(to_store) << endl;
        //cout << " in d-mem [" << place_in_array << "]" << d_mem[place_in_array] << endl;
    }

    return d_mem[place_in_array];
}
#endif