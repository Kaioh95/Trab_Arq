#include <iostream>
#include "PC.h"
//class PO_PC_HW {

int main(int argc, char* argv[]){

    ULA *ula = new ULA();
    REGS *regs =  new REGS();
    PC *pc = new PC(*ula, *regs);
        
    for(int _clock=0; _clock < 100; _clock++) {
        pc->FTE();
        pc->updateState();
        if(pc->getLastState() == true) break;    
    }
	return 0;      
}
