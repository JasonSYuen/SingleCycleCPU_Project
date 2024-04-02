#include <iostream>
#include "Fetch.h"
#include "Execute.h"
#include "Mem.h"
#include "decode.h"
#pragma once
using namespace std;

int pc = 0;
int rf[32];
int main()
{
    for (int j = 0; j < 6; j++)
    {

        cout << "hello world" << endl;
        string machine_code = Fetch();
        cout << "machine code: " << machine_code << endl;
        string *ALU_INFO = decode(machine_code);
        cout << " " << endl;
        for (int i = 0; i < 7; i++)
        {
            cout << ALU_INFO[i] << ", ";
        }
        cout << " " << endl;
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
        cout << "ALU output: " << ALU_output << endl;

        int r = 10;

        if (ALU_INFO[6] == "lw" || ALU_INFO[6] == "sw")
        {
            int t = bin_to_dec(ALU_output) * 4;
            ALU_output = dec_to_bin(t);

            while (ALU_output.length() % 4 != 0)
            {
                ALU_output.insert(0, "0");
            }
            string hex_ALU_out = "";
            for (int i = 0; i < ALU_output.length(); i = i + 4)
            {
                string temp = ALU_output.substr(i, 4);
                if (temp == "0000")
                {
                    hex_ALU_out.append("0");
                }
                if (temp == "0001")
                {
                    hex_ALU_out.append("1");
                }
                if (temp == "0010")
                {
                    hex_ALU_out.append("2");
                }
                if (temp == "0011")
                {
                    hex_ALU_out.append("3");
                }
                if (temp == "0100")
                {
                    hex_ALU_out.append("4");
                }
                if (temp == "0101")
                {
                    hex_ALU_out.append("5");
                }
                if (temp == "0110")
                {
                    hex_ALU_out.append("6");
                }
                if (temp == "0111")
                {
                    hex_ALU_out.append("7");
                }
                if (temp == "1000")
                {
                    hex_ALU_out.append("8");
                }
                if (temp == "1001")
                {
                    hex_ALU_out.append("9");
                }
                if (temp == "1010")
                {
                    hex_ALU_out.append("A");
                }
                if (temp == "1011")
                {
                    hex_ALU_out.append("B");
                }
                if (temp == "1100")
                {
                    hex_ALU_out.append("C");
                }
                if (temp == "1101")
                {
                    hex_ALU_out.append("D");
                }
                if (temp == "1110")
                {
                    hex_ALU_out.append("E");
                }
                if (temp == "1111")
                {
                    hex_ALU_out.append("F");
                }
            }
            cout << "hex: " << hex_ALU_out << endl;
            r = Mem(hex_ALU_out, ALU_INFO[6], ALU_INFO[2]);
            // r = Mem(hex_ALU_out, "sw", "00110");
        }
        cout << r << endl;
    }
}
