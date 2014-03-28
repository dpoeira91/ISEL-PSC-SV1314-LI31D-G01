#include <stdio.h>

char *xstrstr(const char * haystack , const char * needle);

char * xstrstr(const char *haystack , const char * needle){
	//verify if there's a needle
	if(needle == '\0')
		return  (char*)haystack; //if there's no needle, returns the whole string

	const char *haystack_copy, *needle_copy, *haystack_current;
	haystack_copy = haystack_current = haystack;
	needle_copy = needle;	

	while( *haystack_copy != '\0' ){
		while((*needle_copy != '\0')&&(*needle_copy == *haystack_copy)){ // while they letters are the same
			needle_copy++;
			haystack_copy++;
		}
		if(*needle_copy == '\0') // if we get to the end of the needle, it means we found the needle in the haystack
			return (char *)haystack_current;
		else{ // at this point, there's no needle on this haystack, so it will check the next one
			needle_copy = needle; 
			haystack_copy = ++haystack_current;
		}			
	}
	
	return  NULL;
}
