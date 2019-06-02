#ifndef PC_H
#define PC_H

#include "AC.h"
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
		int clock = 0;
		ULA ula;
		AC ac;
		MEM mem;

		PC(ULA &u, AC &a, MEM &m);
		void FTE();
		void updateState();
		bool getLastState();
};

#endif