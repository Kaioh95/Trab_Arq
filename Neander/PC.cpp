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

	switch(instrucao)
	{
		case 0: //NOP
		cout<<"NOOOP"<<endl;
		    cont--;
			break;

		case 16: //STA
			mem.set(end, ac.get(0));
			cout<<"STA: end "<<end<<"| value "<<ac.get(0)<< endl;
			break;

		case 32: //LDA
			ac.set(0, mem.get(end));
			cout<<"LDA: end "<<end<<"| value "<<mem.get(end)<< endl;
			break;

		case 48: //ADD
			ula.setA(ac.get(0));
			ula.setB(mem.get(end));
			ula.op(1);
			ac.set(0, ula.getS());
			break;

		case 64: //OR
			ula.setA(ac.get(0));
			ula.setB(mem.get(end));
			ula.op(4);
			ac.set(0, ula.getS());
			break;

		case 80: //AND
			ula.setA(ac.get(0));
			ula.setB(mem.get(end));
			ula.op(5);
			ac.set(0, ula.getS());
			break;

		case 96: //NOT
			ula.setA(ac.get(0));
			ula.op(3);
			ac.set(0, ula.getS());
			break;	

		case 128: //JMP
			cout<<"JMP: end "<<end<<endl;
			cont = end;

			break;

		case 144://JN
			if(ula.getN())
			{
				cout<<"JN: end "<<end<<endl;
				cont = end;
			}
			break;

		case 160: //JZ
			if(ula.getZ())
			{
				cout<<"JZ: end "<<end<<endl;
				cont = end;
			}
			break;

		case 240: //HLT
			cout<<"Fim do programa"<<endl;
			lastState=true;
			break;
		default:
			break;
	}
}

void PC::updateState()
{
	EA = PE;
}

bool PC::getLastState()
{
	return lastState;
}