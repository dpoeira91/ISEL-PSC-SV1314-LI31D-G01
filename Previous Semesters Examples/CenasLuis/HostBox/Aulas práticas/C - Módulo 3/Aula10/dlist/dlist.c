#include "dlist.h"

void dlist_init(struct dlist_node * head) {
	head->prev = head->next = head;
}

bool dlist_isEmpty(struct dlist_node * head) {
	return head->next == head;
}

void dlist_insertAfter(struct dlist_node * ref_node,
                       struct dlist_node * new_node) {
	new_node->prev = ref_node;
	new_node->next = ref_node->next;
	
	new_node->next->prev = new_node;
	new_node->prev->next = new_node;
}
