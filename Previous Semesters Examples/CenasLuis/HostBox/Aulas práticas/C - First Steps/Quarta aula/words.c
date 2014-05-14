#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

#define WORD_LEN 256

struct word_entry {
	char word[WORD_LEN];
	unsigned count;
};

typedef struct word_entry WordEntry;

WordEntry words[1024];
unsigned num_words = 0 ;

WordEntry * findWord(char * word ) {return NULL;}

void processWord(char * word ) {
	WordEntry *entry = findWord(word);
	if (entry){
		entry -> count +=1 ;
	}
	else{
		entry = &words (num_words);
		entry -> count = 1 ;
		strcpy(entry->word, word);
		num_words +=1;
	}
}


int main(){
	int c;
	bool inword = false;
	
	char word[WORD_LEN];
	unsigned wlen = 0;

	while (( c = getchar() ) != EOF ){
		if (inword){
			if (isspace(c)){
				inword = false;
				word[wlen]= '\0';
				processWord(word);
			}
		}
		else {
			if (!isspace(c)){
				inword = true;
				wlen = 0;
			}
		}
		
		if(inword){
			word[wlen++] = c;
		}
	}
	return 0;
}
