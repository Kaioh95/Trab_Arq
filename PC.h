#ifndef PC_H
#define PC_H
#include "REGS.h"
#include "ULA.h"
#include <iostream>

using namespace std;

class PC{
public:
    int EA = 0, PE; // estado atual, proximo estado
    bool lastState;
    ULA ula;
    REGS regs;
    
    PC (ULA _ula, REGS _regs);
    void FTE();
    void updateState();
    bool getLastState();

};

PC::PC(ULA _ula, REGS _regs) {
        ula= _ula; regs= _regs;
        lastState= false;
};
    
void PC::FTE(){
    switch (EA){
        case 0 :
            ula.op(7);
            cout<<"OP A=1 da ULA"<<endl;
            regs.writeR(1, ula.writeResult());
            cout<<"Load no endreço de r."<<endl;
            ula.op(8);
            cout<<"OP A=0 da ULA"<<endl;
            regs.writeR(5, ula.writeResult());
            cout<<"Load no endreço de sair."<<endl;
            ula.op(5);
            cout<<"A op 5 verifica se a entrada A é igual a 0"<<endl;
            if(ula.getCond() == 0){
                PE = 1;
                cout<<"Se sim, então PE = 1"<<endl;
            }
            else{
                lastState = true;
                cout<<"Caso contrario, avança para ultimo estado."<<endl;
            }
            break; 
        case 1 :
            cout<<"Input da variável r na entrada A da ULA"<<endl;
            ula.readA(regs.readR(1));
            cout<<"Input da variável r na entrada B da ULA"<<endl;
            ula.readB(regs.readR(1));
            cout<<"OP A*B da UlA"<<endl;
            ula.op(2);
            regs.writeR(4, ula.writeResult());
            cout<<"Load em Auxiliar"<<endl;
            PE = 2;
            cout<<"PE = 2"<<endl;
            break;
        case 2 :
            cout<<"Input da variável x na entrada A da ULA"<<endl;
            ula.readA(regs.readR(3));
            cout<<"Input da variável Auxiliar na entrada B da ULA"<<endl;
            ula.readB(regs.readR(4));
            cout<<"OP A-B da UlA"<<endl;
            ula.op(1);
            regs.writeR(4, ula.writeResult());
            cout<<"Load em Auxiliar"<<endl;
            PE = 3;
            cout<<"PE = 3"<<endl;
            break;
        case 3 :
            cout<<"Input da variável r na entrada A da ULA"<<endl;
            ula.readA(regs.readR(1));
            cout<<"Input da variável r na entrada B da ULA"<<endl;
            ula.readB(regs.readR(1));
            cout<<"OP A+B da UlA"<<endl;
            ula.op(0);
            regs.writeR(2, ula.writeResult());
            cout<<"Load em rp"<<endl;
            PE = 4;
            cout<<"PE = 4"<<endl;
            break;
        case 4 :
            cout<<"Input da variável Auxiliar na entrada A da ULA"<<endl;
            ula.readA(regs.readR(4));
            cout<<"Input da variável rp na entrada B da ULA"<<endl;
            ula.readB(regs.readR(2));
            cout<<"OP A/B da UlA"<<endl;
            ula.op(3);
            regs.writeR(4, ula.writeResult());
            cout<<"Load em Auxiliar"<<endl;
            PE = 5;
            cout<<"PE = 5"<<endl;
            break;
        case 5 :
            cout<<"Input da variável r na entrada A da ULA"<<endl;
            ula.readA(regs.readR(1));
            cout<<"Input da variável Auxiliar na entrada B da ULA"<<endl;
            ula.readB(regs.readR(4));
            cout<<"OP A+B da UlA"<<endl;
            ula.op(0);
            regs.writeR(0, ula.writeResult());
            cout<<"Load em res"<<endl;
            PE = 6;
            cout<<"PE = 6"<<endl;
            break;
        case 6 :
            cout<<"Input da variável res na entrada A da ULA"<<endl;
            ula.readA(regs.readR(0));
            cout<<"Input da variável res na entrada B da ULA"<<endl;
            ula.readB(regs.readR(0));
            cout<<"OP A*B da UlA"<<endl;
            ula.op(4);
            regs.writeR(2, ula.writeResult());
            cout<<"Load em rp"<<endl;
            PE = 7;
            cout<<"PE = 7"<<endl;
            break;
        case 7 :
            cout<<"Input da variável rp na entrada A da ULA"<<endl;
            ula.readA(regs.readR(2));
            cout<<"Input da variável r na entrada B da ULA"<<endl;
            ula.readB(regs.readR(1));
            cout<<"OP A-B da UlA"<<endl;
            ula.op(1);
            regs.writeR(4, ula.writeResult());
            cout<<"Load em Auxiliar"<<endl;
            PE = 8;
            cout<<"PE = 8"<<endl;
            break;
        case 8 :
            cout<<"Input da variável Auxiliar na entrada A da ULA"<<endl;
            ula.readA(regs.readR(4));
            cout<<"OP A==0 da UlA"<<endl;
            ula.op(5);
            regs.writeR(4, ula.getCond());
            cout<<"Load em Auxiliar"<<endl;
            PE = 9;
            cout<<"PE = 9"<<endl;
            break;
        case 9 :
            cout<<"Input da variável r na entrada A da ULA"<<endl;
            ula.readA(regs.readR(1));
            cout<<"Input da variável res na entrada B da ULA"<<endl;
            ula.readB(regs.readR(0));
            cout<<"OP A==B da UlA"<<endl;
            ula.op(6);
            regs.writeR(2, ula.getCond());
            cout<<"Load em rp"<<endl;
            PE = 10;
            cout<<"PE = 10"<<endl;
            break;
        case 10 :
            if(regs.readR(4)==0 || regs.readR(2)==0){
                PE = 11;
                cout<<"PE = 11"<<endl;
            }
            else{
                PE = 12;
                cout<<"PE = 12"<<endl;
            }
            break;
        case 11 :
            cout<<"OP s=1 da ULA"<<endl;
            ula.op(7);
            regs.writeR(5, ula.writeResult());
            cout<<"Load em sair"<<endl;
            PE = 12;
            cout<<"PE = 12"<<endl;
            break;
        case 12 :
            cout<<"Input da variável res na entrada A da ULA"<<endl;
            ula.readA(regs.readR(0));
            cout<<"OP s=A da UlA"<<endl;
            ula.op(9);
            regs.writeR(1, ula.writeResult());
            cout<<"Load em r"<<endl;
            if(regs.readR(5) == 1){
                lastState = true;
                cout<<"PE = lastState"<<endl;
            }
            else{
                PE = 0;
                cout<<"PE = 0"<<endl;
            }
            break;
        default: break;
    }
}
        
void PC::updateState(){
    EA= PE;  
};
        
bool PC::getLastState() {
    return(lastState);
};

#endif