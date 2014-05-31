#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include <curl/curl.h>
#include "workLib.h"

int main(){
	json_t * final;	
	char * url;
	url = "http://headers.jsontest.com/";
	int *retcod;
	retcod = 0;
	final = (void*) http_get_json(url, retcod);
	return 0;
}
