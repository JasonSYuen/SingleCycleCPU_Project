#ifndef WRITEBACK_H // guard
#define WRITEBACK_H
#include <string>
#include "decode.h"

using namespace std;

extern int rf[32];
extern int total_clock_cycles;

void writeback(string comp, int mem, string dest, string type)
{
    if (type == "")
    {
        rf[bin_to_dec(dest)] = bin_to_dec(comp);
    }
    if (type == "lw")
    {
        rf[bin_to_dec(dest)] = mem;
    }

    total_clock_cycles++;
}

#endif