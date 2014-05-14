#include <stddef.h>
#include <stdbool.h>

void * find_in( void * values, size_t num_elems, size_t elem_size, bool (*is_better)(void * new, void * old))){
	void * res = values;
	void * cur;
	for (cur = values + elem_size ; --len; cur += elem_size){
		if (is_better(cur, res))
			res = cur;
	}
	return res;
}
