#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <jansson.h>

#define MAXSIZE 200

char * table(char * table, const char * tableContents){
	table = malloc(strlen(tableContents) + 26);
	sprintf(table, "<table border = 1>%s</table>", tableContents);
	return table;
}

char * tr(char * tr,const char * trContents){
	tr = malloc(strlen(trContents) + 9);
	sprintf(tr, "<tr>%s</tr>", trContents);
	return tr;
}

char * td(char * td, const char * tdContents){
	td = malloc(strlen(tdContents) + 9);
	sprintf(td, "<td>%s</td>", tdContents);
	return td;
}

char * th(char * th, const char * thContents){
	th = malloc(strlen(thContents) + 9);
	sprintf(th, "<th>%s</th>", thContents);
	return th;
}

char * h1(char * h1, const char * header){
	h1 = malloc(strlen(header)+9);
	sprintf(h1, "<h1>%s</h1>", header);
	return h1;
}

char * h2(char * h2, const char * header){
	h2 = malloc(MAXSIZE);
	sprintf(h2, "<h2>%s</h2>", header);
	return h2;
}

char * h3(char * h3, const char * header){
	h3 = malloc(MAXSIZE);
	sprintf(h3, "<h3>%s</h3>", header);
	return h3;
}

void withContent(char * ptr,const char * new_content){
	sprintf(ptr, "%s%s", ptr, new_content);
}

char * html_page(char* page ,char * title, char * content){
	page = malloc(10000);
	sprintf(page, "<html><head><title>%s</title></head><body><h1>%s</h1>%s</body></html>",title, title, content);
	return page;
}

char * contatToPtr(char * ptr, char * str1,const char * str2){
	ptr = malloc(1000);
	sprintf(ptr, "%s%s", str1, str2);
	return ptr;
}