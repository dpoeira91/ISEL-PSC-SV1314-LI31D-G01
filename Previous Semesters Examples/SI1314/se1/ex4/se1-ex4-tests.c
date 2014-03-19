#include <stdbool.h>
#include <stdio.h>

typedef struct stnode {
	unsigned number;
	char * name;
	unsigned section;
	struct stnode * next;
} StudentNode; 

void buildStudentSections(StudentNode * sections[], StudentNode students[], size_t num_students);

bool test_one_student() {
	StudentNode student = { 11111, "Afonso Henriques", 1, NULL };
	StudentNode * sections[3] = { NULL, NULL, NULL };
	
	buildStudentSections(sections, &student, 1);
	
	return sections[0] == NULL && sections[1] == &student && sections[2] == NULL;
}

bool test_two_students_on_non_empty_list() {
	StudentNode old_student = { 11111, "Afonso Henriques", 2, NULL };
	StudentNode new_students[] = {
		{ 22222, "Sancho I", 2, NULL },
		{ 33333, "Afonso II", 0, NULL }
	};
	StudentNode * sections[3] = { NULL, NULL, &old_student };
	
	buildStudentSections(sections, new_students, 2);
	
	return sections[0] == &new_students[1] && sections[1] == NULL && sections[2] == &new_students[0] && new_students[0].next == &old_student;
}

int main() {
	if (test_one_student() &&
	    test_two_students_on_non_empty_list()) {
		return 0;	
	}
	printf("se1-ex4: at least one test has failed\n");
	return 1;
}
