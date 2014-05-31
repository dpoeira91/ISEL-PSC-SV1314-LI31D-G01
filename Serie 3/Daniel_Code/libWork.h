#include<stdio.h>
#include <jansson.h>
#include <curl/curl.h>

#ifndef libWork_h__
#define libWork_h__

json_t * http_get_json(const char * url, int * retcod);
int http_get_file(const char * url, const char * filename);

#endif	//calc_libWork_h__
