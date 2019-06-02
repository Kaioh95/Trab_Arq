#include "PC.h"

PC::PC(ULA &_ula, REGS &_regs, MEM &_mem) {
        ula= _ula; regs= _regs;  mem = _mem;
        lastState= false;
};

void PC::FTE(){
    if(cont <= 127 && !lastState){
        int instrucao = mem.read(cont);
        cont++;
        int endereco = mem.read(cont);
        cont++;
        cout<<"Contador de Programa: "<<cont<<endl;
        clock += 3;

        switch (instrucao){
            case 0://NOP
                cout<<"NOP: "<<instrucao<<endl;
                cont--;
                break; 
            case 16://STA direto
                cout<<"STA: "<<instrucao<<", endereco: "<<endereco<<endl;
                mem.write(endereco, regs.readR(0));
                clock += 3;
                break;
            case 17://STA Indireto
                cout<<"STA, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                mem.write(mem.read(endereco), regs.readR(0));
                clock += 3;
                break;
            case 19://STA Indexado
                cout<<"STA indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                mem.write(mem.read(endereco+regs.readR(2)), regs.readR(0));
                clock += 3;
                break;
            case 20://STB direto
                cout<<"STB: "<<instrucao<<", endereco: "<<endereco<<endl;
                mem.write(endereco, regs.readR(1));
                clock += 3;
                break;
            case 21://STB Indireto
                cout<<"STB, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                mem.write(mem.read(endereco), regs.readR(1));
                clock += 3;
                break;
            case 23://STB Indexado
                cout<<"STA indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                mem.write(mem.read(endereco+regs.readR(2)), regs.readR(1));
                clock += 3;
                break;
            case 24://STX direto
                cout<<"STX: "<<instrucao<<", endereco: "<<endereco<<endl;
                mem.write(endereco, regs.readR(2));
                clock += 3;
                break;
            case 25://STX Indireto
                cout<<"STX, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                mem.write(mem.read(endereco), regs.readR(2));
                clock += 3;
                break;
            case 27://STX Indexado
                cout<<"STX, indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                mem.write(mem.read(endereco+regs.readR(2)), regs.readR(2));
                clock += 3;
                break;
            case 32://LDA direto
                cout<<"LDA: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readB(mem.read(endereco));
                ula.op(0);
                regs.writeR(0, mem.read(endereco));
                clock += 3;
                break;
            case 33://LDA Indireto
                cout<<"LDA, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(0);
                regs.writeR(0, mem.read(mem.read(endereco)));
                clock += 3;
                break;
            case 34://LDA constante
                cout<<"LDA: "<<instrucao<<", #"<<endereco<<endl;
                ula.readB(endereco);
                ula.op(0);
                regs.writeR(0, endereco);
                clock += 3;
                break;
            case 35://LDA Indexado
                cout<<"LDA, indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readB(mem.read(mem.read(endereco + regs.readR(2))));
                ula.op(0);
                regs.writeR(0, mem.read(mem.read(endereco + regs.readR(2))));
                clock += 3;
                break;
            case 36://LDB direto
                cout<<"LDB: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readB(mem.read(endereco));
                ula.op(0);
                regs.writeR(1, mem.read(endereco));
                clock += 3;
                break;
            case 37://LDB Indireto
                cout<<"LDB, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(0);
                regs.writeR(1, mem.read(mem.read(endereco)));
                clock += 3;
                break;
            case 38://LDB constante
                cout<<"LDB: "<<instrucao<<", #"<<endereco<<endl;
                ula.readB(endereco);
                ula.op(0);
                regs.writeR(1, endereco);
                clock += 3;
                break;
            case 39://LDB Indexado
                cout<<"LDB indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readB(mem.read(mem.read(endereco + regs.readR(2))));
                ula.op(0);
                regs.writeR(1, mem.read(mem.read(endereco + regs.readR(2))));
                clock += 3;
                break;
             case 40://LDX direto
                cout<<"LDB: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readB(mem.read(endereco));
                ula.op(0);
                regs.writeR(2, mem.read(endereco));
                clock += 3;
                break;
            case 41://LDX Indireto
                cout<<"LDB, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(0);
                regs.writeR(2, mem.read(mem.read(endereco)));
                clock += 3;
                break;
            case 42://LDX constante
                cout<<"LDB: "<<instrucao<<", #"<<endereco<<endl;
                ula.readB(endereco);
                ula.op(0);
                regs.writeR(2, endereco);
                clock += 3;
                break;
            case 43://LDX Indexado
                cout<<"LDX indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readB(mem.read(mem.read(endereco + regs.readR(2))));
                ula.op(0);
                regs.writeR(2, mem.read(mem.read(endereco + regs.readR(2))));
                clock += 3;
                break;
            case 48://ADD A Direto
                cout<<"ADD A: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco));
                ula.op(1);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 49://ADD A Indireto
                cout<<"ADD A, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(1);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 50://ADD A Constante
                cout<<"ADD A: "<<instrucao<<", #"<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(endereco);
                ula.op(1);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 51://ADD A Indexado
                cout<<"ADD A indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(1);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 52://ADD B Direto
                cout<<"ADD B: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco));
                ula.op(1);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 53://ADD B Indireto
                cout<<"ADD B, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(1);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 54://ADD B Constante
                cout<<"ADD B: "<<instrucao<<", #"<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(endereco);
                ula.op(1);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 55://ADD B Indexado
                cout<<"ADD B indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(1);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 56://ADD X Direto
                cout<<"ADD X: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco));
                ula.op(1);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 57://ADD X Indireto
                cout<<"ADD X, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(1);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 58://ADD X Constante
                cout<<"ADD X: "<<instrucao<<", #"<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(endereco);
                ula.op(1);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 59://ADD X Indexado
                cout<<"ADD X indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(1);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 64://OR A Direto
                cout<<"OR A: "<<instrucao<<", endereco: "<<endereco<<endl; 
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco));
                ula.op(3);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 65://OR A Indireto
                cout<<"OR A, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(3);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 66://OR A Constante
                cout<<"OR A: "<<instrucao<<", #"<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(endereco);
                ula.op(3);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 67://OR A Indexado
                cout<<"OR A indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(3);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 68://OR B Direto
                cout<<"OR B: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco));
                ula.op(3);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 69://OR B indireto
                cout<<"OR B, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(3);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 70://OR B Constante
                cout<<"OR B: "<<instrucao<<", #"<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(endereco);
                ula.op(3);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 71://OR B Indexado
                cout<<"OR B indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(3);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 72://OR X Direto
                cout<<"OR X: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco));
                ula.op(3);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 73://OR X Indireto
                cout<<"OR X: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(3);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 74://OR X Constante
                cout<<"OR X: "<<instrucao<<", #"<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(endereco);
                ula.op(3);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 75://OR X Indexado
                cout<<"OR X indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(3);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 80://AND A Direto
                cout<<"AND A: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco));
                ula.op(4);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 81://AND A Indireto
                cout<<"AND A, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(4);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 82://AND A Constante
                cout<<"AND A: "<<instrucao<<", #"<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(endereco);
                ula.op(4);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 83://AND A Indexado
                cout<<"AND A indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(4);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 84://AND B Direto
                cout<<"AND B: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco));
                ula.op(4);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 85://AND B Indireto
                cout<<"AND B, I"<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(4);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 86://AND B Constante
                cout<<"AND B: "<<instrucao<<", #"<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(endereco);
                ula.op(4);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 87://AND B Indexado
                cout<<"AND B indexado"<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(4);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 88://AND X Direto
                cout<<"AND X: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco));
                ula.op(4);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 89://AND X Indireto
                cout<<"AND X, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(4);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 90://AND X Constante
                cout<<"AND X: "<<instrucao<<", #"<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(endereco);
                ula.op(4);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 91://AND X Indexado
                cout<<"AND X indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(4);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 96://NOT A
                cout<<"NOT A: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.op(5);
                regs.writeR(0, ula.writeResult());
                clock += 1;
                break;
            case 100://NOT B
                cout<<"NOT B: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.op(5);
                regs.writeR(1, ula.writeResult());
                clock += 1;
                break;
            case 104://NOT X
                cout<<"NOT X: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.op(5);
                regs.writeR(2, ula.writeResult());
                clock += 1;
                break;
            case 112://SUB A Direto
                cout<<"SUB A: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco));
                ula.op(2);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 113://SUB A Indireto
                cout<<"SUB A, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(2);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 114://SUB A Constante
                cout<<"SUB A: "<<instrucao<<", #"<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(endereco);
                ula.op(2);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 115://SUB A Indexado
                cout<<"SUB A indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(2);
                regs.writeR(0, ula.writeResult());
                clock += 3;
                break;
            case 116://SUB B Direto
                cout<<"SUB B:"<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco));
                ula.op(2);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 117://SUB B Indireto
                cout<<"SUB B, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(2);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 118://SUB B Constante
                cout<<"SUB B"<<instrucao<<", #"<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(endereco);
                ula.op(2);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 119://SUB B Indexado
                cout<<"SUB B indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(2);
                regs.writeR(1, ula.writeResult());
                clock += 3;
                break;
            case 120://SUB X Direto
                cout<<"SUB X: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco));
                ula.op(2);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 121://SUB X Indireto
                cout<<"SUB X, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(mem.read(mem.read(endereco)));
                ula.op(2);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 122://SUB X Constante
                cout<<"SUB X: "<<instrucao<<", #"<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(endereco);
                ula.op(2);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 123://SUB X Indexado
                cout<<"SUB X indexado: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.readB(mem.read(endereco + regs.readR(2)));
                ula.op(2);
                regs.writeR(2, ula.writeResult());
                clock += 3;
                break;
            case 128://JMP Direto
                cout<<"JMP Direto: "<<instrucao<<", endereco: "<<endereco<<endl;
                cont = endereco;
                clock += 1;
                break;
            case 129://JMP Indireto
                cout<<"JMP, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                cont = mem.read(endereco);
                clock += 3;
                break;
            case 144://JN Direto
                cout<<"JN: "<<instrucao<<", endereco: "<<endereco<<endl;
                if(ula.getn()){
                    cont = endereco;
                }
                clock += 1;
                break;
            case 145://JN Indireto
                cout<<"JN, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                if(ula.getn()){
                    cont = mem.read(endereco);
                }
                clock += 3;
                break;
            case 160://JZ Direto
                cout<<"JZ: "<<instrucao<<", endereco: "<<endereco<<endl;
                if(ula.getz()){
                    cont = endereco;
                }
                clock += 1;
                break;
            case 161://JZ Indireto
                cout<<"JZ, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                if(ula.getz()){
                    cont = mem.read(endereco);
                }
                clock += 3;
                break;
            case 176://JC Direto
                cout<<"JC: "<<instrucao<<", endereco: "<<endereco<<endl;
                if(ula.getc()){
                    cont = endereco;
                }
                clock += 1;
                break;
            case 177://JC Indireto
                cout<<"JC, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                if(ula.getc()){
                    cont = mem.read(endereco);
                }
                clock += 3;
                break;
            case 192://JSR Direto
                cout<<"JSR: "<<instrucao<<", endereco: "<<endereco<<endl;
                mem.write(endereco, cont);
                cont = endereco;
                cont++;
                clock += 1;
                break;
            case 193://JSR Indireto
                cout<<"JSR, I: "<<instrucao<<", endereco: "<<endereco<<endl;
                mem.write(mem.read(endereco), cont);
                cont = mem.read(endereco);
                cont++;
                clock += 3;
                break;
            case 208://NEG A
                cout<<"NEG A: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.op(6);
                regs.writeR(0, ula.writeResult());
                clock += 1;
                break;
            case 212://NEG B
                cout<<"NEG B: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.op(6);
                regs.writeR(1, ula.writeResult());
                clock += 1;
                break;
            case 216://NEG X
            cout<<"NEG X: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.op(6);
                regs.writeR(2, ula.writeResult());
                clock += 1;
                break;
            case 224://SHR A
            cout<<"SHR A: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(0));
                ula.op(7);
                regs.writeR(0, ula.writeResult());
                clock += 1;
                break;
            case 228://SHR B
            cout<<"SHR B: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(1));
                ula.op(7);
                regs.writeR(1, ula.writeResult());
                clock += 1;
                break;
            case 232://SHR X
            cout<<"SHR X: "<<instrucao<<", endereco: "<<endereco<<endl;
                ula.readA(regs.readR(2));
                ula.op(7);
                regs.writeR(2, ula.writeResult());
                clock += 1;
                break;
            case 240://HLT
            cout<<"HLT: "<<instrucao<<", endereco: "<<endereco<<endl;
                lastState = true;
                break;
            default: break;
        }
        cout<<"Clock total: "<< clock << endl;
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