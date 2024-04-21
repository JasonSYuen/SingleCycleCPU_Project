#include <iostream>
#include "Fetch.h"
#include "Execute.h"
#include "Mem.h"
#include "decode.h"
#include "writeback.h"
#include "controlUnit.h"

using namespace std;

int pc = 0;
int rf[32];

int total_clock_cycles = 0;

string regWrite;
string branch;
string aluSrc;
string memWrite;
string memToReg;
string memRead;
string aluOp;
string aluZero = "0";
string branchTarget = "0";

int main()
{
    rf[1] = 32;
    rf[2] = 5;
    rf[10] = 112;
    rf[11] = 4;

    for (int j = 0; j < 6; j++)
    {

        // FETCH
        string machine_code = Fetch();
        cout << "machine code: " << machine_code << endl;

        // DECODE
        string *ALU_INFO = decode(machine_code);
        cout << endl;
        cout << "DECODE ARRAY: ";
        for (int i = 0; i < 7; i++)
        {
            cout << ALU_INFO[i] << ", ";
        }
        cout << endl;

        // EXECUTE

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

        cout << endl;
        cout << "ALU output: " << ALU_output << endl;

        // MEM
        int r = 0;

        if (memWrite == "1" || memRead == "1" || memToReg == "1")
        {
            int temp = bin_to_dec(ALU_output);
            cout << temp << endl;
            string hex_ALU_out = dec_to_hex(temp);

            cout << "hex: " << hex_ALU_out << endl;
            cout << endl;

            r = Mem(hex_ALU_out, ALU_INFO[6], ALU_INFO[2]);
            // r = Mem(hex_ALU_out, "sw", "00110");
        }
        cout << "Memory Output: " << r << endl;
        cout << endl;
        // WRITE BACK
        writeback(ALU_output, r, ALU_INFO[3], ALU_INFO[6]);
        cout << "In rf[" << bin_to_dec(ALU_INFO[3]) << "]: " << rf[bin_to_dec(ALU_INFO[3])] << endl;

        cout << "total clock cycles: " << total_clock_cycles << endl;
        cout << "pc: " << pc << endl;
        cout << "###############################################################" << endl;
    }
}
