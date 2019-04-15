#ifndef ULA_H
#define ULA_H

class ULA{
public:
    float a, b, s;
    bool cond1;
     
    ULA();
    void readA(float _a);
    void readB(float _b);
    float writeResult();

    public:
        void op(int ulaOP);
    public:
        bool getCond();    
};

#endif


       

    






