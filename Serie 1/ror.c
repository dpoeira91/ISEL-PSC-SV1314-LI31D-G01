#include <stdio.h>
const int intSize = sizeof(int)* 8;
int ror(int val, unsigned n);

int main(){
	printf("Size of Integer: %d bits\n", intSize);
	int n, valToRotate;
	valToRotate = 1;
	for (n = 0; n<33; ++n)
		printf("%d %d %d\n", valToRotate, n, ror(valToRotate, n));
	return 0;
}

int ror(int val, unsigned n){
	return (val << intSize - (n%intSize)) | (val >> (n%intSize));
}
