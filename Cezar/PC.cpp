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
	if (code_ =="HLT"){
			regs->writeR(7, regs->readR(7)+1);
			cout << "Comando: "<< code_ << endl;
			exit(2);
		}
		// Instrução de NOP
		if (code_ =="NOP"){
			regs->writeR(7, regs->readR(7)+1);			
			cout << "Comando: "<< code_ << endl;
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
			regs->writeR(7, regs->readR(7)+2);
			MOV(code, code_);
			return;
		}
		if (code_ =="ADD"){
			regs->writeR(7, regs->readR(7)+2);	

		}
		if (code_ =="SUB"){
			regs->writeR(7, regs->readR(7)+2);	

		}
		if (code_ =="CMP"){
			regs->writeR(7, regs->readR(7)+2);	

		}
		if (code_ =="AND"){
			regs->writeR(7, regs->readR(7)+2);	

		}
		if (code_ =="OR"){
			regs->writeR(7, regs->readR(7)+2);	

		}
		cout << "Código inválido: " << 	code << endl;
		exit(3);		
};

void PC::MOV(string code, string subcode){
	code.erase(0, subcode.size()+1);
	string str_2 = "";
	string str_1 = "";
	int i = 0;
	while(code[i]!= ',' and code[i] != '\n'){
		str_1.append(code,i, 1);
		i++;
	}
	i = 0;
	code.erase(0,str_1.size()+1);
	cout << "Buscou o primeiro:" << str_1 << endl << "Tamanho: " << str_1.size() << endl;
	int Operando_1 = Buscar_operando(str_1);
	cout << "Entrou Aqui" << endl;
	while(code[i]!= ',' and code[i] != '\0' and code[i] != ' '){
		str_2.append(code,i, 1);
		i++;
	}
	cout << "Buscou o Segundo: " << str_2 << endl;
	int Operando_2 = Buscar_operando(str_2);
	Buscar_destino(str_2, Operando_1);
}



int PC::Buscar_operando(string code){

	// Modo direto, pego o valor do registrador.
	if (code[0] == 'R'){
		return(regs->readR(is_dec(static_cast<char>(code[1]))));
	}
	else if (code[0] == '(' and code[3] == ')' and code[1] == 'R'){
		// Modo indireto
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
	else if(code[0] == '-'){
		// Modo Pré-decrementado.
		if(code.size() == 5){
			int numero = regs->readR(is_dec(static_cast<char const>(code[2])));
			numero -= 1;
			regs->writeR(is_dec(static_cast<char const>(code[2])),regs->readR(is_dec(static_cast<char const>(code[2]))) - 1 );
			return mem->read(numero);
		}
		// Modo Pré-decrementado indireto.
		if (code.size() == 6 and code[5] == 'I'){
			int numero = regs->readR(is_dec(static_cast<char const>(code[2])));
			numero -= 1;
			numero = mem->read(numero);
			regs->writeR(is_dec(static_cast<char const>(code[2])),regs->readR(is_dec(static_cast<char const>(code[2]))) - 1 );
			return mem->read(numero);
		}
	}
	// Modo Indexado
	else if(code[code.size()-1] == ')' and code[code.size()-3] == 'R'){
		string str = "";
		str.append(code, 0, code.size()-5);
		int numero = regs->readR(is_dec(static_cast<char const>(code[2])));
		numero += stoi(str);
		return mem->read(numero);
	}
	// Modo indexado indireto
	else if(code[code.size()-1] == 'I' and code[code.size()-4] == 'R'){
		string str = "";
		str.append(code, 0, code.size()-6);
		int numero = regs->readR(is_dec(static_cast<char const>(code[2])));
		numero += stoi(str);
		numero = mem->read(numero);
		return mem->read(numero);
	}
	else{
		cout << "Registrador inválido" << endl;
		exit(6);
	}

};

void PC::Buscar_destino(string code, int value){

	// Modo direto, pego o valor do registrador.
	if (code[0] == 'R'){
		regs->writeR(is_dec(static_cast<char>(code[1])), value);
	}
	else if (code[0] == '(' and code[3] == ')' and code[1] == 'R'){
		// Modo indireto
		if(code.size() == 3){
			mem->write(regs->readR(is_dec(static_cast<char const>(code[2]))), value);
		}
		// Modo Pós-incrementado
		if (code[4]=='+' and code.size() == 5){
			int numero = regs->readR(is_dec(static_cast<char const>(code[2]))) - 1;
			mem->write(numero, value);
		}
		// Modo Pós-Incrementado indireto
		if(code[4] == '+' and code[5] == 'I'){
			int numero = regs->readR(is_dec(static_cast<char const>(code[2]))) - 1;
			numero = mem->read(numero);
			mem->write(numero, value);
		}
	}
	else if(code[0]== '-' and code[2] == 'R'){
		// Modo Pré-decrementado.
		if(code.size() == 5){
			int numero = regs->readR(is_dec(static_cast<char const>(code[2])));
			mem->write(numero, value);
		}
		// Modo Pré-decrementado indireto.
		if (code.size() == 6 and code[5] == 'I'){
			int numero = regs->readR(is_dec(static_cast<char const>(code[2])));
			numero = mem->read(numero);
			mem->write(numero, value);
		}
	}
	// Modo Indexado
	else if(code[code.size()-1] == ')' and code[code.size()-3] == 'R'){
		string str = "";
		str.append(code, 0, code.size()-5);
		int numero = regs->readR(is_dec(static_cast<char const>(code[2])));
		numero += stoi(str);
		mem->write(numero, value);
	}
	// Modo indexado indireto
	else if(code[code.size()-1] == 'I' and code[code.size()-4] == 'R'){
		string str = "";
		str.append(code, 0, code.size()-6);
		int numero = regs->readR(is_dec(static_cast<char const>(code[2])));
		numero += stoi(str);
		numero = mem->read(numero);
		mem->write(numero, value);
	}
	else{
		cout << "Registrador inválido" << endl;
		exit(6);
	}

};

