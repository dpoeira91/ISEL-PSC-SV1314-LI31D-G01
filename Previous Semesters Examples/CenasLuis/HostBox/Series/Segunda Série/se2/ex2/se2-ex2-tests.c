#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>

void printout(char * str);

// BEWARE:
//   No error checks nor timeouts are used in this test.
//   If the tested function hangs, this test will hang too.
//   Under some conditions, the test may succeed even if the tested
//   function crashes.
bool test_basic_printout() {
	char tst_str[] = "PSC SE2 EX2\n";
	char res_str[sizeof tst_str];
	int  fd[2];

	memset(res_str, 0, sizeof res_str);

	// Create an auxiliar process (with fork) to run the test function.
	// A pipe is used to read back the string from the standard
	// output of the auxiliar process.
	pipe(fd);
	if (fork() == 0) {
		// Connects the pipe to the standard output descriptor.
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		
		// Executes the tested function.
		printout(tst_str);
		exit(0);
	}

	// Read whatever comes out from the standard output of the auxiliar process.
	int res, cur = 0, total = sizeof res_str - 1;
	close(fd[1]);
	while (cur < total && (res = read(fd[0], res_str + cur, total - cur)) > 0) cur += res;
	close(fd[0]);
	
	// Evaluate the result.
	return cur == total && memcmp(tst_str, res_str, sizeof tst_str) == 0;
}

int main() {
	if (test_basic_printout()) {
		return 0;	
	}
	printf("se2-ex2: at least one test has failed\n");
	return 1;
}
