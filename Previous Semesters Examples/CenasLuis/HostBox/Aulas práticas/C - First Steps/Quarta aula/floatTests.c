# include <stdio.h>

struct float_bits{
	unsigned m:23;
	unsigned e:8;
	unsigned s:1;
};

typedef struct float_bits FloatBits;

union Float_type{
	float f;
	int i;
	struct float_bits b;
};

typedef union Float_type FloatType;

void show_Float(float a){
	FloatType ft;
	ft.f = a;
	printf("f= %f \t i = 0x%08X \t b= {s=%d ; e= %d ; m= 0x%06X } \n" , ft.f , ft.i , ft.b.s , ft.b.e, ft.b.m );
}

int main(){
	show_Float(0.0);
	show_Float(1.0);
	show_Float(2.0);
	show_Float(3.0);
	show_Float(4.0);
	show_Float(5.0);
	show_Float(15.0);
	show_Float(3.141592654);
}
