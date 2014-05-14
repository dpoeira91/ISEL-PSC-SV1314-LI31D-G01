#include <stdbool.h>

struct dlist_node {
	struct dlist_node * prev;
	struct dlist_node * next;
};

typedef struct dlist_node dnode_t;
typedef struct dlist_node dlist_t;

void dlist_init(dnode_t * head);

bool dlist_isEmpty(dnode_t * head);

void dlist_insertAfter(dnode_t * ref_node,
                       dnode_t * new_node);

static inline void dlist_insertHead (dnode_t * head, dnode_t new_node){
	dlist_insertAfter(head, new_node);
}

static inline void dlist_insertBefore (dnode_t * ref_node, dnode_t new_node){
	dlist_insertAfter((ref_node)->prev, new_node);
}

static inline void dlist_insertTail (dnode_t * head, dnode_t new_node){
	dlist_insertBefore(head, new_node);
}

void dlist_remove(dnode_t * node);
