#include <stdio.h>
#include "bomb.h"
 
void doPhase(const char * prompt, int (*phase)(char *), const char * okmsg) {
	char line[256];

	fputs(prompt, stdout);
	if (!fgets(line, sizeof(line), stdin)) {
		puts("Adeus.");
		exit(0);
	}
	line[strlen(line) - 1] = 0;

	if (phase(line))
		puts(okmsg);
	else
		explode_bomb();
}

int main(int argc, char * argv[]) {

	bomb_setup();
	
	doPhase("Senha 1: ", phase1, ok_messages[0]);
	doPhase("Senha 2: ", phase2, ok_messages[1]);
 
	return 0;
}

