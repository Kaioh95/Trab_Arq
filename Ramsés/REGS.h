#ifndef REGS_H
#define REGS_H

class REGS{
public:
    //int [] regs;
    int* regs;
    
    REGS();
    ~REGS();
    int readR(int _adress);
    void writeR(int _adress, int _v);  
};

#endif
