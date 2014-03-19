#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


size_t strtrim(char * dst, const char * src);


bool test_trim_spaces_at_both_ends() {
	char dst[11];
	const char * src = " \tPSC \t ISEL  ";
	size_t res;
	
	res = strtrim(dst, src);
	
	
	return res == 4 && strcmp(dst, "PSC \t ISEL") == 0;
}


int main() {
	if (test_trim_spaces_at_both_ends()) {
		return 0;	
	}
	printf("se1-ex2: at least one test has failed\n");
	return 1;
}
