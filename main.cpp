#include <iostream>
#include "Fetch.h"
#include "Execute.h"
#include "Mem.h"
#include "decode.h"

using namespace std;

int pc = 0;
int rf[32];
int main()
{
    cout << "hello world" << endl;
    string machine_code = Fetch();
    cout << machine_code << endl;
    string *ALU_INFO = decode(machine_code);
    for (int i = 0; i < 7; i++)
    {
        cout << ALU_INFO[i] << endl;
    }
    // operation, rs1, rs2, rd, imm, alu_ctrl
    string ALU_output;
    if (ALU_INFO[0] == "R")
    {
        ALU_output = Execute(ALU_INFO[5], ALU_INFO[1], ALU_INFO[2]);
    }
    if (ALU_INFO[0] == "I")
    {
        ALU_output = Execute(ALU_INFO[5], ALU_INFO[1], ALU_INFO[4]);
    }
    if (ALU_INFO[0] == "S")
    {
        ALU_output = Execute(ALU_INFO[5], ALU_INFO[4], ALU_INFO[1]);
    }
    /*
    if (ALU_INFO[0] == "SB")
    {
        string ALU_output = Execute(ALU_INFO[5], ALU_INFO[1], ALU_INFO[2]);
    }
    if (ALU_INFO[0] == "UJ")
    {
        string ALU_output = Execute(ALU_INFO[5], ALU_INFO[1], ALU_INFO[2]);
    }
    if (ALU_INFO[0] == "")
    {
        string ALU_output = Execute(ALU_INFO[5], ALU_INFO[1], ALU_INFO[2]);
    }
    */
    cout << ALU_output << endl;
}
