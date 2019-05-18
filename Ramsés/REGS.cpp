#include "REGS.h"

REGS::REGS(){
    regs = new int[3];
    regs[0] = 0; regs[1] = 0; regs[2] = 0;
};
REGS::~REGS(){
	delete[] regs;
}
    
int REGS::readR(int _adress){
    return (regs[_adress]);
};
    
void REGS::writeR(int _adress, int _v){
    regs[_adress]= _v;
};