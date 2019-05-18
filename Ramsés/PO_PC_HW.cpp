#include <iostream>
#include <fstream>
#include "PC.h"

using namespace std;

int main(int argc, char* argv[]){

    ULA *ula = new ULA();
    REGS *regs =  new REGS();
    MEM *mem = new MEM();
    PC *pc = new PC(*ula, *regs, *mem);

    //streampos pos;
    string str;
    string bloco;
    int c = 0;
	//streamsize size;
    ifstream arq("leitura.txt", ios::in);
    if(!arq){
    	cout<<"o arquivo não foi aberto"<<endl;
    	exit(1);
    }
    while(!arq.eof()){
    	getline(arq, str);

    	if(!str.compare("dados")){
    		bloco = str;
    	}
    	else if(!str.compare("cod")){
    		bloco = str;
    	}

    	if(!bloco.compare("dados") && str.compare("dados") && !str.empty()){
    		size_t found = str.find(" ");
    		string end;
    		string dado;
    		int i;
    		for(i = 0; i < (int)found; i++){
    			end.push_back(str[i]);
    		}
    		for(int j = i+1; j < (int)str.size(); j++){
    			dado.push_back(str[j]);
    		}
    		mem->write(atoi(end.c_str()), atoi(dado.c_str()));
    		cout<<"sim "<<str<<endl;
    	}
    	if(!bloco.compare("cod") && str.compare("cod") && !str.empty()){
    		mem->write(c++, atoi(str.c_str()));
    		cout<<"sim "<<str<<endl;
    	}
    }
    /*for(int k = 0; k < 256; k++){
    	cout<<k<<": "<<(mem->read(k))<<endl;
    }*/
    arq.close();

    for(int _clock=0; _clock < 999; _clock++){
        cout<<"sim "<<c<<endl;
        pc->FTE();
        pc->updateState();
    	//cout<<"RA: "<< regs->readR(0) <<" RB: "<< regs->readR(1) <<" RX: "<< regs->readR(2) << endl;
        if(pc->getLastState() == true) break;    
    }
	return 0;      
}
