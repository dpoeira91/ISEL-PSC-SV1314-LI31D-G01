#include <stdio.h>

#define MAX_STRING_SIZE 1000

char *xstrstr(const char * haystack , const char * needle);

int main(int argc, char **argv){
	char lines[MAX_STRING_SIZE],c,*strcur,*result;
	const char * keyword;
	int i = 0,kidx;
	while ((c = getchar()) != EOF && i<MAX_STRING_SIZE){
		lines[i++] = c;}
	if (i < MAX_STRING_SIZE)
		lines[i] = '\0';
	i = 0;
	strcur = &lines[i];
	printf("\n",strcur);
	while ((c = lines[i++]) != '\0'){
		if (c == '\n'){
			lines[i - 1] = '\0';
			result = NULL;
			for (kidx = 1; (kidx <= argc)&&(result == NULL); kidx++){
				keyword = (*argv)+(kidx*sizeof(*argv));
				result = xstrstr(strcur, keyword);
			}	
			if (result != NULL)
				printf("%s \n", strcur);
			strcur = &lines[i];
		}
	}
	result = xstrstr(strcur, keyword);
	if (result != NULL)
		printf("%s \n", strcur);

}
