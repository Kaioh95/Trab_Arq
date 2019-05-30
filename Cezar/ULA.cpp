#include "ULA.h"
#include <iostream>
using namespace std;

ULA::ULA(REGS * regs){
    //n = false;
    //z = true;
    //c = false;
    this->reg = regs;

}
ULA::~ULA(){}

void ULA::readA(int _a) {}
void ULA::readB(int _b) {}
// float ULA::writeResult() {}

void ULA::op(int ulaOP,int font, int dest){
    switch (ulaOP) {
        case 1:
            dest = dest + font;
            break;
        case 2:
            dest = dest - font;
            break;
        case 3:
            dest = (dest || font);
            break;
        case 4:
            dest = (dest && font);
            break;
        // case 5:
        //     dest = -a - 1;
        //     break;
        // case 6:
        //     dest = -a;
        //     break;
        // case 7:
        //     dest = a/2;
        default:
            break;
    }
    // if(s > 127 || s < -128){
    //     c = true;
    //     z = false;
    //     n = false;
    //     if(s<0){ n = true; }
    // }

    // else if(s < 0){
    //     n = true;
    //     z = false;
    //     c = false;
    // }
    
    // else if(s == 0){
    //     z = true;
    //     n = false;
    //     c = false;
    // }
    // else{
    //     z = false;
    //     n = false;
    //     c = false;
        
    // }
    cout<<"N: "<< n 
        <<" Z: "<< z 
        <<" C: "<< c << endl;

}
   
bool ULA::getn() { return(n); }
bool ULA::getz() { return(z); }
bool ULA::getc() { return(c); }