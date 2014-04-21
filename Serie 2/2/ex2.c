#include <stdio.h>
#include <string.h>

/* xstrpbrk: assembly version of the strpbrk function */
char *xstrpbrk(const char *cs, const char *ct);

int main()
{
    char *p;
    int n = 0;
    
    p = xstrpbrk("", "");
    n += p == NULL;
    
    p = xstrpbrk("abc", "abc");
    n += strcmp(p, "abc") == 0;

    p = xstrpbrk("abc", "b");
    n += strcmp(p, "bc") == 0;

    p = xstrpbrk("abc", "c");
    n += strcmp(p, "c") == 0;

    p = xstrpbrk("abc", "d");
    n += p == NULL;
    
    if (n == 5) {
		printf("--all tests succeeded!\n");
		return 0;
	} else {
    	printf("--at least one test failed!\n");
		return 1;
	}
}

