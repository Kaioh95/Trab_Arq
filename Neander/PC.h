#ifndef PC_H
#define PC_H

#include "REGS.h"
#include "ULA.h"
#include "MEM.hpp"

#include <string>
#include <iostream>

using namespace std;

class PC
{
	public:
		int EA;
		int PE;
		bool lastState;
		int cont;
		ULA ula;
		REGS regs;
		MEM mem;

		PC(ULA &u, REGS &r, MEM &m);
		void FTE();
		void updateState();
		bool getLastState();
};

#endif