#ifndef REGS_H
#define REGS_H

class REGS{
public:
    //int [] regs;
    int* regs;
    
    REGS ();
    int readR(int _adress);
    void writeR(int _adress, int _v);  
};

REGS::REGS(){
    regs = new int[16];
};
    
int REGS::readR(int _adress){
    return (regs[_adress]);
};
    
void REGS::writeR(int _adress, int _v){
    regs[_adress]= _v;
};

#endif
