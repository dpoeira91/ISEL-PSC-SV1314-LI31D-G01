#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <jansson.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <math.h>

struct stat st = { 0 };

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
char * concat_document_url(char * url,char * title, int id);
char * concat_attachment_url(char * url,char * title, int id);
char * concat_title(char * title,char * acronym, char * semester, char * class_name);
char * parse_projects(json_t * projects, char * title);

json_t * http_get_json(const char * url, int * retcod);
json_t * find_class(json_t * root, char * acronym, char * semester, char * class_name);
json_t * get_projects(json_t * root_class);

int http_get_file(const char *url, const char * filename);
char * workitem_to_html(char * html_table_row, struct workItem item);
char * html_page(char * page,char * title, char * content);
char * table(char * table, const char * tableContents);
char * tr(char * tr, const char * trContents);
char * td(char * td, const char * tdContents);
char * th(char * th, const char * thContents);
char * h1(char * h1, const char * header);
char * h2(char * h2, const char * header);
char * h3(char * h3, const char * header);
void withContent(char * ptr, const char * new_content);
char * contatToPtr(char * ptr, char * str1,const char * str2);
struct workItem parse_workItem(json_t * workItem);
json_t * get_workItem(json_t * root_projects, int index);

int main(){
	json_t *thoth,*_class,*projects,*project;
	FILE *file;
	char * url = "http://thoth.cc.e.ipl.pt/api/v1/classes";
	int retcod[] = { 0 },i;
	char *acronym = "PSC", *semester = "1314v", *class_name = "LI31D", *title = concat_title(title,acronym,semester,class_name);
	struct workItem item;
	thoth = http_get_json(url, retcod);
	_class = find_class(thoth, acronym, semester, class_name);
	projects = get_projects(_class);
	if (stat("./Thoth", &st) == -1) {
		mkdir("./Thoth", 0700);
	}
	else
		printf("directory already exists\n");
	char * html_table = parse_projects(projects,title);
	char * page = html_page(page,title, html_table);
	free(html_table);
	html_table = NULL;
	free(title);
	title = NULL;
	file = fopen("./Thoth/thoth.html", "wb");
	if (file){
		fputs(page,file);
		fclose(file);
	}
	free(page);
	page = NULL;
	return 0;
}

char * parse_projects(json_t * projects, char * title){
	char *builder = malloc(7000), *row, *header = malloc(1000), *html_table,*url,*aux = NULL,
		*acro = th(acro,"Acronym"),
		*t = th(t,"Title"),
		*start = th(start,"Start Date"),
		*due = th(due,"Due Date"),
		*group = th(group,"Group or Individual"),
		*report = th(report,"Report"),
		*attachment = th(attachment,"Attachment");
	struct workItem item;
	json_t *project;
	size_t i;
	if (json_array_size(projects) == 0)
		return html_table;
	sprintf(header, "%s%s%s%s%s%s%s", acro, t , start , due, group , report ,attachment );
	free(acro);
	free(t);
	free(start);
	free(due);
	free(group);
	free(report);
	free(attachment);
	acro = NULL;
	t = NULL;
	start = NULL;
	due = NULL;
	group = NULL;
	report = NULL;
	row = tr(row,header);
	free(header);
	header = NULL;
	sprintf(builder, "%s", row);
	free(row);
	row = NULL;
	for (i = 0; i<json_array_size(projects); i++){
		project = get_workItem(projects, i);
		item = parse_workItem(project);
		http_get_file((url=concat_document_url(url, title, item.id)), contatToPtr(aux, "./Thoth/", item.document));
		free(aux);
		aux = NULL;
		free(url);
		url = NULL;
		if (item.attachment_name != NULL){
			http_get_file((url = concat_document_url(url, title, item.id)), contatToPtr(aux, "./Thoth/", item.attachment_name));
			free(url);
			url = NULL;
			free(aux);
			aux = NULL;
		}
		row = workitem_to_html(row,item);
		withContent(builder, row);
		free(row);
		row = NULL;
	}
	html_table = table(html_table,builder);
	return html_table;
}

char * concat_document_url(char * url,char * title, int id){
	url = malloc(500);
	sprintf(url, "http://thoth.cc.e.ipl.pt/classes/%s/workitems/%d/document", title, id);
	return url;
}

char * concat_attachment_url(char * url,char * title, int id){
	url = malloc(500);
	sprintf(url, "http://thoth.cc.e.ipl.pt/classes/%s/workitems/%d/attachment", title, id);
	return url;
}

char * concat_title(char * title,char * acronym, char * semester, char * class_name){
	title = malloc(500);
	sprintf(title, "%s/%s/%s", acronym, semester, class_name);
	return title;
}