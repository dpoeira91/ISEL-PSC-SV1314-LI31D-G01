#include <stdio.h>
#include "libWork.h"

int main(){
	char * url;	
	url = "http://www.isel.pt/docs/img/fundo2.jpg";
	char * filename;
	filename = "test.out";
	int a;	
	a = http_get_file(url, filename);
	return a;

}
