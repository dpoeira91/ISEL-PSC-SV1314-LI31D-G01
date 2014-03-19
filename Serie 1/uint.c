#include <stdio.h>
#include <stdbool.h>

/*
sign   exponent(8bits)    fraction(23bits)
|           |                    |
0       11111111       00000000000000000000000

source:http://en.wikipedia.org/wiki/Single-precision_floating-point_format
*/

#define signMask 0x80000000
#define exponentMask 0x7F800000
#define fractionMask 0x007FFFFF

bool is_uint(float f);

int main(){
	float toTest;
	toTest = 1.0;
	is_uint(toTest);
	return 0;
}

bool is_uint(float f){
	unsigned int sign = f & signMask;
//	unsigned int fraction = f & fractionMask;
	unsigned int exponent = f & exponentMask;

	if(sign == 1 || exponent != 0)
		return false;	

/* Um float e escrito em binario mas esta "dividido" em 3 partes:
		sinal, expoente e parte significativa.
		1 bit para o sinal + 23 bits para a parte significativa + 8 para o expoente = 32bits

	   - Verificar se o sinal e 1, se for, retorna false
	   - Fazer uma mascara com 8bits a zero e comparar com a parte do expoente, se for != 0 retorna false
	*/
	return true;
}
