#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

unsigned long max_value(bool sign, size_t nbytes);

bool test_max_for_one_unsigned_byte() {
	unsigned long res;
	
	res = max_value(false, 1);
	
	return res == 255;
}

bool test_max_for_one_signed_byte() {
	unsigned long res;
	
	res = max_value(true, 1);
	
	return res == 127;
}

bool test_max_for_signed_long_bytes() {
	unsigned long res;
	
	res = max_value(true, sizeof (long));
	
	return res == LONG_MAX;
}

int main() {
	if (test_max_for_one_unsigned_byte() &&
	    test_max_for_one_signed_byte() &&
	    test_max_for_signed_long_bytes()) {
		return 0;	
	}
	printf("se1-ex1: at least one test has failed\n");
	return 1;
}
