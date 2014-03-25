#include <stdio.h>

#define MAX_STRING_SIZE 1000

char *xstrstr(const char * haystack , const char * needle);

int main(){
	char lines[MAX_STRING_SIZE],c,*strcur,*result;
	const char batatas[] = "batatas";
	int i = 0;
	while ((c = getchar()) != EOF && i<MAX_STRING_SIZE){
		lines[i++] = c;}
	if (i < MAX_STRING_SIZE)
		lines[i] = '\0';
	i = 0;
	strcur = &lines[i];
	printf("%s\n",strcur);
	while ((c = lines[i++]) != '\0'){
		if (c == '\n'){
			lines[i - 1] = '\0';
			result = xstrstr(strcur, batatas);
			if (result != NULL)
				printf("%s \n", strcur);
			strcur = &lines[i];
		}
	}
	result = xstrstr(strcur, batatas);
	if (result != NULL)
		printf("%s \n", strcur);

}
