#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <ctype.h>
#include "fat32libfunc.h"
#include "rdfat.h"

int main(int argc, char * argv[]){
	FILE * fp = fopen((const char *)argv[1], "rb");
	void * h = dlopen( "./fat32lib.so" , RTLD_NOW );
	*(void**)&getBPB = dlsym(h, "getBPB");
	*(void**)&fat_use = dlsym(h, "fat_use");
	*(void**)&fat_open = dlsym(h, "fat_open");
	*(void**)&fat_read = dlsym(h, "fat_read");
	*(void**)&fat_close = dlsym(h, "fat_close");
	*(void**)&fat_release = dlsym(h, "fat_release");
	const char * buffer = getBPB(fp);
	FAT * actualFat = fat_use( buffer );
	lookAndRead( actualFat , getPathUpperCased((char *)argv[2]) ,   (const char *)argv[3] );
	fat_release(actualFat);
	free((void*)buffer);
	dlclose((void*)h);
	fclose(fp);
	return 0;
}

void lookAndRead( FAT * fat, const char * fileName , const char * destinationFileName ){
	FFILE * file = fat_open(fat, fileName);
	if (file == NULL){
		printf("Ficheiro inexistente. \n");
		free((void*) fileName);
		return;
	}
	size_t len = file-> size;
	len += (len+3) && 0x3;
	const char * buf = (const char *)(malloc(len));
	fat_read(file, len , (void*)buf);
	writeToFile((const char *)buf, destinationFileName );
	fat_close(file);
	free((void*) fileName);
}

void writeToFile( const char * buf , const char * destinationFileName ){
	FILE * newFile;
	newFile = fopen( destinationFileName , "w");
	fprintf(newFile, "%s" , buf);
	fclose(newFile);
	free((void*)buf);
}

const char * getPathUpperCased(char * path){
	char * upperCasedPath = (char *)(malloc(strlen(path)));
	unsigned int position = 0;
	while (*path){
		upperCasedPath[position++] = toupper(*path);
		++path;
	}
	return (const char *)upperCasedPath;
}
