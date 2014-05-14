#include "fatstrct.h"

void * (*getBPB) (FILE * fp);
void * (*fat_use) (const char * partition);
void * (*fat_open) (FAT * fat , const char * name);
void * (*fat_read) (FFILE * f , size_t len, void * buf);
void * (*fat_close) (FFILE * f);
void * (*fat_release) (FAT * fat);
