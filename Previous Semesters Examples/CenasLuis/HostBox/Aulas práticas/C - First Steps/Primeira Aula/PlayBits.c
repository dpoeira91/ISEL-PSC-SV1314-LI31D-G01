#include <stdio.h>

int main(){
	int mv = setbit (5,1);
	int nnv = flipbit(mv, 2);
	printf("%x..%x\n", mv, nnv);
	return 0;
}

int setbit(int val, int idx) {
	return val | (0x1<<idx);
}

int flipbit(int val, int idx) {
	return (val) ^ (0x1<<idx);
}
