#include "bomb.h"

char * readNIntegers(char * line, int * dst, unsigned int * n) {
	char c;
	while (*n) {
		line = readInteger(line, 10, dst);
		if (!line) break;
		--*n;
		while ((c = *line) == ' ' || c == '\t') ++line;
		if (c == 0) break;
		++dst;
	}
	return line;
}

