#include <stddef.h>

typedef struct stnode {
	unsigned number;
	char * name;
	unsigned section;
	struct stnode * next;
} StudentNode; 

void buildStudentSections(StudentNode * sections[], StudentNode students[], size_t num_students) {
	int i=0;
	int sec;
	for(;i<num_students;++i){	
		sec = students[i].section;
		students[i].next = sections[sec];	// next do student aponta student que esta a ser apontado por section 
		sections[sec] = &students[i];		// section aponta novo student	
	}	
}
