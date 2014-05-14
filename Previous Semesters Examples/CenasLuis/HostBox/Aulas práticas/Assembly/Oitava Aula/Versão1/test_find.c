#include <stddef.h>
#include <stdbool.h>

void * find_in (void * values , size_t nelems, size_t esize, bool (*is_better) (void * new, void * old));

bool is_shorter(void * new, void *old ){
	return strlen(*(char**)new) < strlen(*(char**)old); 
}

char * find_shorter_string (char * strs [] , size_t len) {
	return * (char **) find_in(strs, len, sizeof strs[0] , is_shorter);
}

int main(int argc , char * argv[]){	
	char * shorter;
	shorter = find_shorter_string(argv +1 , argc -1);
	puts(shorter);
	return 0;
}
