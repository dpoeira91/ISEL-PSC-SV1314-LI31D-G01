#include <stdbool.h>

struct dlist_node {
	struct dlist_node * prev;
	struct dlist_node * next;
};

void dlist_init(struct dlist_node * head);

bool dlist_isEmpty(struct dlist_node * head);

void dlist_insertAfter(struct dlist_node * ref_node,
                       struct dlist_node * new_node);

#define dlist_insertHead dlist_insertAfter

#define dlist_insertBefore(REF_NODE, NEW_NODE)\
	dlist_insertAfter((REF_NODE)->prev, NEW_NODE)

#define dlist_insertTail dlist_insertBefore
