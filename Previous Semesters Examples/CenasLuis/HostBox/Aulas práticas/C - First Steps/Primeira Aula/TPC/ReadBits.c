#include <stdio.h>

unsigned readBits(unsigned v, unsigned idx, unsigned len){
	return (v>>idx)&((1<<len)-1);
}

int main(){
	int actualBits = readBits(-2450,1,6);
	printf("Cropped bit sequence = %d\n" , actualBits);
	return 0;
}
