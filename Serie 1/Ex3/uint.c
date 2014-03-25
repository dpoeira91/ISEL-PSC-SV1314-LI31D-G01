#include <stdio.h>
#include <stdbool.h>

//defines
#define MANTISSA_MASK ~(~0<<23)

//structures
struct floatstruct{
	unsigned int mantissa : 23;
	unsigned int exponent : 8;
	unsigned int signal : 1;
};

union floatbits{
	float f;
	struct floatstruct bits;
};

//methods declarations
bool is_uint(float f);

int main(){
	float f = 0.3;
	union floatbits fb;
	fb.f = f;
	printf("MANTISSA_MASK : %d \n", MANTISSA_MASK);
	printf("mantissa : %d \n", fb.bits.mantissa);
	printf("exponent : %d \n", (fb.bits.exponent-127));
	printf("signal : %d \n", fb.bits.signal);
	printf("is_uint(%f) : ", f);
	printf(is_uint(f) ? "true\n" : "false\n");
}

bool is_uint(float f){
	union floatbits fb;
	unsigned decimal_part;
	fb.f = f;
	decimal_part = fb.bits.mantissa;
	if (fb.bits.signal == 1)
		return false;
	if (fb.bits.exponent - 127 < 0)
		return false;
	if (((decimal_part << fb.bits.exponent-127) & MANTISSA_MASK )!= 0)
		return false;
	return true;

	
}