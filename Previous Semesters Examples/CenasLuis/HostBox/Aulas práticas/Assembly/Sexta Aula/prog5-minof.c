#include <stdio.h>

int [] vals = {-3 , 3, 1, 0, 25};

int min_Of(char * vals , unsigned len);

int main(){
	int a = min_Of(vals, 5);
	printf("Minimo = %d \n" , a);
	return 0;
}
