#include "PC.h"

PC::PC(ULA &u, AC &a, MEM &m)
{
	ula = u;
	ac = a;
	mem = m;

	cont = 0;
	EA = 0;
	lastState = false;
}

void PC::FTE()
{
	int instrucao = mem.get(cont);
	cont++;
	int end = mem.get(cont);
	cont++;
	clock += 3;

	switch(instrucao)
	{
		case 0: //NOP
		cout<<"NOOOP"<<endl;
		    cont--;
			break;

		case 16: //STA
			ula.setB(ac.get(0));
			ula.op(0);
			mem.set(end, ac.get(0));
			cout<<"STA: end "<<end<<"| value "<<ac.get(0)<< endl;
			clock += 3;
			break;

		case 32: //LDA
			ula.setB(mem.get(end));
			ula.op(0);
			ac.set(0, mem.get(end));
			cout<<"LDA: end "<<end<<"| value "<<mem.get(end)<< endl;
			clock += 3;
			break;

		case 48: //ADD
			ula.setA(ac.get(0));
			ula.setB(mem.get(end));
			ula.op(1);
			ac.set(0, ula.getS());
			clock += 3;
			break; 

		case 64: //OR
			ula.setA(ac.get(0));
			ula.setB(mem.get(end));
			ula.op(4);
			ac.set(0, ula.getS());
			clock += 3;
			break;

		case 80: //AND
			ula.setA(ac.get(0));
			ula.setB(mem.get(end));
			ula.op(5);
			ac.set(0, ula.getS());
			clock += 3;
			break;

		case 96: //NOT
			ula.setA(ac.get(0));
			ula.op(2);
			ac.set(0, ula.getS());
			clock += 1;
			break;	

		case 128: //JMP
			cout<<"JMP: end "<<end<<endl;
			clock += 1;
			cont = end;
			break;

		case 144://JN
			if(ula.getN())
			{
				cout<<"JN: end "<<end<<endl;
				cont = end;
			}
			clock += 1;
			break;

		case 160: //JZ
			if(ula.getZ())
			{
				cout<<"JZ: end "<<end<<endl;
				cont = end;
			}
			clock += 1;
			break;

		case 240: //HLT
			cout<<"Fim do programa"<<endl;
			lastState=true;
			break;

		default:
			break;
	}
	cout<<"Clock total: "<<clock << endl;
}

void PC::updateState()
{
	EA = PE;
}

bool PC::getLastState()
{
	return lastState;
}