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

PC::PC(ULA _ula, REGS _regs) {
        ula= _ula; regs= _regs;
        lastState= false;
};
    
void PC::FTE(){
    switch (EA){
        case 0 :
            ula.op(7);
            regs.writeR(1, ula.writeResult());
            ula.op(8);
            regs.writeR(5, ula.writeResult());
            ula.op(5);
            if(ula.getCond()) PE = 1;
            else lastState = true; 
            break; 
        case 1 :
            ula.readA(regs.readR(1));
            ula.readB(regs.readR(1));
            ula.op(2);
            regs.writeR(4, ula.writeResult());
            PE = 2;
            break;
        case 2 :
            ula.readA(regs.readR(3));
            ula.readB(regs.readR(4));
            ula.op(1);
            regs.writeR(4, ula.writeResult());
            PE = 3;
            break;
        case 3 :
            ula.readA(regs.readR(1));
            ula.readB(regs.readR(1));
            ula.op(0);
            regs.writeR(2, ula.writeResult());
            PE = 4;
            break;
        case 4 :
            ula.readA(regs.readR(4));
            ula.readB(regs.readR(2));
            ula.op(3);
            regs.writeR(4, ula.writeResult());
            PE = 5;
            break;
        case 5 :
            ula.readA(regs.readR(1));
            ula.readB(regs.readR(4));
            ula.op(1);
            regs.writeR(0, ula.writeResult());
            PE = 6;
            break;
        case 6 :
            ula.readA(regs.readR(0));
            ula.readB(regs.readR(0));
            ula.op(4);
            regs.writeR(2, ula.writeResult());
            PE = 7;
            break;
        case 7 :
            ula.readA(regs.readR(2));
            ula.readB(regs.readR(1));
            ula.op(4);
            regs.writeR(1, ula.writeResult());
            PE = 8;
            break;
        case 8 :
            ula.readA(regs.readR(0));
            ula.readB(regs.readR(0));
            ula.op(4);
            regs.writeR(2, ula.writeResult());
            PE = 9;
            break;
        default: break;
    }
}
        
void PC::updateState(){
    EA= PE;  
};
        
bool PC::getLastState() {
    return(lastState);
};

#endif