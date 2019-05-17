#include "MEM.h"

MEM::MEM(){
    mem = new int[256];
};
MEM::~MEM(){
	delete[] mem;
}
    
int MEM::read(int _adress){
    return (mem[_adress]);
};
    
void MEM::write(int _adress, int _v){
    mem[_adress]= _v;
};