#include <stdio.h>

int i = 31;
float f = 2.0;
double d;
long double a ;

int vals [24];

void func(int vs[24]){
	printf("%u\n", sizeof vs);
}

int main(){
	unsigned sz;
	
	sz = sizeof vals;
	func (vals);
	printf("%u\n", sz);
	return 0;
}
