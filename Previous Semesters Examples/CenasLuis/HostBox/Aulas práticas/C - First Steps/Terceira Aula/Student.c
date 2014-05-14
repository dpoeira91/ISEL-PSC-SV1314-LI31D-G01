#include <stdio.h>

enum Program { INFO, TELE, MULT, QUIM };

typedef enum Program program_t;

struct Student {
	char name[256];
	unsigned number;
	program_t program;
	float average;
};

typedef struct Student student_t;

void printProgram (program_t prog){
	switch(prog){
		case INFO:
			printf("LEIC ");
			break;
		case TELE:
			printf("LEETC ");
			break;
		case MULT:
			printf("LERCM ");
			break;
		case QUIM:
			printf("LEQB ");
			break;
		default:
			printf("ISEL ");
			break;
	}
}

student_t theStudent = { "João Trindade", 19723 , INFO, 20.0 };

void printStudent(struct Student s){
	printf("{ name = \"%s\"; number = %u; program = ", s.name, s.number);
	printProgram(s.program);
	printf("} \n");
}

void setStudentNumber(student_t * s, unsigned n){
	(*s).number = n;
}


int main () {
	setStudentNumber( &theStudent, 88888);
	printStudent(theStudent);
	return 0;
}
