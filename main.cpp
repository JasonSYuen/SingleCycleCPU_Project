#include <iostream>
#include "Fetch.h"
#include "Execute.h"
#include "Mem.h"
#include "decode.h"

using namespace std;

int pc = 0;

int main()
{
    cout << "hello world" << endl;
    string machine_code = Fetch();
    cout << machine_code << endl;
    string *test = decode(machine_code);
    for (int i = 0; i < 6; i++)
    {
        cout << test[i] << endl;
    }
    // operation, rs1, rs2, rd, imm, alu_ctrl
}
