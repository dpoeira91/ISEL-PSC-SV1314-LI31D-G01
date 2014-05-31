#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include <curl/curl.h>

/*This structure will help to store the json in memory instead of a file*/
struct MemoryBuffer{
	char *memory;
	size_t size;
};

static size_t write_to_buffer(void *contents, size_t size, size_t nmemb, void *context)
{
	size_t contentsSize = size *nmemb;
	struct MemoryBuffer *mem = (struct MemoryBuffer *) context;

	mem->memory = realloc(mem->memory, mem->size + contentsSize + 1);
	if (mem->memory == NULL) {
		/* out of memory! */
		printf("not enough memory (realloc returned NULL)\n");
		return 0;
	}

	memcpy(&(mem->memory[mem->size]), contents, contentsSize);
	mem->size += contentsSize;
	mem->memory[mem->size] = 0;

	return contentsSize;
}

json_t * http_get_json(const char * url, int * retcod){
	CURL *handler;
	CURLcode res;

	struct MemoryBuffer buffer;

	buffer.memory = malloc(1);  /* will be grown as needed by the realloc on the write to buffer function */
	buffer.size = 0;    /* no data means size = 0 */

	/*Initializes the libcurl library*/
	curl_global_init(CURL_GLOBAL_ALL);

	/*Initializes the CURL handler to perform the HTTP GET*/
	handler = curl_easy_init();

	/*Checks if the init was performed*/
	if (!handler){
		fprintf(stderr, "***error: curl_easy_init() failed\n");
		return NULL;
	}

	/* specify URL to get */
	curl_easy_setopt(handler, CURLOPT_URL, url);

	/* send all data to the write_to_buffer function  */
	curl_easy_setopt(handler, CURLOPT_WRITEFUNCTION, write_to_buffer);

	/* we pass our 'buffer' struct to the function */
	curl_easy_setopt(handler, CURLOPT_WRITEDATA, (void *)&buffer);

	/* some servers don't like requests that are made without a user-agent
	field, so we provide one */
	curl_easy_setopt(handler, CURLOPT_USERAGENT, "libcurl-agent/1.0");

	/* set the FOLLOWLOCATION option */
	curl_easy_setopt(handler, CURLOPT_FOLLOWLOCATION, 1L);

	/* perform the HTTP get request */
	res = curl_easy_perform(handler);
	if (res != CURLE_OK) {
		fprintf(stderr, "***error: curl_easy_perform() failed: %s\n",
			curl_easy_strerror(res));
		*retcod = res;
		return NULL;
	}
	json_t * json = json_string(buffer.memory);
	if (buffer.memory)
		free(buffer.memory);
	
	/*Cleanup of the handler*/
	curl_easy_cleanup(handler);

	/*Cleanup of all the libcurl*/
	curl_global_cleanup();

	return json;
}