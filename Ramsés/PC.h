#ifndef PC_H
#define PC_H
#include "REGS.h"
#include "ULA.h"
#include "MEM.h"
#include <iostream>

using namespace std;

class PC{
public:
	int cont = 0;
    int EA = 0;
    int PE; // estado atual, proximo estado
    bool lastState;
    ULA ula;
    REGS regs;
    MEM mem;
    
    PC (ULA _ula, REGS _regs, MEM _mem);
    void FTE();
    void updateState();
    bool getLastState();

};
#endif