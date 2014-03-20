#include <stdio.h>

#define MAXCHARS 500

char *xstrstr(const char * haystack , const char * needle);


int main(){
	int c;	
	char s[MAXCHARS];
	int i;
	char *p;
	char coisas[8] = "teste";
	char * ret;



	s[0] = (c=getchar());
	p = &s[0];
	for( i = 1 ; (c = getchar()) != EOF ; ++i )	
		if( c == '\n' ){		
			c = '\0';			
			s[i] = c ;			
			ret = xstrstr(p, coisas);
			if(ret != NULL)
				printf( "%s \n", p );
			p = &s[i+1];
		}
		else
			s[i] = c;

	return 0;
}
