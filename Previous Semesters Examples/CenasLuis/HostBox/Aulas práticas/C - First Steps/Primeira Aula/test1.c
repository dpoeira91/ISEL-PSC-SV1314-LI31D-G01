#include <stdio.h>

int a = 5;
double b = 3.1;

int func (int a) {
	return a+7;
}

int main (){
	printf ("%d\n" , func(8));
	return 0;
}
