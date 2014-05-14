#include <stdio.h>

int i1;
int i2;
int i3;

char str1[12];

int f1(){
	return 0;
}

int main(){
	int l1;
	int l2;
	
	printf("&i1 = %p\n", &i1);
	printf("&i2 = %p\n", &i2);
	printf("&i3 = %p\n", &i3);
	printf("&str1 = %p\n", &str1);
	printf("&f1 = %p\n", &f1);
	printf("&l1 = %p\n", &l1);
	printf("&l2 = %p\n", &l2);
	printf("&main = %p\n", &main);
	
	return 0;
}
