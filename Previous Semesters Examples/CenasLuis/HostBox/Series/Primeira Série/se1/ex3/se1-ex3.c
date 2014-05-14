#include <stdio.h>

typedef struct floatbits {
	unsigned significand : 23; unsigned exponent : 8; unsigned sign : 1;
} floatbits_t; 

float s2f(short int s) {
	floatbits_t f = { 0x7FFFFF, 0xFF, 0x1 };
	unsigned shortBitSize = 0;
	short int aux = s;
	if (aux){
		while(aux>>=1){
			++shortBitSize;
		}
		f.exponent = shortBitSize + 127;
	}
	else
		f.exponent = 0;
	f.sign = f.sign & s>>15;
	f.significand = ((1<<shortBitSize)-s)<<(23-shortBitSize);
	return *(float*)&f;
}
