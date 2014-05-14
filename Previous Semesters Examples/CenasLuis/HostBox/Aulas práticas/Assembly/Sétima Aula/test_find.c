#include <stdio.h>
#include <stdstr.h>

int find_min(int * values , size_t len);
int find_max(int * values , size_t len);
const char * find_first_string(const char * strs , size_t len);
int values [] = {3,-1,7,8,15,31,0};

const char * strs[] = {"PSC","LEIC","LI31D"};


int main(){
	
	int min, max;
	
	min = find_min(values, sizeof values/ sizeof values[0]);
	max = find_max(values, sizeof values / sizeof values[0]);
	
	printf("min = %d\nmax = %d \n", min, max);
	
	first_str = find_first_string(strs,sizeof strs / sizeof strs[0]);
	
	printf("Primeira string = %s \n", first_str);
	
	return 0;
}
