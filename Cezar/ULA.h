#include "REGS.h"
#ifndef ULA_H
#define ULA_H


class ULA{
public:
    REGS *reg;
    bool n = 0, z = 0, c = 0, v = 0;
     
    ULA(REGS * regs);
    ~ULA();
    void readA(int _a);
    void readB(int _b);
    float writeResult();

    void op(int ulaOP, int font, int dest);

    bool getn();
    bool getz();
    bool getc(); 
    bool overflow();   
}; 

#endif


       

    






