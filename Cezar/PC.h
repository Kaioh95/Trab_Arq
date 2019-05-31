#include <iostream>
#include <string>
#include "ULA.h"
#include "REGS.h"
#include "MEM.h"

using namespace std;

class PC{
	private:
		REGS * regs;
		MEM * mem;
		ULA * ula;

	public:
		PC(REGS * regs, MEM * mem, ULA * ula);
		~PC();
		int is_dec(char code);
		void decodificar(string code);
		int Buscar_operando(string code);

};