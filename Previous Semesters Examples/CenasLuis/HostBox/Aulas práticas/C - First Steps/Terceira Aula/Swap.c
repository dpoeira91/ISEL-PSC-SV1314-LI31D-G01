#include <stdio.h>

void sawp (int * i1 , int * i2) {
	int t = (*i1);
	(*i1) = (*i2);
	(*i2) = t;
}

int val1 = 3;
int val2 = 21;

int main(){
	sawp(&val1, &val2);
	printf("%d , %d \n" , val1, val2);
	return 0;
}
