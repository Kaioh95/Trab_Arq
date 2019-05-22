#include "ULA.h"

ULA::ULA()
{
	z = false;
	n = false;
}

void ULA::setA(float a)
{
	this->a = a;
}

void ULA::setB(float b)
{
	this->b = b;
}

float ULA::getS(void)
{
	return this->s;
}

bool ULA::getZ(void)
{
	return this->z;
}

bool ULA::getN(void)
{
	return this->n;
}

void ULA::op(int op)
{
	switch(op)
	{
		case 0:
			break;
		case 1:
			s = a + b;
			break;
		case 2:
			s = a - b;
			break;
		case 3:
			s = -a - 1;
			break;
		case 4:
			s = (a || b);
			break;
		case 5:
			s = (a && b);
		default:
			break;
	}
}