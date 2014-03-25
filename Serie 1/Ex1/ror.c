#include <stdio.h>
#define INT_SIZE (sizeof(int)*8)
int ror(int val, unsigned n);

int ror(int val, unsigned n){
	return (val << INT_SIZE - (n%INT_SIZE)) | (val >> (n%INT_SIZE));
}
