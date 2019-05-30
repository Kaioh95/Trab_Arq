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

    // ifstream arq("arquivo.txt", ios::in);

    // if(!arq){
    // 	cout<<"o arquivo não foi aberto"<<endl;
    // 	exit(1);
    // }

    // while(getline(arq, str)){

    // }

    string nao = "N34";
    // string estranha = nao[1];
    cout << "Vamos ver se converte certo, devia ser 3: " << stoi(nao[1]) << endl;
    
	return 0;      
}
