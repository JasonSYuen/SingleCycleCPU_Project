#include <iostream>
#include "Fetch.h"
#include "Execute.h"
#include "Mem.h"
#include "decode.h"
#include "writeback.h"

using namespace std;

int pc = 0;
int rf[32];
int total_clock_cycles = 1;

string regWrite = "0";
string branch = "0";
string aluSrc = "0";
string memWrite = "0";
string memToReg = "0";
string memRead = "0";
string aluOp = "0";

int branchTarget;

int input1;
int input2;
int dest;
int immediate;
string aluCtrl;

string aluZero;
bool branchbecauseiwantto = false;
int main()
{
    rf[1] = 32;
    rf[2] = 5;
    rf[10] = 112;
    rf[11] = 4;

    string input;
    cout << "Enter the program file name to run:" << endl;
    cin >> input;
    cout << endl;

    for (int j = 0; j < 6; j++)
    {
        cout << "total_clock_cycles " << total_clock_cycles << " :" << endl;
        if (pc == 8)
        {
            branchbecauseiwantto = true;
        }
        else
        {
            branchbecauseiwantto = false;
        }
        //cout << "hello world" << endl;

        input1 = 0;
        input2 = 0;
        dest = 0;
        immediate = 0;
        aluCtrl = "";

        string machine_code = Fetch(input);
        //cout << "machine code: " << machine_code << endl;
        decode(machine_code);
        //cout << "DECODE ARRAY: " << input1 << " " << input2 << " " << dest << " " << immediate << endl;

        // operation, rs1, rs2, rd, imm, alu_ctrl
        string ALU_output;

        ALU_output = Execute(aluCtrl, input1, input2);

        //cout << "ALU output: " << ALU_output << endl;

        int memOutput = 10;

        if (memWrite == "1" || memRead == "1" || memToReg == "1")
        {
            int t = bin_to_dec(ALU_output);
            // ALU_output = dec_to_bin(t);

            // while (ALU_output.length() % 4 != 0)
            // {
            //     ALU_output.insert(0, "0");
            // }
            string hex_ALU_out = dec_to_hex(t);

            //cout << "hex: " << hex_ALU_out << endl;
            //cout << endl;

            memOutput = Mem2(hex_ALU_out, dest);
            // r = Mem(hex_ALU_out, "sw", "00110");
        }

        //cout << "Memory Output: " << memOutput << endl;
        //cout << endl;

        writeback(ALU_output, memOutput, dest);
        // cout << "In rf[" << bin_to_dec(ALU_INFO[3]) << "]: " << rf[bin_to_dec(ALU_INFO[3])] << endl;
        //cout << "###############################################################" << endl;
        FetchEnd();
        cout << endl;

    }
    cout << "program terminated:" << endl;
    cout << "total execution time is " << total_clock_cycles-1 << " cycles" << endl;
}
