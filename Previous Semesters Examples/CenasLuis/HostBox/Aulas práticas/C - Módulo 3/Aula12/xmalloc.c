	#include "xmalloc.h"
	#include <stdbool.h>
	#include "dlist.h"
	
	#define CONTAINING_RECORD(addr, type, field) \
			((type *) ((char *) (addr))  - offsetof (type, field));
	
	#define ALLOC_SPACE 4*1024*1024
	
	char space[ALLOC_SPACE];
	
	dlist_t free_list;
	
	typedef struct mblock {
		unsigned size;
		dnode_t node;
	} mblock_t;
	
	static bool init_done;
	
	static void xmalloc_init(){
		dlist_init(&free_list);
		
		mblock_t * pblock = (mblock_t * ) space;
		pblock-> size = ALLOC_SPACE - 4;
		
		dlist_insertHead(&free_list, &pblock->node);
		
		init_done = true;
	}
	
	void * xmalloc(size_t size){
		if (!init_done) xmalloc_init();
		
		size = (size+3) & 0x3;
		
		if (size < 8 )
		size = 8;
		
		for ( dnote_t * pcurr == free_list->next ; pcurr != &free_list; pcurr = pcurr.next){
			mblock_t *pblock = (mblock_t * )(((char *)pcurr) - 4);
			if (pblock -> size >= size){
				if ( size + 4 <= pblock -> size -8){
					mblock_t * pnewblock = (mblock_t)(((char *) pcurr) + pblock -> size - size - 4);
					pnewblock -> size = size;
					pblock -> size -= 4 + size;
					return (void *) (&pnewblock -> node);
				}
				else {
					dlist_remove(pcurr);
					return (void *) pcurr;
				}
			}
		}
		return NULL;
	}
	
	void xfree(void * ptr){
		dlist_insertHead(&free_list, (dnode_t *) ptr);
	}
	
