#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include "fatstrct.h"
const char * getBPB( FILE * fp );
FAT * fat_use(const char * partition );
FFILE * fat_open(FAT * myFat, const char * fileName);
int fat_read(FFILE * f, size_t len , void * buf );
int fat_close(FFILE * f);
int fat_release(FAT * fat);

const char * getCluster(unsigned short clusterNumber , const char * actualCluster , bool toFree);

FFILE * addFile(FFILE * newFile, const char * fileName, const char * filePos);

const char * readFromFile(size_t size);

unsigned char lookForFileInList(FFILE * f);

FFILE * searchForFile( const char ** myPath , unsigned short clusterNumber, const char *  actualCluster, unsigned short clusterIndex , bool isFolder , unsigned int deep );

FFILE * isPartOfPath( const char * actualCluster, unsigned short clusterIndex , const char * fileName, bool isFolder , unsigned short clusterNumber , const char ** myPath , unsigned int deep );

const char * getPath( const char * fileName , bool isFolder);

const char ** getFilePath( const char * filePath );

const char * getPartOfName( const char * fileName , bool isFolder );

void populateByFolderFormatting( const char * fileName, char * name , unsigned int numOfChars);

void populateByFileFormatting ( const char * fileName, char * name , unsigned int numOfChars);
