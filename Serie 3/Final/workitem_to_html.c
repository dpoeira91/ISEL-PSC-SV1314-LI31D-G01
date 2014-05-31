#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include <curl/curl.h>
#include "libWork.h"
/*
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
*/
//struct workItem item;

char * workitem_to_html(char * html_table_row, struct workItem item){
	html_table_row = malloc(1000);
	char *acro = td(acro,item.acronym),
		*title = td(title,item.title),
		*start = td(start,item.startDate),
		*due = td(due,item.dueDate),
		*group = td(group,(item.group) ? "Group" : "Individual"),
		*report = td(report,(item.report) ? "Required" : "Optional"),
		*attachment = td(attachment,(item.attachment) ? "Required" : "Optional"),
		*row = malloc(1000);
	sprintf(row, "%s%s%s%s%s%s%s", acro , title, start, due , group, report, attachment);
	html_table_row = tr(html_table_row, row);
	free(row);
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
	row = NULL;
	return html_table_row;
}