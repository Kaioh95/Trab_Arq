#ifndef REGS_H
#define REGS_H

class REGS{
public:
    //int [] regs;
    float* regs;
    
    REGS ();
    float readR(int _adress);
    void writeR(int _adress, float _v);  
};

#endif
