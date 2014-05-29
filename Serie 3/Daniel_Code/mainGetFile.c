#include <stdio.h>
#include <curl/curl.h>
#include <dlfcn.h>

int http_get_file(const char * url, const char * filename);

int main(){
	char * url;

	void * h = dlopen( "./mylib.so" , RTLD_NOW );
	*(void**)&http_get_file = dlsym(h, "http_get_file");
	
	url = "http://www.isel.pt/docs/img/fundo2.jpg";
	
	char * filename;
	
	filename = "test.out";
	int a;	
	a = http_get_file(url, filename);
	dlclose((void*)h);
	
	return a;

}
