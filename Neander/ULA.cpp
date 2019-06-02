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
			s = b;
			break;
		case 1:
			cout<<"ULA: "<<a<<" + "<<b<<endl;
			s = a + b;
			break;
		case 2:
			cout<<"ULA: NOT "<<a<< endl;
			s = -a - 1;
			break;
		case 3:
			cout<<"ULA: OR"<<endl;
			s = (a || b);
			break;
		case 4:
			cout<<"ULA: AND"<<endl;
			s = (a && b);
		default:
			break;
	}

	if(s < 0){
        n = true;
        z = false;
    }
    
    else if(s == 0){
        z = true;
        n = false;
    }
    else{
        z = false;
        n = false;     
    }
    cout<<"N: "<< n 
        <<" Z: "<< z << endl;
}