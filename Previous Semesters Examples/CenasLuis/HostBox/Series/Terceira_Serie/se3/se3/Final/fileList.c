#include "fileList.h"

void fileList_init(fileList_node * head) {
	head->prev = head->next = head;
}

bool fileList_isEmpty(fileList_node * head) {
	return head->next == head;
}

void fileList_insertAfter(fileList_node * ref_node,
                       fileList_node * new_node) {
	new_node->prev = ref_node;
	new_node->next = ref_node->next;
	
	new_node->next->prev = new_node;
	new_node->prev->next = new_node;
}

void fileList_remove( fileList_node * nodeToRemove ) {
	
	nodeToRemove -> prev -> next = nodeToRemove -> next ;
	nodeToRemove -> next -> prev = nodeToRemove -> prev ;	
}
