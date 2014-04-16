#include<stdio.h>

int main(){
 unsigned val = 0x12345678;
 unsigned aux = 0;
 int i;
 for( i=31 ; i>=0 ; --i )
     aux = aux | ((val >> i)&1);

printf("%d \n",aux);
 return 0;
}