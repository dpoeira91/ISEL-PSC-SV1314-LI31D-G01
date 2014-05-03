#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(void * base, size_t nmemb, size_t size, (int)(*compare)(const void *, const void *)){
	void *p, *q, *chosen;
	int i, j;
	chosen = malloc(size);
	for (i = 1, p = base + size; i < nmemb; ++i, p += size){
		memcpy(chosen, p, size);
		for (q = p, j = i; j>0 && (*compare)(q - size, chosen) > 0; --j, q -= size){
			memcpy(q, q - size, size);
		}
		memcpy(p, chosen, size);
	}
	free(chosen);
}