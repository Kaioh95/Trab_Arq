#include "REGS.h"

REGS::REGS(){
    regs = new float[1];
};
    
float REGS::get(int _adress){
    return (regs[_adress]);
};
    
void REGS::set(int _adress, float _v){
    regs[_adress]= _v;
};