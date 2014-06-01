#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include <curl/curl.h>

#ifndef libWork_h__
#define libWork_h__

struct workItem {
	int id;
	const char *acronym;
	const char *title;
	const char *startDate;
	const char *dueDate;
	const char *document;
	const char *attachment_name;
	int group;
	int report;
	int attachment;

};

typedef struct workItem item;

extern json_t * http_get_json(const char * url, int * retcod);
extern int http_get_file(const char * url, const char * filename);
extern char * concat_document_url(char * url,char * title, int id);
extern char * concat_attachment_url(char * url,char * title, int id);
extern char * concat_title(char * title,char * acronym, char * semester, char * class_name);
extern char * parse_projects(json_t * projects, char * title); 
extern json_t * http_get_json(const char * url, int * retcod);
extern json_t * find_class(json_t * root, char * acronym, char * semester, char * class_name);
extern json_t * get_projects(json_t * root_class);
extern int http_get_file(const char *url, const char * filename);
extern char * workitem_to_html(char * html_table_row, struct workItem item);
extern char * html_page(char * page,char * title, char * content);
extern char * table(char * table, const char * tableContents);
extern char * tr(char * tr, const char * trContents);
extern char * td(char * td, const char * tdContents);
extern char * th(char * th, const char * thContents);
extern char * h1(char * h1, const char * header);
extern char * h2(char * h2, const char * header);
extern char * h3(char * h3, const char * header);
extern void withContent(char * ptr, const char * new_content);
extern char * contatToPtr(char * ptr, char * str1,const char * str2);
extern struct workItem parse_workItem(json_t * workItem);
extern json_t * get_workItem(json_t * root_projects, int index);



#endif	//libWork_h__
