#include <stdio.h>

char *xstrstr(const char * haystack , const char * needle);

int main(){
	const char message[] = "escxxcolafd";
	const char key[] = "cola";
	char * ret;
	ret = xstrstr( message , key );
	printf( "%s \n", ret );
	return 0;
}

char * xstrstr(const char *haystack , const char * needle){
	// verifica se os ponteiros estão vazios
	if(needle == '\0') // se needle tiver vazia retorna o ponteiro para o inicio da 1a string
		return  (char*)haystack; // haystack = ponteiro , *haystack = conteudo do endereço	

	//Inicializa variáveis
	const char *haystack_copy, *needle_copy, *haystack_current;
	haystack_copy = haystack_current = haystack;
	needle_copy = needle;	

	//Procura a palavra
	while( *haystack_copy != '\0' ){ //enquanto nao se chegar ao fim da 1a string
		while((*needle_copy != '\0')&&(*needle_copy == *haystack_copy)){ // se o conteudo de memoria for igual nos 2 (mesma letra)
			needle_copy++;
			haystack_copy++;
		}
		if(*needle_copy == '\0')
			return (char *)haystack_current;
		else{
			needle_copy = needle;
			haystack_copy = ++haystack_current;
		}			
	}
	
	return  NULL;
}
