#include <stdio.h>


unsigned countbits(unsigned val){
	unsigned res = 0;
	while(val != 0){
		if(val & 1 != 0)
			res++;
		val >>=1;
	}
	return res;
}

int main(){
	printf(" 5 => %d\n",countbits(5));
	printf(" 13 => %d\n",countbits(13));
	printf(" 15 => %d\n",countbits(15));
	printf(" 16 => %d\n",countbits(16));
	printf(" -1 => %d\n",countbits(-1));
	return 0;
}

