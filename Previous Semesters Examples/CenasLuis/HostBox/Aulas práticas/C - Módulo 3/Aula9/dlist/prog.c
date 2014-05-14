#include <stdio.h>
#include "dlist.h"

struct dlist_node head;

struct dlist_node node1;
struct dlist_node node2;
struct dlist_node node3;

int main() {
	
	dlist_init(&head);
	
	printf("empty? %s\n", dlist_isEmpty(&head) ? "true" : "false");
	
	dlist_insertHead(&head, &node3);
	dlist_insertHead(&head, &node1);
	
	dlist_insertAfter(&node1, &node2);
	
	printf("empty? %s\n", dlist_isEmpty(&head) ? "true" : "false");

	return 0;
}
