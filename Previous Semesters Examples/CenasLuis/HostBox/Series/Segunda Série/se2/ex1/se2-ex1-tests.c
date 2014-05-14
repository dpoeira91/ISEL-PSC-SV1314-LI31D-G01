#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

size_t xstrlcat(char * dst, const char * src, size_t size);

bool test_basic_strlcat() {
	char dst[11] = "ISEL";
	const char * src = " - PSC";
	size_t res;
	
	res = xstrlcat(dst, src, sizeof dst);
	
	return res == 10 && strcmp(dst, "ISEL - PSC") == 0;
}

int main() {
	if (test_basic_strlcat()) {
		return 0;	
	}
	printf("se2-ex1: at least one test has failed\n");
	return 1;
}
