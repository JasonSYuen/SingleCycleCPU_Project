#ifndef DECODE_H // guard
#define DECODE_H
#include <string>
#include <iostream>
#include "dec_bin_hex_conversion.h"
using namespace std;

extern int rf[32];

string *decode(string bin)
{
    string *curr = new string[7];
    // curr's values are as follow:
    // operation, rs1, rs2, rd, imm, alu_ctrl

    string opcode = bin.substr(25, 7);
    // strncpy(opcode, machine_code + (25), 7);

    string R = "0110011";
    string R2 = "0111011";
    string I = "0000011";
    string I2 = "0010011";
    string I3 = "1100111";
    string S = "0100011";
    string SB = "1100011";
    string UJ = "1101111";

    string funct3 = "";
    string funct7 = "";

    string rs1 = "";
    string rs2 = "";
    string rd = "";

    string imm;

    string I_imm = "";

    string S_imm = "";

    string SB_imm = "";

    string UJ_imm = "";

    string op = "";
    string op2 = ""; /////USE FOR OPERATION _________________________

    // if (strcmp(opcode, R) == 0)
    if (opcode == R)
    {
        // strncpy(funct7, machine_code + (0), 7);
        // strncpy(rs2, machine_code + (7), 5);
        // strncpy(rs1, machine_code + (12), 5);
        // strncpy(funct3, machine_code + (17), 3);
        // strncpy(rd, machine_code + (20), 5);
        funct7 = bin.substr(0, 7);
        rs2 = bin.substr(7, 5);
        rs1 = bin.substr(12, 5);
        funct3 = bin.substr(17, 3);
        rd = bin.substr(20, 5);

        int x = bin_to_dec(funct3);
        int y = bin_to_dec(funct7);

        op = "R";
    }
    if (opcode == I || opcode == I2)
    {
        /*strncpy(I_imm, machine_code + (0), 12);
        strncpy(rs1, machine_code + (12), 5);
        strncpy(funct3, machine_code + (17), 3);
        strncpy(rd, machine_code + (20), 5);*/

        I_imm = bin.substr(0, 12);
        rs1 = bin.substr(12, 5);
        funct3 = bin.substr(17, 3);
        rd = bin.substr(20, 5);

        int f3 = bin_to_dec(funct3);
        imm = I_imm;

        op = "I";

        if (f3 == 2 && opcode == I)
        {
            op2 = "lw";
        }
    }
    if (opcode == S)
    {
        /*strncpy(S_imm, machine_code + (0), 7);
        strncpy(rs2, machine_code + (7), 5);
        strncpy(rs1, machine_code + (12), 5);
        strncpy(funct3, machine_code + (17), 3);
        strncpy(S2_imm, machine_code + (20), 5);
        strncat(imm_total, S_imm, 8);
        strncat(imm_total, S2_imm, 6);*/

        S_imm = bin.substr(0, 7) + bin.substr(20, 5);
        rs2 = bin.substr(7, 5);
        rs1 = bin.substr(12, 5);
        funct3 = bin.substr(17, 3);

        int x = bin_to_dec(funct3);
        imm = S_imm;

        op = "S";

        if (x == 2)
        {
            op2 = "sw";
        }
    }
    if (opcode == SB)
    {
        /*strncpy(S_imm, machine_code + (0), 7);
        strncpy(rs2, machine_code + (7), 5);
        strncpy(rs1, machine_code + (12), 5);
        strncpy(funct3, machine_code + (17), 3);
        strncpy(S2_imm, machine_code + (20), 5);
        strncat(imm_total, S2_imm + (4), 1);
        strncat(imm_total, S_imm + (1), 6);
        strncat(imm_total, S2_imm, 4);
        strncat(imm_total, "00", 1);*/

        S_imm = bin.substr(24, 1) + bin.substr(1, 6) + bin.substr(20, 4) + "0";
        rs2 = bin.substr(7, 5);
        rs1 = bin.substr(12, 5);
        funct3 = bin.substr(17, 3);

        int x = bin_to_dec(funct3);
        imm = S_imm;
        op = "SB";

        if (x == 0)
        {
            op2 = "beq";
        }
    }
    if (opcode == UJ)
    {
        /*strncat(UJ_imm, machine_code + (0), 1);
        strncat(UJ_imm, machine_code + (12), 8);
        strncat(UJ_imm, machine_code + (11), 1);
        strncat(UJ_imm, machine_code + (1), 10);
        strncat(UJ_imm, "00", 1);

        strncpy(rd, machine_code + (20), 5);*/

        UJ_imm = bin.substr(0, 1) + bin.substr(12, 8) + bin.substr(11, 1) + bin.substr(1, 10) + "0";
        rd = bin.substr(20, 25);

        imm = UJ_imm;
        op = "UJ";
    }

    curr[0] = op;
    curr[1] = to_string(rf[bin_to_dec(rs1)]);
    curr[2] = to_string(rf[bin_to_dec(rs2)]);
    curr[3] = rd;
    curr[4] = imm;
    curr[6] = op2;
    if (op == "R")
    {
        if (bin_to_dec(funct3) == 0 && bin_to_dec(funct7) == 0 || op2 == "lw" || op2 == "sw")
            curr[5] = "0010";
        if (bin_to_dec(funct3) == 0 && bin_to_dec(funct7) == 32 || op == "beq")
            curr[5] = "0110";
        if (bin_to_dec(funct3) == 7 && bin_to_dec(funct7) == 0)
            curr[5] = "0000";
        if (bin_to_dec(funct3) == 6 && bin_to_dec(funct7) == 0)
            curr[5] = "0001";
    }
    else
    {
        if (op2 == "lw")
        {
            curr[5] = "0010";
        }
        if (op2 == "sw")
            curr[5] = "0010";
        if (op2 == "beq")
            curr[5] = "0110";
    }

    return curr;
}

#endif