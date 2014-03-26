#include <stdio.h>

#define MAXCHARS 500

char *xstrstr(const char * haystack , const char * needle);


int main(int argc, char **argv){
	int c;	
	char stringinput[MAXCHARS];
	int i;
	char *p;
	char * ret = NULL;
	int argccopy = argc; // cada vez que acabo de testar as keywords, tenho de reiniciar
	char **argvcopy;
	argvcopy= argv;
	stringinput[0] = (c=getchar());
	p = &stringinput[0];
	for( i = 1 ; (c = getchar()) != EOF ; ++i ){
		if( c == '\n' ){		
			c = '\0';
			stringinput[i] = c;
			while( (--argccopy>0)){		
				ret = xstrstr(p, *++argvcopy);
				if(ret != NULL){
					printf( "%s \n", p );
					break;
				}
			}
			argccopy = argc; //o valor e decrementado no while, e necessario voltar a dizer o numero de argumentos
			argvcopy = argv;// e necessario garantir que apos testar os argumentos, os ponteiros estao a apontar para o inicio dos argumentos
			ret = NULL;     //reinicializacao das variaveis	
			p = &stringinput[i+1]; // nao da problema para quando o i for 500? ou 499?	
		}
		else
			stringinput[i] = c;
		
	}
	return 0;
}
