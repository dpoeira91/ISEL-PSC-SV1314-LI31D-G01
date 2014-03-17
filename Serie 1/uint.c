#include <stdio.h>

bool is_uint(float f);

int main(){
	float toTest;
	is_uint(toTest);
	return 0;
}

bool is_uint(float f){
	/* Um float e escrito em binario mas esta "dividido" em 3 partes:
		sinal, expoente e parte significativa.
		1 bit para o sinal + 23 bits para a parte significativa + 8 para o expoente = 32bits

	   - Verificar se o sinal e 1, se for, retorna false
	   - Fazer uma mascara com 8bits a zero e comparar com a parte do expoente, se for != 0 retorna false
	*/


	return true;
}
