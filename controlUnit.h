#ifndef DECODE_H // guard
#define DECODE_H
#include <string>
#include <iostream>
#include "dec_bin_hex_conversion.h"
using namespace std;

string *controlUnit(string opcode)
{
    string *controlSignals = new string[7];
    // regWrite, Branch, ALUSRC, MemWrite, MemtoReg, MemRead, ALUOP

    string R = "0110011";
    string R2 = "0111011";
    string I = "0000011";
    string I2 = "0010011";
    string I3 = "1100111";
    string S = "0100011";
    string SB = "1100011";
    string UJ = "1101111";

    if (opcode == R || opcode == R2)
    {
    }
    if (opcode == I || opcode == I2)
    {
    }
    if (opcode == S)
    {
    }

    if (opcode == SB)
    {
    }

    if (opcode == UJ)
    {
    }
}

#endif