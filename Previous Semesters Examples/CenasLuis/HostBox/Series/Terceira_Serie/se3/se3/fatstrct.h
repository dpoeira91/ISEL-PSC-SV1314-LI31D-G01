typedef struct FAT{
	unsigned int NumberOfBytesPerCluster;
	unsigned int DataAreaStart;
} FAT;

typedef struct FFILE{
	char * name;
	unsigned short startingCluster;
	unsigned int size;
} FFILE;
