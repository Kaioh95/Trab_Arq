#ifndef REGS_H
#define REGS_H

class REGS{
public:
    //int [] regs;
    // Cria os registradores.
    int* regs;
    
    REGS();
    ~REGS();
    // Lê o valor do registrador.
    int readR(int _adress)const;
    // Escreve um valor do registrador.
    void writeR(int _adress, int _v);  
};

#endif
