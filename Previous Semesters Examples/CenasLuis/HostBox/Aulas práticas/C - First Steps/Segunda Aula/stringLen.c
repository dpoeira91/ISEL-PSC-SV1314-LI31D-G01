#include <stdio.h>

//O corpo do método abaixo é idêntico a
//unsigned stringLen(char * str)
//Isto porque o que é passado é um ponteiro para o inicio do array
/*
unsigned stringLen(char str []){
	unsigned len = 0;
	while (str[len]){
		len += 1;
	}
	return len;
}
*/

unsigned stringLen(char * str){
	char * start = str;
	while (*str++);
	return str - start -1;
}

char str1[] = "PSC";
char str2[] = "LI31D";

int main(){
	char * p1 = &str1[0];
	char * p2 = &str2[0];
	printf("%d\n" , stringLen(p1));
	printf("%d\n" , stringLen(p2));
	return 0;
}
