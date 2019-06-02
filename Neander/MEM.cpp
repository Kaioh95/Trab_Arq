#include "MEM.hpp"

MEM::MEM()
{
	this->mem = new int[256];
	
	for(int i = 0; i < 256; i++){
        mem[i] = 0;
    }
}
MEM::~MEM()
{
	delete[] mem;
}

float MEM::get(int position)
{
	return mem[position];
}

void MEM::set(int position, float v)
{
	mem[position] = v;
}