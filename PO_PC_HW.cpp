#include <iostream>
#include "PC.h"

using namespace std;

int main(int argc, char* argv[]){

    float x;
    ULA *ula = new ULA();
    REGS *regs =  new REGS();
    PC *pc = new PC(*ula, *regs);
    cout<<"Digite um valor para x: ";
    cin>>x; 
    pc->regs.writeR(3, x);
        
    for(int _clock=0; _clock < 100; _clock++) {
        pc->FTE();
        pc->updateState();
        if(pc->getLastState() == true) break;    
    }
    cout<<"A raiz quadrada de "<< x <<" é: "<<pc->regs.readR(0)<<endl;
	return 0;      
}
