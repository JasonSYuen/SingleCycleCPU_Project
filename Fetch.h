#ifndef Fetch_H_
#define Fetch_H_
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

extern int pc;

string Fetch()
{

    string text;
    ifstream MyFile;

    MyFile.open("sample_part1.txt");

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
    pc += 4;

    int next_pc = pc + 4;

    return text;
}
#endif