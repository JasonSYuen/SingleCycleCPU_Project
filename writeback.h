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

void writeback(string comp, int mem, int dest)
{

    if (regWrite == "1")
    {
        if (memToReg == "1")
        {
            rf[dest] = mem;
            cout << "x" << dest << " is modified to 0x" << dec_to_hex(mem) << endl;
        }
        else
        {
            rf[dest] = bin_to_dec(comp);
            cout << "x" << dest << " is modified to 0x" << dec_to_hex(bin_to_dec(comp)) << endl;
        }
        if (branch == "1")
        {
            rf[dest] = pc + 4;
        }

        // cout << "In rf[" << dest << "]: " << rf[dest] << endl;
    }

    total_clock_cycles++;
}

#endif