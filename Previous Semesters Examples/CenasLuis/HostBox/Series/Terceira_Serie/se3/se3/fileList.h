#include <stdbool.h>
#include "fatlib.h"

struct fileList_node {
	FFILE * file;
	struct fileList_node * prev;
	struct fileList_node * next;
};

typedef struct fileList_node fileList_node;

void fileList_init(fileList_node * head);

bool fileList_isEmpty(fileList_node * head);

void fileList_insertAfter(fileList_node * ref_node, fileList_node * new_node);

void fileList_remove( fileList_node * nodeToRemove );

#define fileList_insertHead fileList_insertAfter

#define fileList_insertBefore(REF_NODE, NEW_NODE)\
	fileList_insertAfter((REF_NODE)->prev, NEW_NODE)

#define fileList_insertTail fileList_insertBefore
