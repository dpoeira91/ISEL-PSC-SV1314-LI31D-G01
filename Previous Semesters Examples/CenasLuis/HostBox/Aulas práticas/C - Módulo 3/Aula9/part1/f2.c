
// declare foo
#include "f1.h"

#define SIZE 60000

int data [SIZE] = {1,3,2};

void bar(){
	int i;
	for ( i = 0 ; i < SIZE ; ++i){
		data[i] = foo(i, 500.0 , "cool");
	}
} 
