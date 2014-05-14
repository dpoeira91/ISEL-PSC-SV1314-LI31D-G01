#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

size_t strtrim(char * dst, const char * src) {
	unsigned charToCopyIndex = 0,  strStart = 0 , strEnd = 0 , idx = 0;
	bool firstLetter = false;
	while(src[idx]){
		if ((isblank(src[idx]))  && (!firstLetter) )
				++strStart;
		if (!isblank(src[idx])) {
			if (!firstLetter)
				firstLetter = true;
			strEnd = idx;
		}
		++idx;
	}
	charToCopyIndex = strStart;
	while( charToCopyIndex <= strEnd){
		printf("%c\n" , src[charToCopyIndex]);
		(*dst++) = src[charToCopyIndex++];
	}
	(*dst) = '\0';
	return idx-strEnd+strStart-1;
}
