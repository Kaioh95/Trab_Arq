#ifndef PC_H
#define PC_H
#include "REGS.h"
#include "ULA.h"
#include <iostream>

using namespace std;

class PC{
public:
    int EA = 0;
    int PE; // estado atual, proximo estado
    bool lastState;
    ULA ula;
    REGS regs;
    
    PC (ULA _ula, REGS _regs);
    void FTE();
    void updateState();
    bool getLastState();

};
#endif