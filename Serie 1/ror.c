#include <stdio.h>

int ror(int val, unsigned n);

int main(){
	int n, valToRotate;
	valToRotate = 1;
	for(n=0;n<34;++n)
		printf("%d %d %d\n",valToRotate,n,ror(valToRotate,n));
	return 0;
}

int ror(int val, unsigned n){
return (val<<32-(n%32))|(val>>(n%32));
}
