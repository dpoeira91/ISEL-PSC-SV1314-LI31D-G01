#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

unsigned long long max_value(bool sign, size_t nbytes) {
		
	if(nbytes > sizeof(long) || nbytes == 0)
		return 0;
	unsigned long max = (2<<((CHAR_BIT*nbytes)-1))-1;	// colocar todos os bits de nbytes a 1
	return (sign) ? max>>1: max;						// caso (sign) ultimo bit é o bit sinal logo o alcance é menor

}
