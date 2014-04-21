#include <stdio.h>
#include <limits.h>

/* reverse: assembly function that returns v with bits reverted */
unsigned reverse(unsigned v);

int main()
{
    int n = 0;
    
    n += reverse(0x12345678) == 0x1e6a2c48;
    n += reverse(0x1e6a2c48) == 0x12345678;
    n += reverse(0x80000000) == 0x00000001;
    n += reverse(0x00000001) == 0x80000000;
    n += reverse(0xffffffff) == 0xffffffff;
    n += reverse(0x00000000) == 0x00000000;
    
    if (n == 6) {
        printf("--all tests succeeded!\n");
		return 0;
    } else {
        printf("--at least one eteste failed!\n");
    	return 1;
	}
}

