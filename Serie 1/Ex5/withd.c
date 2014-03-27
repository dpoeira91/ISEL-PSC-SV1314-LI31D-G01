#include <stdio.h>
//Define
#define MAX_STRING_SIZE 1000
//Functions used
char *xstrstr(const char * haystack , const char * needle);

int main(int argc, char **argv){
	/*Declares lines which will be used to store all the lines from the standard input.
	c which will serve to read and add chars to the lines variable.
	The pointer *strcur will be usefull to read lines variable line by line.
	*result will store the results of the multiple calls to the xstrstr function one by one.
	The keyword pointer will be used to read all the keywords given to the program by argument in the command line*/
	char lines[MAX_STRING_SIZE],c,*strcur,*result, *keyword;

	/*i will be used to write and later read on/from (respectivly) the lines variable.
	kidx will be used to get all the keywords from the argv variavle (which represent the keywords given by argument)*/
	int i = 0,kidx;

	/*this cicle will read all the chars from the standard input and store them in the variable lines until it either finds the end of file or i reaches the MAX_STRING_SIZE*/
	while ((c = getchar()) != EOF && i<MAX_STRING_SIZE)
	{
		lines[i++] = c;
	}
	/*this line garantees that even if i didn't reach MAX_STRING_SIZE the index after the last char read will be the \0 wich represents the end of a string*/
	if (i < MAX_STRING_SIZE)
		lines[i] = '\0';

	/*Here we set the variables to run in a new cicle, i is now 0 so that it can help read chars from the lines variable.
	strcur now points to the address of the first char in the lines variable.
	Also, an empty line is printed so it is easier to distinguish the input from the output*/
	i = 0;
	strcur = &lines[i];
	printf("\n");

	/*This cicle will read all the chars from the lines variable.
	When it finds an end of lines represented by the char \n he replaces it with the \0 wich is a termination for a string.
	Then it places the NULL value in the result variable to run a second cicle until it is either not NULL, meaning we found a match, or we run out of keywords to look for.
	This inner cicle calls the function xstrstr with the parameters strcur wich now points to a line instead of the original full lines variable, and the current keyword we are checking.
	After the inner cicle ends, if the result is not NULL, meaning we found a match, the line pointed by strcur is printed.
	After that strcur will point to the char next to the \0 we replaced when we found the \n and we go back to the begining of the cicle*/
	while ((c = lines[i++]) != '\0'){
		if (c == '\n'){
			lines[i - 1] = '\0';
			result = NULL;
			for (kidx = 1; (kidx < argc) && (result == NULL); kidx++){
				keyword = (argv)[kidx];
				result = xstrstr(strcur, keyword);
			}	
			if (result != NULL)
				printf("%s \n", strcur);
			strcur = &lines[i];
		}
	}
	return 0;

}
