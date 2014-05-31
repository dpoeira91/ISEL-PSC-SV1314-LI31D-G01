#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include <curl/curl.h>

json_t * http_get_json(const char * url, int * retcod);

int main(){
	char* urls[] = { "http://thoth.cc.e.ipl.pt/api/v1/classes/293/workitems",
	"http://thoth.cc.e.ipl.pt/api/v1/classes",
	"http://thoth.cc.e.ipl.pt/api/v1/classes/293 ",
	"http://thoth.cc.e.ipl.pt/api/v1/classes/294/workitems ",
	"http://thoth.cc.e.ipl.pt/api/v1/workitems/887"};
	int retcod[] = { 0 };
	int count = 0, urlsSize = 5,i;
	for (i = 0; i < urlsSize; i++){
		json_t * result = http_get_json(urls[i], retcod);
		if (result != NULL) {
			count++;
		}
		else{
			fprintf(stderr, "***error: json wasn't obtained!\n return code : %d \n",*retcod);
		}
		json_decref(result);
		result = NULL;
	}
	if (count != urlsSize){
		printf("Failed %d tests!", (urlsSize - count - 1));
		return 1;
	}
	printf("All %d tests were sucessfull!\n",count);
	return 0;
}