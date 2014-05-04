#include <stdio.h>
#include <string.h>
char *xstrpbrk(const char *cs, const char *ct);

char *xstrpbrk(const char *cs, const char *ct){
	const char * aux = ct;
	while( *cs != '\0'){
		for(; *ct != '\0'; ++ct){
			if(*cs == *ct)
				return (char*)cs;
		}
		ct= aux;
		++cs;
	}
	return NULL;
}
