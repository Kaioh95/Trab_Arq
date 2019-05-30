#include "MEM.h"

MEM::MEM(){
    mem = new int[256];
    for(int i=0; i<256; i++){
    	mem[i] = 0;
    }
};
MEM::~MEM(){
	delete[] mem;
}
    
int MEM::read(int _adress)const{
    return (mem[_adress]);
};
    
void MEM::write(int _adress, int _v){
    mem[_adress]= _v;
};