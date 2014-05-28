#include <stdio.h>
#include <curl/curl.h>

extern int http_get_file(const char * url, const char * filename);

int main(){
	char * url;
	
	url = "http://www.isel.pt/docs/img/fundo2.jpg";
	
	char * filename;
	
	filename = "test.out";
	http_get_file(url, filename);
	
	return 0;

}
