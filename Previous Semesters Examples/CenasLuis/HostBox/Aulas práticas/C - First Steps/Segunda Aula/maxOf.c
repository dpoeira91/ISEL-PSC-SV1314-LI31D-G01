#include <stdio.h>

int data [4] = {3,-7,13,27};

int maxOf(int vals[], unsigned len){
	int max = vals[0];
	int i = 0;
	while (++i < len){
		if (vals[i]> max)
			max = vals[i];
	}
	return max;
}

/*
int minOf(int vals [] , unsigned len ) {
	int min = vals[0];
	int i;
	for (i = 1;i < len;++i){
		if (vals[i] < min) 
			min = vals[i];
	}
	return min;
}*/

void negAllOf (int vals[] , unsigned len){
	int i;
	for (i = 0 ; i < len ; ++i){
		vals[i] = -vals[i];
	}
}

//Com ponteiros

int minOf(int * vals, unsigned len ) {
	int * pmin = vals;
	while(len--){
		if (*vals < *pmin)
			pmin = vals;
		vals++;
	}
	return *pmin;
}

int main (){
//	negAllOf(data, 4);
	int max = maxOf(data, 4);
	int min = minOf(data, 4);
	printf("Valor máximo = %d\n" , max);
	printf("Valor minimo = %d\n" , min);
	return 0;
}
