#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include <curl/curl.h>
 
struct MemoryStruct {
  char *memory;
  size_t size;
};

json_t * http_get_json(const char * url, int * retcod);
int http_get_file(const char * url, const char * filename);

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp){
 	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *)userp;
 
 	mem->memory = realloc(mem->memory, mem->size + realsize + 1);
	
	if(mem->memory == NULL) {
    /* out of memory! */ 
    	printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }
 
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;
 
  return realsize;
}
 
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream){
  int written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

json_t * http_get_json(const char * url, int * retcod){

	CURL *curl_handle;
	CURLcode res;

	struct MemoryStruct chunk;

	chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */ 
	chunk.size = 0;    /* no data at this point */ 

	curl_global_init(CURL_GLOBAL_ALL);

	/* init the curl session */ 
	curl_handle = curl_easy_init();

	/* specify URL to get */ 
	curl_easy_setopt(curl_handle, CURLOPT_URL, url);

	/* send all data to this function  */ 
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
	
	/* we pass our 'chunk' struct to the callback function */ 
	curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &chunk);
	
	/* some servers don't like requests that are made without a user-agent
	field, so we provide one */ 
	curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
	
	/* get it! */ 
	res = curl_easy_perform(curl_handle);

	/* check for errors */ 
	if(res != CURLE_OK) {
		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		*retcod = res;
		return NULL;
	
	}
	/* cleanup curl stuff */ 
	curl_easy_cleanup(curl_handle);
	
	/* we're done with libcurl, so clean it up */ 
	curl_global_cleanup();

	json_t * thoth;
	json_error_t error;
	
	thoth = json_loads(chunk.memory,0, &error);
	
	return thoth;

}


int http_get_file(const char * url, const char * filename){

  	FILE *bodyfile; // create a file pointer

	CURL * curl;
	CURLcode res;

//start the libcurl library
	curl_global_init(CURL_GLOBAL_ALL);

//start the curl to perform the HTTP_GET
	curl = curl_easy_init();

	if(!curl){ // if we don't get a curl, something went wrong
		fprintf(stderr, "curl_easy_init() failed \n");
		return 1;
	}

// from here, we set the options that we want the curl to handle
	
// we give curl the url that we want to use
	curl_easy_setopt(curl, CURLOPT_URL, url );

// since the url is redirected and we want to follow it, we use CURLOPT_FOLLOWLOCATION to tell the libcurl that we want it to follow that redirection
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // 1L = positive long set to 1

/* after the follow, libcurl will perform the action to write into memory (I think), then it will be calledback
 ( check http://curl.haxx.se/libcurl/c/curl_easy_setopt.html#CURLOPTFOLLOWLOCATION )
*/
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

// this will open the file, meaning, from now on we can write on the file
	bodyfile = fopen(filename,"wb"); // w or wb : Truncate to zero length or create file for writing
  	
	if (bodyfile == NULL) { // if there's no file created, we clean up the curl and terminate the program
    	curl_easy_cleanup(curl);
    	return 1;
  	}

// now it's ready to copy to the file what is on memory (from when the CURLOPT_WRITEFUNCTION was called)
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, bodyfile); 
	
// check if there are no errors
	res = curl_easy_perform(curl);


	if( res != CURLE_OK ){
		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		return 1;
	}

//it's all good to go, just close the file and clear everything!

	fclose(bodyfile);
	
	curl_easy_cleanup(curl);
	return 0;
}
