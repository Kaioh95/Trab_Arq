#include "REGS.h"

REGS::REGS(){
    regs = new float[16];
};
    
float REGS::readR(int _adress){
    return (regs[_adress]);
};
    
void REGS::writeR(int _adress, float _v){
    regs[_adress]= _v;
};