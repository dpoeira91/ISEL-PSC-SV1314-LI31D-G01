#include <stdio.h>

char str1[32] = "PSC ";
char str2[] = "LI31D";

void stringCat(char dest[] , char src []){
	unsigned aux = 0;
	unsigned destLen = strnlen(dest);
	while (src[aux]){
		dest[destLen++] = src[aux++];
	}
	dest[destLen]= '\0';
}

int main(){
	stringCat(str1, str2);
	printf("%s\n", str1);
	return 0;
}
