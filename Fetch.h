#ifndef Fetch_H_
#define Fetch_H_
#include <iostream>
#include <fstream>
#include <string>
#include "dec_bin_hex_conversion.h"

using namespace std;

int amount;

extern int pc;
extern string aluZero;

extern string branch;
extern int branchTarget;
string Fetch(string input)
{

    string text;
    ifstream MyFile;

    MyFile.open(input);

    int count = 0;
    string line;
    while (getline(MyFile, line))
    {
        // cout << line << endl;

        if (count == pc)
        {
            text = line;
        }
        count += 4;
    }

    MyFile.close();
    amount = 4;
    pc += amount;

    int next_pc = pc + 4;

    if (branch == "1" && aluZero == "1")
    {
        amount = branchTarget;
        pc = pc + amount;
        // next_pc = pc + branchTarget;  branch target needs to be int
    }

    return text;
}

void FetchEnd(){
    cout << "pc is modified to 0x" << dec_to_hex(pc) << endl;
}
#endif