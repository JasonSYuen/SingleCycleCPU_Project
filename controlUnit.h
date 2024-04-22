#ifndef controlUnit // guard
#define controlUnit
#include <iostream>
#include <string>

using namespace std;

extern std::string regWrite;
extern std::string branch;
extern std::string aluSrc;
extern std::string memWrite;
extern std::string memToReg;
extern std::string memRead;
extern std::string aluOp;

void controlUnit(string opcode)
{
    std::string R = "0110011";
    std::string R2 = "0111011";
    std::string I = "0000011"; // lw
    std::string I2 = "0010011";
    std::string I3 = "1100111";
    std::string S = "0100011";
    std::string SB = "1100011";
    std::string UJ = "1101111";

    if (opcode == R || opcode == R2)
    {
        regWrite = "1"; // regWrite
        branch = "0";   // branch
        aluSrc = "0";   // ALUSRC
        memWrite = "0"; // MemWrite;
        memToReg = "0"; // MemToReg
        memRead = "0";  // MemRead
        aluOp = "10";   // ALUOP
    }
    if (opcode == I)
    {
        regWrite = "1"; // regWrite
        branch = "0";   // branch
        aluSrc = "1";   // ALUSRC
        memWrite = "0"; // MemWrite;
        memToReg = "1"; // MemToReg
        memRead = "1";  // MemRead
        aluOp = "00";   // ALUOP
    }

    if (opcode == I2)
    {
        regWrite = "1"; // regWrite
        branch = "0";   // branch
        aluSrc = "1";   // ALUSRC
        memWrite = "0"; // MemWrite;
        memToReg = "0"; // MemToReg
        memRead = "0";  // MemRead
        aluOp = "00";   // ALUOP
    }
    if (opcode == S)
    {
        regWrite = "0"; // regWrite
        branch = "0";   // branch
        aluSrc = "1";   // ALUSRC
        memWrite = "1"; // MemWrite;
        memToReg = "0"; // MemToReg
        memRead = "0";  // MemRead
        aluOp = "00";   // ALUOP
    }
    if (opcode == SB)
    {
        regWrite = "0"; // regWrite
        branch = "1";   // branch
        aluSrc = "0";   // ALUSRC
        memWrite = "0"; // MemWrite;
        memToReg = "0"; // MemToReg
        memRead = "0";  // MemRead
        aluOp = "01";   // ALUOP
    }

    if (opcode == UJ)
    {
    }
}

#endif