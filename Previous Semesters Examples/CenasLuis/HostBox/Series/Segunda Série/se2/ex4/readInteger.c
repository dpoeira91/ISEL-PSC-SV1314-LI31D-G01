#include "bomb.h"

char * readInteger(char * line, int base, int * dst ) {
	int dig, num = 0, ndig = 0;
	for (;;) {
		dig = line[ndig] - '0';
		if (dig < 0 || dig >= base) break;
		num = num * base + dig;
		++ndig;
	}
	*dst = num;
	return ndig ? line + ndig : NULL;
}

