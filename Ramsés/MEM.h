#ifndef MEM_H
#define MEM_H

class MEM{
public:
    //int [] regs;
    int* mem;
    
    MEM();
    ~MEM();
    int read(int _adress);
    void write(int _adress, int _v);  
};

#endif
