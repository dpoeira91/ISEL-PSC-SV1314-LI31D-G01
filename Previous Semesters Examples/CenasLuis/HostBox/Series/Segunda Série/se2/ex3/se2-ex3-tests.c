#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void * convertAll(
	const void * input,
	size_t idim,
	size_t len,
	void * output,
	size_t odim,
	void (*convertOne)(const void * in, void * out, void * ctx),
	void * ctx
);

void convertIntToDouble(const void * in, void * out, void * ctx) {
	*(double *)out = *(const int *)in;
}

bool test_int_to_double() {
	int src[] = { 4136, -7199, 0, 2122, -351 };

	double expected_dst[] = { src[0], src[1], src[2], src[3], src[4] };
	double dst[(sizeof expected_dst) / (sizeof expected_dst[0])];

	void * expected_res = dst + ((sizeof expected_dst) / (sizeof expected_dst[0]));
	void * res;
	
	res = convertAll(src, sizeof src[0], sizeof src / sizeof src[0],
	                 dst, sizeof dst[0], convertIntToDouble, NULL);
	
	return res == expected_res && memcmp(dst, expected_dst, sizeof expected_dst) == 0;
}

void convertStrToNumber(const void * in, void * out, void * ctx) {
	*(long *)out = strtol(*(const char **)in, NULL, (int)ctx);
}

bool test_str_to_number() {
	const char * src[] = { "12345", "-7104", "0", "-55374", "221" };

	long expected_dst[] = { 012345, -07104, 0, -055374, 0221 };
	long dst[(sizeof expected_dst) / (sizeof expected_dst[0])];

	void * expected_res = dst + ((sizeof expected_dst) / (sizeof expected_dst[0]));
	void * res;
	
	res = convertAll(src, sizeof src[0], sizeof src / sizeof src[0],
	                 dst, sizeof dst[0], convertStrToNumber, (void *)8);
	
	return res == expected_res && memcmp(dst, expected_dst, sizeof expected_dst) == 0;
}

int main() {
	if (test_int_to_double() &&
	    test_str_to_number()) {
		return 0;	
	}
	printf("se2-ex3: at least one test has failed\n");
	return 1;
}
