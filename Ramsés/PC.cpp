#include "PC.h"

PC::PC(ULA _ula, REGS _regs, MEM _mem) {
        ula= _ula; regs= _regs;  mem = _mem;
        lastState= false;
};

void PC::FTE(){
    if(cont != 126 && !lastState){
        int instrucao = mem.read(cont);
        cont++;
        int endereco = mem.read(cont);
        cont++;

        switch (instrucao){
            case 0:
               
                break; 
            case 16://STA direto
                mem.read(cont);
                break;
            case 17://STA Indireto

                break;
            case 19://STA Indexado

                break;
            case 20://STB direto

                break;
            case 21://STB Indireto

                break;
            case 23://STB Indexado

                break;
            case 24://STX direto
                
                break;
            case 25://STX Indireto

                break;
            case 27://STX Indexado

                break;
            case 32://LDA direto
                
                break;
            case 33://LDA Indireto
                
                break;
            case 34://LDA constante
                
                break;
            case 35://LDA Indexado
                
                break;
            case 36://LDB direto
                
                break;
            case 37://LDB Indireto
                
                break;
            case 38://LDB constante
                
                break;
            case 39://LDB Indexado
                
                break;
             case 40://LDX direto
                
                break;
            case 41://LDX Indireto
                
                break;
            case 42://LDX constante
                
                break;
            case 43://LDX Indexado
                
                break;
            case 48://ADD A Direto
               
                break;
            case 49://ADD A Indireto

                break;
            case 50://ADD A Constante

                break;
            case 51://ADD A Indexado

                break;
            case 52://ADD B Direto
               
                break;
            case 53://ADD B Indireto

                break;
            case 54://ADD B Constante

                break;
            case 55://ADD B Indexado

                break;
            case 56://ADD X Direto
               
                break;
            case 57://ADD X Indireto

                break;
            case 58://ADD X Constante

                break;
            case 59://ADD X Indexado

                break;
            case 64://OR A Direto 
               
                break;
            case 65://OR A Indireto

                break;
            case 66://OR A Constante

                break;
            case 67://OR A Indexado

                break;
            case 68://OR B Direto 
               
                break;
            case 69://OR B Indireto

                break;
            case 70://OR B Constante

                break;
            case 71://OR B Indexado

                break;
            case 72://OR X Direto 
               
                break;
            case 73://OR X Indireto

                break;
            case 74://OR X Constante

                break;
            case 75://OR X Indexado

                break;
            case 80://AND A Direto

                break;
            case 81://AND A Indireto

                break;
            case 82://ADD A Constante

                break;
            case 83://ADD A Indexado

                break;
            case 84://AND B Direto

                break;
            case 85://AND B Indireto

                break;
            case 86://ADD B Constante

                break;
            case 87://ADD B Indexado

                break;
            case 88://AND X Direto

                break;
            case 89://AND X Indireto

                break;
            case 90://ADD X Constante

                break;
            case 91://ADD X Indexado

                break;
            case 96://NOT A

                break;
            case 100://NOT B

                break;
            case 104://NOT X

                break;
            case 112://SUB

                break;
            case 128://JMP

                break;
            case 144://JN

                break;
            case 160://JZ

                break;
            case 176://JC

                break;
            case 192://JSR

                break;
            case 208://NEG

                break;
            case 224://SHR

                break;
            case 240://HLT
                lastState = true;
                break;
            default: break;
        }
    }
    else{
        lastState = true;
    }
}
        
void PC::updateState(){
    EA = PE;  
};
        
bool PC::getLastState() {
    return(lastState);
};