#include <stdio.h>

float raiz(float x);

float absF(float x);

int main(void){
	float n;								
	printf("\n\nForneça um número que deseja calcular a raiz quadrada: ");
	scanf("%f",&n);
	printf("\n\nA raiz quadrada de %.5f é %.12f\n\n",n,raiz(n));
	return(0);

}

/* Calcula Valor absoluto para tipo float */
float absF(float x) {
	if(x < 0)								
		return(-1*x);							
	else
		return(x);							
}

/* Calcula a Raiz Quadrada */
float raiz(float x){
	float r = 1.00; /* Chute inicial */
	float rp, res;
	float auxiliar;								
	int sair = 0;

	while(!sair) {
		auxiliar = r*r;
		auxiliar = x - auxiliar;
		rp = r+r;
		auxiliar = auxiliar / rp;
		res = r + auxiliar;
		/* Checa resulado */

		rp = res * res;
		auxiliar = rp - r;
		auxiliar = auxiliar == 0;
		printf("\n?? %.2f \n", auxiliar);
		rp = r == res;
		if(auxiliar || rp)
		sair = 1;
		r = res;
		// Vai pro estado 0;
	}

	return(res);

}