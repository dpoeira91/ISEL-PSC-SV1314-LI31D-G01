#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include <curl/curl.h>

json_t * http_get_json(const char * url, int * retcod);

int main(){
	json_t * final;	
	char * url;
	url = "http://headers.jsontest.com/";
	int *retcod;
	retcod = 0;
	final = http_get_json(url, retcod);
	
	return 0;
}
