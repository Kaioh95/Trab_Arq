#include "ULA.h"

ULA::ULA() { cond1 = false; }
void ULA::readA(float _a) {a= _a;}
void ULA::readB(float _b) {b= _b;}
float ULA::writeResult() {return(s);}

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
            if(a == 0){cond1 = 1;}else{cond1 = 0;} 
            break;
        case 6:
            if(a == b){cond1 = 1;}else{cond1 = 0;}
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