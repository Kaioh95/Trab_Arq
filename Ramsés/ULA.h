#ifndef ULA_H
#define ULA_H

class ULA{
public:
    int a, b, s;
    bool n, z, c;
     
    ULA();
    ~ULA();
    void readA(int _a);
    void readB(int _b);
    float writeResult();

    void op(int ulaOP);

    bool getn();
    bool getz();
    bool getc();    
};

#endif


       

    






