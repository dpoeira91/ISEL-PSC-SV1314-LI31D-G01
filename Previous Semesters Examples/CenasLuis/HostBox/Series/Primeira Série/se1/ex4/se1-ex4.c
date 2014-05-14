#include <stddef.h>

typedef struct stnode {
	unsigned number;
	char * name;
	unsigned section;
	struct stnode * next;
} StudentNode; 

void buildStudentSections(StudentNode * sections[], StudentNode students[], size_t num_students) {
	while (num_students--){
		if (sections[students[num_students].section] == NULL)
			sections[students[num_students].section] = &students[num_students];
		else{
			students[num_students].next = sections[students[num_students].section];
			sections[students[num_students].section] = &students[num_students];
		}
	}
}
