#include <iostream>
#include "PC.h"

using namespace std;

int main(int argc, char* argv[]){

    //float x;
    ULA *ula = new ULA();
    REGS *regs =  new REGS();
    MEM *mem = new MEM();
    PC *pc = new PC(*ula, *regs, *mem); 
        
    for(int _clock=0; _clock < 999; _clock++) {
        pc->FTE();
        pc->updateState();
        if(pc->getLastState() == true) break;    
    }
	return 0;      
}
