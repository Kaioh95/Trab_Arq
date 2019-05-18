#include "ULA.h"

ULA::ULA(){
    n = false;
    z = false;
    c = false;
}
ULA::~ULA(){}

void ULA::readA(int _a) {a= _a;}
void ULA::readB(int _b) {b= _b;}
float ULA::writeResult() {return(s);}

void ULA::op(int ulaOP){
    switch (ulaOP) {
        case 0:
            s = b;
            break;
        case 1:
            s = a + b;
            break;
        case 2:
            s = a - b;
            break;
        case 3:
            s = (a || b);
            break;
        case 4:
            s = (a && b);
            break;
        case 5:
            s = -a - 1;
            break;
        case 6:
            s = -a;
            break;
        case 7:
            s = a/2;
        default:
            break;
    }
}
   
bool ULA::getn() { return(n); }
bool ULA::getz() { return(z); }
bool ULA::getc() { return(c); }