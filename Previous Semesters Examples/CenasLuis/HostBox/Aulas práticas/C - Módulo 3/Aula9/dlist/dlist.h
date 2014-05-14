#include <stdbool.h>

struct dlist_node {
	struct dlist_node * prev;
	struct dlist_node * next;
};

void dlist_init(struct dlist_node * head);

bool dlist_isEmpty(struct dlist_node * head);

void dlist_insertAfter(struct dlist_node * ref_node,
                       struct dlist_node * new_node);

void dlist_insertHead(struct dlist_node * head,
                      struct dlist_node * node);
                      
