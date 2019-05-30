#include "REGS.h"

REGS::REGS(){
    regs = new int[8];
    for(int i =0; i < 8; i++){
    	regs[i] = 0;
    }
};

REGS::~REGS(){
	delete[] regs;
}
    
int REGS::readR(int _adress)const{
    return (regs[_adress]);
};
    
void REGS::writeR(int _adress, int _v){
    regs[_adress]= _v;
};