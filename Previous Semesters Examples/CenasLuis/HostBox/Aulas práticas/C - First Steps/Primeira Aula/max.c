#include <stdio.h>

int max(int a , int b){
	if ((a-b) > 0) return a;
	return b;
}

int main(){
	int m = max(-3,28);
	printf("max = %d\n" , m);
	return 0;
}
