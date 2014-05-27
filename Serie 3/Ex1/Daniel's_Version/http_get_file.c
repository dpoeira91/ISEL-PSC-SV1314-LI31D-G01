#include <stdio.h>
#include <curl/curl.h>


int http_get_file(const char * url, const char * filename);



// auxiliar method, copied from the example  sepheaders.c

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream){
  int written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}


int main(int argc, char *argv[]){
	if(argc > 3)
	printf("%s", "ERROR: Only 2 arguments are accepted, first url, then file name!\n");
	char * url;
	
	url = argv[1];
	//	url = "http://www.isel.pt/docs/img/fundo2.jpg";
	
	char * filename;
	
	filename = argv[2];
	//filename = "test.out";
	http_get_file(url, filename);
	
	return 0;

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
