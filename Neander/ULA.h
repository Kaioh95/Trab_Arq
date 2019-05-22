#ifndef ULA_H
#define ULA_H

class ULA
{
public:
	float a, b, s;
	bool n, z;


	ULA();

	void setA(float a);
	void setB(float b);

	float getS(void);

	bool getZ(void);
	bool getN(void);

	void op(int op);
};

#endif