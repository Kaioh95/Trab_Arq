#include "REGS.h"

REGS::REGS(){
    regs = new int[3];
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