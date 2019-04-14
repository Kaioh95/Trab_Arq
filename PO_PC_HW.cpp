#include <iostream>
#include "PC.h"

using namespace std;

int main(int argc, char* argv[]){

    ULA *ula = new ULA();
    REGS *regs =  new REGS();
    PC *pc = new PC(*ula, *regs);
    pc->regs.writeR(3, 4);
        
    for(int _clock=0; _clock < 100; _clock++) {
        pc->FTE();
        pc->updateState();
        if(pc->getLastState() == true) break;    
    }
    cout<<"A raiz quadrada de 4 é: "<<pc->regs.readR(0)<<endl;
	return 0;      
}
