#include "foo.h"

int main(const int argc , const char ** argv){
	
	void *temp_foo = getFoo(5);
	
	printString(temp_foo);
	
	return 0;
}
