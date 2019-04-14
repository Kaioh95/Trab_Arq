#ifndef ULA_H
#define ULA_H

class ULA{
public:
    int a, b, s;
    bool cond1;
     
    ULA();
    void readA(int _a);
    void readB(int _b);
    int writeResult();

    public:
        void op(int ulaOP);
    public:
        bool getCond();    
};

ULA::ULA() { cond1 = false; }
void ULA::readA(int _a) {a= _a;}
void ULA::readB(int _b) {b= _b;}
int ULA::writeResult() {return(s);}

void ULA::op(int ulaOP){
    switch (ulaOP) {
        case 0:
            s = a + b;
            break;
        case 1:
            s = a - b;
            break;
        case 2:
            s = a * b;
            break;
        case 3:
            s = a / b;
            break;
        case 4:
            s = a * a;
            break;
        case 5:
            if(a == 0){cond1 = true;}else{cond1 = false;} 
            break;
        case 6:
            if(a == b){cond1 = true;}else{cond1 = false;}
            break;
        case 7:
            s = 1;
            break;
        case 8:
            s = 0;
            break;
        case 9:
            s = a;
            break;
        default:
            break;
    }
}
   
bool ULA::getCond() { return(cond1); }

#endif


       

    






