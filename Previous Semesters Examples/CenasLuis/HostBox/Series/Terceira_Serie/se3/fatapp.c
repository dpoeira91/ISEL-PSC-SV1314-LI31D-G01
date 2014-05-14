#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/msdos_fs.h>
#include "fileList.h"

#define Converter( typeRet, Addr ) *((typeRet *)&Addr)
#define MAX_FULL_FILE_NAME_LENGTH 11
#define MAX_FILE_NAME_LENGTH 8
#define FIRST_CLUSTER 2
#define BPB_SIZE 512
#define FOLDER 0x10
#define DIRECTORY_ENTRY_SIZE 64
#define OFF_SET_TO_FILE_INFO 32
#define OFF_SET_TO_FILE_ATTRIBUTE 11
#define OFF_SET_TO_STARTING_CLUSTER_OF_FILE 26
#define OFF_SET_TO_FILE_SIZE 28
#define DIRECTORY_ENTRY_MARK 'A'

static FILE * fp;
static FAT * ft;
static struct fileList_node head;

const char * getBPB(FILE * file ){
	fileList_init(&head);
	fp = file;
    if ( fp == NULL ) {
		printf("Erro no carregamento do ficheiro\n");
		return NULL;
	}
	return readFromFile(BPB_SIZE);
}

FAT * fat_use(const char * partition ){  
	struct fat_boot_sector * newSector = (struct fat_boot_sector *) partition;
	unsigned short NumberOfBytesPerSector = Converter(unsigned short, newSector -> sector_size);
    ft = ((FAT *)malloc(sizeof (FAT)));
    ft -> NumberOfBytesPerCluster = NumberOfBytesPerSector * newSector -> sec_per_clus ;
    ft -> DataAreaStart = NumberOfBytesPerSector*newSector->reserved + (newSector->fats * (newSector->fat32_length * NumberOfBytesPerSector));
    return ft;
}

FFILE * fat_open(FAT * myFat, const char * fileName){
	const char ** myPath = getFilePath(fileName);
	if (&(*myPath[0]) == NULL) return NULL;
	bool isFolder = (myPath[1] == NULL) ? false : true;
	FFILE * newFile = searchForFile(myPath, FIRST_CLUSTER, getCluster(FIRST_CLUSTER, NULL , false) , OFF_SET_TO_FILE_INFO, isFolder, 0);
	free((void*)myPath);
	return newFile;
}

FFILE * searchForFile( const char ** myPath , unsigned short clusterNumber, const char *  actualCluster, unsigned short clusterIndex , bool isFolder , unsigned int deep ){
	FFILE * newFile = NULL;
	const char * fileName = (const char *)malloc(strlen(myPath[deep]));
	fileName = getPartOfName(myPath[deep] , isFolder );
	while ( * (actualCluster + clusterIndex ) == DIRECTORY_ENTRY_MARK ){
		newFile = isPartOfPath( actualCluster, clusterIndex , fileName, isFolder , clusterNumber , myPath, deep);
		if ( newFile != NULL ) break;			
		clusterIndex += DIRECTORY_ENTRY_SIZE;
		if (clusterIndex >=  ft -> NumberOfBytesPerCluster ) {
			actualCluster = getCluster(++clusterNumber, actualCluster , true );
			clusterIndex -=  ft -> NumberOfBytesPerCluster ;
		}
	}
	free((void*)fileName);
	free((void*)actualCluster);
	return newFile;
}

FFILE * isPartOfPath( const char * actualCluster, unsigned short clusterIndex , const char * fileName, bool isFolder , unsigned short clusterNumber , const char ** myPath , unsigned int deep ){
	FFILE * newFile = NULL;
	if (strncmp( (actualCluster + clusterIndex + OFF_SET_TO_FILE_INFO) , fileName , MAX_FULL_FILE_NAME_LENGTH) == false){
		if (isFolder && *(actualCluster + clusterIndex + OFF_SET_TO_FILE_INFO + OFF_SET_TO_FILE_ATTRIBUTE ) == FOLDER )
			newFile = searchForFile(myPath, clusterNumber+1, getCluster( Converter(unsigned short, *(actualCluster + clusterIndex + OFF_SET_TO_FILE_INFO + OFF_SET_TO_STARTING_CLUSTER_OF_FILE)) , NULL , false), DIRECTORY_ENTRY_SIZE, myPath[deep+2] , deep+1);
		else
			newFile = addFile(newFile, fileName, ( actualCluster + clusterIndex + OFF_SET_TO_FILE_INFO ) );
	}
	return newFile;
}

