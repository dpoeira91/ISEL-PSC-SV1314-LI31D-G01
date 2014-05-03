#include<stdio.h>
#include<string.h>

void sort(void * base, size_t nmemb, size_t size, int(*compare)(const void *, const void *));

int __strcmp(const void *d1, const void *d2){
	return strcmp(*(char * *)d1, *(char * *)d2);
}

char *data[] = {"9999","888","111","03"};

int main(){
	int i;
	sort(data, sizeof(data) / sizeof(*data), sizeof(*data), __strcmp);
	for (i = 0; i < sizeof(data) / sizeof(*data); i++)
		print("%s\n", data[i]);
	return 0;
}