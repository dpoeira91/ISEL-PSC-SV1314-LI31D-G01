	
	#include "f1.h"
	
	int a = 5;
	
	int foo(int arg, double d, char * w){
		return a + arg;
	}
	
	void fx(){
			a += 3;
	}
	
	int foo2(int arg){
		if (a > 0){
			return a + arg;
			fx();
		}
		else 
		return 0;
	}
