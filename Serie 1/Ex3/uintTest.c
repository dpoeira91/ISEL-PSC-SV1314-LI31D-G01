#include <stdio.h>
#include <stdbool.h>

//methods declarations
bool is_uint(float f);

int main(){
	float f = 3.000;
	printf("is_uint(%f) : ", f);
	printf(is_uint(f) ? "true\n" : "false\n");
	f = 1;
	printf("is_uint(%f) : ", f);
	printf(is_uint(f) ? "true\n" : "false\n");
	f = 0.3;
	printf("is_uint(%f) : ", f);
	printf(is_uint(f) ? "true\n" : "false\n");
	f = -3.000;
	printf("is_uint(%f) : ", f);
	printf(is_uint(f) ? "true\n" : "false\n");
	f = 1.5;
	printf("is_uint(%f) : ", f);
	printf(is_uint(f) ? "true\n" : "false\n");
	f = 0.0001;
	printf("is_uint(%f) : ", f);
	printf(is_uint(f) ? "true\n" : "false\n");
	f = 0.001;
	printf("is_uint(%f) : ", f);
	printf(is_uint(f) ? "true\n" : "false\n");
	f = 0.01;
	printf("is_uint(%f) : ", f);
	printf(is_uint(f) ? "true\n" : "false\n");
	f = 0.1;
	printf("is_uint(%f) : ", f);
	printf(is_uint(f) ? "true\n" : "false\n");
	return 0;
}