#include <stdio.h>

char *xstrstr(const char * haystack , const char * needle);

int main(){
	const char message[] = "escolafd";
	const char key[] = "cola";
	char * ret;
	ret = xstrstr( message , key );
	printf( "%s \n", ret );
	return 0;
}

char * xstrstr(const char * haystack , const char * needle){
	if(needle == '\0') // se needle tiver vazia retorna o ponteiro para o inicio da 1a string
		return  (char*)haystack; // haystack = ponteiro , *haystack = conteudo do endereço	
	const char* haystack_copy = NULL ;	
	const char* needle_copy = needle;
	while( *haystack != '\0' ){ //enquanto nao se chegar ao fim da 1a string
		if( *needle_copy == '\0' )
			break;
		else{
			if( *needle_copy == *haystack ){ // se o conteudo de memoria for igual nos 2 (mesma letra)
				needle_copy++;
				if( haystack_copy == NULL)
					haystack_copy = haystack;
			}
			else if ( needle_copy != needle ) {
				haystack_copy = NULL; // solucao ma
				needle_copy = needle;
			}		
		}
		++haystack;
	}
	return (char*)haystack_copy;
}
