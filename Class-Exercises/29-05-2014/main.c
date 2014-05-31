#include <stdio.h>

void swap();

int buf[] = { 1, 2 };

int main(void){
	printf("buf = { %d , %d }\n", buf[0], buf[1]);
	swap();
	printf("buf = { %d , %d }\n", buf[0], buf[1]);
}