#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>
#include "libWork.h"

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
	return written;
}

int http_get_file(const char *url, const char * filename)
{
	CURL *handler;
	CURLcode CURLres;
	FILE *file;
	
	/*Initializes the libcurl library*/
	curl_global_init(CURL_GLOBAL_ALL);

	/*Initializes the CURL handler to perform the HTTP GET*/
	handler = curl_easy_init();
	/*Checks if the init was performed*/
	if (!handler){
		fprintf(stderr, "***error: curl_easy_init() failed\n");
		return 1;
	}

	/*Sets the handler's URL*/
	curl_easy_setopt(handler, CURLOPT_URL, url);
	
	/*Tells the handler to follow the url if redirected*/
	curl_easy_setopt(handler, CURLOPT_FOLLOWLOCATION, 1L);
	
	/* Sends all the Data to the write_data function */
	curl_easy_setopt(handler, CURLOPT_WRITEFUNCTION, write_data);

	/*opens the file on the filename location in the mode write byte*/
	file = fopen(filename, "wb");

	if (!file){
		fprintf(stderr, "***error: fopen(%s, wb) failed\n",filename);
		return 1;
	}
	/* write the result to this file. CURLOPT_FILE is also known as	CURLOPT_WRITEDATA*/
	curl_easy_setopt(handler, CURLOPT_FILE, file);

	/*Performs the request to the url designated or the one that we are redirected to, res will get the return code*/
	CURLres = curl_easy_perform(handler);
	
	/*Close the file*/
	fclose(file);

	/*Checking for errors*/
	if (CURLres != CURLE_OK){
		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(CURLres));
		return 1;
	}
	
	/*Cleanup of the handler*/
	curl_easy_cleanup(handler);

	return 0;
}