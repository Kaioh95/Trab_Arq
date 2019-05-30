#include "ULA.h"
#include <iostream>
using namespace std;

ULA::ULA(){
    //n = false;
    //z = true;
    //c = false;
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
    if(s > 127 || s < -128){
        c = true;
        z = false;
        n = false;
        if(s<0){ n = true; }
    }

    else if(s < 0){
        n = true;
        z = false;
        c = false;
    }
    
    else if(s == 0){
        z = true;
        n = false;
        c = false;
    }
    else{
        z = false;
        n = false;
        c = false;
        
    }
    cout<<"N: "<< n 
        <<" Z: "<< z 
        <<" C: "<< c << endl;

}
   
bool ULA::getn() { return(n); }
bool ULA::getz() { return(z); }
bool ULA::getc() { return(c); }