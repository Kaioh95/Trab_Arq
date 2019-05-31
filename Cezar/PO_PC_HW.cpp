#include <iostream>
#include <fstream>
#include "PC.h"

using namespace std;

int main(int argc, char* argv[]){

    REGS *regs =  new REGS();
    ULA *ula = new ULA(regs);
    MEM *mem = new MEM();
    PC *pc = new PC(regs, mem, ula);

    string str;
    string bloco;
    int c = 0;

    ifstream arq("leitura1.txt", ios::in);

    if(!arq){
    	cout<<"o arquivo não foi aberto"<<endl;
    	exit(1);
    }


    while(getline(arq, str)){
        pc->decodificar(str);
    }
    
	return 0;      
}
