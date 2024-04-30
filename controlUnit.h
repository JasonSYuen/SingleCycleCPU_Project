#ifndef CONTROLUNIT_H // guard
#define CONTROLUNIT_H
#include <string>
#include <iostream>
using namespace std;

extern string regWrite;
extern string branch;
extern string aluSrc;
extern string memWrite;
extern string memToReg;
extern string memRead;
extern string aluOp;

void controlUnit(string opcode)
{
    string R = "0110011";
    string R2 = "0111011";
    string I = "0000011"; // lw
    string I2 = "0010011";
    string I3 = "1100111";
    string S = "0100011";
    string SB = "1100011";
    string UJ = "1101111";

    if (opcode == R || opcode == R2)
    {
        regWrite = "1";  // regWrite
        branch = "0";  // branch
        aluSrc = "0";  // ALUSRC
        memWrite = "0";  // MemWrite;
        memToReg = "0";  // MemToReg
        memRead = "0";  // MemRead
        aluOp = "10"; // ALUOP
    }
    if (opcode == I)
    {
        regWrite = "1";  // regWrite
        branch = "0";  // branch
        aluSrc = "1";  // ALUSRC
        memWrite = "0";  // MemWrite;
        memToReg = "1";  // MemToReg
        memRead = "1";  // MemRead
        aluOp = "00"; // ALUOP
    }

    if (opcode == I2)
    {
        regWrite = "1";  // regWrite
        branch = "0";  // branch
        aluSrc = "1";  // ALUSRC
        memWrite = "0";  // MemWrite;
        memToReg = "0";  // MemToReg
        memRead = "0";  // MemRead
        aluOp = "00"; // ALUOP
    }
    if (opcode == S)
    {
        regWrite = "0";  // regWrite
        branch = "0";  // branch
        aluSrc = "1";  // ALUSRC
        memWrite = "1";  // MemWrite;
        memToReg = "0";  // MemToReg
        memRead = "0";  // MemRead
        aluOp = "00"; // ALUOP
    }
    if (opcode == SB)
    {
        regWrite = "0";  // regWrite
        branch = "1";  // branch
        aluSrc = "0";  // ALUSRC
        memWrite = "0";  // MemWrite;
        memToReg = "0";  // MemToReg
        memRead = "0";  // MemRead
        aluOp = "01"; // ALUOP
    }

    if (opcode == UJ)
    {
        regWrite = "1";  // regWrite
        branch = "1";  // branch
        aluSrc = "0";  // ALUSRC
        memWrite = "0";  // MemWrite;
        memToReg = "0";  // MemToReg
        memRead = "0";  // MemRead
        aluOp = "11"; // ALUOP
    }
}

#endif