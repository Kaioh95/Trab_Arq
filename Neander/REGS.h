#ifndef REGS_H
#define REGS_H

class REGS{
public:
    //int [] regs;
    float* regs;
    
    REGS ();
    float get(int _adress);
    void set(int _adress, float _v);  
};

#endif
