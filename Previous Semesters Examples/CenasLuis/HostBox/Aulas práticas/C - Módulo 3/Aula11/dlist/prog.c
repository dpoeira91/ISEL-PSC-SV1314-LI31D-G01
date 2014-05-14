#include <stdio.h>
#include <assert.h>
#include "dlist.h"

struct dlist_node head;

struct dlist_node node1;
struct dlist_node node2;
struct dlist_node node3;
struct dlist_node node4;

int main() {
	
	dlist_init(&head);
	
	printf("empty? %s\n", dlist_isEmpty(&head) ? "true" : "false");
	
	dlist_insertHead(&head, &node3);
	dlist_insertHead(&head, &node1);
	
	dlist_insertAfter(&node1, &node2);
	
	dlist_insertHead(&head,&node4);
	
	printf("empty? %s\n", dlist_isEmpty(&head) ? "true" : "false");

	assert(head.next == &node1);
	assert(head.next->next == &node2);
	assert(head.next->next->next == &node3);
/*	assert(head.next->next->next->next == &node4);
	assert(head.next->next->next->next->next == &head);
*/	return 0;
}

