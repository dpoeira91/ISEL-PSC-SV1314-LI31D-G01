#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include <curl/curl.h>

char * table(char * table, const char * tableContents);
char * tr(char * tr, const char * trContents);
char * td(char * td, const char * tdContents);
char * th(char * th, const char * thContents);
char * h1(char * h1, const char * header);
char * h2(char * h2, const char * header);
char * h3(char * h3, const char * header);
struct workItem parse_workItem(json_t * workItem);
json_t * get_workItem(json_t * root_projects, int index);

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

char * workitem_to_html(char * html_table_row, struct workItem item){
	html_table_row = malloc(1000);
	char *acro = td(acro,item.acronym),
		*title = td(title,item.title),
		*start = td(start,item.startDate),
		*due = td(due,item.dueDate),
		*group = td(group,(item.group) ? "Group" : "Individual"),
		*report = td(report,(item.report) ? "Required" : "Optional"),
		*attachment = td(attachment,(item.attachment) ? "Required" : "Optional"),
		*row;
	sprintf(html_table_row, "%s%s%s%s%s%s%s", acro , title, start, due , group, report, attachment);
	html_table_row = tr(row,html_table_row);
	free(html_table_row);
	free(acro);
	free(title);
	free(start);
	free(due);
	free(group);
	free(report);
	free(attachment);
	acro = NULL;
	title = NULL;
	start = NULL;
	due = NULL;
	group = NULL;
	report = NULL;
	html_table_row = NULL;
	return row;
}