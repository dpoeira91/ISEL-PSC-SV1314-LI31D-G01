#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <jansson.h>

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

json_t * http_get_json(const char * url, int * retcod);

json_t * find_class(json_t * root, char * acronym, char * semester , char * class_name){
	json_t *classes, *acro, *sem, *name,*current_class ,*links,*self,*class_link;
	const char *value;
	size_t i;
	int retcod[] = { 0 };
	if (!json_is_object(root)) {
		fprintf(stderr, "***error: root is not an object\n");
		return NULL;
	}
	classes = json_object_get(root, "classes");
	if (!json_is_array(classes)) {
		fprintf(stderr, "***error: classes is not an array\n");
		return NULL;
	}
	for (i = 0; i < json_array_size(classes); i++){
		/* get the classes[i] object */
		current_class = json_array_get(classes, i);
		if (!json_is_object(current_class)) {
			fprintf(stderr, "***error: classes[%d] is not an object\n", i);
			return NULL;
		}
		acro = json_object_get(current_class, "courseUnitShortName");
		if (!json_is_string(acro)) {
			fprintf(stderr, "***error: classes[%d].courseUnitShortName is not a string\n", i);
			return NULL;
		}
		value = json_string_value(acro);
		if ((strcmp(value, acronym)) != 0)
			continue;
		sem = json_object_get(current_class, "lectiveSemesterShortName");
		if (!json_is_string(sem)) {
			fprintf(stderr, "***error: classes[%d].lectiveSemesterShortName is not a string\n", i);
			return NULL;
		}
		value = json_string_value(sem);
		if ((strcmp(value, semester)) != 0)
			continue;
		name = json_object_get(current_class, "className");
		if (!json_is_string(sem)) {
			fprintf(stderr, "***error: classes[%d].className is not a string\n", i);
			return NULL;
		}
		value = json_string_value(name);
		if ((strcmp(value, class_name)) != 0)
			continue;
		links = json_object_get(current_class, "_links");
		if (!json_is_object(links)) {
			fprintf(stderr, "***error: classes[%d]._links is not an object\n", i);
			return NULL;
		}
		self = json_object_get(links, "self");
		if (!json_is_string(self)) {
			fprintf(stderr, "***error: classes[%d]._links.self is not a string\n", i);
			return NULL;
		}
		value = json_string_value(self);
		class_link = http_get_json(value, retcod);
		return class_link;
	}
	return NULL;
}

json_t * get_projects(json_t * root_class){
	json_t *links, *workItems,*projects;
	const char * url;
	int retcod[] = { 0 };
	if (!json_is_object(root_class)) {
		fprintf(stderr, "***error: root_class is not an object\n");
		return NULL;
	}
	links = json_object_get(root_class, "_links");
	if (!json_is_object(links)) {
		fprintf(stderr, "***error: root_class._links is not an object\n");
		return NULL;
	}
	workItems = json_object_get(links, "workItems");
	if (!json_is_string(workItems)) {
		fprintf(stderr, "***error: root_class._links.workItems is not a string\n");
		return NULL;
	}
	url = json_string_value(workItems);
	projects = http_get_json(url, retcod);
	projects = json_object_get(projects, "workItems");
	if (!json_is_array(projects)){
		fprintf(stderr, "***error: workItems is not an array\n");
		return NULL;
	}
	return projects;
}

json_t * get_workItem(json_t * root_projects, int index){
	json_t *project, *links, *self ,*workItem;
	const char * url;
	int retcod[] = { 0 };
	project = json_array_get(root_projects, index);
	if (!json_is_object(project)) {
		fprintf(stderr, "***error: projects[%d] is not an object\n", index);
		return NULL;
	}
	links = json_object_get(project, "_links");
	if (!json_is_object(links)) {
		fprintf(stderr, "***error: projects[%d]._links is not an object\n",index);
		return NULL;
	}
	self = json_object_get(links, "self");
	if (!json_is_string(self)) {
		fprintf(stderr, "***error: projects[%d]._links.self is not a string\n", index);
		return NULL;
	}
	url = json_string_value(self);
	workItem = http_get_json(url, retcod);
	return workItem;
}

