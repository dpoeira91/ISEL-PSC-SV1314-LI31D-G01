#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10000000

char data [128*1024*1024];
volatile int sum;

double eval(size_t d){
	size_t n , i = 0;
	clock_t ini , fin;
	int accum = 0;
	ini = clock();
	for ( n = 0 ; n < N ; ++n){
		accum += data[i];
		if ((i += d) >= sizeof data){
			i = 0;
		}
	}
	fin = clock();
	sum = accum;
	return (((double)(fin-ini)) * 1000) / CLOCKS_PER_SEC;
}

int main(){
	srand(time(NULL));
	int i;
	for ( i = 0 ; i < 128*1024*1024 ; ++i ){
		data[i] = rand();
	}
	size_t d;
	double t, tx[3];
	for(d = 16384 ; d>= 1 ; d/= 2){
		eval(d);
		eval(d);
		tx[0] = eval(d);
		tx[1] = eval(d);
		tx[2] = eval(d);
		
		t = (tx[0] < tx[1] ? tx[0] : tx[1]);
		t = (t < tx[2] ? t : tx[2]);
		printf("%4u: %f\n" , d, t);
	}
	return sum;
}
