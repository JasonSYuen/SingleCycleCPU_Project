#ifndef WRITEBACK_H // guard
#define WRITEBACK_H
#include <string>
#include "decode.h"

using namespace std;

extern int rf[32];
extern int total_clock_cycles;

extern string regWrite;
extern string branch;
extern string aluSrc;
extern string memWrite;
extern string memToReg;
extern string memRead;
extern string aluOp;
extern string rd;

string registerNameDuckery(int dest)
{
    if (dest == 0)
    {
        return "zero";
    }
    if (dest == 1)
    {
        return "ra";
    }
    if (dest == 2)
    {
        return "sp";
    }
    if (dest == 3)
    {
        return "gp";
    }
    if (dest == 4)
    {
        return "tp";
    }
    if (dest > 4 && dest < 8)
    {
        return "t" + to_string(dest - 5);
    }
    if (dest == 8)
    {
        return "s0";
    }
    if (dest == 9)
    {
        return "s1";
    }
    // if (dest == 10 || dest == 11){
    //     return "a" + to_string(dest-10);
    // }
    if (dest > 9 && dest < 18)
    {
        return "a" + to_string(dest - 10);
    }
    if (dest > 17 && dest < 28)
    {
        return "s" + to_string(dest - 16);
    }
    if (dest > 27)
    {
        return "t" + to_string(dest - 25);
    }
    return "oops";
}

void writeback(string comp, int mem, int dest)
{

    if (regWrite == "1")
    {
        if (memToReg == "1")
        {
            rf[dest] = mem;
            cout << registerNameDuckery(dest) << " is modified to 0x" << dec_to_hex(mem) << endl;
        }
        else if (branch == "1")
        {
            rf[dest] = pc;
            cout << registerNameDuckery(dest) << " is modified to 0x" << dec_to_hex(pc) << endl;
        }

        else
        {
            rf[dest] = bin_to_dec(comp);
            cout << registerNameDuckery(dest) << " is modified to 0x" << dec_to_hex(bin_to_dec(comp)) << endl;
        }

        // cout << "In rf[" << dest << "]: " << rf[dest] << endl;
    }

    total_clock_cycles++;
}

#endif