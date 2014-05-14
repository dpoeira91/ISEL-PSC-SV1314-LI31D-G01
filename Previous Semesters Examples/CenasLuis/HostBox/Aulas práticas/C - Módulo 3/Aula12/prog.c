#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define TEST1_SIZE 16

void test1(){
	void * mem = xmalloc(TEST1_SIZE);
	
	for (int i = 0 ; i < TEST1_SIZE ; ++i) {
		((char *) mem) [i] = 0;
	}
	
	xfree(mem);
}

struct mydata {
	char name[16];
	unsigned num;	
};

void test2(){
	struct mydata * pdata = (struct mydata *) xmalloc (sizeof(struct mydata));

	strcpy(pdata -> name , "PSC");
	pdata-> num = 1000;
	xfree(pdata);

}

#define TEST3_SIZE1 1014
#define TEST3_SIZE2 4096

void test3(){
	void * mem1 = xmalloc(TEST3_SIZE1);
	void * mem2 = xmalloc(TEST3_SIZE2);

	assert (mem1 != NULL);
	assert (mem2 != NULL);
	
	xfree(mem1);
	xfree(mem2);
}

int main(){
	test1();
	test2();
	test3();
	return 0;
}
