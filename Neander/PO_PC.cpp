#include "PC.h"

#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
	ULA *ula = new ULA();
    AC *ac =  new AC();
    MEM *mem = new MEM();
    PC *pc = new PC(*ula, *ac, *mem);


    //Dados
    ifstream dados("dados.txt");

    string line;
    int c = 0;

    if (!dados)
    {
        cout<<"Erro ao abrir arquivo"<<endl;
        return -1;
    }
    while(getline(dados, line))
    {
        if (!line.empty())
        {
            size_t found = line.find(" ");
            string end;
            string dado;
            int i;
            
            for(i = 0; i < (int)found; i++)end.push_back(line[i]);

            for(int j = i+1; j < (int)line.size(); j++)dado.push_back(line[j]);

            mem->set(atoi(end.c_str()), atoi(dado.c_str()));
        }
    }
    dados.close();


    //Funcoes
    ifstream func("func2.txt");

    if (!func) {
        cout<<"Erro ao abrir arquivo"<<endl;
        return -1;
    }
    while(getline(func, line))
    {
        if (!line.empty())mem->set(c++, atoi(line.c_str()));
    }

    func.close();

    for(int clock=0; clock < 100; clock++)
    {
        pc->FTE();
        pc->updateState();

        if (pc->getLastState() == true)break;

        cout<<"value_AC: "<<ac->get(0)<< endl << endl;
    }

    for(int i = 0; i < 256; i++){
        cout<<i<<": "<< mem->get(i) <<endl;
    }

    cout<<endl;
    return 0;
}