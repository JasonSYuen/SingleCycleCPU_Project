#ifndef Fetch_H_
#define Fetch_H_
#include <iostream>
#include <fstream>
#include <string>
#include "dec_bin_hex_conversion.h"

using namespace std;

extern int pc;
extern int next_pc;
extern string aluZero;

extern string branch;
extern int branchTarget;
string Fetch(string input)
{

    string text;
    ifstream MyFile;

    

    //cout << "branch: " << branch << " aluzero: " << aluZero << endl;
    if (branch == "1" && aluZero == "1")
    {
        pc = pc + branchTarget;
        //cout << pc << endl;
        // next_pc = pc + branchTarget;  branch target needs to be int
    }
    else{
        pc = next_pc;
    }

    if(pc != 0){
        cout << "pc is modified to 0x" << dec_to_hex(pc) << endl;
        cout << endl;
    }

    MyFile.open(input);
    next_pc = pc + 4;

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

    return text;
}
#endif