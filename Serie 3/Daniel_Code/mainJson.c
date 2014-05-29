#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include <curl/curl.h>
#include <dlfcn.h>
//#include "mylib.h"

void * (* http_get_json)(const char * url, int * retcod);

int main(){
	void * h = dlopen( "./mylib.so" , RTLD_NOW );
	*(void**)&http_get_json = dlsym(h, "http_get_json");
	
	
	json_t * final;	
	char * url;
	url = "http://headers.jsontest.com/";
	int *retcod;
	retcod = 0;
	final = http_get_json(url, retcod);
	dlclose((void*)h);
	
	return 0;
}