FFILE * addFile(FFILE * newFile , const char * fileName , const char * filePos){
	newFile = ((FFILE *)malloc(sizeof(FFILE)));
	struct fileList_node * fileToAdd = (struct fileList_node *)malloc(sizeof(struct fileList_node));
	newFile -> name = (char *)fileName;
	newFile -> startingCluster = Converter(unsigned short, *( filePos + OFF_SET_TO_STARTING_CLUSTER_OF_FILE ) );
	newFile -> size = Converter(unsigned int , *( filePos + OFF_SET_TO_FILE_SIZE ));
	fileToAdd -> file = newFile;
	fileList_insertAfter(&head, fileToAdd);
	return newFile;
}

const char * getCluster(unsigned short clusterNumber , const char * actualCluster , bool toFree ){
	if (clusterNumber != FIRST_CLUSTER && toFree == true )
		free((void*) actualCluster);
	fseek(fp , (ft-> DataAreaStart + (clusterNumber - FIRST_CLUSTER) * ft->NumberOfBytesPerCluster), SEEK_SET);
	return readFromFile(ft-> NumberOfBytesPerCluster);
}

const char * readFromFile( size_t size ){
    size_t nelems = 1;
    char * buffer = malloc(size);
    fread(buffer, size, nelems, fp);
    return (const char *)buffer;
}

const char * getPartOfName( const char * fileName , bool isFolder ){
	char * name = malloc(MAX_FULL_FILE_NAME_LENGTH+1);
	unsigned int numOfChars = 0;
	if ( isFolder )
		populateByFolderFormatting(fileName, name, numOfChars);
	else
		populateByFileFormatting(fileName, name, numOfChars);
	name[MAX_FULL_FILE_NAME_LENGTH] = '\0';
	return (const char *)name;
}

void populateByFolderFormatting( const char * fileName, char * name , unsigned int numOfChars){
	while ( (*fileName) ){
		name[numOfChars++] = (*fileName);
		fileName +=1;
	}
	while (numOfChars < MAX_FULL_FILE_NAME_LENGTH ) {
		name[numOfChars++] = ' ' ;
	}
}

void populateByFileFormatting ( const char * fileName, char * name , unsigned int numOfChars) {
	while ( (*fileName) ){
		if ( (*fileName) == '.')
			while ( numOfChars < MAX_FILE_NAME_LENGTH ){
				name [numOfChars++] = ' ';
			}
		else 
			name[numOfChars++] = (*fileName);
		fileName +=1;
	}
}

int fat_read(FFILE * f, size_t len , void * buf ){
	if ( f == NULL ) return true;
	const char * actualCluster = getCluster( f-> startingCluster , NULL , false);
	buf = memcpy( buf, (const void*)actualCluster, len);
	free((void*)actualCluster);
	return false;
}

int fat_close(FFILE * f){
	unsigned char isFile = lookForFileInList(f);
	if (isFile){
		free((void*)f->name);
		free((void*)f);
	}
	return isFile;
}

unsigned char lookForFileInList(FFILE * f){
	fileList_node * headCopy = (&head)->next;
	while ( headCopy != (&head) ){
		if ( (headCopy -> file) == f ){
			free((void*)headCopy);
			fileList_remove(headCopy);
			return true;
		}
		headCopy = headCopy -> next;
	}
	return false;
}

int fat_release(FAT * fat){
	if (fileList_isEmpty(&head)){
		free((void*) fat);
		return false;
	}
	return true;
}

const char ** getFilePath( const char * filePath ){
	char ** res  = (char**)malloc(strlen(filePath));
	char *  p    = strtok ((char*)filePath, "/");
	int index = 0;
	
	while (p) {
		res[index++] = p;
		p = strtok (NULL, "/");
	}
	
	res[index] = '\0';
	return (const char **) res;
}
