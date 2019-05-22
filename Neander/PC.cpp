#include "PC.h"

PC::PC(ULA &u, REGS &r, MEM &m)
{
	ula = u;
	regs = r;
	mem = m;

	cont = 0;
	EA = 0;
	lastState = false;
}

void PC::FTE()
{
	int instrucao = mem.get(cont);
	cout<<cont<<": "<<mem.get(cont)<<endl;
	cont++;
	int end = mem.get(cont);
	cont++;

	switch(instrucao)
	{
		case 0: //NOP
		    cont--;
			break;

		case 16: //STA
			mem.set(end, regs.get(0));
			break;

		case 32: //LDA
			regs.set(0, mem.get(end));
			break;

		case 48: //ADD
			ula.setA(regs.get(0));
			ula.setB(mem.get(end));
			ula.op(1);
			//cout<<"ula getS: "<<ula.getS()<<endl;
			regs.set(0, ula.getS());
			break;

		case 64: //OR
			ula.setA(regs.get(0));
			ula.setB(mem.get(end));
			ula.op(4);
			regs.set(0, ula.getS());
			break;

		case 80: //AND
			ula.setA(regs.get(0));
			ula.setB(mem.get(end));
			ula.op(5);
			regs.set(0, ula.getS());
			break;

		case 96: //NOT
			ula.setA(regs.get(0));
			ula.op(3);
			regs.set(0, ula.getS());
			break;	

		case 128: //JMP
			cont = mem.get(end);

			break;

		case 144://JN
			if(ula.getN())
			{
				cont = mem.get(end);
			}
			break;

		case 160: //JZ
			if(ula.getZ())
			{
				cont = mem.get(end);
			}
			break;

		case 240: //HLT
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