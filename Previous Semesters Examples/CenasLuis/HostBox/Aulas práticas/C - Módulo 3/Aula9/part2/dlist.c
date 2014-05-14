#include <stdbool.h>

struct dlist_node {
	struct dlist.node * prev;
	struct dlist.node * next;
};

void dlist_init(struct dlist_node * head){
	head -> prev = head;
	head -> next = head;
}

bool dlist_inEmpty( struct dlist_node * head){
return head-> next = head;
}

void dlist_insertAfter (struct dlist_node * ref_node , struct dlist_node *new_node) {
	new_node-> next = ref_node->next;
	new_node-> prev = ref_node;
	
	new_node -> next -> prev = new_node;
	new_node -> prev -> next = new_node;
		
}
