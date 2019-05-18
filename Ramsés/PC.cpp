#include "PC.h"

PC::PC(ULA _ula, REGS _regs, MEM _mem) {
        ula= _ula; regs= _regs;  mem = _mem;
        lastState= false;
};

void PC::FTE(){
    if(cont != 127 && !lastState){
        int instrucao = mem.read(cont);
        cont++;
        int endereco = mem.read(cont);
        cont++;

        switch (instrucao){
            case 0://NOP
                cont--;
                break; 
            case 16://STA direto
                mem.write(endereco, regs.readR(0));
                break;
            case 17://STA Indireto
                mem.write(mem.read(endereco), regs.readR(0));
                break;
            case 19://STA Indexado
                mem.write(mem.read(endereco+regs.readR(2)), regs.readR(0));
                break;
            case 20://STB direto
                mem.write(endereco, regs.readR(1));
                break;
            case 21://STB Indireto
                mem.write(mem.read(endereco), regs.readR(1));
                break;
            case 23://STB Indexado
                mem.write(mem.read(endereco+regs.readR(2)), regs.readR(1));
                break;
            case 24://STX direto
                mem.write(endereco, regs.readR(2));
                break;
            case 25://STX Indireto
                mem.write(mem.read(endereco), regs.readR(2));
                break;
            case 27://STX Indexado
                mem.write(mem.read(endereco+regs.readR(2)), regs.readR(2));
                break;
            case 32://LDA direto
                regs.writeR(regs.readR(0), mem.read(endereco));
                break;
            case 33://LDA Indireto
                regs.writeR(regs.readR(0), mem.read(mem.read(endereco)));
                break;
            case 34://LDA constante
                regs.writeR(regs.readR(0), endereco);
                break;
            case 35://LDA Indexado
                regs.writeR(regs.readR(0), mem.read(mem.read(endereco + regs.readR(2))));
                break;
            case 36://LDB direto
                regs.writeR(regs.readR(1), mem.read(endereco));
                break;
            case 37://LDB Indireto
                regs.writeR(regs.readR(1), mem.read(mem.read(endereco)));
                break;
            case 38://LDB constante
                regs.writeR(regs.readR(1), endereco);
                break;
            case 39://LDB Indexado
                regs.writeR(regs.readR(1), mem.read(mem.read(endereco + regs.readR(2))));
                break;
             case 40://LDX direto
                regs.writeR(regs.readR(2), mem.read(endereco));
                break;
            case 41://LDX Indireto
                regs.writeR(regs.readR(2), mem.read(mem.read(endereco)));
                break;
            case 42://LDX constante
                regs.writeR(regs.readR(2), endereco);
                break;
            case 43://LDX Indexado
                regs.writeR(regs.readR(2), mem.read(mem.read(endereco + regs.readR(2))));
                break;
            case 48://ADD A Direto
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco));
                ula.op(1);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 49://ADD A Indireto
                ula.readA(regs.readR(0));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(1);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 50://ADD A Constante
                ula.readA(regs.readR(0));
                ula.readB(endereco);
                ula.op(1);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 51://ADD A Indexado
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(1);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 52://ADD B Direto
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco));
                ula.op(1);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 53://ADD B Indireto
                ula.readA(regs.readR(1));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(1);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 54://ADD B Constante
                ula.readA(regs.readR(1));
                ula.readB(endereco);
                ula.op(1);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 55://ADD B Indexado
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(1);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 56://ADD X Direto
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco));
                ula.op(1);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 57://ADD X Indireto
                ula.readA(regs.readR(2));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(1);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 58://ADD X Constante
                ula.readA(regs.readR(2));
                ula.readB(endereco);
                ula.op(1);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 59://ADD X Indexado
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(1);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 64://OR A Direto 
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco));
                ula.op(3);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 65://OR A Indireto
                ula.readA(regs.readR(0));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(3);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 66://OR A Constante
                ula.readA(regs.readR(0));
                ula.readB(endereco);
                ula.op(3);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 67://OR A Indexado
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(3);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 68://OR B Direto 
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco));
                ula.op(3);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 69://OR B Indireto
                ula.readA(regs.readR(1));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(3);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 70://OR B Constante
                ula.readA(regs.readR(1));
                ula.readB(endereco);
                ula.op(3);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 71://OR B Indexado
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(3);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 72://OR X Direto 
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco));
                ula.op(3);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 73://OR X Indireto
                ula.readA(regs.readR(2));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(3);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 74://OR X Constante
                ula.readA(regs.readR(2));
                ula.readB(endereco);
                ula.op(3);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 75://OR X Indexado
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(3);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 80://AND A Direto
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco));
                ula.op(4);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 81://AND A Indireto
                ula.readA(regs.readR(0));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(4);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 82://ADD A Constante
                ula.readA(regs.readR(0));
                ula.readB(endereco);
                ula.op(4);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 83://ADD A Indexado
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(4);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 84://AND B Direto
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco));
                ula.op(4);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 85://AND B Indireto
                ula.readA(regs.readR(1));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(4);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 86://ADD B Constante
                ula.readA(regs.readR(1));
                ula.readB(endereco);
                ula.op(4);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 87://ADD B Indexado
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(4);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 88://AND X Direto
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco));
                ula.op(4);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 89://AND X Indireto
                ula.readA(regs.readR(2));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(4);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 90://ADD X Constante
                ula.readA(regs.readR(2));
                ula.readB(endereco);
                ula.op(4);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 91://ADD X Indexado
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(4);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 96://NOT A
                ula.readA(regs.readR(0));
                ula.op(5);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 100://NOT B
                ula.readA(regs.readR(1));
                ula.op(5);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 104://NOT X
                ula.readA(regs.readR(2));
                ula.op(5);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 112://SUB A Direto
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco));
                ula.op(2);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 113://SUB A Indireto
                ula.readA(regs.readR(0));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(2);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 114://SUB A Constante
                ula.readA(regs.readR(0));
                ula.readB(endereco);
                ula.op(2);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 115://SUB A Indexado
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(2);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 116://SUB B Direto
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco));
                ula.op(2);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 117://SUB B Indireto
                ula.readA(regs.readR(1));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(2);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 118://SUB B Constante
                ula.readA(regs.readR(1));
                ula.readB(endereco);
                ula.op(2);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 119://SUB B Indexado
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(2);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 120://SUB X Direto
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco));
                ula.op(2);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 121://SUB X Indireto
                ula.readA(regs.readR(2));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(2);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 122://SUB X Constante
                ula.readA(regs.readR(2));
                ula.readB(endereco);
                ula.op(2);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 123://SUB X Indexado
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(2);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 128://JMP Direto
                cont = mem.read(endereco);
                break;
            case 129://JMP Indireto
                cont = mem.read(mem.read(endereco));
                break;
            case 144://JN Direto
                if(ula.getn()){
                    cont = mem.read(endereco);
                }
                break;
            case 145://JN Indireto
                if(ula.getn()){
                    cont = mem.read(mem.read(endereco));
                }
                break;
            case 160://JZ Direto
                if(ula.getz()){
                    cont = mem.read(endereco);
                }
                break;
            case 161://JZ Indireto
                if(ula.getz()){
                    cont = mem.read(mem.read(endereco));
                }
                break;
            case 176://JC Direto
                if(ula.getc()){
                    cont = mem.read(endereco);
                }
                break;
            case 177://JC Indireto
                if(ula.getc()){
                    cont = mem.read(mem.read(endereco));
                }
                break;
            case 192://JSR Direto
                mem.write(mem.read(endereco), cont);
                cont = mem.read(endereco);
                cont++;
                break;
            case 193://JSR Indireto
                mem.write(mem.read(mem.read(endereco)), cont);
                cont = mem.read(mem.read(endereco));
                cont++;
                break;
            case 208://NEG A
                ula.readA(regs.readR(0));
                ula.op(6);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 212://NEG B
                ula.readA(regs.readR(1));
                ula.op(6);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 216://NEG X
                ula.readA(regs.readR(2));
                ula.op(6);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 224://SHR A
                ula.readA(regs.readR(0));
                ula.op(7);
                regs.writeR(regs.readR(0), ula.writeResult());
                break;
            case 228://SHR B
                ula.readA(regs.readR(1));
                ula.op(7);
                regs.writeR(regs.readR(1), ula.writeResult());
                break;
            case 232://SHR X
                ula.readA(regs.readR(2));
                ula.op(7);
                regs.writeR(regs.readR(2), ula.writeResult());
                break;
            case 240://HLT
                lastState = true;
                break;
            default: break;
        }
    }
    else if(cont>=127){
        lastState = true;
    }
}
        
void PC::updateState(){
    EA = PE;  
};
        
bool PC::getLastState() {
    return(lastState);
};