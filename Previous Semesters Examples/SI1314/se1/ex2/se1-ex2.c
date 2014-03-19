#include <stddef.h>
#include <ctype.h>

size_t strtrim(char * dst, const char * src) {
	int removed=0;
	int length=0;
	int i=0;
	int copy=0;
	
	while(src[length])
		++length;					// length                             

	while(isblank(src[i])!=0)
		++i;					   // primeiro caractere nao branco      
		
	int j= length-1;
	while(isblank(src[j])!=0)
		--j; 					   // ultimo caractere nao branco        

	removed = i+(length-(j+1)); 
	
	for(;i<=j;++i, ++copy)
		dst[copy] = src[i];
	dst[copy] = '\0';
	
	return removed;	
}
