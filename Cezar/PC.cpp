#include "PC.h"

PC::PC(REGS* regs, MEM * mem, ULA * ula){
	this->regs = regs;
	this->mem = mem;
	this->ula = ula;
};

PC::~PC(){

};

void PC::decodificar(string code){
	string code_;
	int i = 0;
	while(code[i] != ' '){
		code_[i] = code[i];
		i++;
	}
};

int PC::Buscar_operando(string code){
	// Modo direto, pego o valor do registrador.
	if (code[0] == 'R'){
		return(regs->readR(static_cast<char>(code[1])));
	}
	if (code[0] == '(' and code[3] == ')'){
		// Modo indexado indireto
		if(code.size() == 3){
			return mem->read(regs->readR(static_cast<char>(code[1])));
		}
	}
};