struct workItem parse_workItem(json_t * workItem){
	json_t *id, *acronym, *title, *group, *startDate, 
		*dueDate, *documentInfo, *attachmentInfo,
		*reportInfo, *attachmentUploadInfo;
	struct workItem item = { .id = -1,
							.acronym = NULL,
							.title = NULL,
							.startDate = NULL,
							.dueDate = NULL,
							.document = NULL,
							.attachment_name = NULL,
							.group = 0, 
							.report = 0, 
							.attachment = 0 };
	id = json_object_get(workItem, "id");
	if (!json_is_integer(id)){
		fprintf(stderr, "***error: workItem.id is not a integer\n");
		return item;
	}
	acronym = json_object_get(workItem, "acronym");
	if (!json_is_string(acronym)) {
		fprintf(stderr, "***error: workitem.acronym is not a string\n");
		return item;
	}
	title = json_object_get(workItem, "title");
	if (!json_is_string(title)) {
		fprintf(stderr, "***error: workitem.title is not a string\n");
		return item;
	}
	startDate = json_object_get(workItem, "startDate");
	if (!json_is_string(startDate)) {
		fprintf(stderr, "***error: workitem.startDate is not a string\n");
		return item;
	}
	dueDate = json_object_get(workItem, "dueDate");
	if (!json_is_string(dueDate)) {
		fprintf(stderr, "***error: workitem.dueDate is not a string\n");
		return item;
	}
	group = json_object_get(workItem, "requiresGroupSubmission");
	if (!json_is_boolean(group)){
		fprintf(stderr, "***error: workitem.requiresGroupSubmission is not a boolean\n");
		return item;
	}
	documentInfo = json_object_get(workItem, "infoDocument");
	if (!json_is_object(documentInfo)){
		fprintf(stderr, "***error: workitem.infoDocument is not an object\n");
		return item;
	}
	documentInfo = json_object_get(documentInfo, "fileName");
	if (!json_is_string(documentInfo)) {
		fprintf(stderr, "***error: workitem.infoDocument.fileName is not a string\n");
		return item;
	}
	attachmentInfo = json_object_get(workItem, "attachmentsDocument");
	if ((!json_is_object(attachmentInfo)) && attachmentInfo != NULL){
		fprintf(stderr, "***error: workitem.attachmentsDocument is not an object\n");
		return item;
	}
	if (attachmentInfo != NULL){
		attachmentInfo = json_object_get(attachmentInfo, "fileName");
		if (!json_is_string(attachmentInfo)) {
			fprintf(stderr, "***error: workitem.attachmentsDocument.fileName is not a string\n");
			return item;
		}
	}
	reportInfo = json_object_get(workItem, "reportUploadInfo");
	if (!json_is_object(reportInfo)){
		fprintf(stderr, "***error: workitem.reportUploadInfo is not an object\n");
		return item;
	}
	reportInfo = json_object_get(reportInfo, "isRequired");
	if (!json_is_boolean(reportInfo)){
		fprintf(stderr, "***error: workitem.reportUploadInfo.isRequired is not a boolean\n");
		return item;
	}
	attachmentUploadInfo = json_object_get(workItem, "attachmentUploadInfo");
	if (!json_is_object(attachmentUploadInfo)){
		fprintf(stderr, "***error: workitem.attachmentUploadInfo is not an object\n");
		return item;
	}
	attachmentUploadInfo = json_object_get(attachmentUploadInfo, "isRequired");
	if (!json_is_boolean(reportInfo)){
		fprintf(stderr, "***error: workitem.attachmentUploadInfo.isRequired is not a boolean\n");
		return item;
	}
	item.id = json_integer_value(id);
	item.acronym = json_string_value(acronym);
	item.title = json_string_value(title);
	item.startDate = json_string_value(startDate);
	item.dueDate = json_string_value(dueDate);
	item.document = json_string_value(documentInfo);
	item.attachment_name = (attachmentInfo == NULL) ? NULL : json_string_value(attachmentInfo);
	item.group = json_is_true(group);
	item.report = json_is_true(reportInfo);
	item.attachment = json_is_true(attachmentUploadInfo);
	return item;
}