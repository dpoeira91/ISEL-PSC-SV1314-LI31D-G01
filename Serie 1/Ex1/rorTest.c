#include <stdio.h>
#define INT_SIZE (sizeof(int)*8)
int ror(int val, unsigned n);

int main(){
	int n, valToRotate;	
	valToRotate = 1073741824;	
	printf("Size of Integer: %d bits, value to rotate: %d\n", INT_SIZE, valToRotate);
	
	
	for (n = 0; n<33; ++n)
		printf("%d %d\n", n, ror(valToRotate, n));
	return 0;
}
