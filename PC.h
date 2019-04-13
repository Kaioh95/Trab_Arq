#ifndef PC_H
#define PC_H
#include "REGS.h"
#include "ULA.h"

class PC{
public:
    int EA, PE; // estado atual, proximo estado
    bool lastState;
    ULA ula;
    REGS regs;
    
    PC (ULA _ula, REGS _regs);
    void FTE();
    void updateState();
    bool getLastState();

};

PC(ULA _ula, REGS _regs) {
        ula= _ula; regs= _regs;
        lastState= false;
}
    
void FTE(){
    switch (EA){
        case 0 :{
            ula.op(3); // executa instrução de controle na ULA
            if (ula.getCond() == true)
                PE= 2; 
            else
                PE= 3; // estado de controle
            break; 
            } 
        case 1 :{
            PE= 5; 
            ula.readA(regs.readR(2)); 
            ula.readB(regs.readR(5));
            ula.op(0);
            regs.writeR(2, ula.writeResult());  
            break;
        }
        case 2 :{
            lastState= true; // nesse caso, 2 é o ultimo estado
        }
        default: break;
    }
}
        
void updateState(){
    EA= PE;  
}
        
bool getLastState() {
    return(lastState);
}

#endif