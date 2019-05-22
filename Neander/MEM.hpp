#ifndef MEM_H
#define MEM_H

class MEM
{
public:
	int *mem;

	MEM();
	~MEM();
	float get(int position);
	void set(int position, float v);
};

#endif