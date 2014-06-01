#include "libWork.h"

char * workitem_to_html(char * html_table_row, struct workItem item){
	html_table_row = malloc(1000);
	char *acro,	*title,	*start,	*due,*group,*report,*attachment,*row;
	acro = title = start = due = group = report = attachment = row = NULL;
	acro = td(acro, item.acronym);
	title = td(title, item.title);
	start = td(start, item.startDate);
	due = td(due, item.dueDate);
	group = td(group, (item.group) ? "Group" : "Individual");
	report = td(report, (item.report) ? "Required" : "Optional");
	attachment = td(attachment, (item.attachment) ? "Required" : "Optional");
	row = malloc(1000);
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
	return html_table_row;
}