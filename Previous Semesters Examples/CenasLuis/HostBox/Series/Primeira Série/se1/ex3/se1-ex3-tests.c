#include <stdbool.h>
#include <stdio.h>

float s2f(short int s);

bool test_zero() {
	float res;
	
	res = s2f(0);
	
	return res == 0.0;
}

bool test_two() {
	float res;
	
	res = s2f(2);
	
	return res == 2.0;
}
int main() {
	if (test_zero() &&
	    test_two()) {
		return 0;	
	}
	printf("se1-ex3: at least one test has failed\n");
	return 1;
}
