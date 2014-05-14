#include <stdio.h>

float FarsToCels( int a ){
	float res = (float)5/9;
	return res*(a-32);
}

int main(){
	int i = 0;
	while (i <= 10){
		printf("%d Fahrenheit ----  %f Celsius \n", i*10 , FarsToCels(i*10));
		++i;
	}
	return 0;
}
