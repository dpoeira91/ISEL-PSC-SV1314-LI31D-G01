#include <stdio.h>

struct F{
	unsigned significand : 23;
	unsigned exponent : 8;
	unsigned signal : 1;
};
	
union floatbits{
	float value;
	struct F f;
};

float fsum(float f1, float f2){
	//unsigned res = 0x7FFFFFFF;
	//return *(float*)&res;
	
	union floatbits fa, fb; 
	union floatbits res;
	fa.value = f1;
	fb.value = f2;

	if(fa.f.signal == fb.f.signal){ // sinal igual e expoente igual
		res.f.signal = fa.f.signal;
		if(fa.f.exponent == fb.f.exponent){
			res.f.exponent = fa.f.exponent;
			res.f.significand = fa.f.significand + fb.f.significand;
		}
		res.value = fa.value + fb.value;
	}

	printf("sinal: 0x%x\n", fa.f.signal);
	printf("expoente: %d\n", fa.f.exponent);
	printf("significante: 0x%x\n", fa.f.significand);
	
	return res.value;
}
/*
int main(){
	float f1, f2;
	f1 = 2.0f;
	f2 = 2.0f;
	printf("float res: %f\n", fsum(f1, f2));
	return 0;
}*/
