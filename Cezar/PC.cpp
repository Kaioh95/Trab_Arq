#include "PC.h"

PC::PC(REGS* regs, MEM * mem, ULA * ula){
	this->regs = regs;
	this->mem = mem;
	this->ula = ula;
};

PC::~PC(){

};



// Métodos auxiliares
int PC::is_dec(char code){
	if (code =='0'){
		return 0;
	}
	if (code =='1'){
		return 1;
	} 
	if (code =='2'){
		return 2;
	} 
	if (code =='3'){
		return 3;
	} 
	if (code =='4'){
		return 4;
	} 
	if (code =='5'){
		return 5;
	}
	if (code =='6'){
		return 6;
	}
	if (code =='7'){
		return 7;
	}
	cout << "Código Inválido" << endl;
	exit(4);
}

void PC::decodificar(string code){
	string code_;
	int i = 0;
	while(code[i] != ' ' and code[i] != '\0'){
		code_.append(code,i, 1);
		i++;
		// Instrução de Parada
	}
	cout << "Code_: "<< code_ << endl;
	if (code_ =="HLT"){
			exit(2);
		}
		// Instrução de NOP
		if (code_ =="HLT"){
			system("sleep 1");
			return;
		}
		// Instrução de JUMP
		if (code_ =="BR"){

		}
		if (code_ =="BNE"){

		}
		if (code_ =="BEQ"){

		}
		if (code_ =="BPL"){

		}
		if (code_ =="BMI"){

		}
		if (code_ =="BVC"){

		}
		if (code_ =="BCC"){

		}
		if (code_ =="BCS"){

		}
		if (code_ =="BGE"){

		}
		if (code_ =="BLT"){

		}
		if (code_ =="BGT"){

		}
		if (code_ =="BLE"){

		}
		if (code_ =="BHI"){

		}
		if (code_ =="BLS"){

		}
		if (code_ =="JMP"){

		}
		// Instrução de laço de repetição
		if (code_ =="SOB"){

		}
		// Instrução de subrotina
		if (code_ =="JSR"){

		}
		if (code_ =="RTS"){

		}
		// Instruções de um operando
		if (code_ =="CLR"){

		}
		if (code_ =="NOT"){

		}
		if (code_ =="INC"){

		}
		if (code_ =="DEC"){

		}
		if (code_ =="NEG"){

		}
		if (code_ =="TST"){

		}
		if (code_ =="ROR"){

		}
		if (code_ =="ROL"){

		}
		if (code_ =="ASR"){

		}
		if (code_ =="ASL"){

		}
		if (code_ =="ADC"){

		}
		if (code_ =="SBC"){

		}
		// Instruções de dois operandoS
		if (code_ =="MOV"){

		}
		if (code_ =="ADD"){

		}
		if (code_ =="SUB"){

		}
		if (code_ =="CMP"){

		}
		if (code_ =="AND"){

		}
		if (code_ =="OR"){

		}
		cout << "Código inválido: " << 	code << endl;
		exit(3);		
};

int PC::Buscar_operando(string code){

	// Modo direto, pego o valor do registrador.
	if (code[0] == 'R'){
		return(regs->readR(is_dec(static_cast<char>(code[1]))));
	}
	if (code[0] == '(' and code[3] == ')' and code[1] == 'R'){
		// Modo indexado
		if(code.size() == 3){
			return mem->read(regs->readR(is_dec(static_cast<char const>(code[2]))));
		}
		// Modo Pós-incrementado
		if (code[4]=='+' and code.size() == 5){
			int numero = regs->readR(is_dec(static_cast<char const>(code[2])));
			regs->writeR(is_dec(static_cast<char const>(code[2])),regs->readR(is_dec(static_cast<char const>(code[2]))) + 1 );
			return mem->read(numero);
		}
		// Modo Pós-Incrementado indireto
		if(code[4] == '+' and code[5] == 'I'){
			int numero = regs->readR(is_dec(static_cast<char const>(code[2])));
			numero = mem->read(numero);
			regs->writeR(is_dec(static_cast<char const>(code[2])),regs->readR(is_dec(static_cast<char const>(code[2]))) + 1 );
			return mem->read(numero);
		}
	}
	if(code[0]== '-' and code[2] == 'R'){
		// Registrador Pré-decrementado.
		if(code.size() == 5){
			int numero = regs->readR(is_dec(static_cast<char const>(code[2])));
			numero -= 1;
			regs->writeR(is_dec(static_cast<char const>(code[2])),regs->readR(is_dec(static_cast<char const>(code[2]))) - 1 );
			return mem->read(numero);
		}
		// Registrador Pré-decrementado indireto.
		if (code.size() == 6 and code[5] == 'I'){
			int numero = regs->readR(is_dec(static_cast<char const>(code[2])));
			numero -= 1;
			numero = mem->read(numero);
			regs->writeR(is_dec(static_cast<char const>(code[2])),regs->readR(is_dec(static_cast<char const>(code[2]))) - 1 );
			return mem->read(numero);
		}
	}
	if(code[code.size()-1] == ')'){
		// Registrador Indexado indireto

	}

};

